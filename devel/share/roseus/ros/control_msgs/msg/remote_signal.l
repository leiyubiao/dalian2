;; Auto-generated. Do not edit!


(when (boundp 'control_msgs::remote_signal)
  (if (not (find-package "CONTROL_MSGS"))
    (make-package "CONTROL_MSGS"))
  (shadow 'remote_signal (find-package "CONTROL_MSGS")))
(unless (find-package "CONTROL_MSGS::REMOTE_SIGNAL")
  (make-package "CONTROL_MSGS::REMOTE_SIGNAL"))

(in-package "ROS")
;;//! \htmlinclude remote_signal.msg.html


(defclass control_msgs::remote_signal
  :super ros::object
  :slots (_description _remoteSig ))

(defmethod control_msgs::remote_signal
  (:init
   (&key
    ((:description __description) "")
    ((:remoteSig __remoteSig) 0)
    )
   (send-super :init)
   (setq _description (string __description))
   (setq _remoteSig (round __remoteSig))
   self)
  (:description
   (&optional __description)
   (if __description (setq _description __description)) _description)
  (:remoteSig
   (&optional __remoteSig)
   (if __remoteSig (setq _remoteSig __remoteSig)) _remoteSig)
  (:serialization-length
   ()
   (+
    ;; string _description
    4 (length _description)
    ;; int64 _remoteSig
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _description
       (write-long (length _description) s) (princ _description s)
     ;; int64 _remoteSig
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _remoteSig (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _remoteSig) (= (length (_remoteSig . bv)) 2)) ;; bignum
              (write-long (ash (elt (_remoteSig . bv) 0) 0) s)
              (write-long (ash (elt (_remoteSig . bv) 1) -1) s))
             ((and (class _remoteSig) (= (length (_remoteSig . bv)) 1)) ;; big1
              (write-long (elt (_remoteSig . bv) 0) s)
              (write-long (if (>= _remoteSig 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _remoteSig s)(write-long (if (>= _remoteSig 0) 0 #xffffffff) s)))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _description
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _description (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; int64 _remoteSig
#+(or :alpha :irix6 :x86_64)
      (setf _remoteSig (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _remoteSig (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;;
   self)
  )

(setf (get control_msgs::remote_signal :md5sum-) "ef064086b30dd0b129639e1bf28f6fd1")
(setf (get control_msgs::remote_signal :datatype-) "control_msgs/remote_signal")
(setf (get control_msgs::remote_signal :definition-)
      "string description
int64 remoteSig

")



(provide :control_msgs/remote_signal "ef064086b30dd0b129639e1bf28f6fd1")


