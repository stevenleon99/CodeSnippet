#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{   
    vector<int> nums = {1,2,3,5,6,3};
    unordered_set<int> res(nums.begin(), nums.end());
    cout << "unordered_set bc: " <<res.bucket_count();
    // cout << "unordered_set bs: " <<res.bucket_size(res[1]);
    cout << "unordered_set max bc: " <<res.max_bucket_count() <<endl;
    cout << "unordered_set size: " << res.size() <<endl;
    for (auto itr = res.begin(); itr!=res.end(); itr++){
        cout << *itr << endl;
    }
    if (res.find(3) == res.end()){cout << "key not in set " << endl;}
    return 0;
}
