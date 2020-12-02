#include <bits/stdc++.h>
using namespace std;

bool isValid(string input){
    int firstPos = 0, secondPos = 0;
    int ip = 0;
    while(input[ip] != '-'){
        firstPos = firstPos*10 + input[ip] - '0';
        ip++;
    } ip++;
    while(input[ip] != ' '){
        secondPos = secondPos*10 + input[ip] - '0';
        ip++;
    }
    char ch = input[ip+1];
    ip+= 4;
    return (input[ip + firstPos-1] == ch && input[ip +secondPos-1] != ch) || (input[ip +firstPos-1] != ch && input[ip +secondPos-1] == ch);
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