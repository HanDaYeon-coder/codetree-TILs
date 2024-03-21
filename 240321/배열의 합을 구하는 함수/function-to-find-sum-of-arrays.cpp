#include <iostream>
using namespace std;

int N;  //배열의 크기
int arr[14][14];

int main() {
    cin >> N;

    //배열 입력
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin>>arr[i][j];
        }
    }

    // 새로운 열 계산
    for(int i=0; i<N; i++){
        int ansColumn = 0;
        for(int j=0; j<N; j++) {
            ansColumn += arr[j][i];
        }
        arr[N][i] = ansColumn;
    }

    // 새로운 행 계산
    for(int i=0; i<=N; i++) {
        int ansRow = 0;
        for(int j=0; j<N; j++) {
            ansRow += arr[i][j];
        }
        arr[i][N] = ansRow;
    }

    for(int i=0; i<=N; i++){
        for(int j=0; j<=N; j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}