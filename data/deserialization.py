import demo_pb2

# 十六进制字符串
hex_string = "0a0474657374120c746573745f6d6573736167651a0131210cb4095b7b8ed941"

# 解析十六进制字符串
byte_data = bytes.fromhex(hex_string)

# 解析消息
publish_info = demo_pb2.PublishInfo()
publish_info.ParseFromString(byte_data)

# 打印消息内容
print("Name:", publish_info.name)
print("Message Type:", publish_info.message_type)
print("Publish Message:", publish_info.publish_msg)
print("Timestamp:", publish_info.timestamp)
