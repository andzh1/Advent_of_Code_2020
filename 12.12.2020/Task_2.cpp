#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("Puzzle_Input.txt", "r", stdin);
    string s;
    long long x = 0, y = 0, waypointX = 10, waypointY = 1; 
    while(cin >> s){
        char move = s[0];
        int direction = 0;
        int value = stoi(s.substr(1, s.length() - 1));
        if(move == 'R' || move == 'L'){
            if(move == 'R'){
                direction = value;
            }
            else {
                direction = 360 - value;
                direction %= 360;
            }
            if(direction != 0) {
                if(direction == 180) {
                    waypointX = -waypointX;
                    waypointY = -waypointY;
                }
                else {
                    swap(waypointX, waypointY);
                    if(direction == 90) waypointY = -waypointY;
                    if(direction == 270) waypointX = -waypointX;
                }
            }
        }
        else {
            if(move == 'F'){
                x += value*waypointX;
                y += value*waypointY;
            }
            if(move == 'N') waypointY += value;
            if(move == 'S') waypointY-= value;
            if(move == 'E') waypointX += value;
            if(move == 'W') waypointX -= value;
        }
    }
    cout << abs(x) + abs(y);
}