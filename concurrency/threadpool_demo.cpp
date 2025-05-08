#include <boost/asio.hpp>
#include <iostream>
#include <thread>

void task(int id) {
    std::cout << "Task " << id << " is running in thread " << std::this_thread::get_id() << "\n";
}

int main() {
    boost::asio::thread_pool pool(4); // Create a pool with 4 threads

    for (int i = 0; i < 10; ++i) {
        boost::asio::post(pool, [i] { task(i); });
    }

    pool.join();  // Wait for all tasks to finish
    return 0;
}