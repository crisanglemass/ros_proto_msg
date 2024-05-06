;; Auto-generated. Do not edit!


(when (boundp 'sensor_msgs::LaserScan)
  (if (not (find-package "SENSOR_MSGS"))
    (make-package "SENSOR_MSGS"))
  (shadow 'LaserScan (find-package "SENSOR_MSGS")))
(unless (find-package "SENSOR_MSGS::LASERSCAN")
  (make-package "SENSOR_MSGS::LASERSCAN"))

(in-package "ROS")
;;//! \htmlinclude LaserScan.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass sensor_msgs::LaserScan
  :super ros::object
  :slots (_header _angle_min _angle_max _angle_increment _time_increment _scan_time _range_min _range_max _ranges _intensities ))

(defmethod sensor_msgs::LaserScan
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:angle_min __angle_min) 0.0)
    ((:angle_max __angle_max) 0.0)
    ((:angle_increment __angle_increment) 0.0)
    ((:time_increment __time_increment) 0.0)
    ((:scan_time __scan_time) 0.0)
    ((:range_min __range_min) 0.0)
    ((:range_max __range_max) 0.0)
    ((:ranges __ranges) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:intensities __intensities) (make-array 0 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _header __header)
   (setq _angle_min (float __angle_min))
   (setq _angle_max (float __angle_max))
   (setq _angle_increment (float __angle_increment))
   (setq _time_increment (float __time_increment))
   (setq _scan_time (float __scan_time))
   (setq _range_min (float __range_min))
   (setq _range_max (float __range_max))
   (setq _ranges __ranges)
   (setq _intensities __intensities)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:angle_min
   (&optional __angle_min)
   (if __angle_min (setq _angle_min __angle_min)) _angle_min)
  (:angle_max
   (&optional __angle_max)
   (if __angle_max (setq _angle_max __angle_max)) _angle_max)
  (:angle_increment
   (&optional __angle_increment)
   (if __angle_increment (setq _angle_increment __angle_increment)) _angle_increment)
  (:time_increment
   (&optional __time_increment)
   (if __time_increment (setq _time_increment __time_increment)) _time_increment)
  (:scan_time
   (&optional __scan_time)
   (if __scan_time (setq _scan_time __scan_time)) _scan_time)
  (:range_min
   (&optional __range_min)
   (if __range_min (setq _range_min __range_min)) _range_min)
  (:range_max
   (&optional __range_max)
   (if __range_max (setq _range_max __range_max)) _range_max)
  (:ranges
   (&optional __ranges)
   (if __ranges (setq _ranges __ranges)) _ranges)
  (:intensities
   (&optional __intensities)
   (if __intensities (setq _intensities __intensities)) _intensities)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; float32 _angle_min
    4
    ;; float32 _angle_max
    4
    ;; float32 _angle_increment
    4
    ;; float32 _time_increment
    4
    ;; float32 _scan_time
    4
    ;; float32 _range_min
    4
    ;; float32 _range_max
    4
    ;; float32[] _ranges
    (* 4    (length _ranges)) 4
    ;; float32[] _intensities
    (* 4    (length _intensities)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; float32 _angle_min
       (sys::poke _angle_min (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _angle_max
       (sys::poke _angle_max (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _angle_increment
       (sys::poke _angle_increment (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _time_increment
       (sys::poke _time_increment (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _scan_time
       (sys::poke _scan_time (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _range_min
       (sys::poke _range_min (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _range_max
       (sys::poke _range_max (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32[] _ranges
     (write-long (length _ranges) s)
     (dotimes (i (length _ranges))
       (sys::poke (elt _ranges i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;; float32[] _intensities
     (write-long (length _intensities) s)
     (dotimes (i (length _intensities))
       (sys::poke (elt _intensities i) (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; float32 _angle_min
     (setq _angle_min (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _angle_max
     (setq _angle_max (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _angle_increment
     (setq _angle_increment (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _time_increment
     (setq _time_increment (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _scan_time
     (setq _scan_time (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _range_min
     (setq _range_min (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _range_max
     (setq _range_max (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32[] _ranges
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _ranges (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _ranges i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     ))
   ;; float32[] _intensities
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _intensities (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _intensities i) (sys::peek buf ptr- :float)) (incf ptr- 4)
     ))
   ;;
   self)
  )

(setf (get sensor_msgs::LaserScan :md5sum-) "90c7ef2dc6895d81024acba2ac42f369")
(setf (get sensor_msgs::LaserScan :datatype-) "sensor_msgs/LaserScan")
(setf (get sensor_msgs::LaserScan :definition-)
      "Header header               # 时间戳和坐标系信息
float32 angle_min           # 最小测量角度 [弧度]
float32 angle_max           # 最大测量角度 [弧度]
float32 angle_increment     # 两次连续测量之间的角度增量 [弧度]
float32 time_increment      # 两次连续测量之间的时间增量 [秒] - 如果激光器是连续的，这个值应该是0
float32 scan_time           # 一次扫描的时间 [秒]
float32 range_min           # 测量距离的最小值 [米]
float32 range_max           # 测量距离的最大值 [米]
float32[] ranges            # 距离测量值数组 [米] - 如果没有检测到物体，将值设为无穷大
float32[] intensities       # 强度测量值数组 - 可选字段，如果激光雷达支持强度测量

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
string frame_id

")



(provide :sensor_msgs/LaserScan "90c7ef2dc6895d81024acba2ac42f369")


