#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int arrN[200004];
int arrM[14];
vector<int> ans;

bool is_beautiful(int idx){
    vector<int> v;

    for(int i=idx; i<idx+M; i++){
        v.push_back(arrN[i]);
    }

    sort(v.begin(), v.end());

    int x = abs(v[0]-arrM[0]);

    for(int i=0; i<M; i++){
        if(x != abs(v[i]-arrM[i])){
            return false;
        }
    }

    return true;
}

int main() {
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> arrN[i];
    }

    cin >> M;
    for(int i=0; i<M; i++){
        cin >> arrM[i];
    }

    sort(arrM, arrM+M);

    for(int i=0; i<=N-M; i++){
        if(is_beautiful(i)){
            ans.push_back(i);
        }
    }

    cout<<ans.size()<<"\n";
    for(auto i : ans){
        cout<<i+1<<"\n";
    }

    return 0;
}