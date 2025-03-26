#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, m, p1, p2, val;
    cin >> n >> m;

    vector<vector<int>> grid(n+1, vector<int>(n+1, INT_MAX));
    for (int i=0; i<m; i++){
        cin >> p1 >> p2 >> val; // not applicable to val < 0
        grid[p1][p2] = val;
    }

    int start =1;
    int end = n;

    std::vector<int> minDist(n+1, INT_MAX);
    minDist[start] = 0;
    vector<bool> visited(n+1, false);

    for (int i=1; i<=n; i++){
        int minVal = INT_MAX;
        int cur = 1;
        
        // 1. min distance unvisited
        for (int v=1; v<=n; v++) {
            if (!visited[v] && minDist[v] < minVal) {
                minVal = minDist[v];
                cur = v;
            }
        }

        visited[cur] = true;

        // update the mindist from ori to each reachable
        for (int v=1; v<=n; v++) {
            if (!visited[v] && grid[cur][v] != INT_MAX && minDist[cur] + grid[cur][v] < minDist[v]){
                minDist[v] = minDist[cur] + grid[cur][v]; 
            }
        }

        cout << "result is: " << minDist[end];
    }
    return 0;
}
