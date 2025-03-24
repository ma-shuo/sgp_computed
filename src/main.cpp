#include <iostream>
#include <fstream>
#include "lib/json.hpp"

#include "utils/FileUtils.h"

using json = nlohmann::json;

int main() {
    // 输出当前工作目录
    json j = readJson();

    // 访问 JSON 数据
    std::string name = j["name"];
    int age = j["age"];
    bool is_student = j["is_student"];
    std::vector<std::string> courses = j["courses"];

    // 输出数据
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Is Student: " << std::boolalpha << is_student << std::endl;
    std::cout << "Courses: ";
    for (const auto& course : courses) {
        std::cout << course << " ";
    }
    std::cout << std::endl;


    // 获取用户输入
    std::string output_filename;
    std::cout << "请输入要输出的文件名字: ";
    std::cin >> output_filename;
    // 创建一个 ofstream 对象并打开文件
    std::ofstream outFile(output_filename);
    // 检查文件是否成功打开
    if (!outFile) {
        std::cerr << "无法打开文件！" << std::endl;
        return 1;
    }
    // 写入内容到文件
    outFile << "Hello, World!\n";
    outFile << "This is a C++ file writing example.\n";
    // 关闭文件
    outFile.close();
    std::cout << "文件写入成功！" << std::endl;

    return 0;
}
