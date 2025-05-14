#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> father(1001, 0);


void init() {
    for (int i=0; i<father.size(); i++) {
        father[i] = i;
    }
}


int find(int u) {
    return u == father[u] ? u : find(father[u]);
}

bool isSame(int u, int v) {
    int u_f = find(u);
    int v_f = find(v);

    return u_f == v_f;
}


// v->u
void join(int u, int v) {
    int u_f = find(u);
    father[v] = u_f;
}


int main(int argc, char const *argv[])
{
    cin >> n; // number node
    int s, t; // ver s and ver t connected
    init();
    for (int i=0; i<n; i++) {
        cin >> s >> t;
        if (isSame(s, t)) {
            cout << "s-t is redundant" << s << "-" << "t" << endl;
            return 0;
        } else {
            join(s, t);
        }
    }
    return 0;
}
