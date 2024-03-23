#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[24][24];

int dx1[4] = {2,1,-1,-2};
int dy1[4] = {0,0,0,0};

int dx2[4] = {-1,0,1,0};
int dy2[4] = {0,1,0,-1};

int dx3[4] = {-1,1,1,-1};
int dy3[4] = {1,1,-1,-1};

vector<pair<int,int>> v;
vector<int> b;
int max_ans;

void permutation() {
    if(b.size() == v.size()) {
        int ans = 0;

        for(int i=0; i<v.size(); i++) {
            if(b[i] == 1) {
                for(int j=0; j<4; j++) {
                    int nx = v[i].first + dx1[j];
                    int ny = v[i].second + dy1[j];
                    
                    if(nx >= n or ny >= n or nx < 0 or ny < 0) {
                        continue;
                    }

                    if(arr[nx][ny] == 0) {
                        arr[nx][ny] = 2;
                        ans++;
                    }
                }
            } else if(b[i] == 2) {
                for(int j=0; j<4; j++) {
                    int nx = v[i].first + dx2[j];
                    int ny = v[i].second + dy2[j];
                    
                    if(nx >= n or ny >= n or nx < 0 or ny < 0) continue;
                    if(arr[nx][ny] == 0) {
                        arr[nx][ny] = 2;
                        ans++;
                    }
                }
            } else if(b[i] == 3) {
                for(int j=0; j<4; j++) {
                    int nx = v[i].first + dx3[j];
                    int ny = v[i].second + dy3[j];
                    
                    if(nx >= n or ny >= n or nx < 0 or ny < 0) continue;
                    if(arr[nx][ny] == 0) {
                        arr[nx][ny] = 2;
                        ans++;
                    }
                }
            }
        }
        
        // 배열 초기화
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(arr[i][j] == 2) {
                    arr[i][j] = 0;
                }
            }
        }

        int v_size = v.size();

        max_ans = max((ans+v_size), max_ans);

        return;
    }

    for(int i=1; i<=3; i++) {
        b.push_back(i);
        permutation();
        b.pop_back();
    }
}

int main() {
    cin >> n;

    // 폭탄 놓는 순열 구하기
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 1) {
                v.push_back({i,j});
            }
        }
    }

    permutation();

    cout<<max_ans<<"\n";

    return 0;
}