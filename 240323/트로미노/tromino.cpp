#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[204][204];
int ans;

int main() {
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<=n-2; i++) {
        for(int j=0; j<=m-2; j++) {
            int a = arr[i][j] + arr[i][j+1] + arr[i+1][j]+ arr[i+1][j+1];
            int b = min(min(min(arr[i][j],arr[i][j+1]),arr[i+1][j]),arr[i+1][j+1]);
            ans = max(ans, a-b);
        }
    }

    for(int i=0; i<=n-3; i++) {
        for(int j=0; j<=m-3; j++) {
            int a = arr[i][j] + arr[i][j+1] + arr[i][j+2];
            int b = arr[i][j] + arr[i+1][j] + arr[i+2][j];
            ans = max(max(ans, a),b);
        }
    }

    cout<<ans<<"\n";

    return 0;
}