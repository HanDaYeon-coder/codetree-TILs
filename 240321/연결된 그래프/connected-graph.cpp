#include <iostream>
#include <vector>
using namespace std;

int n, m;
int a, b;
int visited[104];
vector<int> v[104];
int ans;

void dfs(int x) {
    visited[x] = 1;

    for(int i=0; i<v[x].size(); i++) {
        int nx = v[x][i];
        if(visited[nx] == 0) {
            dfs(nx);
            ans++;
        }
    }
}

int main() {
    cin>>n>>m;

    for(int i=0; i<m; i++) {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1);

    cout<<ans<<"\n";

    return 0;
}