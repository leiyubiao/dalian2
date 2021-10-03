; Auto-generated. Do not edit!


(cl:in-package perception_msgs-msg)


;//! \htmlinclude ts_Object.msg.html

(cl:defclass <ts_Object> (roslisp-msg-protocol:ros-message)
  ((object_id
    :reader object_id
    :initarg :object_id
    :type cl:integer
    :initform 0)
   (rel_pose
    :reader rel_pose
    :initarg :rel_pose
    :type perception_msgs-msg:ts_3DPose
    :initform (cl:make-instance 'perception_msgs-msg:ts_3DPose))
   (geometry_state
    :reader geometry_state
    :initarg :geometry_state
    :type cl:boolean
    :initform cl:nil)
   (geometry
    :reader geometry
    :initarg :geometry
    :type perception_msgs-msg:ts_Geometry
    :initform (cl:make-instance 'perception_msgs-msg:ts_Geometry)))
)

(cl:defclass ts_Object (<ts_Object>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ts_Object>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ts_Object)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name perception_msgs-msg:<ts_Object> is deprecated: use perception_msgs-msg:ts_Object instead.")))

(cl:ensure-generic-function 'object_id-val :lambda-list '(m))
(cl:defmethod object_id-val ((m <ts_Object>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader perception_msgs-msg:object_id-val is deprecated.  Use perception_msgs-msg:object_id instead.")
  (object_id m))

(cl:ensure-generic-function 'rel_pose-val :lambda-list '(m))
(cl:defmethod rel_pose-val ((m <ts_Object>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader perception_msgs-msg:rel_pose-val is deprecated.  Use perception_msgs-msg:rel_pose instead.")
  (rel_pose m))

(cl:ensure-generic-function 'geometry_state-val :lambda-list '(m))
(cl:defmethod geometry_state-val ((m <ts_Object>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader perception_msgs-msg:geometry_state-val is deprecated.  Use perception_msgs-msg:geometry_state instead.")
  (geometry_state m))

(cl:ensure-generic-function 'geometry-val :lambda-list '(m))
(cl:defmethod geometry-val ((m <ts_Object>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader perception_msgs-msg:geometry-val is deprecated.  Use perception_msgs-msg:geometry instead.")
  (geometry m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ts_Object>) ostream)
  "Serializes a message object of type '<ts_Object>"
  (cl:let* ((signed (cl:slot-value msg 'object_id)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'rel_pose) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'geometry_state) 1 0)) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'geometry) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ts_Object>) istream)
  "Deserializes a message object of type '<ts_Object>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'object_id) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'rel_pose) istream)
    (cl:setf (cl:slot-value msg 'geometry_state) (cl:not (cl:zerop (cl:read-byte istream))))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'geometry) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ts_Object>)))
  "Returns string type for a message object of type '<ts_Object>"
  "perception_msgs/ts_Object")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ts_Object)))
  "Returns string type for a message object of type 'ts_Object"
  "perception_msgs/ts_Object")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ts_Object>)))
  "Returns md5sum for a message object of type '<ts_Object>"
  "2fab78d59d066c44e1549d3ee0b45ece")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ts_Object)))
  "Returns md5sum for a message object of type 'ts_Object"
  "2fab78d59d066c44e1549d3ee0b45ece")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ts_Object>)))
  "Returns full string definition for message of type '<ts_Object>"
  (cl:format cl:nil "~%int32 object_id~%~%ts_3DPose rel_pose~%~%bool geometry_state~%ts_Geometry geometry~%~%================================================================================~%MSG: perception_msgs/ts_3DPose~%float64 x~%float64 y~%float64 z~%float64 phi~%float64 theta~%float64 psi~%~%================================================================================~%MSG: perception_msgs/ts_Geometry~%float64 length~%float64 width~%float64 height~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ts_Object)))
  "Returns full string definition for message of type 'ts_Object"
  (cl:format cl:nil "~%int32 object_id~%~%ts_3DPose rel_pose~%~%bool geometry_state~%ts_Geometry geometry~%~%================================================================================~%MSG: perception_msgs/ts_3DPose~%float64 x~%float64 y~%float64 z~%float64 phi~%float64 theta~%float64 psi~%~%================================================================================~%MSG: perception_msgs/ts_Geometry~%float64 length~%float64 width~%float64 height~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ts_Object>))
  (cl:+ 0
     4
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'rel_pose))
     1
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'geometry))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ts_Object>))
  "Converts a ROS message object to a list"
  (cl:list 'ts_Object
    (cl:cons ':object_id (object_id msg))
    (cl:cons ':rel_pose (rel_pose msg))
    (cl:cons ':geometry_state (geometry_state msg))
    (cl:cons ':geometry (geometry msg))
))
