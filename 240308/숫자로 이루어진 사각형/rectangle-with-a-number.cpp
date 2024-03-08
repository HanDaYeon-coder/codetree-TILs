#include <iostream>
using namespace std;

int main() {
    int N;
    char ans = '1';

    cin>>N;

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(ans > '9') {
                ans = '1';
            }
            cout<<ans<<" ";
            ans++;
        }
        cout<<"\n";
    }
    return 0;
}