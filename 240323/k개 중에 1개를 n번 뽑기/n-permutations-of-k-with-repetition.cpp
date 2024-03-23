#include <iostream>
#include <vector>
using namespace std;

int K, N;
vector<int> b;

void combi() {
    if(b.size() == N) {
        for(int i : b) {
            cout<< i <<" ";
        }
        cout<<"\n";
        return;
    }

    for(int i=1; i<=K; i++) {
        b.push_back(i);
        combi();
        b.pop_back();
    }
}

int main() {
    cin >> K >> N;  //kCn 중복

    combi();
    
    return 0;
}