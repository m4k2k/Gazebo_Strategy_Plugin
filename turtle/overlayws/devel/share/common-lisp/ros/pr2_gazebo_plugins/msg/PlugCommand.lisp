; Auto-generated. Do not edit!


(cl:in-package pr2_gazebo_plugins-msg)


;//! \htmlinclude PlugCommand.msg.html

(cl:defclass <PlugCommand> (roslisp-msg-protocol:ros-message)
  ((ac_present
    :reader ac_present
    :initarg :ac_present
    :type cl:boolean
    :initform cl:nil)
   (charge_rate
    :reader charge_rate
    :initarg :charge_rate
    :type cl:float
    :initform 0.0)
   (discharge_rate
    :reader discharge_rate
    :initarg :discharge_rate
    :type cl:float
    :initform 0.0)
   (charge
    :reader charge
    :initarg :charge
    :type cl:float
    :initform 0.0))
)

(cl:defclass PlugCommand (<PlugCommand>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <PlugCommand>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'PlugCommand)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name pr2_gazebo_plugins-msg:<PlugCommand> is deprecated: use pr2_gazebo_plugins-msg:PlugCommand instead.")))

(cl:ensure-generic-function 'ac_present-val :lambda-list '(m))
(cl:defmethod ac_present-val ((m <PlugCommand>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pr2_gazebo_plugins-msg:ac_present-val is deprecated.  Use pr2_gazebo_plugins-msg:ac_present instead.")
  (ac_present m))

(cl:ensure-generic-function 'charge_rate-val :lambda-list '(m))
(cl:defmethod charge_rate-val ((m <PlugCommand>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pr2_gazebo_plugins-msg:charge_rate-val is deprecated.  Use pr2_gazebo_plugins-msg:charge_rate instead.")
  (charge_rate m))

(cl:ensure-generic-function 'discharge_rate-val :lambda-list '(m))
(cl:defmethod discharge_rate-val ((m <PlugCommand>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pr2_gazebo_plugins-msg:discharge_rate-val is deprecated.  Use pr2_gazebo_plugins-msg:discharge_rate instead.")
  (discharge_rate m))

(cl:ensure-generic-function 'charge-val :lambda-list '(m))
(cl:defmethod charge-val ((m <PlugCommand>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pr2_gazebo_plugins-msg:charge-val is deprecated.  Use pr2_gazebo_plugins-msg:charge instead.")
  (charge m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <PlugCommand>) ostream)
  "Serializes a message object of type '<PlugCommand>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'ac_present) 1 0)) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'charge_rate))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'discharge_rate))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'charge))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <PlugCommand>) istream)
  "Deserializes a message object of type '<PlugCommand>"
    (cl:setf (cl:slot-value msg 'ac_present) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'charge_rate) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'discharge_rate) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'charge) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<PlugCommand>)))
  "Returns string type for a message object of type '<PlugCommand>"
  "pr2_gazebo_plugins/PlugCommand")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PlugCommand)))
  "Returns string type for a message object of type 'PlugCommand"
  "pr2_gazebo_plugins/PlugCommand")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<PlugCommand>)))
  "Returns md5sum for a message object of type '<PlugCommand>"
  "852b7035ee3e7fa6390824cf7b7e6dd1")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'PlugCommand)))
  "Returns md5sum for a message object of type 'PlugCommand"
  "852b7035ee3e7fa6390824cf7b7e6dd1")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<PlugCommand>)))
  "Returns full string definition for message of type '<PlugCommand>"
  (cl:format cl:nil "bool ac_present~%float64 charge_rate~%float64 discharge_rate~%float64 charge~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'PlugCommand)))
  "Returns full string definition for message of type 'PlugCommand"
  (cl:format cl:nil "bool ac_present~%float64 charge_rate~%float64 discharge_rate~%float64 charge~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <PlugCommand>))
  (cl:+ 0
     1
     8
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <PlugCommand>))
  "Converts a ROS message object to a list"
  (cl:list 'PlugCommand
    (cl:cons ':ac_present (ac_present msg))
    (cl:cons ':charge_rate (charge_rate msg))
    (cl:cons ':discharge_rate (discharge_rate msg))
    (cl:cons ':charge (charge msg))
))
