#include <bits/stdc++.h>
using namespace std;

bool isValid(string input){
    int min = 0, max = 0;
    int ip = 0;
    while(input[ip] != '-'){
        min = min*10 + input[ip] - '0';
        ip++;
    } ip++;
    while(input[ip] != ' '){
        max = max*10 + input[ip] - '0';
        ip++;
    }
    char ch = input[ip+1];
    ip+= 4;
    int amount = 0;
    while(ip < input.length()){
        if(input[ip] == ch) amount ++;
        ip++;
    }
    return amount >= min && amount <= max;
} 

int main(){
    int n = 1000;
    string input;
    int amount = 0;
    for(int i = 0; i < n; i++){
        getline(cin, input);
        amount += isValid(input);
    }
    cout << amount;
}