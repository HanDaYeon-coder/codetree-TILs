#include <iostream>
using namespace std;

int N;
int arr[50];

void fibo(int n){
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 1;

    for(int i=3; i<=n; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }
}

int main() {
    cin >> N;

    fibo(N);
    cout<<arr[N]<<"\n";

    return 0;
}