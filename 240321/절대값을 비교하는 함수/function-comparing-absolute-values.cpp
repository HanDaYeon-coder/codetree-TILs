#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int N;
int a, b;

int main() {
    cin>>N;

    for(int i=0; i<N; i++) {
        cin >> a >> b;
        int abs_a = abs(a);
        int abs_b = abs(b);

        cout<< max(abs_a, abs_b)<<"\n";
    }

    return 0;
}