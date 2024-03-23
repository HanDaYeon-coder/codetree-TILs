#include <iostream>
using namespace std;

string s;
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};

int rdx[4] = {0,1,0,-1};
int rdy[4] = {1,0,-1,0};

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
            if(dir >= 0) {
                x += dx[dir%4];
                y += dy[dir%4];
            } else {
                x += rdx[(-dir)%4];
                y += rdy[(-dir)%4];
            }
        }
    }

    cout<<x<<" "<<y<<"\n";

    return 0;
}