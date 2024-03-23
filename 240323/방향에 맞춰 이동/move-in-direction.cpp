#include <iostream>
using namespace std;

int N;
char dir;
int num;
int x, y;

int main() {
    cin >> N;

    for(int i=0; i<N; i++) {
        cin >> dir >> num;

        if(dir == 'W') {
            x -= num;
        } else if (dir == 'S') {
            y -= num;
        } else if (dir == 'N') {
            y += num;
        } else if (dir == 'E') {
            x += num;
        }
    }

    cout<< x << " " << y <<"\n";

    return 0;
}