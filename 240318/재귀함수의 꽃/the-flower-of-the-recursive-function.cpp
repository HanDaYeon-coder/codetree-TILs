#include <iostream>
using namespace std;

int N = 0;

void printX(int n){
    if(n==0) return;
    cout<<n<<" ";
    printX(n-1);
    cout<<n<<" ";
}

int main() {
    cin >> N;
    printX(N);
    return 0;
}