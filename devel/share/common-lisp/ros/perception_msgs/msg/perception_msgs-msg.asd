
(cl:in-package :asdf)

(defsystem "perception_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "ts_3DPose" :depends-on ("_package_ts_3DPose"))
    (:file "_package_ts_3DPose" :depends-on ("_package"))
    (:file "ts_Geometry" :depends-on ("_package_ts_Geometry"))
    (:file "_package_ts_Geometry" :depends-on ("_package"))
    (:file "ts_LKA" :depends-on ("_package_ts_LKA"))
    (:file "_package_ts_LKA" :depends-on ("_package"))
    (:file "ts_Object" :depends-on ("_package_ts_Object"))
    (:file "_package_ts_Object" :depends-on ("_package"))
    (:file "ts_ObjectList" :depends-on ("_package_ts_ObjectList"))
    (:file "_package_ts_ObjectList" :depends-on ("_package"))
  ))