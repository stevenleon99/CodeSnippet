#include <boost/thread.hpp>
#include <iostream>

void task() {
    try {
        int ct = 0;
        while (true) {
            std::cout << "count is : " << ct << std::endl;
            ct++;
            boost::this_thread::sleep_for(boost::chrono::milliseconds(100));
            boost::this_thread::interruption_point();  // check for interruption
        }
    } catch (boost::thread_interrupted&) {
        std::cout << "Thread interrupted!\n";
    }
}

int main() {
    boost::thread t(task);
    boost::this_thread::sleep_for(boost::chrono::seconds(1));
    t.interrupt();  // asks the thread to stop, stop before counting to 10
    t.join();
}