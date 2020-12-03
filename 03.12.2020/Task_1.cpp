#include <bits/stdc++.h>
using namespace std;

const int fileLength = 323;

int counterOfTrees(string input[], int down, int right){
    int length = input[0].length();
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
    string input[fileLength];
    for(int i = 0; i < fileLength; i++) cin >> input[i];
    long long counter = 1;
    counter *= counterOfTrees(input, 1, 3);
    cout << counter;
}