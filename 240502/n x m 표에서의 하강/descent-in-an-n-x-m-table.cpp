#include <iostream>
using namespace std;

int n, m;
int ans = 1e9;
int arr[500][500];
int visited[500][500]; 
int dx[3] = {1,1,1};
int dy[3] = {0,1,-1};

void init_visited(){
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            visited[i][j]=0;
        }
    }
}

void dfs(int x, int y, int dir, int cost){ //dir : 남쪽 = 1, 남서쪽 = 2, 남동쪽 = 3
    visited[x][y] = 1;

    // if(cost >= ans){
    //     return;
    // }
    if(x==n-1){
        if(ans > cost){
            ans = cost;
        }
    }

    for(int i=0; i<3; i++){
        if(dir == i) continue;
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 or ny <0 or nx >= n or ny >= m) continue;
        if(cost <= arr[nx][ny]) continue;
        if(visited[nx][ny]==0){
            visited[nx][ny] = 1;
            dfs(nx,ny,i, cost+arr[nx][ny]);
            visited[nx][ny] = 0;
        }
    }

    return;
}

int main() {
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<m; i++) {
        init_visited();
        dfs(0,i,-1, arr[0][i]);
    }

    cout<<ans<<"\n";

    return 0;
}