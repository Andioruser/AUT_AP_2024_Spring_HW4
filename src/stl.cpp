#include "stl.h"

void initial_vector_with_3_multiples(std::vector<int>& v, size_t size) {

}

int count_unique_above(std::vector<int> v, int n) {

}

std::string vector_to_string(std::vector<int> v, char separator) {

}

void square_elements(std::vector<int>& v) {

}

void copy_if_even(const std::vector<int>& source, std::vector<int>& destination) {

}

std::string getTimestamp() {
    // 获取当前时间
    std::time_t t = std::time(nullptr);
    
    // 转换为本地时间
    std::tm* tm_ptr = std::localtime(&t);
    
    // 格式化时间为 "Mon May 13 17:50:43 2024"
    char buffer[100];
    std::strftime(buffer, sizeof(buffer), "%a %b %d %H:%M:%S %Y", tm_ptr);
    
    return std::string(buffer);
}