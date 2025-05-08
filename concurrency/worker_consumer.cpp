#include <boost/thread.hpp>
#include <boost/chrono.hpp>
#include <iostream>
#include <queue>
#include <atomic>
#include <time.h>

using namespace std;

std::queue<int> task_queue;
boost::mutex queue_mutex;
boost::condition_variable queue_cv;
std::atomic<bool> done(false);

void producer(int id, const int count) {
    for (int i = 0; i < count; ++i) {
        {
            // only one thread can access the queue at a time
            boost::unique_lock<boost::mutex> lock(queue_mutex);
            int task = id * 100 + i;
            task_queue.push(task);
            std::cout << "Producer " << id << " produced task " << task << "\n";
        }
        queue_cv.notify_one();
        boost::this_thread::sleep_for(boost::chrono::milliseconds(1000));
    }
}

void consumer(int id) {
    while (true) {
        boost::unique_lock<boost::mutex> lock(queue_mutex);
        //// avoid spurious wakeup
        // easy encounter pitfall
        // if no signal done is set, some consumer wake up late
        // will wait forever for start
        queue_cv.wait(lock, [] { return !task_queue.empty() || done.load(); });

        // atomic variable will only have one status at a time like bool
        // ensure safe, lock-free access across threads. 
        if (task_queue.empty() && done.load()) break;

        int task = task_queue.front();
        task_queue.pop();
        lock.unlock();

        std::cout << "Consumer " << id << " processed task " << task << "\n";
        boost::this_thread::sleep_for(boost::chrono::milliseconds(1500));
    }
}

int main() {
    const int num_producers = 2;
    const int num_consumers = 3;
    const int tasks_per_producer = 5;

    std::vector<boost::thread> producers;
    std::vector<boost::thread> consumers;


    for (int i = 0; i < num_producers; ++i) {
        producers.emplace_back(boost::thread(producer, i + 1, tasks_per_producer));
    }

    for (int i = 0; i < num_consumers; ++i) {
        consumers.emplace_back(boost::thread(consumer, i + 1));
    }

    for (auto& t : producers) t.join();


    //// complete task signal
    // Why notify_all() once is enough:
    // All waiting consumers wake up.
    // Those who see tasks in the queue will process them.
    // Those who wake up too late and find the queue empty will see done == true and exit cleanly.
    done = true;
    // Example use: When shutting down, and you want all waiting consumers to exit.
    queue_cv.notify_all();  // Wake up consumers

    for (auto& t : consumers) t.join();

    std::cout << "All tasks processed.\n";
    return 0;
}