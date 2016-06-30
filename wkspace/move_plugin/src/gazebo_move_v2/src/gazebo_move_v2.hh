/*
 * Copyright (C) 2014-2015 Open Source Robotics Foundation
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

#ifndef _GAZEBO_MOVE_V2_HH_
#define _GAZEBO_MOVE_V2_HH_

//#include <gazebo/common/Plugin.hh>
/*
#include <gazebo/gui/GuiPlugin.hh>
#ifndef Q_MOC_RUN  // See: https://bugreports.qt-project.org/browse/QTBUG-22829
#include <gazebo/transport/transport.hh>
#include <gazebo/gui/gui.hh>
#endif
*/
//#include <boost/thread.hpp>

//#include <ros/ros.h>

//using namespace gazebo;
//namespace gazebo
//{
class GazeboMove : public gazebo::SystemPlugin
{

    // Q_OBJECT

    /// \brief Constructor
    /// \param[in] _parent Parent widget
public:
    GazeboMove();

    /// \brief Destructor
public:
    virtual ~GazeboMove();

public:
    boost::thread * t1;

private:
    void OnButton_btnSpawnSphere();
    void OnButton_btnMoveRobot();
    void OnButton_btnTest();
    void CheckROS();

    void Init();

private:
    std::vector<event::ConnectionPtr> connections;


//    class communication
//    {
//        public ros::Publisher pub;
//        public ros::NodeHandle nod;
//    }
//
//private:
//    communication com;

    /*
    private:
            ros::NodeHandle nod;

    */

    //ros::Publisher * pub;


//      public: int main();

    /*

        /// \brief Counter used to create unique model names
    private:
        unsigned int counter;



        /// \brief Node used to establish communication with gzserver.
    private:
        transport::NodePtr node;


        /// \brief Publisher of factory messages.
    private:
        transport::PublisherPtr factoryPub;
    */
private:
    static void MoveRobot(); //const;
    void sleepLoud(unsigned int _sleepTime);
//
public:
    void Load(int _argc = 0, char **_argv = NULL) ; //redeclaring it, to be aware of it
    int main(int argc, char** argv);

};
//}
//}
#endif