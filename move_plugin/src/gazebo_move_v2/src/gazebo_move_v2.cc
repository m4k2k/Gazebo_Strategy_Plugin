/*
 *
 *
*/

// Include Rand.hh first due to compilation error on osx (boost #5010)
// https://svn.boost.org/trac/boost/ticket/5010
#include <gazebo/math/Rand.hh>

#include <ros/ros.h>

#include <gazebo/rendering/rendering.hh>
//#include <gazebo/gazebo.hh> //rem
#include <gazebo/transport/transport.hh>
#include <gazebo/msgs/msgs.hh>
//#include <gazebo/math/gzmath.hh>
#include <gazebo/gui/gui.hh>
//#include <gazebo/gui/GuiIface.hh>
//#include <gazebo/gui/MouseEventHandler.hh>
//#include <gazebo/common/MouseEvent.hh>
#include <gazebo/common/common.hh>

#include <geometry_msgs/Twist.h>

#include <move_base_msgs/MoveBaseAction.h>

#include <actionlib/client/simple_action_client.h>
//#include <actionlib/client/terminal_state.h>
//#include <actionlib/client/simple_client_goal_state.h>

//#include <sstream>
//#include <iostream>
//#include <stdlib.h>

//#include <algorithm>

//#include <qt4/Qt/qmessagebox.h>
//#include <QtCore>
//#include <QtWidgets/QMessageBox>
//#include <QMessageBox>

//#include <boost/thread/mutex.hpp>
//#include <boost/thread/thread.hpp>
//#include <boost/thread.hpp>



//GAZEBO_QT_HEADERS_H_

//#include <QtGui>


//using namespace gazebo; // instead of namespace gazebo { ... }

// Register this plugin with the simulator
//GZ_REGISTER_SYSTEM_PLUGIN(GazeboMove)

#include "gazebo_move_v2.hh"

#define PLUGIN_NAME "GazeboMove"
#define PLUGIN_VERSION "2.04"

/////////////////////////////////////////////
/// \brief Constructor
GazeboMove::GazeboMove()
{

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

//delete rc1.actionclient;
//delete ac2;
    this->connections.clear();
    gazebo::gui::MouseEventHandler::Instance()->RemovePressFilter("glwidget"); // removes the mouse click subscription
}

///////////////////////////////////////////////
///// \brief called after the plugin has been constructed.
///// \brief loaded before gzclient is fully loaded / rendered
///// \brief and before other plugins

void GazeboMove::Load(int _argc, char** _argv)
{
    std::cout << std::endl << "Loading Gazebo Plugin " << PLUGIN_NAME << " version " << PLUGIN_VERSION << std::endl;
    this->connections.push_back(gazebo::event::Events::ConnectPreRender(boost::bind(&GazeboMove::Update, this)));
    gazebo::gui::MouseEventHandler::Instance()->AddPressFilter("glwidget", boost::bind(&GazeboMove::OnMouseButtonPress, this, _1)); // we filter all button release events
    //QMessageBox::information(NULL, "msgbox 2", "Hi!");
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

GazeboMove::V_RobotGoalClient::iterator  GazeboMove::V_RobotGoalClient_GetIt(const std::string& _robotname, GazeboMove::V_RobotGoalClient& _cVec)
{
    //int index(0); // was used but changed to an iterator since a vector is better not used with indexes, better with iterators
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


/////////////////////////////////////////////
/// \brief Called every PreRender event. See the Load function.
void GazeboMove::Update()
{

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
void GazeboMove::Init()
{
    std::cout << std::endl << "init" << std::endl;
    while(CheckROS())
        break;//sleepLoud(5);

}

void GazeboMove::sleepLoud(unsigned int _sleepTime)
{
    std::cout << std::endl << "sleeping " << _sleepTime << " seconds" << std::endl;
    for(unsigned int i=0; i<_sleepTime; i++) gazebo::common::Time::Sleep(1);
}
//void GazeboMove::MoveRobotNav(geometry_msgs::Point& _target)
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
        //ac.sendGoal(goal, boost::bind(&GazeboMove::doneCb, this, _1, _2), MoveBaseClient::SimpleActiveCallback(), MoveBaseClient::SimpleFeedbackCallback());
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

/*

void GazeboMove::Constr()
{
    this->counter = 0;

    // Set the frame background and foreground colors
    this->setStyleSheet(
        "QFrame { background-color : rgba(100, 100, 100, 255); color : white; }");

    // Create the main layout
    QHBoxLayout *mainLayout = new QHBoxLayout;

    // Create the frame to hold all the widgets
    QFrame *mainFrame = new QFrame();

    // Create the layout that sits inside the frame
    QVBoxLayout *frameLayout = new QVBoxLayout();

    // Create a push button, and connect it to the OnButton function
    QPushButton *btnSpawnSphere = new QPushButton(tr("Spawn Object"));
    connect(btnSpawnSphere, SIGNAL(clicked()), this, SLOT(OnButton_btnSpawnSphere()));

    QPushButton *btnMoveRobot = new QPushButton(tr("Move Robot"));
    connect(btnMoveRobot, SIGNAL(clicked()), this, SLOT(OnButton_btnMoveRobot()));

    QPushButton *btnTest = new QPushButton(tr("Test"));
    connect(btnTest, SIGNAL(clicked()), this, SLOT(OnButton_btnTest()));


    // Add the button to the frame's layout
    frameLayout->addWidget(btnSpawnSphere);
    frameLayout->addWidget(btnMoveRobot);
    frameLayout->addWidget(btnTest);

    // Add frameLayout to the frame
    mainFrame->setLayout(frameLayout);

    // Add the frame to the main layout
    mainLayout->addWidget(mainFrame);

    // Remove margins to reduce space
    frameLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    this->setLayout(mainLayout);

    // Position and resize this widget
    this->move(10, 10);
    //this->resize(120, 30);
    this->resize(160, 130);

    // Create a node for transportation
    this->node = transport::NodePtr(new transport::Node());
    this->node->Init();
    this->factoryPub = this->node->Advertise<msgs::Factory>("~/factory");
    }
*/



/*
/////////////////////////////////////////////////
void GazeboMove::OnButton_btnTest()
{
    QMessageBox msgBox;
    msgBox.setText("msgbox 1");
    msgBox.exec();

    QMessageBox::information(NULL, "msgbox 2", "Hi!");


}
*/

/*
/////////////////////////////////////////////////
void GazeboMove::OnButton_btnSpawnSphere()
{
    std::ostringstream newModelStr;
    newModelStr << "<sdf version ='" << SDF_VERSION << "'>"
                << "<model name='plugin_unit_sphere_" << this->counter++ << "'>"
                << "  <pose>0 0 1.5 0 0 0</pose>"
                << "  <link name='link'>"
                << "    <inertial><mass>1.0</mass></inertial>"
                << "    <collision name='collision'>"
                << "      <geometry>"
                << "        <sphere><radius>0.5</radius></sphere>"
                << "      </geometry>"
                << "    </collision>"
                << "    <visual name ='visual'>"
                << "      <geometry>"
                << "        <sphere><radius>0.5</radius></sphere>"
                << "      </geometry>"
                << "      <material>"
                << "        <script>"
                << "          <uri>file://media/materials/scripts/gazebo.material</uri>"
                << "          <name>Gazebo/Grey</name>"
                << "        </script>"
                << "      </material>"
                << "    </visual>"
                << "  </link>"
                << "  </model>"
                << "</sdf>";

    // Send the model to the gazebo server
    msgs::Factory msg;
    msg.set_sdf(newModelStr.str());
    this->factoryPub->Publish(msg);
}
*/

