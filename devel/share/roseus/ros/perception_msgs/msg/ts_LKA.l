;; Auto-generated. Do not edit!


(when (boundp 'perception_msgs::ts_LKA)
  (if (not (find-package "PERCEPTION_MSGS"))
    (make-package "PERCEPTION_MSGS"))
  (shadow 'ts_LKA (find-package "PERCEPTION_MSGS")))
(unless (find-package "PERCEPTION_MSGS::TS_LKA")
  (make-package "PERCEPTION_MSGS::TS_LKA"))

(in-package "ROS")
;;//! \htmlinclude ts_LKA.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass perception_msgs::ts_LKA
  :super ros::object
  :slots (_header _lanetype _quality _model _View_range _Position_C0 _Headingangle_C1 _Curvature_C2 _dCurvature_C3 _Lane_width ))

(defmethod perception_msgs::ts_LKA
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:lanetype __lanetype) 0)
    ((:quality __quality) 0)
    ((:model __model) 0)
    ((:View_range __View_range) 0.0)
    ((:Position_C0 __Position_C0) 0.0)
    ((:Headingangle_C1 __Headingangle_C1) 0.0)
    ((:Curvature_C2 __Curvature_C2) 0.0)
    ((:dCurvature_C3 __dCurvature_C3) 0.0)
    ((:Lane_width __Lane_width) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _lanetype (round __lanetype))
   (setq _quality (round __quality))
   (setq _model (round __model))
   (setq _View_range (float __View_range))
   (setq _Position_C0 (float __Position_C0))
   (setq _Headingangle_C1 (float __Headingangle_C1))
   (setq _Curvature_C2 (float __Curvature_C2))
   (setq _dCurvature_C3 (float __dCurvature_C3))
   (setq _Lane_width (float __Lane_width))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:lanetype
   (&optional __lanetype)
   (if __lanetype (setq _lanetype __lanetype)) _lanetype)
  (:quality
   (&optional __quality)
   (if __quality (setq _quality __quality)) _quality)
  (:model
   (&optional __model)
   (if __model (setq _model __model)) _model)
  (:View_range
   (&optional __View_range)
   (if __View_range (setq _View_range __View_range)) _View_range)
  (:Position_C0
   (&optional __Position_C0)
   (if __Position_C0 (setq _Position_C0 __Position_C0)) _Position_C0)
  (:Headingangle_C1
   (&optional __Headingangle_C1)
   (if __Headingangle_C1 (setq _Headingangle_C1 __Headingangle_C1)) _Headingangle_C1)
  (:Curvature_C2
   (&optional __Curvature_C2)
   (if __Curvature_C2 (setq _Curvature_C2 __Curvature_C2)) _Curvature_C2)
  (:dCurvature_C3
   (&optional __dCurvature_C3)
   (if __dCurvature_C3 (setq _dCurvature_C3 __dCurvature_C3)) _dCurvature_C3)
  (:Lane_width
   (&optional __Lane_width)
   (if __Lane_width (setq _Lane_width __Lane_width)) _Lane_width)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; int64 _lanetype
    8
    ;; int64 _quality
    8
    ;; int64 _model
    8
    ;; float64 _View_range
    8
    ;; float64 _Position_C0
    8
    ;; float64 _Headingangle_C1
    8
    ;; float64 _Curvature_C2
    8
    ;; float64 _dCurvature_C3
    8
    ;; float64 _Lane_width
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; int64 _lanetype
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _lanetype (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _lanetype) (= (length (_lanetype . bv)) 2)) ;; bignum
              (write-long (ash (elt (_lanetype . bv) 0) 0) s)
              (write-long (ash (elt (_lanetype . bv) 1) -1) s))
             ((and (class _lanetype) (= (length (_lanetype . bv)) 1)) ;; big1
              (write-long (elt (_lanetype . bv) 0) s)
              (write-long (if (>= _lanetype 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _lanetype s)(write-long (if (>= _lanetype 0) 0 #xffffffff) s)))
     ;; int64 _quality
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _quality (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _quality) (= (length (_quality . bv)) 2)) ;; bignum
              (write-long (ash (elt (_quality . bv) 0) 0) s)
              (write-long (ash (elt (_quality . bv) 1) -1) s))
             ((and (class _quality) (= (length (_quality . bv)) 1)) ;; big1
              (write-long (elt (_quality . bv) 0) s)
              (write-long (if (>= _quality 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _quality s)(write-long (if (>= _quality 0) 0 #xffffffff) s)))
     ;; int64 _model
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _model (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _model) (= (length (_model . bv)) 2)) ;; bignum
              (write-long (ash (elt (_model . bv) 0) 0) s)
              (write-long (ash (elt (_model . bv) 1) -1) s))
             ((and (class _model) (= (length (_model . bv)) 1)) ;; big1
              (write-long (elt (_model . bv) 0) s)
              (write-long (if (>= _model 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _model s)(write-long (if (>= _model 0) 0 #xffffffff) s)))
     ;; float64 _View_range
       (sys::poke _View_range (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Position_C0
       (sys::poke _Position_C0 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Headingangle_C1
       (sys::poke _Headingangle_C1 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Curvature_C2
       (sys::poke _Curvature_C2 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _dCurvature_C3
       (sys::poke _dCurvature_C3 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Lane_width
       (sys::poke _Lane_width (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; int64 _lanetype
#+(or :alpha :irix6 :x86_64)
      (setf _lanetype (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _lanetype (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _quality
#+(or :alpha :irix6 :x86_64)
      (setf _quality (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _quality (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _model
#+(or :alpha :irix6 :x86_64)
      (setf _model (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _model (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; float64 _View_range
     (setq _View_range (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Position_C0
     (setq _Position_C0 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Headingangle_C1
     (setq _Headingangle_C1 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Curvature_C2
     (setq _Curvature_C2 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _dCurvature_C3
     (setq _dCurvature_C3 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Lane_width
     (setq _Lane_width (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get perception_msgs::ts_LKA :md5sum-) "735c1f26da9c3fb23d10971553941226")
(setf (get perception_msgs::ts_LKA :datatype-) "perception_msgs/ts_LKA")
(setf (get perception_msgs::ts_LKA :definition-)
      "Header header
int64 lanetype  #0-dashed 1-solid 2-undecided 3-road edge 4-double lane mark 5-Botts' dots 6-invalid
int64 quality   #0,1-low quality 2,3-high quality
int64 model     # 1-linear, 2-parabolic, 3-3rd degree model
float64 View_range
float64 Position_C0
float64 Headingangle_C1
float64 Curvature_C2
float64 dCurvature_C3
float64 Lane_width
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

")



(provide :perception_msgs/ts_LKA "735c1f26da9c3fb23d10971553941226")


