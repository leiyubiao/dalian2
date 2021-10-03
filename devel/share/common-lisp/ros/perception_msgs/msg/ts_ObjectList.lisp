; Auto-generated. Do not edit!


(cl:in-package perception_msgs-msg)


;//! \htmlinclude ts_ObjectList.msg.html

(cl:defclass <ts_ObjectList> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (sensor
    :reader sensor
    :initarg :sensor
    :type cl:string
    :initform "")
   (objects
    :reader objects
    :initarg :objects
    :type (cl:vector perception_msgs-msg:ts_Object)
   :initform (cl:make-array 0 :element-type 'perception_msgs-msg:ts_Object :initial-element (cl:make-instance 'perception_msgs-msg:ts_Object))))
)

(cl:defclass ts_ObjectList (<ts_ObjectList>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ts_ObjectList>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ts_ObjectList)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name perception_msgs-msg:<ts_ObjectList> is deprecated: use perception_msgs-msg:ts_ObjectList instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <ts_ObjectList>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader perception_msgs-msg:header-val is deprecated.  Use perception_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'sensor-val :lambda-list '(m))
(cl:defmethod sensor-val ((m <ts_ObjectList>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader perception_msgs-msg:sensor-val is deprecated.  Use perception_msgs-msg:sensor instead.")
  (sensor m))

(cl:ensure-generic-function 'objects-val :lambda-list '(m))
(cl:defmethod objects-val ((m <ts_ObjectList>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader perception_msgs-msg:objects-val is deprecated.  Use perception_msgs-msg:objects instead.")
  (objects m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ts_ObjectList>) ostream)
  "Serializes a message object of type '<ts_ObjectList>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'sensor))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'sensor))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'objects))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'objects))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ts_ObjectList>) istream)
  "Deserializes a message object of type '<ts_ObjectList>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'sensor) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'sensor) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'objects) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'objects)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'perception_msgs-msg:ts_Object))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ts_ObjectList>)))
  "Returns string type for a message object of type '<ts_ObjectList>"
  "perception_msgs/ts_ObjectList")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ts_ObjectList)))
  "Returns string type for a message object of type 'ts_ObjectList"
  "perception_msgs/ts_ObjectList")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ts_ObjectList>)))
  "Returns md5sum for a message object of type '<ts_ObjectList>"
  "ada8e9075049a493d6740fe5140a812a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ts_ObjectList)))
  "Returns md5sum for a message object of type 'ts_ObjectList"
  "ada8e9075049a493d6740fe5140a812a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ts_ObjectList>)))
  "Returns full string definition for message of type '<ts_ObjectList>"
  (cl:format cl:nil "Header header~%string sensor~%ts_Object[] objects~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: perception_msgs/ts_Object~%~%int32 object_id~%~%ts_3DPose rel_pose~%~%bool geometry_state~%ts_Geometry geometry~%~%================================================================================~%MSG: perception_msgs/ts_3DPose~%float64 x~%float64 y~%float64 z~%float64 phi~%float64 theta~%float64 psi~%~%================================================================================~%MSG: perception_msgs/ts_Geometry~%float64 length~%float64 width~%float64 height~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ts_ObjectList)))
  "Returns full string definition for message of type 'ts_ObjectList"
  (cl:format cl:nil "Header header~%string sensor~%ts_Object[] objects~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: perception_msgs/ts_Object~%~%int32 object_id~%~%ts_3DPose rel_pose~%~%bool geometry_state~%ts_Geometry geometry~%~%================================================================================~%MSG: perception_msgs/ts_3DPose~%float64 x~%float64 y~%float64 z~%float64 phi~%float64 theta~%float64 psi~%~%================================================================================~%MSG: perception_msgs/ts_Geometry~%float64 length~%float64 width~%float64 height~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ts_ObjectList>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4 (cl:length (cl:slot-value msg 'sensor))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'objects) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ts_ObjectList>))
  "Converts a ROS message object to a list"
  (cl:list 'ts_ObjectList
    (cl:cons ':header (header msg))
    (cl:cons ':sensor (sensor msg))
    (cl:cons ':objects (objects msg))
))
