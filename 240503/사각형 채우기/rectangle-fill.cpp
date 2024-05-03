#include <iostream>
using namespace std;

int n;
int arr[1004];

void func(){
    arr[0]=0;
    arr[1]=1;
    arr[2]=2;
    for(int i=3; i<=n; i++){
        arr[i] = arr[i-1]+arr[i-2];
    }
}

int main() {
    cin >> n;
    func();

    cout<<arr[n]<<"\n";
    return 0;
}