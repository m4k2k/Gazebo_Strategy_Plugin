#include <gazebo/math/Rand.hh>
#include <gazebo/gui/GuiIface.hh>
#include <gazebo/rendering/rendering.hh>
#include <gazebo/gazebo.hh>
#include <gazebo/gui/MouseEventHandler.hh>
#include <gazebo/common/MouseEvent.hh>
#include <boost/thread/mutex.hpp>
#include <boost/thread/thread.hpp>

namespace gazebo
{
class SystemGUI : public SystemPlugin
{
    /////////////////////////////////////////////
    /// \brief Destructor
public:
    virtual ~SystemGUI()
    {
        this->connections.clear();
        if (this->userCam)
            this->userCam->EnableSaveFrame(false);
        this->userCam.reset();
    }

    /////////////////////////////////////////////
    /// \brief Called after the plugin has been constructed.
public:
    void Load(int /*_argc*/, char ** /*_argv*/)
    {
        this->connections.push_back(
            event::Events::ConnectPreRender(
                boost::bind(&SystemGUI::Update, this)));

        gui::MouseEventHandler::Instance()->AddPressFilter("glwidget", boost::bind(&SystemGUI::OnMousePress, this, _1));
    }

    /////////////////////////////////////////////
    // \brief Called once after Load
private:
    void Init()
    {
    }

    boost::mutex mutexMouseClicked;
    math::Vector2i mouseClicked;
    bool isMouseClicked;
private:
    bool OnMousePress(const common::MouseEvent& _event)
    {
        boost::mutex::scoped_lock lock(mutexMouseClicked);
        mouseClicked = _event.pos;
        isMouseClicked = true;
        std::cout<<"Clicked at "<<mouseClicked<<" of screen "<<std::endl;
    }

    /////////////////////////////////////////////
    /// \brief Called every PreRender event. See the Load function.
private:
    void Update()
    {
        if (!this->userCam)
        {
            // Get a pointer to the active user camera
            this->userCam = gui::get_active_camera();
        }
        // Get scene pointer
        rendering::ScenePtr scene = rendering::get_scene();

        // Wait until the scene is initialized.
        if (!scene || !scene->GetInitialized())
            return;

        if(isMouseClicked && this->userCam)
        {
            boost::mutex::scoped_lock lock(mutexMouseClicked);
            math::Vector3 position_clicked;
            scene->GetFirstContact(this->userCam, mouseClicked, position_clicked);
            std::cout<<"Clicked at "<<position_clicked<<" of world\n"<<std::endl;
            isMouseClicked = false;
        }
    }

    /// Pointer the user camera.
private:
    rendering::UserCameraPtr userCam;

    /// All the event connections.
private:
    std::vector<event::ConnectionPtr> connections;
};

// Register this plugin with the simulator
GZ_REGISTER_SYSTEM_PLUGIN(SystemGUI)
}
