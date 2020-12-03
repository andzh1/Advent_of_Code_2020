#include <bits/stdc++.h>
using namespace std;

typedef string inputType;

int counterOfTrees(vector <string> input, int down, int right){
    int length = input[0].length();
    int fileLength = input.size();
    int counter = 0, y = 0, x = 0;
    while(y < fileLength){
        if(input[y][x % length] == '#') counter ++;
        y += down;
        x += right;
        x = x % length;
    }
    return counter;
}

int main(){
    freopen("Puzzle_Input.txt", "r", stdin);
    vector <inputType> input;
    inputType s;
    while(cin >> s) input.push_back(s);
    cout << counterOfTrees(input, 1, 3);
}