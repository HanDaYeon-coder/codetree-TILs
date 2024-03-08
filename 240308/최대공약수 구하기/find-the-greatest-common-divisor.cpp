#include <iostream>
using namespace std;

void gcd(int a, int b){
    if(b==0) {
        cout<<a<<"\n";
        return;
    }
    gcd(b, a%b);
}

int main() {
    int n,m;
    int ans;
    cin>>n>>m;

    if(m>n) {
        gcd(m,n);
    } else {
        gcd(n,m);   
    }

    return 0;
}