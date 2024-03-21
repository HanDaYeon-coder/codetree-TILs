#include <iostream>
#include <queue>
using namespace std;

int n, m;
int arr[104][104];
int visited[104][104];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int ans;

int main() {
    cin>>n>>m;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin>>arr[i][j];
        }
    }

    queue<pair<int,int>> que;
    que.push({1,1});
    visited[1][1] = 1;

    while(!que.empty()) {
        pair<int,int> here = que.front();
        que.pop();

        if(here.first == n and here.second == m) {
            cout<<visited[n][m]<<"\n";
            break;
        }
        
        for(int i=0; i<4; i++) {
            int nx = here.first + dx[i];
            int ny = here.second + dy[i];

            if(nx > n or ny > m or nx <= 0 or ny <= 0) continue;
            if(arr[nx][ny] == 0) continue;

            visited[nx][ny] = visited[here.first][here.second] + 1;
            que.push({nx,ny});
        }
    }


    return 0;
}