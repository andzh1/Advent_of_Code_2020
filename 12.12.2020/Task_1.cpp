#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("Puzzle_Input.txt", "r", stdin);
    string s;
    long long x = 0, y = 0, direction = 90;
    while(cin >> s){
        char move = s[0];
        int value = stoi(s.substr(1, s.length() - 1));
        if(move == 'R'){
            direction += value;
            direction %= 360;
        }
        else if(move == 'L'){
            direction += 360 - value;
            direction %= 360;
        }
        else {
            if(move == 'F'){
                if(direction == 0) move = 'N';
                if(direction == 90) move = 'E';
                if(direction == 180) move = 'S';
                if(direction == 270) move = 'W';
            }
            if(move == 'N') y+= value;
            if(move == 'S') y-= value;
            if(move == 'E') x+= value;
            if(move == 'W') x-= value;
        }
    }
    cout << abs(x) + abs(y);
}