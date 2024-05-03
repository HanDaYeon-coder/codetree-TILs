#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v;
string arr[24];
int ans = 0;

void combi(int start, int r){
    if(ans!=0){
        return;
    }
    if(v.size()==r){
        int cnt = 0;

        for(int j=0; j<9; j++){
            int sum = 0;
            
            for(auto i : v){
                sum += (arr[i][j]-'0');
            }
            if(sum<10){
                cnt++;
            }
        }

        if(cnt==9){
            ans = r;
        }
        return;
    }

    for(int i=start+1; i<n; i++){
        v.push_back(i);
        combi(i, r);
        v.pop_back();
    }
}

int main() {
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    for(int i=0; i<n; i++){
        int length = 9-arr[i].size();
        string zero_str = "";

        for(int j=0; j<length; j++){
            zero_str += '0';
        }
        
        arr[i] = zero_str + arr[i];
    }

    for(int i=n; i>=1; i--){
        combi(-1,i);

        if(ans!=0){
            cout<<i<<"\n";
            break;
        }
    }
    return 0;
}