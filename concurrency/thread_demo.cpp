#include <thread>
#include <iostream>
#include <string.h>

using namespace std;


void say_hello(string arg1) {
    std::cout << "msg is: arg1" << std::endl;
}

int main() {
    string arg1 = "Hello from main thread!";
    std::thread t(say_hello, arg1);
    t.join();
}