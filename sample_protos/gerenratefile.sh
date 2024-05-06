#!/bin/bash
# 进入脚本所在目录
cd "$(dirname "$0")" || exit
# 执行 protoc 命令
protoc publish_info.proto --cpp_out=.
