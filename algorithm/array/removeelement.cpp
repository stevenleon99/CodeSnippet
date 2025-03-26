#include <iostream>
#include <vector>

using namespace std;


class Solution{
public:
    int remove_element(vector<int>& arr, int val){
        int index = arr.size()-1;
        int slowindex = 0;
        for (int fastindex = 0; fastindex < index; fastindex++){
            if (arr[fastindex] != val){
                arr[slowindex++] = arr[fastindex];
            }

        }
        return slowindex;
    }
};

int main(int argc, const char** argv) {
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    Solution sol;
    int res = sol.remove_element(nums, val);
    printf("number of array element is: %d", res);
    return 0;
}