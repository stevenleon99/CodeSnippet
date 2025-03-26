#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    int n, bagweight;
    cin >> n >> bagweight;
    cout << "n: " << n << "bagweight: " << bagweight << endl;
    vector<int> weight(n, 0);
    vector<int> value(n, 0);
    for (int i=0; i<n; i++) {
        cin >> weight[i];
    }
    for (int j=0; j<n; j++){
        cin >> value[j];
    }

    vector<vector<int>> dp(weight.size(), vector<int>(bagweight+1, 0));

    for (int j=weight[0]; j<=bagweight; j++){
        dp[0][j] = value[0];
    }

    for (int i=1; i<weight.size(); i++){
        for (int j=0; j<bagweight; j++){
            if (j<weight[i]) dp[i][j] = dp[i-1][j];
            else {
                dp[i][j] = max(dp[i-1][j-weight[i]]+value[i], dp[i-1][j]);
            }
        }
    }

    cout << dp[n-1][bagweight] << endl;
    return 0;
}
