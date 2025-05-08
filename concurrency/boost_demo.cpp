#include <boost/thread.hpp>
#include <iostream>
#include <string.h>

using namespace std;

void say_hello(string msg) {
    std::cout << "msg is : " << msg << std::endl;
}

int main() {
    string arg1 = "Hello from main thread!";
    boost::thread t(say_hello, arg1);
    t.join();
}