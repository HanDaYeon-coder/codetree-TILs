#include <iostream>
using namespace std;
int N = 0;

void printStar(int n) {
    if(n==N) return;
    for(int i=0; i<=n; i++) {
        cout<<"*";
    }
    cout<<"\n";
    printStar(n+1);
}

int main() {
    cin >> N;
    printStar(0);
    return 0;
}