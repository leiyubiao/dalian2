; Auto-generated. Do not edit!


(cl:in-package control_msgs-msg)


;//! \htmlinclude remote_signal.msg.html

(cl:defclass <remote_signal> (roslisp-msg-protocol:ros-message)
  ((description
    :reader description
    :initarg :description
    :type cl:string
    :initform "")
   (remoteSig
    :reader remoteSig
    :initarg :remoteSig
    :type cl:integer
    :initform 0))
)

(cl:defclass remote_signal (<remote_signal>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <remote_signal>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'remote_signal)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name control_msgs-msg:<remote_signal> is deprecated: use control_msgs-msg:remote_signal instead.")))

(cl:ensure-generic-function 'description-val :lambda-list '(m))
(cl:defmethod description-val ((m <remote_signal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader control_msgs-msg:description-val is deprecated.  Use control_msgs-msg:description instead.")
  (description m))

(cl:ensure-generic-function 'remoteSig-val :lambda-list '(m))
(cl:defmethod remoteSig-val ((m <remote_signal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader control_msgs-msg:remoteSig-val is deprecated.  Use control_msgs-msg:remoteSig instead.")
  (remoteSig m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <remote_signal>) ostream)
  "Serializes a message object of type '<remote_signal>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'description))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'description))
  (cl:let* ((signed (cl:slot-value msg 'remoteSig)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <remote_signal>) istream)
  "Deserializes a message object of type '<remote_signal>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'description) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'description) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'remoteSig) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<remote_signal>)))
  "Returns string type for a message object of type '<remote_signal>"
  "control_msgs/remote_signal")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'remote_signal)))
  "Returns string type for a message object of type 'remote_signal"
  "control_msgs/remote_signal")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<remote_signal>)))
  "Returns md5sum for a message object of type '<remote_signal>"
  "ef064086b30dd0b129639e1bf28f6fd1")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'remote_signal)))
  "Returns md5sum for a message object of type 'remote_signal"
  "ef064086b30dd0b129639e1bf28f6fd1")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<remote_signal>)))
  "Returns full string definition for message of type '<remote_signal>"
  (cl:format cl:nil "string description~%int64 remoteSig~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'remote_signal)))
  "Returns full string definition for message of type 'remote_signal"
  (cl:format cl:nil "string description~%int64 remoteSig~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <remote_signal>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'description))
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <remote_signal>))
  "Converts a ROS message object to a list"
  (cl:list 'remote_signal
    (cl:cons ':description (description msg))
    (cl:cons ':remoteSig (remoteSig msg))
))
