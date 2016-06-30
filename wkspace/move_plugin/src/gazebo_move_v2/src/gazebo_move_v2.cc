/*
 * Copyright (C) 2012-2015 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

// Include Rand.hh first due to compilation error on osx (boost #5010)
// https://svn.boost.org/trac/boost/ticket/5010
#include <gazebo/math/Rand.hh>
//#include <gazebo/gui/GuiIface.hh>
#include <gazebo/rendering/rendering.hh>
#include <gazebo/gazebo.hh>

#include <gazebo/transport/transport.hh>
#include <gazebo/msgs/msgs.hh>
#include <gazebo/math/gzmath.hh>
// #include <gazebo/common/plugin.hh>

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <iostream>

#include <stdlib.h>
//#include <qt4/Qt/qmessagebox.h>

//#include <QtCore>


//#include <qt
//#include <QtWidgets/QMessageBox>

//#include <QMessageBox>

//#include <gazebo/math/Rand.hh>
#include <gazebo/gui/GuiIface.hh>
//#include <gazebo/rendering/rendering.hh>
//#include <gazebo/gazebo.hh>
#include <gazebo/gui/MouseEventHandler.hh>
#include <gazebo/common/MouseEvent.hh>
#include <boost/thread/mutex.hpp>
#include <boost/thread/thread.hpp>

//#include <boost/thread.hpp>

#include <sstream>
// #include <gazebo/msgs/msgs.hh>
// #include <gazebo/gazebo.hh>



//GAZEBO_QT_HEADERS_H_

//#include <QtGui>
#include <gazebo/gui/gui.hh>

//using namespace gazebo; // instead of namespace gazebo { ... }

// Register this plugin with the simulator
//GZ_REGISTER_SYSTEM_PLUGIN(GazeboMove)


#include "gazebo_move_v2.hh"

//namespace gazebo
//{
//gazebo

/////////////////////////////////////////////
/// \brief Constructor
GazeboMove::GazeboMove()
{

    std::cout << std::endl << "We are online!" << std::endl;
    /*
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
    */



//    ros::NodeHandle b;
//
//    nod =  &b;


}

void GazeboMove::CheckROS()
{
    if(ros::master::check())
    {
        if (!ros::isInitialized())
        {
            ROS_INFO("ROS is not initialized, trying to initialize it..");

            int argc = 0;

            char** argv = NULL;

            ros::init(argc, argv, "gazebo", ros::init_options::NoSigintHandler |

                      ros::init_options::AnonymousName);

        }
        else
            std::cout << std::endl << "ROS is already initialized.." << std::endl;
    }
    else
        std::cout << std::endl << "ROS Master not running.." << std::endl;

}


/////////////////////////////////////////////
/// \brief Destructor
GazeboMove::~GazeboMove()
{
this->connections.clear();
}



///////////////////////////////////////////////
///// \brief called after the plugin has been constructed.
///// \brief loaded before gzclient is fully loaded / rendered
///// \brief and before other plugins

void GazeboMove::Load(int _argc, char** _argv)
{
    std::cout << std::endl << "load" << std::endl;

/*
            this->connections.push_back(
            event::Events::ConnectPreRender(
                boost::bind(&SystemMouse::Update, this)));
*/


    //ros::init(_argc, _argv, "pub_joint_command_test");

    //QMessageBox::information(NULL, "msgbox 2", "Hi!");
//ros::Duration

}

/////////////////////////////////////////////
// \brief called once after Load
// \brief loaded after other plugins run through Load and Constructor
void GazeboMove::Init()
{
    sleepLoud(5);
    CheckROS();
//    sleepLoud(15);
//    CheckROS();
    std::cout << std::endl << "init" << std::endl;
}

void GazeboMove::sleepLoud(unsigned int _sleepTime)
{
    for(int i=0; i<_sleepTime; i++)
    {
        gazebo::common::Time::Sleep(1);
        //sleep(1);
        std::cout << std::endl << "sleep " << i << std::endl;
    }
}

int GazeboMove::main(int argc, char** argv)
{

    //ros::init(argc, argv, "pub_joint_command_test");

    std::cout << std::endl << " main is loaded Oo" << std::endl;

}



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


/////////////////////////////////////////////////
void GazeboMove::OnButton_btnMoveRobot()
{


//std::thread t1(task1, "Hello");
    if(t1 != NULL && t1->joinable())
    {
        t1->join();
        t1->interrupt();
        //delete t1;
    }

    t1 = new boost::thread(&MoveRobot);

    // GazeboMove::MoveRobot();
}
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
//
        while (ros::ok())
        {
//
//            ros::Duration(5.0).sleep();
            cnt++;
            //ROS_INFO("Sending vel msg %i",cnt);
            std::cout << "Sending vel msg " << cnt << std::endl;
            geometry_msgs::Twist new_vel;
            //new_vel.linear.x = 100.0;//(4*double(rand())/double(RAND_MAX)-2)*100.0;
            //new_vel.linear.y = 0;
            //new_vel.linear.z = (6*double(rand())/double(RAND_MAX)-3)*10.0;
            new_vel.angular.x = 0;
            new_vel.angular.y = 0;
            new_vel.angular.z = 0;
            new_vel.linear.x = 100.0;
            new_vel.linear.y = 0;
            new_vel.linear.z = 0;
//
//        new_vel.angular.x = 0;
//        new_vel.angular.y = 0;
//        new_vel.angular.z = 1.0;
            pub.publish(new_vel);
            ros::spinOnce();
            rate.sleep();
            if(cnt>=1000) break;
        }

    }

}

GZ_REGISTER_SYSTEM_PLUGIN(GazeboMove)
//}



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
