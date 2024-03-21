#include <iostream>
#include <vector>
using namespace std;

int n, m;
int a,b;
vector<int> v[1004];
int visited[1004];
int max_cnt;
int v_cnt[1004];
int cnt;

void bfs(int x) {
    visited[x] = 1;
    for(int i=0; i<v[x].size(); i++) {
        int nx = v[x][i];
        if(visited[nx]==0){
            bfs(nx);
            cnt++;
        }
    }
}

int main() {
    cin>>n>>m;

    for(int i=0; i<m; i++) {
        cin>>a>>b;
        v[a].push_back(b);
    }

    for(int i=1; i<=n; i++) {
        //초기화
        for(int j=0; j<=n; j++) {
            visited[j]= 0;
        }
        cnt=0;

        bfs(i);
        v_cnt[i]=cnt;
        if(cnt>max_cnt){
            max_cnt = cnt;
        }
    }

    for(int i=1; i<=n; i++) {
        if(v_cnt[i]==max_cnt){
            cout<<i<<" ";
        }
    }

    return 0;
}