; Auto-generated. Do not edit!


(cl:in-package control_msgs-msg)


;//! \htmlinclude control_req.msg.html

(cl:defclass <control_req> (roslisp-msg-protocol:ros-message)
  ((Vel_req
    :reader Vel_req
    :initarg :Vel_req
    :type cl:float
    :initform 0.0)
   (Angle_req
    :reader Angle_req
    :initarg :Angle_req
    :type cl:float
    :initform 0.0)
   (Gear_req
    :reader Gear_req
    :initarg :Gear_req
    :type cl:integer
    :initform 0))
)

(cl:defclass control_req (<control_req>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <control_req>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'control_req)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name control_msgs-msg:<control_req> is deprecated: use control_msgs-msg:control_req instead.")))

(cl:ensure-generic-function 'Vel_req-val :lambda-list '(m))
(cl:defmethod Vel_req-val ((m <control_req>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader control_msgs-msg:Vel_req-val is deprecated.  Use control_msgs-msg:Vel_req instead.")
  (Vel_req m))

(cl:ensure-generic-function 'Angle_req-val :lambda-list '(m))
(cl:defmethod Angle_req-val ((m <control_req>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader control_msgs-msg:Angle_req-val is deprecated.  Use control_msgs-msg:Angle_req instead.")
  (Angle_req m))

(cl:ensure-generic-function 'Gear_req-val :lambda-list '(m))
(cl:defmethod Gear_req-val ((m <control_req>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader control_msgs-msg:Gear_req-val is deprecated.  Use control_msgs-msg:Gear_req instead.")
  (Gear_req m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <control_req>) ostream)
  "Serializes a message object of type '<control_req>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'Vel_req))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'Angle_req))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let* ((signed (cl:slot-value msg 'Gear_req)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <control_req>) istream)
  "Deserializes a message object of type '<control_req>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Vel_req) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Angle_req) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'Gear_req) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<control_req>)))
  "Returns string type for a message object of type '<control_req>"
  "control_msgs/control_req")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'control_req)))
  "Returns string type for a message object of type 'control_req"
  "control_msgs/control_req")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<control_req>)))
  "Returns md5sum for a message object of type '<control_req>"
  "f755ac002e0891a7af88d03d37522ace")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'control_req)))
  "Returns md5sum for a message object of type 'control_req"
  "f755ac002e0891a7af88d03d37522ace")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<control_req>)))
  "Returns full string definition for message of type '<control_req>"
  (cl:format cl:nil "float64 Vel_req~%float64 Angle_req~%int32 Gear_req~%# 0x0:P 0x1:R 0x2:N 0x3:D~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'control_req)))
  "Returns full string definition for message of type 'control_req"
  (cl:format cl:nil "float64 Vel_req~%float64 Angle_req~%int32 Gear_req~%# 0x0:P 0x1:R 0x2:N 0x3:D~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <control_req>))
  (cl:+ 0
     8
     8
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <control_req>))
  "Converts a ROS message object to a list"
  (cl:list 'control_req
    (cl:cons ':Vel_req (Vel_req msg))
    (cl:cons ':Angle_req (Angle_req msg))
    (cl:cons ':Gear_req (Gear_req msg))
))
