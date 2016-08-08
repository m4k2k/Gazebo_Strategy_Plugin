/*
 *
 *
*/

// Include Rand.hh first due to compilation error on osx (boost #5010)
// https://svn.boost.org/trac/boost/ticket/5010
#include <gazebo/math/Rand.hh>

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

#include <gazebo/rendering/rendering.hh>
#include <gazebo/transport/transport.hh>
#include <gazebo/msgs/msgs.hh>
#include <gazebo/gui/gui.hh>
#include <gazebo/common/common.hh>

#include "gazebo_move_v2.hh"

#define PLUGIN_NAME "GazeboMove"
#define PLUGIN_VERSION "2.04"

/////////////////////////////////////////////
/// \brief Constructor
GazeboMove::GazeboMove()
{

}

/////////////////////////////////////////////
/// \brief Destructor
GazeboMove::~GazeboMove()
{

    for (GazeboMove::V_RobotGoalClient::iterator it = VecGoalClients.begin() ; it != VecGoalClients.end(); it++)
    {
        const GazeboMove::RobotGoalClient& rc = *it;
        delete rc.actionclient;
    }
    VecGoalClients.clear();
    gazebo::gui::MouseEventHandler::Instance()->RemovePressFilter("glwidget"); // removes the mouse click subscription

}

///////////////////////////////////////////////
///// \brief called after the plugin has been constructed.
///// \brief loaded before gzclient is fully loaded / rendered
///// \brief and before other plugins

void GazeboMove::Load(int _argc, char** _argv)
{
    std::cout << std::endl << "Loading Gazebo Plugin " << PLUGIN_NAME << " version " << PLUGIN_VERSION << std::endl;

    gazebo::gui::MouseEventHandler::Instance()->AddPressFilter("glwidget", boost::bind(&GazeboMove::OnMouseButtonPress, this, _1)); // we filter all button release events
}

bool GazeboMove::OnMouseButtonPress(const gazebo::common::MouseEvent& _event) //fetches both left and right click
{
    if((_event.button == gazebo::common::MouseEvent::LEFT) && _event.control) //only if the left mouse button and Control are both pressed
    {
        if (!this->userCam)
            this->userCam = gazebo::gui::get_active_camera(); // Get a pointer to the active user camera

        gazebo::rendering::ScenePtr scene = gazebo::rendering::get_scene(); // Get scene pointer

        if (!scene || !scene->GetInitialized()) // Wait until the scene is initialized.
            return true;

        gazebo::math::Vector3 mouseClickpos3D;

        scene->GetFirstContact(this->userCam,  _event.pos, mouseClickpos3D);

        gazebo::rendering::VisualPtr vpt = scene->GetSelectedVisual();

        if (vpt!=NULL)
        {

            std::string robotName = vpt->GetName();

            std::cout << "I catched a " << robotName << "! and I can";

            if (!isNavEnabled(robotName))
                std::cout << "'t";

            else
            {
                //now we can work.. we know we have a nav robot

                GazeboMove::V_RobotGoalClient::iterator it = V_RobotGoalClient_GetIt(robotName, VecGoalClients);

                if(it!=VecGoalClients.end())
                {
                    const GazeboMove::RobotGoalClient& rc = *it;

                    MoveRobotNav(mouseClickpos3D,rc.actionclient);

                }
                else//the iterator is Empty or Client not yet present -> we need a new client
                {
                    GazeboMove::RobotGoalClient rGc = RobotGoalClient(robotName, new MoveBaseClient(robotName + "/move_base", true));


                    while(!rGc.actionclient->waitForServer(ros::Duration(5.0))) ROS_INFO("Waiting for the move_base action server to come up");

                    VecGoalClients.push_back(rGc);

                    MoveRobotNav(mouseClickpos3D,rGc.actionclient);
                }
            }
            std::cout << " navigate it!" << std::endl;
        }
    }

    return true;
}

bool GazeboMove::CheckROS()
{
    if(!ros::master::check() && !ros::isInitialized())
    {
        ROS_INFO("ROS is not initialized, trying to initialize it..");
        int argc = 0;
        char** argv = NULL;
        ros::init(argc, argv, "gazebo", ros::init_options::NoSigintHandler | ros::init_options::AnonymousName);
    }
    else
    {
        ROS_INFO("ROS is initialized..");
        return true;
    }
    return false;
}

void GazeboMove::DebugMBox(const std::string& _message)
{
    QMessageBox msgBox;
    msgBox.setText(QString::fromStdString(_message));
    msgBox.exec();
}

GazeboMove::V_RobotGoalClient::iterator  GazeboMove::V_RobotGoalClient_GetIt(const std::string& _robotname, GazeboMove::V_RobotGoalClient& _cVec)
{

    for (GazeboMove::V_RobotGoalClient::iterator it = _cVec.begin() ; it != _cVec.end(); it++)
    {
        const GazeboMove::RobotGoalClient& rc = *it;

        if(rc.name == _robotname)
            return it;
    }

    return _cVec.end();
}

bool GazeboMove::HasNoMoveBaseActionGoal(const ros::master::TopicInfo& _info)
{
    return (_info.datatype != "move_base_msgs/MoveBaseActionGoal");
}



std::string GazeboMove::getNameSpaceOfTopic(const std::string& _topicFQDN)
{
    return _topicFQDN.substr(1,_topicFQDN.find('/',1)-1);
}


bool GazeboMove::isNavEnabled(std::string _robotNamespace)
{

    ros::master::V_TopicInfo master_topics;

    ros::master::getTopics(master_topics);/**< Getting all available ROS Topics which are published */

    if(master_topics.size())/**< Check the size (if no topics available, very uncommon but could happen then we dont need to continue */
    {
        master_topics.erase(std::remove_if(master_topics.begin(), master_topics.end(), HasNoMoveBaseActionGoal),master_topics.end());/**< Removing all topics which doesnt have a movebasegoal (required for our navigation)*/

        if(master_topics.size()) /**< we only continue if there are navigateable robots */

            for (ros::master::V_TopicInfo::iterator it = master_topics.begin() ; it != master_topics.end(); it++)
            {
                const ros::master::TopicInfo& info = *it;

                if(GazeboMove::getNameSpaceOfTopic(info.name) == _robotNamespace)

                    return true;
            }

        else

            std::cout << "no controlable robots found!" << std::endl;
    }
    else

        std::cout << "no topics found, there muse be an error?!" << std::endl;

    return false;
}

void GazeboMove::PrintNavEnabledRobots()
{
    ros::master::V_TopicInfo master_topics;

    ros::master::getTopics(master_topics);/**< Getting all available ROS Topics which are published */

    master_topics.erase(std::remove_if(master_topics.begin(), master_topics.end(), HasNoMoveBaseActionGoal),master_topics.end());/**< Removing all topics which doesnt have a movebasegoal (required for our navigation)*/

    std::cout << "available robots: ";

    for (ros::master::V_TopicInfo::iterator it = master_topics.begin() ; it != master_topics.end(); it++)
    {
        const ros::master::TopicInfo& info = *it;

        std::cout << info.name << " ";
    }

    std::cout << std::endl;
}


/////////////////////////////////////////////
// \brief called once after Load
// \brief loaded after other plugins run through Load and Constructor
// \brief loaded after Gazebo is loaded completly
void GazeboMove::Init()
{
    std::cout << std::endl << "init" << std::endl;
    while(CheckROS())
        break;
}

void GazeboMove::sleepLoud(unsigned int _sleepTime)
{
    std::cout << std::endl << "sleeping " << _sleepTime << " seconds" << std::endl;
    for(unsigned int i=0; i<_sleepTime; i++) gazebo::common::Time::Sleep(1);
}

void GazeboMove::MoveRobotNav(gazebo::math::Vector3& _target, MoveBaseClient* _ac)
{
    //tell the action client that we want to spin a thread by default

    if(_ac->isServerConnected())
    {
        move_base_msgs::MoveBaseGoal goal;

        goal.target_pose.header.frame_id = "/map";
        goal.target_pose.header.stamp = ros::Time::now();

        goal.target_pose.pose.position.x = _target.x;
        goal.target_pose.pose.position.y = _target.y;
        goal.target_pose.pose.position.z = _target.z;

        goal.target_pose.pose.orientation.w = 1.0;

        ROS_INFO("Sending goal [X]:%f [Y]:%f [W]:%f", goal.target_pose.pose.position.x, goal.target_pose.pose.position.y, goal.target_pose.pose.orientation.w);

        // Need boost::bind to pass in the 'this' pointer_safety
        _ac->sendGoal(goal,
                      boost::bind(&GazeboMove::goalCallback, this, _1, _2),
                      MoveBaseClient::SimpleActiveCallback(),
                      boost::bind(&GazeboMove::feedbackCb, this, _1));
    }
    else
    {
        ROS_INFO("##ERROR##");
        ROS_INFO("ac server not ready??");
    }
}

void GazeboMove::feedbackCb(const move_base_msgs::MoveBaseFeedback::ConstPtr& _feedback)
{
    ROS_INFO("currently at [X]:%f [Y]:%f [W]:%f",_feedback->base_position.pose.position.x,_feedback->base_position.pose.position.y,_feedback->base_position.pose.orientation.w);
}

void GazeboMove::goalCallback(const actionlib::SimpleClientGoalState& _state, const move_base_msgs::MoveBaseResult::ConstPtr& _result)
{
    if(_state == actionlib::SimpleClientGoalState::SUCCEEDED)
        ROS_INFO("Goal reached!!");
    else
        ROS_INFO("Goal failed!!");
}

GZ_REGISTER_SYSTEM_PLUGIN(GazeboMove)

/* ############################################ CODE END ############################################ */
