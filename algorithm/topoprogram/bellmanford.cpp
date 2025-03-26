#include <iostream>
#include <vector>
#include <list>
#include <climits>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, m, p1, p2, val;
    cin >> n >> m;

    vector<vector<int>> grid;

    for (int i=0; i<m; i++) {
        cin >> p1 >> p2 >> val;
        grid.push_back({p1, p2, val});
    }

    int start=1;
    int end=n;

    vector<int> minDist(n+1, INT_MAX);
    minDist[start] = 0;
    
    for (int i=1; i<n; i++) {
        for (vector<int> &side : grid) {
            int from = side[0];
            int to = side[1];
            int price = side[2];

            if (minDist[from] != INT_MAX && minDist[to] > minDist[from] + price) {
                minDist[to] = minDist[from] + price;
            }
        }

        cout << "对所有边松弛 " << i << "次" << endl;
        for (int k = 1; k <= n; k++) {
            cout << minDist[k] << " ";
        }
        cout << endl;
    }



    return 0;
}
