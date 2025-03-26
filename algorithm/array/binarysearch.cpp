#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Binary search function to find the index of a given value in the array
    static int binarysearch(vector<int> arr, int target) {
        int length = arr.size()-1;
        int left = 0;
        int right = length;
        while (left <= right){
            int middle = left + ((right - left) / 2); // prevent memory excceeding
            if(arr[middle]>target){
                right = middle -1 ;
            }
            else if (arr[middle]<target){
                left = middle + 1;
            }
            else {
                printf("the index of target: %d", middle);
                return 1;}
        }

        // time complexity upper limit O(n)
        // for(auto i = 0; i< length; i++){
        //     if(arr[i] == target){
        //         printf("the index of target: %d", i);
        //         return 1;}
        // } 

        return 0;
    }
};

int main() {
    vector<int> arr = {-1,0,3,5,9,12};
    int target = 3;
    int res = Solution::binarysearch(arr, target);
    if (!res) {printf("do no exist target in array");} 
    return -1;
}