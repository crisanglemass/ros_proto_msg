
(cl:in-package :asdf)

(defsystem "sensor_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "LaserScan" :depends-on ("_package_LaserScan"))
    (:file "_package_LaserScan" :depends-on ("_package"))
  ))