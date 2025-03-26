#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    if (m > n) {cout << "m > n" << endl; return 0;}

    vector<int> dp(n+1, 0);
    dp[0] = 1;
    
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++){
            if (i>=j) {
                dp[i] += dp[i-j];
            }
        }
    }

    std::cout << "number of mean: " << dp[n] << std::endl;

    return 0;
}
