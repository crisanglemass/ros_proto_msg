#!/bin/bash

# 获取当前脚本所在目录
SCRIPT_DIR=$(dirname "$0")

# 下载图像并保存为image.jpg
curl -o "$SCRIPT_DIR/image.jpg" "https://th.bing.com/th/id/R.d4c3af858afbf8f342085635c39c88cc?rik=dNhicxloyYpfSQ&pid=ImgRaw&r=0"

