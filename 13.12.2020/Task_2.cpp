#include <bits/stdc++.h>
using namespace std;

/* BE CAREFULL!
This solution is, in my opinion, one of the worst possible solutions of this problem :-) */

int main(){
    freopen("Puzzle_Input.txt", "r", stdin);
    int n;
    cin >> n;
    string s;
    cin >> s;
    cin >> s;
    stringstream input(s);
    vector <string> tokens;
    while(getline(input, s, ',')) tokens.push_back(s);
    int length = tokens.size();
    int schedule[length];
    int amountOfNumbers = 0, maxNumber = 0, ipMax;
    for(int i = 0; i < length; i++){
        if(tokens[i] == "x") schedule[i] = 0;
        else {
            schedule[i] = stoi(tokens[i]);
            amountOfNumbers++;
            if(maxNumber < schedule[i]){
                maxNumber = schedule[i];
                ipMax = i;
            }
        }
    }
    int numbers[amountOfNumbers];
    int differences[amountOfNumbers];
    int counter = 0;
    for(int i = 0; i < length; i++){
        if(schedule[i] > 0) {
            differences[counter] = i - ipMax;
            numbers[counter] = schedule[i];
            counter ++;
        }
    }
    int slash = differences[0];
    for(int i = 0;  i < amountOfNumbers; i++){
        while(differences[i] < 0) 
            differences[i] += numbers[i];
    }
    for(long long ip = 99999999921653; ip < 3000000000000000; ip+= 528203) /* I figured out, that buses 991, 13 & 41 will arrive at the same time, 
    so in required range should be number x, which we can divide by 528203 (in other words, x % 528203 = 0). All we need to do - is just 
    small (SMALL!) loop for ip in range (99999999921653; INFINITE)... Some day it will stop)*/
    {
        bool exists = true;
        for(int j = 0; j < amountOfNumbers; j++){
            if((ip + differences[j]) % numbers[j] != 0) exists = false;
        }
        if(exists) {cout << ip + slash; break;}
    }
} 