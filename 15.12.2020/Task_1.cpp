#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("Puzzle_Input.txt", "r", stdin);
    int game[2020];
    int cuurentPosition = 7; // = amount of input numbers
    for(int i = 0;  i < cuurentPosition; i++) 
        cin >> game[i];
    for(; cuurentPosition < 2020; cuurentPosition++){
        int current = game[cuurentPosition - 1];
        int leftCounter = cuurentPosition - 2;
        for(; leftCounter >= 0; leftCounter--){
            if(game[leftCounter] == game[cuurentPosition - 1]) break;
        }
        game[cuurentPosition] = cuurentPosition - leftCounter - 1;
        if(leftCounter == -1) game[cuurentPosition] = 0;
    }
    cout << game[2019];
}