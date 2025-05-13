#include <iostream>
#include <vector>

using namespace std;
// the minimal distance to interconnect all islands

int main(int argc, char const *argv[])
{
    int v, e;
    int x, y, k;
    cin >> v >> e; // vertex edge
    vector<vector<int>> grid (v+1, vector<int>(v+1, 10001));
    while(e--) {
        cin >> x >> y >> k;
        grid[x][y] = k;
        grid[y][x] = k;   
    }

    vector<int> minDist(v+1, 10001); // from 1 to v
    vector<int> visitTree(v+1, false);

    for (int i=1; i<v; i++) {
        int minVal = INT_MAX;
        int cur = -1;
        for (int j=1; j<minDist.size(); j++) {
            if (minDist[j] < minVal && visitTree[j] == false) {
                cur = j;
                minVal = minDist[j];
            }
        }

        visitTree[cur] = true;

        for (int k=1; k<=v; k++) {
            // if (visitTree[k] == false && grid[cur][k] < minDist[k]) {
            if (grid[cur][k] < minDist[k]) {
                minDist[k] = grid[cur][k];
            }
        }
    }

    for (int i=2; i<minDist.size(); i++) {
        cout << "idx " << i << " :" << minDist[i] << endl;
        
    }

    return 0;
}
