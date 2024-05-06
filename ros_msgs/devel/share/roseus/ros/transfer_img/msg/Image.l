;; Auto-generated. Do not edit!


(when (boundp 'transfer_img::Image)
  (if (not (find-package "TRANSFER_IMG"))
    (make-package "TRANSFER_IMG"))
  (shadow 'Image (find-package "TRANSFER_IMG")))
(unless (find-package "TRANSFER_IMG::IMAGE")
  (make-package "TRANSFER_IMG::IMAGE"))

(in-package "ROS")
;;//! \htmlinclude Image.msg.html


(defclass transfer_img::Image
  :super ros::object
  :slots (_id _name _msg_type _encode_msg _timestamp ))

(defmethod transfer_img::Image
  (:init
   (&key
    ((:id __id) 0)
    ((:name __name) "")
    ((:msg_type __msg_type) "")
    ((:encode_msg __encode_msg) "")
    ((:timestamp __timestamp) 0.0)
    )
   (send-super :init)
   (setq _id (round __id))
   (setq _name (string __name))
   (setq _msg_type (string __msg_type))
   (setq _encode_msg (string __encode_msg))
   (setq _timestamp (float __timestamp))
   self)
  (:id
   (&optional __id)
   (if __id (setq _id __id)) _id)
  (:name
   (&optional __name)
   (if __name (setq _name __name)) _name)
  (:msg_type
   (&optional __msg_type)
   (if __msg_type (setq _msg_type __msg_type)) _msg_type)
  (:encode_msg
   (&optional __encode_msg)
   (if __encode_msg (setq _encode_msg __encode_msg)) _encode_msg)
  (:timestamp
   (&optional __timestamp)
   (if __timestamp (setq _timestamp __timestamp)) _timestamp)
  (:serialization-length
   ()
   (+
    ;; uint16 _id
    2
    ;; string _name
    4 (length _name)
    ;; string _msg_type
    4 (length _msg_type)
    ;; string _encode_msg
    4 (length _encode_msg)
    ;; float64 _timestamp
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint16 _id
       (write-word _id s)
     ;; string _name
       (write-long (length _name) s) (princ _name s)
     ;; string _msg_type
       (write-long (length _msg_type) s) (princ _msg_type s)
     ;; string _encode_msg
       (write-long (length _encode_msg) s) (princ _encode_msg s)
     ;; float64 _timestamp
       (sys::poke _timestamp (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint16 _id
     (setq _id (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; string _name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _msg_type
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _msg_type (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _encode_msg
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _encode_msg (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; float64 _timestamp
     (setq _timestamp (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get transfer_img::Image :md5sum-) "744347aa4b3e0b8a8d56e91de0a07387")
(setf (get transfer_img::Image :datatype-) "transfer_img/Image")
(setf (get transfer_img::Image :definition-)
      "uint16 id
string name
string msg_type
string encode_msg
float64 timestamp


")



(provide :transfer_img/Image "744347aa4b3e0b8a8d56e91de0a07387")


