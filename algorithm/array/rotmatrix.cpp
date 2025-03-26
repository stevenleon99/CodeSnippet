#include <iostream>
#include <vector>

using namespace std;

class Solution{

public:
    vector<vector<int>> rotmatrix(int num){
        vector<vector<int>> res(num, vector<int>(num, 0));
        int loop = num/2; 
        int mid = num/2; // the index of x, y for the center
        int startloop = 1;
        int x = 0, y = 0;
        int count = 1; 
        // cout << loop; // not round the res but just truncate
        while (loop--){
            int i = x, j = y;
            for (i; i < num - startloop; i++){
                res[j][i] = count++;
            }
            for (j; j < num - startloop; j++){
                res[j][i] = count++;
            }
            for (i; i > x; i--){
                res[j][i] = count++;
            }
            for (j; j > y; j--){
                res[j][i] = count++;
            }
            x++;
            y++;
            startloop++;

        }

        if(num%2){
            res[mid][mid] = count;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    int num = 3;
    Solution sol;
    vector<vector<int>> res = sol.rotmatrix(num);
    cout << res[2][2];
    return 0;
}
