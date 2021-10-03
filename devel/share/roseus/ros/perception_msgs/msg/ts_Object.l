;; Auto-generated. Do not edit!


(when (boundp 'perception_msgs::ts_Object)
  (if (not (find-package "PERCEPTION_MSGS"))
    (make-package "PERCEPTION_MSGS"))
  (shadow 'ts_Object (find-package "PERCEPTION_MSGS")))
(unless (find-package "PERCEPTION_MSGS::TS_OBJECT")
  (make-package "PERCEPTION_MSGS::TS_OBJECT"))

(in-package "ROS")
;;//! \htmlinclude ts_Object.msg.html


(defclass perception_msgs::ts_Object
  :super ros::object
  :slots (_object_id _rel_pose _geometry_state _geometry ))

(defmethod perception_msgs::ts_Object
  (:init
   (&key
    ((:object_id __object_id) 0)
    ((:rel_pose __rel_pose) (instance perception_msgs::ts_3DPose :init))
    ((:geometry_state __geometry_state) nil)
    ((:geometry __geometry) (instance perception_msgs::ts_Geometry :init))
    )
   (send-super :init)
   (setq _object_id (round __object_id))
   (setq _rel_pose __rel_pose)
   (setq _geometry_state __geometry_state)
   (setq _geometry __geometry)
   self)
  (:object_id
   (&optional __object_id)
   (if __object_id (setq _object_id __object_id)) _object_id)
  (:rel_pose
   (&rest __rel_pose)
   (if (keywordp (car __rel_pose))
       (send* _rel_pose __rel_pose)
     (progn
       (if __rel_pose (setq _rel_pose (car __rel_pose)))
       _rel_pose)))
  (:geometry_state
   (&optional __geometry_state)
   (if __geometry_state (setq _geometry_state __geometry_state)) _geometry_state)
  (:geometry
   (&rest __geometry)
   (if (keywordp (car __geometry))
       (send* _geometry __geometry)
     (progn
       (if __geometry (setq _geometry (car __geometry)))
       _geometry)))
  (:serialization-length
   ()
   (+
    ;; int32 _object_id
    4
    ;; perception_msgs/ts_3DPose _rel_pose
    (send _rel_pose :serialization-length)
    ;; bool _geometry_state
    1
    ;; perception_msgs/ts_Geometry _geometry
    (send _geometry :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _object_id
       (write-long _object_id s)
     ;; perception_msgs/ts_3DPose _rel_pose
       (send _rel_pose :serialize s)
     ;; bool _geometry_state
       (if _geometry_state (write-byte -1 s) (write-byte 0 s))
     ;; perception_msgs/ts_Geometry _geometry
       (send _geometry :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _object_id
     (setq _object_id (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; perception_msgs/ts_3DPose _rel_pose
     (send _rel_pose :deserialize buf ptr-) (incf ptr- (send _rel_pose :serialization-length))
   ;; bool _geometry_state
     (setq _geometry_state (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; perception_msgs/ts_Geometry _geometry
     (send _geometry :deserialize buf ptr-) (incf ptr- (send _geometry :serialization-length))
   ;;
   self)
  )

(setf (get perception_msgs::ts_Object :md5sum-) "2fab78d59d066c44e1549d3ee0b45ece")
(setf (get perception_msgs::ts_Object :datatype-) "perception_msgs/ts_Object")
(setf (get perception_msgs::ts_Object :definition-)
      "
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



(provide :perception_msgs/ts_Object "2fab78d59d066c44e1549d3ee0b45ece")


