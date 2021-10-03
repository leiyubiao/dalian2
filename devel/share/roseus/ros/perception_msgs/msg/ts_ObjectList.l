;; Auto-generated. Do not edit!


(when (boundp 'perception_msgs::ts_ObjectList)
  (if (not (find-package "PERCEPTION_MSGS"))
    (make-package "PERCEPTION_MSGS"))
  (shadow 'ts_ObjectList (find-package "PERCEPTION_MSGS")))
(unless (find-package "PERCEPTION_MSGS::TS_OBJECTLIST")
  (make-package "PERCEPTION_MSGS::TS_OBJECTLIST"))

(in-package "ROS")
;;//! \htmlinclude ts_ObjectList.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass perception_msgs::ts_ObjectList
  :super ros::object
  :slots (_header _sensor _objects ))

(defmethod perception_msgs::ts_ObjectList
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:sensor __sensor) "")
    ((:objects __objects) (let (r) (dotimes (i 0) (push (instance perception_msgs::ts_Object :init) r)) r))
    )
   (send-super :init)
   (setq _header __header)
   (setq _sensor (string __sensor))
   (setq _objects __objects)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:sensor
   (&optional __sensor)
   (if __sensor (setq _sensor __sensor)) _sensor)
  (:objects
   (&rest __objects)
   (if (keywordp (car __objects))
       (send* _objects __objects)
     (progn
       (if __objects (setq _objects (car __objects)))
       _objects)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; string _sensor
    4 (length _sensor)
    ;; perception_msgs/ts_Object[] _objects
    (apply #'+ (send-all _objects :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; string _sensor
       (write-long (length _sensor) s) (princ _sensor s)
     ;; perception_msgs/ts_Object[] _objects
     (write-long (length _objects) s)
     (dolist (elem _objects)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; string _sensor
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _sensor (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; perception_msgs/ts_Object[] _objects
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _objects (let (r) (dotimes (i n) (push (instance perception_msgs::ts_Object :init) r)) r))
     (dolist (elem- _objects)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get perception_msgs::ts_ObjectList :md5sum-) "ada8e9075049a493d6740fe5140a812a")
(setf (get perception_msgs::ts_ObjectList :datatype-) "perception_msgs/ts_ObjectList")
(setf (get perception_msgs::ts_ObjectList :definition-)
      "Header header
string sensor
ts_Object[] objects
================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id

================================================================================
MSG: perception_msgs/ts_Object

int32 object_id

ts_3DPose rel_pose

bool geometry_state
ts_Geometry geometry

================================================================================
MSG: perception_msgs/ts_3DPose
float64 x
float64 y
float64 z
float64 phi
float64 theta
float64 psi

================================================================================
MSG: perception_msgs/ts_Geometry
float64 length
float64 width
float64 height
")



(provide :perception_msgs/ts_ObjectList "ada8e9075049a493d6740fe5140a812a")


