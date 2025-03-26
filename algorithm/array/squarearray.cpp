#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
    vector<int> arr;
public:
    Solution(vector<int> arr): arr(arr){
        cout << "solution is initialized! \n";
    }
    void squaresort(){
        int index = arr.size();
        // for (auto i = arr.begin(); i != arr.end(); i++){
        //     *i = (*i)*(*i);
        //     printf("this element is %d \n", *i);
        // }
        for (auto i : arr) i = i*i;
        sort(arr.begin(), arr.end());
    }
    void squarebinarysort(){
        int leftindex = 0;
        int rightindex = arr.size()-1;
        int k = rightindex;
        vector<int> res(arr.size(), 0);
        while (leftindex <= rightindex){
            if (arr[leftindex]*arr[leftindex] > arr[rightindex]*arr[rightindex]){
                res[k--] = arr[leftindex]*arr[leftindex];
                leftindex++;
            }
            else{
                res[k--] = arr[rightindex]*arr[rightindex];
                rightindex--;
            }
        }

    }
    void displayarr(){
        for (auto i: arr){
            printf("this element is %d \n", i);
        }
    }
};


int main(int argc, char const *argv[])
{
    vector<int> arr = {-4,-1,0,3,10};
    Solution sol(arr);
    sol.squarebinarysort();
    sol.displayarr();
    return 0;
}
