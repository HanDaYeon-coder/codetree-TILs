#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int a, b;
int arr[1000004];

int main() {
    cin >> n >> k;

    for(int i=0; i<k; i++) {
        cin >> a >> b;
        for(int j=a; j<b; j++){
            arr[j] += 1;
        }
    }

    sort(arr, arr+n);

    cout<<arr[n/2]<<"\n";

    return 0;
}