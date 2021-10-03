
(cl:in-package :asdf)

(defsystem "location_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "RTK" :depends-on ("_package_RTK"))
    (:file "_package_RTK" :depends-on ("_package"))
  ))