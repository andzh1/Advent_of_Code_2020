#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("Puzzle_Input.txt", "r", stdin);
    int n;
    cin >> n;
    int x, dif = INT32_MAX, minX;
    for(int i = 0; i < 9; i++) {
        cin >> x;
        int yx = x - (n % x);
        if(dif > yx){
            dif = yx;
            minX = x;
        }
    }
    cout << minX*dif;
} 