#include <vector>

int sum(const vector<int> vec){
    long sum = 0;
    for (auto num : vec){
        sum += num;
    }
    return sum;
}