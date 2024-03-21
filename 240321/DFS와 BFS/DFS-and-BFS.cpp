#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, k;
int a, b;
vector<int> v[1004];
int visited[1004];

void dfs(int x) {
    visited[x] = 1;
    cout<<x<<" ";

    for(int i=0; i<v[x].size(); i++) {
        int nx = v[x][i];
        if(visited[nx] == 0) {
            dfs(nx);
        }
    }
}

void bfs(int x) {
    queue<int> que;
    que.push(x);
    visited[x] = 1;
    
    while(!que.empty()) {
        int here = que.front();
        que.pop();
        cout<<here<<" ";

        for(int i=0; i<v[here].size(); i++) {
            int nx = v[here][i];

            if(visited[nx] == 0) {
                visited[nx] = 1;
                que.push(nx);
            }
        }
    }
}

int main() {
    cin>>n>>m>>k;

    for(int i=0; i<m; i++) {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i=0; i<1004; i++) {
        visited[i] = 0;
    }

    dfs(k);
    cout<<"\n";

    for(int i=0; i<1004; i++) {
        visited[i] = 0;
    }
    bfs(k);

    return 0;
}