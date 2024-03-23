#include <iostream>
using namespace std;

int n;
int arr[24][24];

int main() {
    cin>>n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>arr[i][j];
        }
    }

    int ans = 0;
    for(int i=0; i<=n-3; i++) {
        for(int j=0; j<=n-3; j++) {
            int num1 = 0;
            for(int k=0; k<3; k++) {
                for(int l=0; l<3; l++) {
                    if(arr[i+k][j+l] == 1) {
                        num1++;
                    }
                }
            }
            if(ans < num1) {
                ans = num1;
            }
        }
    }

    cout<<ans<<"\n";

    return 0;
}