#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int findsubarray(vector<int> arr, int target){
        int left = 0;
        int right = 0;
        int sublength = INT_MAX;
        int sum = 0;
        for (right; right<arr.size(); right++){
            sum += arr[right];
            while (sum >= target){
                sublength = sublength > (right - left + 1) ? (right - left + 1) : sublength;
                sum -= arr[left];
                left++;
            }
        }
        return sublength;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> arr = {2,3,1,2,4,3};
    int target = 7;
    Solution sol;
    int res = sol.findsubarray(arr, target);
    printf("min sub-array length is: %d", res);
    return 0;
}

