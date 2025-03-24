//
// Created by mac on 25-3-24.
//
#include <iostream>
#include <fstream>
#include "lib/json.hpp"
#include "utils/FileUtils.h"


using json = nlohmann::json;


json readJson() {
    // 输出当前工作目录
    std::cout << "当前工作目录: " << std::filesystem::current_path() << std::endl;

    // 打开 JSON 文件
    std::ifstream file("./resources/data.json");
    if (!file.is_open()) {
        std::cerr << "无法打开文件！请检查文件路径和权限。" << std::endl;
        return 1;
    }

    // 解析 JSON 数据
    json j;
    try {
        file >> j; // 从文件流中读取并解析 JSON
    } catch (const json::parse_error& e) {
        std::cerr << "解析 JSON 文件时出错: " << e.what() << std::endl;
        std::cerr << "错误位置: 字节 " << e.byte << std::endl;
        return 1;
    }

    // 关闭文件
    file.close();

    return j;
}

