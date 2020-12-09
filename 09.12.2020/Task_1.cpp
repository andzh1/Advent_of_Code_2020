#include <bits/stdc++.h>
using namespace std;

const int preambleLength = 25;

long long longstoi(string s){
    if(s.length() < 10) return stoi(s);
    else return stoi(s.substr(0, s.length() - 9))*pow(10, 9) + stoi(s.substr(s.length() - 9, 9));
}

int main(){
    freopen("Puzzle_Input.txt", "r", stdin);
    string s;
    vector <long long> XMAS_data;
    while(cin >> s){
        XMAS_data.push_back(longstoi(s));
    }
    int ip = preambleLength;
    while(ip < XMAS_data.size()){
        bool isValid = false;
        for(int i = 0; i < preambleLength - 1; i++){
            for(int j = i + 1; j < preambleLength; j++){
                if(XMAS_data[ip - 1 - i] + XMAS_data[ip - 1 - j] == XMAS_data[ip]) isValid = true;
            }
        }
        if(!isValid){
            cout << XMAS_data[ip] << '\n';
            break;
        }
        ip++;
    }
}