#include <iosteam>
#include <vector>
#include <climits>

using namespace std;


int main(int argc, char const *argv[])
{
    int v, e;
    int x,y,k;
    cin >> v >> e;

    vector<vector<int>> grid(v+1, vector<int>(v+1, 10001));
    while (e--) {
        cin >> x >> y >> k;
        grid[x][y] = k;
        grid[y][x] = k;
    }

    // min distance tree
    vector<int> minDist(v+1, 10001);
    // true if find the min distance for tree node
    vector<bool> isInTree(v+1, false);

    // cycle n-1 because it will cover all edges
    for (int i=1; i<v; i++){
        int cur = -1;
        int minVal = INT_MAX;
        
        // 1. pick vertex with min distance in minDist
        for (int j=1; j<=v; j++){
            if (!isInTree[j] && minDist[j] < minVal){
                minVal = minDist[j];
                cur = j;
            }
        }
        // 2. put it into Tree
        isInTree[cur] = true;
        // 3. 
        for (int j=1; j<=v; j++) {
            if (isintree[j] && grid[cur][j] < minDist[j]) {
                minDist[j] = grid[cur][j];
            }
        }
    }
    return 0;
}

