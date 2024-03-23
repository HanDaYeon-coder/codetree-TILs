#include <iostream>
#include <vector>
using namespace std;

int n;
int ans;
vector<int> b;

void combi() {
    if(b.size() == n) {
        int num = 1;
        bool is_ans = true;
        for(int i=0; i<n; i++) {
            if(b[i] == b[i+1]) {
                num++;
            } else {
                if(num != b[i]) {
                    is_ans = false;
                    break;
                }
                num = 1;
            }
        }

        if(is_ans) {
            ans++;
        }
        return;
    }

    for(int i=1; i<4; i++) {
        b.push_back(i);
        combi();
        b.pop_back();
    }
}

int main() {
    cin>>n; //중복 순열 4ㅠn

    combi();

    cout<<ans<<"\n";

    return 0;
}