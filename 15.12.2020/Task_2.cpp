#include <bits/stdc++.h>
using namespace std;

const int answerNumber = 30000000;

int main(){
    freopen("Puzzle_Input.txt", "r", stdin); // I replaces all ',' in input to spaces, to make input file easier to read.
    map <int, int> game;
    int currentPosition = 7; // = amount of input numbers
    int x;
    for(int i = 0;  i < currentPosition; i++) {
        cin >> x;
        game[x] = i+1;
    }
    int previousNumber = x, currentNumber;
    for(; currentPosition < answerNumber; currentPosition++){
        if(game.count(previousNumber)) 
            currentNumber = currentPosition - game[previousNumber];
        else currentNumber = 0;
        game[previousNumber] = currentPosition;
        previousNumber = currentNumber;
    }
    cout << currentNumber;
}