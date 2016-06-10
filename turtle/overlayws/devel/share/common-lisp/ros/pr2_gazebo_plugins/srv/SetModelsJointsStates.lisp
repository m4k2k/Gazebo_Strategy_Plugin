; Auto-generated. Do not edit!


(cl:in-package pr2_gazebo_plugins-srv)


;//! \htmlinclude SetModelsJointsStates-request.msg.html

(cl:defclass <SetModelsJointsStates-request> (roslisp-msg-protocol:ros-message)
  ((model_names
    :reader model_names
    :initarg :model_names
    :type (cl:vector cl:string)
   :initform (cl:make-array 0 :element-type 'cl:string :initial-element ""))
   (model_joints_states
    :reader model_joints_states
    :initarg :model_joints_states
    :type (cl:vector pr2_gazebo_plugins-msg:ModelJointsState)
   :initform (cl:make-array 0 :element-type 'pr2_gazebo_plugins-msg:ModelJointsState :initial-element (cl:make-instance 'pr2_gazebo_plugins-msg:ModelJointsState))))
)

(cl:defclass SetModelsJointsStates-request (<SetModelsJointsStates-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SetModelsJointsStates-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SetModelsJointsStates-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name pr2_gazebo_plugins-srv:<SetModelsJointsStates-request> is deprecated: use pr2_gazebo_plugins-srv:SetModelsJointsStates-request instead.")))

(cl:ensure-generic-function 'model_names-val :lambda-list '(m))
(cl:defmethod model_names-val ((m <SetModelsJointsStates-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pr2_gazebo_plugins-srv:model_names-val is deprecated.  Use pr2_gazebo_plugins-srv:model_names instead.")
  (model_names m))

(cl:ensure-generic-function 'model_joints_states-val :lambda-list '(m))
(cl:defmethod model_joints_states-val ((m <SetModelsJointsStates-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pr2_gazebo_plugins-srv:model_joints_states-val is deprecated.  Use pr2_gazebo_plugins-srv:model_joints_states instead.")
  (model_joints_states m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SetModelsJointsStates-request>) ostream)
  "Serializes a message object of type '<SetModelsJointsStates-request>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'model_names))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((__ros_str_len (cl:length ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) ele))
   (cl:slot-value msg 'model_names))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'model_joints_states))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'model_joints_states))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SetModelsJointsStates-request>) istream)
  "Deserializes a message object of type '<SetModelsJointsStates-request>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'model_names) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'model_names)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:aref vals i) __ros_str_idx) (cl:code-char (cl:read-byte istream))))))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'model_joints_states) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'model_joints_states)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'pr2_gazebo_plugins-msg:ModelJointsState))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SetModelsJointsStates-request>)))
  "Returns string type for a service object of type '<SetModelsJointsStates-request>"
  "pr2_gazebo_plugins/SetModelsJointsStatesRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetModelsJointsStates-request)))
  "Returns string type for a service object of type 'SetModelsJointsStates-request"
  "pr2_gazebo_plugins/SetModelsJointsStatesRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SetModelsJointsStates-request>)))
  "Returns md5sum for a message object of type '<SetModelsJointsStates-request>"
  "b3f4760ee77e28f605915bcee447b72d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SetModelsJointsStates-request)))
  "Returns md5sum for a message object of type 'SetModelsJointsStates-request"
  "b3f4760ee77e28f605915bcee447b72d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SetModelsJointsStates-request>)))
  "Returns full string definition for message of type '<SetModelsJointsStates-request>"
  (cl:format cl:nil "string[] model_names~%pr2_gazebo_plugins/ModelJointsState[] model_joints_states~%~%================================================================================~%MSG: pr2_gazebo_plugins/ModelJointsState~%geometry_msgs/Pose[] model_pose                          # set as single element array if user wishes to specify model pose, otherwise, leave empty~%string[] joint_names                                     # list of joint names~%float64[] joint_positions                                 # list of desired joint positions, should match joint_names~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of postion and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SetModelsJointsStates-request)))
  "Returns full string definition for message of type 'SetModelsJointsStates-request"
  (cl:format cl:nil "string[] model_names~%pr2_gazebo_plugins/ModelJointsState[] model_joints_states~%~%================================================================================~%MSG: pr2_gazebo_plugins/ModelJointsState~%geometry_msgs/Pose[] model_pose                          # set as single element array if user wishes to specify model pose, otherwise, leave empty~%string[] joint_names                                     # list of joint names~%float64[] joint_positions                                 # list of desired joint positions, should match joint_names~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of postion and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SetModelsJointsStates-request>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'model_names) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4 (cl:length ele))))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'model_joints_states) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SetModelsJointsStates-request>))
  "Converts a ROS message object to a list"
  (cl:list 'SetModelsJointsStates-request
    (cl:cons ':model_names (model_names msg))
    (cl:cons ':model_joints_states (model_joints_states msg))
))
;//! \htmlinclude SetModelsJointsStates-response.msg.html

(cl:defclass <SetModelsJointsStates-response> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil)
   (status_message
    :reader status_message
    :initarg :status_message
    :type cl:string
    :initform ""))
)

(cl:defclass SetModelsJointsStates-response (<SetModelsJointsStates-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SetModelsJointsStates-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SetModelsJointsStates-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name pr2_gazebo_plugins-srv:<SetModelsJointsStates-response> is deprecated: use pr2_gazebo_plugins-srv:SetModelsJointsStates-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <SetModelsJointsStates-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pr2_gazebo_plugins-srv:success-val is deprecated.  Use pr2_gazebo_plugins-srv:success instead.")
  (success m))

(cl:ensure-generic-function 'status_message-val :lambda-list '(m))
(cl:defmethod status_message-val ((m <SetModelsJointsStates-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pr2_gazebo_plugins-srv:status_message-val is deprecated.  Use pr2_gazebo_plugins-srv:status_message instead.")
  (status_message m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SetModelsJointsStates-response>) ostream)
  "Serializes a message object of type '<SetModelsJointsStates-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'status_message))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'status_message))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SetModelsJointsStates-response>) istream)
  "Deserializes a message object of type '<SetModelsJointsStates-response>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'status_message) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'status_message) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SetModelsJointsStates-response>)))
  "Returns string type for a service object of type '<SetModelsJointsStates-response>"
  "pr2_gazebo_plugins/SetModelsJointsStatesResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetModelsJointsStates-response)))
  "Returns string type for a service object of type 'SetModelsJointsStates-response"
  "pr2_gazebo_plugins/SetModelsJointsStatesResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SetModelsJointsStates-response>)))
  "Returns md5sum for a message object of type '<SetModelsJointsStates-response>"
  "b3f4760ee77e28f605915bcee447b72d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SetModelsJointsStates-response)))
  "Returns md5sum for a message object of type 'SetModelsJointsStates-response"
  "b3f4760ee77e28f605915bcee447b72d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SetModelsJointsStates-response>)))
  "Returns full string definition for message of type '<SetModelsJointsStates-response>"
  (cl:format cl:nil "bool success~%string status_message~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SetModelsJointsStates-response)))
  "Returns full string definition for message of type 'SetModelsJointsStates-response"
  (cl:format cl:nil "bool success~%string status_message~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SetModelsJointsStates-response>))
  (cl:+ 0
     1
     4 (cl:length (cl:slot-value msg 'status_message))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SetModelsJointsStates-response>))
  "Converts a ROS message object to a list"
  (cl:list 'SetModelsJointsStates-response
    (cl:cons ':success (success msg))
    (cl:cons ':status_message (status_message msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'SetModelsJointsStates)))
  'SetModelsJointsStates-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'SetModelsJointsStates)))
  'SetModelsJointsStates-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetModelsJointsStates)))
  "Returns string type for a service object of type '<SetModelsJointsStates>"
  "pr2_gazebo_plugins/SetModelsJointsStates")