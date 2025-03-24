# 设置 CMake 最低版本
cmake_minimum_required(VERSION 3.30)

# 定义项目名称
project(sgp_computed
        VERSION 1.0
        DESCRIPTION "Your project description"
        LANGUAGES CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)


# 包含头文件目录
include_directories(${PROJECT_SOURCE_DIR}/include)

# 添加 math 模块
add_library(math STATIC)
# 匹配 src/math 目录下的所有 .cpp 文件
file(GLOB MATH_SOURCES "src/math/*.cpp")
# 动态添加源文件
target_sources(math PRIVATE ${MATH_SOURCES})

# 添加 utils 模块
add_library(utils STATIC)
# 匹配 src/math 目录下的所有 .cpp 文件
file(GLOB UTILS_SOURCES "src/utils/*.cpp")
# 动态添加源文件
target_sources(utils PRIVATE ${UTILS_SOURCES})

# 添加主程序
add_executable(sgp_computed src/main.cpp)

# 链接模块
target_link_libraries(sgp_computed PRIVATE math utils)

# 复制资源文件到构建目录
add_custom_command(
        TARGET sgp_computed POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/src/resources
        ${CMAKE_BINARY_DIR}/build/resources
        COMMENT "Copying resources to build directory"
)

# 定义宏 RESOURCE_DIR，指向构建目录中的资源文件夹
target_compile_definitions(sgp_computed PRIVATE RESOURCE_DIR="${CMAKE_BINARY_DIR}/resources")
