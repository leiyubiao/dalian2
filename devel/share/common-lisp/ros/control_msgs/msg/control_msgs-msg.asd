
(cl:in-package :asdf)

(defsystem "control_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "control_req" :depends-on ("_package_control_req"))
    (:file "_package_control_req" :depends-on ("_package"))
    (:file "remote_signal" :depends-on ("_package_remote_signal"))
    (:file "_package_remote_signal" :depends-on ("_package"))
  ))