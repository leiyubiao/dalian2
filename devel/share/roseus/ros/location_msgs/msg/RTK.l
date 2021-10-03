;; Auto-generated. Do not edit!


(when (boundp 'location_msgs::RTK)
  (if (not (find-package "LOCATION_MSGS"))
    (make-package "LOCATION_MSGS"))
  (shadow 'RTK (find-package "LOCATION_MSGS")))
(unless (find-package "LOCATION_MSGS::RTK")
  (make-package "LOCATION_MSGS::RTK"))

(in-package "ROS")
;;//! \htmlinclude RTK.msg.html


(defclass location_msgs::RTK
  :super ros::object
  :slots (_gpstime _longitude _latitude _height _heading _pitch _roll _velocity _AccelX _AccelY _AccelZ _status ))

(defmethod location_msgs::RTK
  (:init
   (&key
    ((:gpstime __gpstime) 0.0)
    ((:longitude __longitude) 0.0)
    ((:latitude __latitude) 0.0)
    ((:height __height) 0.0)
    ((:heading __heading) 0.0)
    ((:pitch __pitch) 0.0)
    ((:roll __roll) 0.0)
    ((:velocity __velocity) 0.0)
    ((:AccelX __AccelX) 0.0)
    ((:AccelY __AccelY) 0.0)
    ((:AccelZ __AccelZ) 0.0)
    ((:status __status) 0)
    )
   (send-super :init)
   (setq _gpstime (float __gpstime))
   (setq _longitude (float __longitude))
   (setq _latitude (float __latitude))
   (setq _height (float __height))
   (setq _heading (float __heading))
   (setq _pitch (float __pitch))
   (setq _roll (float __roll))
   (setq _velocity (float __velocity))
   (setq _AccelX (float __AccelX))
   (setq _AccelY (float __AccelY))
   (setq _AccelZ (float __AccelZ))
   (setq _status (round __status))
   self)
  (:gpstime
   (&optional __gpstime)
   (if __gpstime (setq _gpstime __gpstime)) _gpstime)
  (:longitude
   (&optional __longitude)
   (if __longitude (setq _longitude __longitude)) _longitude)
  (:latitude
   (&optional __latitude)
   (if __latitude (setq _latitude __latitude)) _latitude)
  (:height
   (&optional __height)
   (if __height (setq _height __height)) _height)
  (:heading
   (&optional __heading)
   (if __heading (setq _heading __heading)) _heading)
  (:pitch
   (&optional __pitch)
   (if __pitch (setq _pitch __pitch)) _pitch)
  (:roll
   (&optional __roll)
   (if __roll (setq _roll __roll)) _roll)
  (:velocity
   (&optional __velocity)
   (if __velocity (setq _velocity __velocity)) _velocity)
  (:AccelX
   (&optional __AccelX)
   (if __AccelX (setq _AccelX __AccelX)) _AccelX)
  (:AccelY
   (&optional __AccelY)
   (if __AccelY (setq _AccelY __AccelY)) _AccelY)
  (:AccelZ
   (&optional __AccelZ)
   (if __AccelZ (setq _AccelZ __AccelZ)) _AccelZ)
  (:status
   (&optional __status)
   (if __status (setq _status __status)) _status)
  (:serialization-length
   ()
   (+
    ;; float64 _gpstime
    8
    ;; float64 _longitude
    8
    ;; float64 _latitude
    8
    ;; float64 _height
    8
    ;; float64 _heading
    8
    ;; float64 _pitch
    8
    ;; float64 _roll
    8
    ;; float64 _velocity
    8
    ;; float64 _AccelX
    8
    ;; float64 _AccelY
    8
    ;; float64 _AccelZ
    8
    ;; int32 _status
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _gpstime
       (sys::poke _gpstime (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _longitude
       (sys::poke _longitude (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _latitude
       (sys::poke _latitude (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _height
       (sys::poke _height (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _heading
       (sys::poke _heading (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _pitch
       (sys::poke _pitch (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _roll
       (sys::poke _roll (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _velocity
       (sys::poke _velocity (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _AccelX
       (sys::poke _AccelX (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _AccelY
       (sys::poke _AccelY (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _AccelZ
       (sys::poke _AccelZ (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; int32 _status
       (write-long _status s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _gpstime
     (setq _gpstime (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _longitude
     (setq _longitude (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _latitude
     (setq _latitude (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _height
     (setq _height (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _heading
     (setq _heading (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _pitch
     (setq _pitch (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _roll
     (setq _roll (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _velocity
     (setq _velocity (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _AccelX
     (setq _AccelX (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _AccelY
     (setq _AccelY (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _AccelZ
     (setq _AccelZ (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; int32 _status
     (setq _status (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get location_msgs::RTK :md5sum-) "6ebf4ab1d131fdca29632da4008b09ac")
(setf (get location_msgs::RTK :datatype-) "location_msgs/RTK")
(setf (get location_msgs::RTK :definition-)
      "float64 gpstime

float64 longitude
float64 latitude
float64 height

float64 heading
float64 pitch
float64 roll

float64 velocity

float64 AccelX
float64 AccelY
float64 AccelZ

int32 status
")



(provide :location_msgs/RTK "6ebf4ab1d131fdca29632da4008b09ac")


