#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int num, pack;
    cin >> num >> pack;
    vector<int> weight(num, 0);
    vector<int> value(num, 0);

    // input the weight and value of item idx "i"
    for (int i=1; i<=num; i++){
        cin >> weight[i] >> value[i];
    }

    vector<vector<int>> dp(num, vector<int>(pack+1, 0));

    for (int i=1; i<=pack; i++){
        dp[0][i] = (i/weight[0])*value[0];
    }

    for (int i=1; i<num; i++){
        for (int j=1; j<=pack; j++) {
            // dp transistion function in complete packer
            if (j >= weight[i]) dp[i][j] = max(dp[i][j-weight[i]+value[i], dp[i-1][j]]);
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return 0;
}
