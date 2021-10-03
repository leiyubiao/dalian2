;; Auto-generated. Do not edit!


(when (boundp 'control_msgs::control_req)
  (if (not (find-package "CONTROL_MSGS"))
    (make-package "CONTROL_MSGS"))
  (shadow 'control_req (find-package "CONTROL_MSGS")))
(unless (find-package "CONTROL_MSGS::CONTROL_REQ")
  (make-package "CONTROL_MSGS::CONTROL_REQ"))

(in-package "ROS")
;;//! \htmlinclude control_req.msg.html


(defclass control_msgs::control_req
  :super ros::object
  :slots (_Vel_req _Angle_req _Gear_req ))

(defmethod control_msgs::control_req
  (:init
   (&key
    ((:Vel_req __Vel_req) 0.0)
    ((:Angle_req __Angle_req) 0.0)
    ((:Gear_req __Gear_req) 0)
    )
   (send-super :init)
   (setq _Vel_req (float __Vel_req))
   (setq _Angle_req (float __Angle_req))
   (setq _Gear_req (round __Gear_req))
   self)
  (:Vel_req
   (&optional __Vel_req)
   (if __Vel_req (setq _Vel_req __Vel_req)) _Vel_req)
  (:Angle_req
   (&optional __Angle_req)
   (if __Angle_req (setq _Angle_req __Angle_req)) _Angle_req)
  (:Gear_req
   (&optional __Gear_req)
   (if __Gear_req (setq _Gear_req __Gear_req)) _Gear_req)
  (:serialization-length
   ()
   (+
    ;; float64 _Vel_req
    8
    ;; float64 _Angle_req
    8
    ;; int32 _Gear_req
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _Vel_req
       (sys::poke _Vel_req (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Angle_req
       (sys::poke _Angle_req (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; int32 _Gear_req
       (write-long _Gear_req s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _Vel_req
     (setq _Vel_req (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Angle_req
     (setq _Angle_req (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; int32 _Gear_req
     (setq _Gear_req (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get control_msgs::control_req :md5sum-) "f755ac002e0891a7af88d03d37522ace")
(setf (get control_msgs::control_req :datatype-) "control_msgs/control_req")
(setf (get control_msgs::control_req :definition-)
      "float64 Vel_req
float64 Angle_req
int32 Gear_req
# 0x0:P 0x1:R 0x2:N 0x3:D

")



(provide :control_msgs/control_req "f755ac002e0891a7af88d03d37522ace")


