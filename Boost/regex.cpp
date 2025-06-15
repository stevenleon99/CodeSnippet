#include <boost/shared_ptr.hpp>
#include <boost/regex.hpp>
#include <iostream>

int main() {
    // Smart pointer
    boost::shared_ptr<int> ptr(new int(42));
    std::cout << "Value: " << *ptr << std::endl;

    // Regex
    std::string s = "email@example.com";
    boost::regex expr(R"(\w+@\w+\.\w+)");
    if (boost::regex_match(s, expr)) {
        std::cout << "Valid email." << std::endl;
    } else {
        std::cout << "Invalid email." << std::endl;
    }
    
    return 0;
}