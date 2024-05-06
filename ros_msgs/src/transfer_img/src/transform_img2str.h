#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <boost/archive/iterators/base64_from_binary.hpp>
#include <boost/archive/iterators/transform_width.hpp>

using namespace std;

std::string base64_decode(const std::string &in) {
    std::string out;
    std::vector<int> T(256, -1);
    for (int i = 0; i < 64; i++)
        T["ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[i]] = i;

    int val = 0, valb = -8;
    for (unsigned char c : in) {
        if (T[c] == -1) break;
        val = (val << 6) + T[c];
        valb += 6;
        if (valb >= 0) {
            out.push_back(char((val >> valb) & 0xFF));
            valb -= 8;
        }
    }
    return out;
}

bool saveImageFromBase64(const std::string& base64_str, const std::string& filename) {
    std::string decoded_data = base64_decode(base64_str);
    std::ofstream file(filename, std::ios::out | std::ios::binary);
    if (!file) {
        std::cerr << "Error: Failed to open file for writing." << std::endl;
        return false;
    }
    file.write(decoded_data.c_str(), decoded_data.length());
    file.close();
    std::cout << "Image saved successfully." << std::endl;
    return true;
}

string imageToBase64(const string& imagePath) {
    // 以二进制模式打开图像文件
    ifstream imageFile(imagePath, ios::in | ios::binary);
    if (!imageFile.is_open()) {
        cerr << "Error opening image file" << endl;
        return "";
    }

    // 读取图像文件内容
    stringstream ss;
    ss << imageFile.rdbuf();
    string imageData = ss.str();
 
    // 将图像数据编码为Base64字符串
    typedef boost::archive::iterators::base64_from_binary<boost::archive::iterators::transform_width<const char *, 6, 8>> Base64EncodeIterator;
    stringstream result;
    copy(Base64EncodeIterator(imageData.c_str()), Base64EncodeIterator(imageData.c_str() + imageData.size()), ostream_iterator<char>(result));
    
    return result.str();
}

