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
#include <gazebo/math/gzmath.hh>
#include <gazebo/gui/gui.hh>
#include <gazebo/gui/GuiIface.hh>
#include <gazebo/gui/MouseEventHandler.hh>
//#include <gazebo/common/MouseEvent.hh>
#include <gazebo/common/common.hh>



#include <geometry_msgs/Twist.h>
//#include <geometry_msgs/PoseStamped.h>

#include <move_base_msgs/MoveBaseAction.h>

#include <actionlib/client/simple_action_client.h>

//#include "actionlib/client/action_client.h"
#include <actionlib/client/terminal_state.h>
//#include "actionlib/client/simple_goal_state.h"

#include <actionlib/client/simple_client_goal_state.h>

#include <sstream>
#include <iostream>
#include <stdlib.h>

//#include <qt4/Qt/qmessagebox.h>
//#include <QtCore>
//#include <QtWidgets/QMessageBox>
//#include <QMessageBox>

#include <boost/thread/mutex.hpp>
#include <boost/thread/thread.hpp>
//#include <boost/thread.hpp>



//GAZEBO_QT_HEADERS_H_

//#include <QtGui>


//using namespace gazebo; // instead of namespace gazebo { ... }

// Register this plugin with the simulator
//GZ_REGISTER_SYSTEM_PLUGIN(GazeboMove)


#include "gazebo_move_v2.hh"

#define PLUGIN_NAME "GazeboMove"
#define PLUGIN_VERSION "2.02.010"

//namespace gazebo
//{
//gazebo

/////////////////////////////////////////////
/// \brief Constructor
GazeboMove::GazeboMove()
{
    //std::cout << std::endl << "We are online!" << std::endl;
//    ros::NodeHandle b;
//
//    nod =  &b;
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
        std::cout << std::endl << "ROS is initialized.." << std::endl;
        return true;
    }
    return false;
}


/////////////////////////////////////////////
/// \brief Destructor
GazeboMove::~GazeboMove()
{
    this->connections.clear();
    if (this->userCam)
        this->userCam->EnableSaveFrame(false);
    this->userCam.reset();
}

///////////////////////////////////////////////
///// \brief called after the plugin has been constructed.
///// \brief loaded before gzclient is fully loaded / rendered
///// \brief and before other plugins

void GazeboMove::Load(int _argc, char** _argv)
{
    std::cout << std::endl << "Loading Gazebo Plugin " << PLUGIN_NAME << "version " << PLUGIN_VERSION << std::endl;
    this->connections.push_back(gazebo::event::Events::ConnectPreRender(boost::bind(&GazeboMove::Update, this)));
    gazebo::gui::MouseEventHandler::Instance()->AddPressFilter("glwidget", boost::bind(&GazeboMove::OnMousePress, this, _1));
    //QMessageBox::information(NULL, "msgbox 2", "Hi!");
//ros::Duration
}

bool GazeboMove::OnMousePress(const gazebo::common::MouseEvent& _event)
{
    boost::mutex::scoped_lock lock(mutexMouseClicked);
    mouseClicked = _event.pos;
    isMouseClicked = true;
    std::cout << "Clicked at " << mouseClicked << " of screen " << std::endl;
}

/////////////////////////////////////////////
/// \brief Called every PreRender event. See the Load function.
void GazeboMove::Update()
{
    if (!this->userCam)
    {
        // Get a pointer to the active user camera
        this->userCam = gazebo::gui::get_active_camera();
    }
    // Get scene pointer
    gazebo::rendering::ScenePtr scene = gazebo::rendering::get_scene();

    // Wait until the scene is initialized.
    if (!scene || !scene->GetInitialized())
        return;

    if(isMouseClicked && this->userCam)
    {
        boost::mutex::scoped_lock lock(mutexMouseClicked);
        gazebo::math::Vector3 position_clicked;
        scene->GetFirstContact(this->userCam, mouseClicked, position_clicked);
        std::cout<< "Clicked at " << position_clicked << " of world\n" << std::endl;
        isMouseClicked = false;
        MoveRobotNav(position_clicked);
    }
}

/////////////////////////////////////////////
// \brief called once after Load
// \brief loaded after other plugins run through Load and Constructor
void GazeboMove::Init()
{
    std::cout << std::endl << "init" << std::endl;
    while(!CheckROS())
        sleepLoud(5);
}

void GazeboMove::sleepLoud(unsigned int _sleepTime)
{
    std::cout << std::endl << "sleeping " << _sleepTime << " seconds" << std::endl;
    for(int i=0; i<_sleepTime; i++)
    {
        gazebo::common::Time::Sleep(1);
        //sleep(1);
    }
}

int GazeboMove::main(int argc, char** argv)
{
    std::cout << std::endl << " main is loaded Oo" << std::endl;
}

/////////////////////////////////////////////////
void GazeboMove::MoveRobotThreaded()
{

//std::thread t1(task1, "Hello");
    if(t1 != NULL && t1->joinable())
    {
        t1->join();
        t1->interrupt();
        //delete t1;
    }

    //t1 = new boost::thread(&MoveRobotNav);

    // GazeboMove::MoveRobot();
}


void GazeboMove::MoveRobotNav(gazebo::math::Vector3 _target)
{
    //ros::init(argc, argv, "simple_navigation_goals");

    //tell the action client that we want to spin a thread by default

    MoveBaseClient ac("move_base", true);
    //wait for the action server to come up
    while(!ac.waitForServer(ros::Duration(5.0)))
    {
        ROS_INFO("Waiting for the move_base action server to come up");
    }

    move_base_msgs::MoveBaseGoal goal;

    //we'll send a goal to the robot to move 1 meter forward
    //goal.target_pose.header.frame_id = "base_link";
    goal.target_pose.header.frame_id = "/map";
    goal.target_pose.header.stamp = ros::Time::now();

    //goal.target_pose.pose.position.x = 1.0;
    goal.target_pose.pose.position.x = _target.x;
    goal.target_pose.pose.position.y = _target.y;
    goal.target_pose.pose.position.z = _target.z;
    //goal.target_pose.pose.position.x = 1.0;
    goal.target_pose.pose.orientation.w = 1.0;

    ROS_INFO("Sending goal");


    // Need boost::bind to pass in the 'this' pointer_safety
    //ac.sendGoal(goal, boost::bind(&GazeboMove::doneCb, this, _1, _2), Client::SimpleActiveCallback(), Client::SimpleFeedbackCallback());
    ac.sendGoal(goal, boost::bind(&GazeboMove::doneCb, this, _1), MoveBaseClient::SimpleActiveCallback(), MoveBaseClient::SimpleFeedbackCallback());
/*
    ac.sendGoal(goal,

                 boost::bind(&GazeboMove::goalCallback, this, _1, _2),
                 MoveBaseClient::SimpleActiveCallback(),
                 boost::bind(&GazeboMove::feebackCallback, this, _1));

                 ac.sendGoal(goal,boost::bind(&Pose_Goal::doneCb, this, _1, _2), Client::SimpleActiveCallback(),Client::SimpleFeedbackCallback());

void Pose_Goal::feedbackCb(const move_base_msgs::MoveBaseFeedbackConstPtr &feedback){
    ROS_INFO("[X]:%f [Y]:%f [W]: %f",feedback->base_position.pose.position.x,feedback->base_position.pose.position.y,feedback->base_position.pose.orientation.w);



    ac.sendGoal(goal);
    ac.waitForResult();

    if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
        ROS_INFO("Hooray, the base moved 1 meter forward");
    else
        ROS_INFO("The base failed to move forward 1 meter for some reason");
    */
}

/*
*/
void GazeboMove::goalCallback(const actionlib::SimpleClientGoalState& state,
                                const move_base_msgs::MoveBaseResult::ConstPtr& result)
{
    if(state == actionlib::SimpleClientGoalState::SUCCEEDED)
        ROS_INFO("Goal reached!!");
    else
        ROS_INFO("Goal failed!!");
}



void GazeboMove::feebackCallback(const move_base_msgs::MoveBaseFeedback::ConstPtr& feedback)
{
ROS_INFO("Callback received 2");


}


void GazeboMove::doneCb(const actionlib::SimpleClientGoalState& state)
{
ROS_INFO("Callback received");
    ROS_INFO("Finished in state [%s]", state.toString().c_str());
    //ROS_INFO("Answer: %i", result->sequence.back());
    //ros::shutdown();
}


void GazeboMove::MoveRobot()// const
{

    // Make sure the ROS node for Gazebo has already been initialized
    if (!ros::isInitialized())
    {
        ROS_FATAL_STREAM("A ROS node for Gazebo has not been initialized and I was unable to initialize manually, unable to load plugin. "
                         << "Load the Gazebo system plugin 'libgazebo_ros_api_plugin.so' in the gazebo_ros package)");
        //return;
    }
    else
    {
        //GazeboMove::com

        ros::NodeHandle nod;

        ros::Publisher pub;

        pub = nod.advertise<geometry_msgs::Twist>("cmd_vel_mux/input/teleop", 100);

        //pub = this->nod.advertise<geometry_msgs::Twist>("cmd_vel_mux/input/teleop", 100);

        ros::Rate rate(100);
        srand(time(0));
        //ros::Subscriber sub = n.subscribe("my_cmd_vel", 10, velCallback);
        int cnt(0);
        int velmsgs(50);
//
        std::cout << "Sending " << velmsgs <<" vel msgs" << std::endl;

        while (ros::ok())
        {

//            ros::Duration(5.0).sleep();
            cnt++;
            //ROS_INFO("Sending vel msg %i",cnt);
            geometry_msgs::Twist new_vel;
            //new_vel.linear.x = 100.0;//(4*double(rand())/double(RAND_MAX)-2)*100.0;
            //new_vel.linear.y = 0;
            //new_vel.linear.z = (6*double(rand())/double(RAND_MAX)-3)*10.0;
            new_vel.angular.x = 0;
            new_vel.angular.y = 0;
            new_vel.angular.z = 0;
            new_vel.linear.x = 1.0;
            new_vel.linear.y = 0;
            new_vel.linear.z = 0;

//        new_vel.angular.x = 0;
//        new_vel.angular.y = 0;
//        new_vel.angular.z = 1.0;

            pub.publish(new_vel);
            ros::spinOnce();
            rate.sleep();
            //sleepLoud(5);
            if(cnt>=velmsgs) break;
            //break;
        }

    }

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






//    void velCallback(geometry_msgs::Twist::ConstPtr& vel)
//
//    {
//
//        geometry_msgs::Twist new_vel = *vel;
//
//        if (vel->linear.x > 1.8)
//        {
//
//            new_vel.linear.x = 1.8;
//
//        }
//
//        pub.publish(new_vel);
//
//
//      //  std::cout << "call back " << &vel << std::endl ;
//
//    }




/*

 std::cout << "Test!!!" << std::endl;
//
//        // Make sure the ROS node for Gazebo has already been initialized
//        if (!ros::isInitialized())
//        {
//            ROS_FATAL_STREAM("A ROS node for Gazebo has not been initialized, unable to load plugin. "
//                             << "Load the Gazebo system plugin 'libgazebo_ros_api_plugin.so' in the gazebo_ros package)");
//            return;
//        }
//
//        else
//
//        {
//            ROS_INFO("Hello World!");
//            std::cout << "ROS is Init.." << std::endl;


        // Create our node for communication




//        void velCallback(geometry_msgs::Twist::ConstPtr& vel)
//
//        {
//
//            geometry_msgs::Twist new_vel = *vel;
//
//            if (vel->linear.x > 1.8)
//            {
//
//                new_vel.linear.x = 1.8;
//
//            }
//
//            pub.publish(new_vel);
//
//        }



//        int main(int argc, char **argv)
//
//        {

        // ros::init(argc, argv, "my_node");



//        ros::Duration(120.0).sleep();


//            ros::Publisher pub;
//
//
//            ros::NodeHandle n;
//
//            pub = n.advertise<geometry_msgs::Twist>("cmd_vel_mux/input/teleop", 10);



//        while (ros::ok())
//
//        {

        //ros::Subscriber sub = n.subscribe("my_cmd_vel", 10, velCallback);

//            geometry_msgs::Twist new_vel;
//
//            new_vel.linear.x = 1.8;
//
//            new_vel.linear.z = 1.8;
//
//            pub.publish(new_vel);
//
//            ros::spinOnce();
        //    }
//        }

//            return 0;
//
//        }


        std::cout << "Test construct" << std::endl;







*/
