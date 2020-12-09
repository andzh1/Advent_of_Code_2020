#include <bits/stdc++.h>
using namespace std;

const int ipOfInvalidNumber = 620;

long long longstoi(string s){
    if(s.length() < 10) return stoi(s);
    else return stoi(s.substr(0, s.length() - 9))*pow(10, 9) + stoi(s.substr(s.length() - 9, 9));
}

int main(){
    freopen("Puzzle_Input.txt", "r", stdin);
    string s;
    vector <long long> XMAS_data;
    for(int i = 0; i < ipOfInvalidNumber; i++){
        cin >> s;
        XMAS_data.push_back(longstoi(s));
    }
    long long invalidNumber = 556543474;//Got it in part 1
    int ipA, ipB;//left & right edges of required contiguous range
    for(int a = 2; a < ipOfInvalidNumber - 2; a++){
        long long summ = XMAS_data[a] + XMAS_data[a+1] + XMAS_data[a+2];
        for(int b = a+3; b < ipOfInvalidNumber; b++){
            if(summ == invalidNumber){
                ipA = a;
                ipB = b;
                break;
            }
            else if(summ > invalidNumber){
                break;
            }
            summ += XMAS_data[b];
        }
    }
    long long min = XMAS_data[ipA];
    long long max = XMAS_data[ipA];
    for(int i = ipA + 1; i < ipB; i++){
        if(max < XMAS_data[i]) max = XMAS_data[i];
        if(min > XMAS_data[i]) min = XMAS_data[i];       
    }
    cout << max + min << '\n';
}