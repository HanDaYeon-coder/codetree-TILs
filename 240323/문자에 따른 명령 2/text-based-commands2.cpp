#include <iostream>
using namespace std;

string s;
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};

int main() {
    cin >> s;

    int x = 0;
    int y = 0;
    int dir = 0;

    for(int i=0; i<s.size(); i++) {
        if(s[i] == 'L') {
            dir += 1;
        } else if (s[i] == 'R') {
            dir -= 1;
        } else {
            x += dx[dir];
            y += dy[dir];
        }
    }

    cout<<x<<" "<<y<<"\n";

    return 0;
}