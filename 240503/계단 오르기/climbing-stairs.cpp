#include <iostream>
#include <queue>
using namespace std;

int n;
int arr[1004];

void func(){
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 1;

    for(int i=4; i<=n; i++) {
        arr[i] = (arr[i-2] + arr[i-3]) % 10007;
    }
}

void func1() {
    queue<int> que;
    que.push(0);
    arr[0]=1;

    while(!que.empty()){
        int x = que.front();
        que.pop();

        if(x>=n){
            return;
        }

        if(arr[x+2]==0){
            arr[x+2] = arr[x];
            que.push(x+2);
        } else {
            arr[x+2] = (arr[x] + arr[x+2]) % 10007;
        }

        if(arr[x+3]==0){
            arr[x+3] = arr[x];
            que.push(x+3);
        } else {
            arr[x+3] = (arr[x] + arr[x+3]) % 10007;
        }
    }
}

int main() {
    cin >> n;

    func1();

    cout<<arr[n]<<"\n";

    return 0;
}