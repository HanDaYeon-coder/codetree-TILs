#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

int n, m;
int colored_cnt;
int cnt; //색칠된 구역 방문 개수
int first_color_x, first_color_y;

int arr1[504][504];
int arr2[504][504]; //색칠된 구역 표시 배열
int visited[504][504];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void init_visited(){
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            visited[i][j] = 0;
        }
    }
}

bool bfs(int x, int y, int D){
    init_visited();
    cnt = 0;

    queue<pair<int,int>> que;
    que.push({x, y});
    visited[x][y] = 1;

    while(!que.empty()) {
        pair<int,int> here = que.front();
        que.pop();

        if(arr2[here.first][here.second]==1){
            cnt++;
            if(cnt==colored_cnt){
                return true;
            }
        }

        for(int i=0; i<4; i++) {
            int nx = here.first+dx[i];
            int ny = here.second+dy[i];

            if(nx < 0 or ny < 0 or nx >= n or ny >= m) continue;
            if(abs(arr1[here.first][here.second]-arr1[nx][ny])>D) continue;
            if(visited[nx][ny]!=0) continue;
            que.push({nx,ny});
            visited[nx][ny] = 1;
        }
    }

    return false;
}

int main() {
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> arr1[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> arr2[i][j];

            if(arr2[i][j]==1){
                colored_cnt++;
                if(colored_cnt==1){
                    first_color_x = i;
                    first_color_y = j;
                }
            }
        }
    }

    for(int d=0; d<1000000001; d++){
        if(bfs(first_color_x,first_color_y,d)){
            cout<<d<<"\n";
            return 0;
        }
    }

    return 0;
}