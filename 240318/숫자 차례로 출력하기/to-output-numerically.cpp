#include <iostream>
using namespace std;

int N = 0;

void printNum1(int n) {
    if(n==N) return;
    cout<<n+1<<" ";
    printNum1(n+1);
}

void printNum2(int n) {
    if(n==0) return;
    cout<<n<<" ";
    printNum2(n-1);
} 


int main() {
    cin>>N;
    printNum1(0);
    cout<<"\n";
    printNum2(N);
    return 0;
}