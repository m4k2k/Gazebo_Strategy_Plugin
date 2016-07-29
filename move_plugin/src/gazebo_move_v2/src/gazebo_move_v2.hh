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

    struct RobotGoalClient
    {
        RobotGoalClient() {}
        RobotGoalClient(const std::string& _name, MoveBaseClient* _actionclient): name(_name) , actionclient(_actionclient) {}
        std::string name;                   ///< Name of the robot
        MoveBaseClient* actionclient;       ///< Pointer to the actionclient
    };

    typedef std::vector<RobotGoalClient> V_RobotGoalClient;


public:
    /// \brief Constructor
    /// \param[in] _parent Parent widget
    GazeboMove();
    /// \brief Destructor
    virtual ~GazeboMove();
    void Load(int _argc = 0, char **_argv = NULL) ; //redeclaring it, to be aware of it

private:

    V_RobotGoalClient VecGoalClients;

    /// All the event connections.
    std::vector<gazebo::event::ConnectionPtr> connections;

    /// Pointer the user camera.
    gazebo::rendering::UserCameraPtr userCam;

    GazeboMove::V_RobotGoalClient::iterator V_RobotGoalClient_GetIt(const std::string& _robotname, GazeboMove::V_RobotGoalClient& _cVec);

    bool sendNavGoal;

    bool isNavEnabled(std::string _robotNamespace);

    std::string getNameSpaceOfTopic(const std::string& _topicFQDN);

    void PrintNavEnabledRobots();

    static bool HasNoMoveBaseActionGoal(const ros::master::TopicInfo& _info);


    void Init();
    void Update(); // only declared to be aware of


    bool CheckROS();

    void MoveRobotNav(gazebo::math::Vector3& _target, GazeboMove::MoveBaseClient* _ac);





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
