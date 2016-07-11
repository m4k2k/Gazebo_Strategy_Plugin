/*
 *
 *
*/

#ifndef _GAZEBO_MOVE_V2_HH_
#define _GAZEBO_MOVE_V2_HH_

class GazeboMove : public gazebo::SystemPlugin
{
    // Q_OBJECT

    typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

public:
    /// \brief Constructor
    /// \param[in] _parent Parent widget
    GazeboMove();
    /// \brief Destructor
    virtual ~GazeboMove();
    void Load(int _argc = 0, char **_argv = NULL) ; //redeclaring it, to be aware of it

private:

    MoveBaseClient* ac;
    /// All the event connections.
    std::vector<gazebo::event::ConnectionPtr> connections;

    /// Pointer the user camera.
    gazebo::rendering::UserCameraPtr userCam;

    bool sendNavGoal;

    void Init();
    void Update(); // only declared to be aware of


    bool CheckROS();

    void MoveRobotNav(gazebo::math::Vector3& _target);

    void goalCallback(const actionlib::SimpleClientGoalState& _state,
                      const move_base_msgs::MoveBaseResult::ConstPtr& _result);

    void feedbackCb(const move_base_msgs::MoveBaseFeedback::ConstPtr& _feedback);

    static void sleepLoud(unsigned int _sleepTime);

    bool OnMouseButtonPress(const gazebo::common::MouseEvent& _event);







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



};

#endif
