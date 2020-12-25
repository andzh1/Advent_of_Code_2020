#include <bits/stdc++.h>
using namespace std;

int modpow(int x, int power, int module) //Returns (x^power) % module
{
    if(power == 0) return 1%module;
    if(power % 2 == 0) return modpow(x, power/2, module)*modpow(x, power/2, module)%module;
    if(power % 2 == 1) return x * modpow(x, power - 1, module) % module;
}

int main(){
    freopen("Puzzle_Input.txt", "r", stdin);
    long cardKey = 15628416;
    long doorKey = 11161639;
    long currentValue = 1;
    int cardLoop;
    int doorLoop;
    for(int i = 1; i < 20201227; i++){
        currentValue *= 7;
        currentValue %= 20201227;
        if(currentValue == cardKey) {cardLoop = i; break;}
    }
    long answer = 1;
    for(int i = 0; i < cardLoop; i++){
        answer *= doorKey;
        answer %= 20201227;
    }
    cout << answer;
}