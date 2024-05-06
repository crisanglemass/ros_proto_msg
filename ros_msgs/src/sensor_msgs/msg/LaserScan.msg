Header header               # 时间戳和坐标系信息
float32 angle_min           # 最小测量角度 [弧度]
float32 angle_max           # 最大测量角度 [弧度]
float32 angle_increment     # 两次连续测量之间的角度增量 [弧度]
float32 time_increment      # 两次连续测量之间的时间增量 [秒] - 如果激光器是连续的，这个值应该是0
float32 scan_time           # 一次扫描的时间 [秒]
float32 range_min           # 测量距离的最小值 [米]
float32 range_max           # 测量距离的最大值 [米]
float32[] ranges            # 距离测量值数组 [米] - 如果没有检测到物体，将值设为无穷大
float32[] intensities       # 强度测量值数组 - 可选字段，如果激光雷达支持强度测量
