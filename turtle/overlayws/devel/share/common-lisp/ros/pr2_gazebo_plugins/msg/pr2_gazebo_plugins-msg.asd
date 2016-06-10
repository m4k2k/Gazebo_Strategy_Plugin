
(cl:in-package :asdf)

(defsystem "pr2_gazebo_plugins-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
)
  :components ((:file "_package")
    (:file "PlugCommand" :depends-on ("_package_PlugCommand"))
    (:file "_package_PlugCommand" :depends-on ("_package"))
    (:file "ModelJointsState" :depends-on ("_package_ModelJointsState"))
    (:file "_package_ModelJointsState" :depends-on ("_package"))
  ))