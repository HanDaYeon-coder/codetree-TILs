#include <iostream>
using namespace std;

int N = 0;

void printStar(int n) {
    if(n==0) return;
    for(int i=0; i<n; i++) {
        cout<<"*"<<" ";
    }
    cout<<"\n";
    printStar(n-1);
    for(int i=0; i<n; i++) {
        cout<<"*"<<" ";
    }
    cout<<"\n";
}

int main() {
    cin >> N;
    printStar(N);
    return 0;
}