#include <iostream>
using namespace std;

int n, m;
int arr[104][104];
int ans;

int main() {
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<=n; i++) { //같은 행에서 찾기
        int prev = 0;
        int num = 1; //연속하는 숫자의 갯수
        int max_num = 0;

        for(int j=0; j<=n; j++) {
            if(prev == arr[i][j]) {
                num++;
            } else {
                if(num >= m) {
                    ans++;
                    break;
                }
                prev = arr[i][j];
                num = 1;
            }
        }
        
    }

    for(int j=0; j<=n; j++) { // 같은 열에서 찾기
        int prev = 0;
        int num = 1; //연속하는 숫자의 갯수 

        for(int i=0; i<=n; i++) {
            if(prev == arr[i][j]) {
                num++;
            } else {
                if(num >= m) {
                    ans++;
                    break;
                }
                prev = arr[i][j];
                num = 1;
            }
        }
    }

    cout<<ans<<"\n";

    return 0;
}