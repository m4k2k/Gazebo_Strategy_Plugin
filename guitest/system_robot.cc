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
#include <gazebo/gui/GuiIface.hh>
#include <gazebo/rendering/rendering.hh>
#include <gazebo/gazebo.hh>

#include <gazebo/transport/transport.hh>
#include <gazebo/msgs/msgs.hh>
#include <gazebo/math/gzmath.hh>

#include <ros/ros.h>

#include <geometry_msgs/Twist.h>
#include <iostream>

namespace gazebo
{
class RobotPlugin : public SystemPlugin
{
    /////////////////////////////////////////////
    /// \brief Destructor
public:
    virtual ~RobotPlugin()
    {

    }

    public:
       RobotPlugin() : SystemPlugin()
    {

       std::cout << "Test!!!" << std::endl;

        // Make sure the ROS node for Gazebo has already been initialized
        if (!ros::isInitialized())
        {
            ROS_FATAL_STREAM("A ROS node for Gazebo has not been initialized, unable to load plugin. "
                             << "Load the Gazebo system plugin 'libgazebo_ros_api_plugin.so' in the gazebo_ros package)");
            return;
        }

        else

        {
            ROS_INFO("Hello World!");
            std::cout << "ROS is Init.." << std::endl;


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


            ros::Publisher pub;


            ros::NodeHandle n;

            pub = n.advertise<geometry_msgs::Twist>("cmd_vel_mux/input/teleop", 1000);



//        while (ros::ok())
//
//        {

            //ros::Subscriber sub = n.subscribe("my_cmd_vel", 10, velCallback);

            geometry_msgs::Twist new_vel;

            new_vel.linear.x = 1.8;

            new_vel.linear.z = 1.8;

            pub.publish(new_vel);

            ros::spinOnce();
        }
//        }

//            return 0;
//
//        }








    }

    /////////////////////////////////////////////
    /// \brief Called after the plugin has been constructed.
public:
    void Load(int /*_argc*/, char ** /*_argv*/)
    {


    }

/////////////////////////////////////////////
// \brief Called once after Load
private:
    void Init()
    {
    }

/////////////////////////////////////////////
/// \brief Called every PreRender event. See the Load function.
private:
    void Update()
    {
    }
};

// Register this plugin with the simulator
GZ_REGISTER_SYSTEM_PLUGIN(RobotPlugin)
}
