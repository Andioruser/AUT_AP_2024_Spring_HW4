#include "stl.h"

void initial_vector_with_3_multiples(std::vector<int>& v, size_t size) {
    
    v.resize(size);

    std::generate(v.begin(),v.end(),[n = 1]() mutable { return n++ * 3 ;});
}

int count_unique_above(std::vector<int> v, int n) {

    std::set<int> unique_elements(v.begin(),v.end());

    return std::count_if(unique_elements.begin(),unique_elements.end(),[n](int x){ return x > n;});
}

std::string vector_to_string(std::vector<int> v, char separator) {
    std::reverse(v.begin(),v.end());
    std::accumulate(v.begin(),v.end(),std::string(),[separator](const std::string&acc,int val){
        return acc.empty() ? std::to_string(val) : acc + separator + std::to_string(val);
    });
}

void square_elements(std::vector<int>& v) {
    std::transform(v.begin(),v.end(),v.begin(),[](int x){return x * x;});
}   

void copy_if_even(const std::vector<int>& source, std::vector<int>& destination) {
    std::copy_if(source.begin(),source.end(),std::back_inserter(destination),[](int x){return x % 2 == 0;});
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