
(cl:in-package :asdf)

(defsystem "pr2_gazebo_plugins-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :pr2_gazebo_plugins-msg
)
  :components ((:file "_package")
    (:file "SetModelsJointsStates" :depends-on ("_package_SetModelsJointsStates"))
    (:file "_package_SetModelsJointsStates" :depends-on ("_package"))
  ))