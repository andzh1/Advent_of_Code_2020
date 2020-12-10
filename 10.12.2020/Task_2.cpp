#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("Puzzle_Input.txt", "r", stdin);
    string s;
    vector <int> input;
    input.push_back(0);
    while(cin >> s) input.push_back(stoi(s));
    long long answer = 1;
    sort(input.begin(), input.end());
    for(int i = 0; i < input.size(); i++){
        int dif = 1, ip = i;
        while(dif == 1 && ip < input.size()){
            dif = input[ip+1] - input[ip];
            ip++;
        } ip--;
        if(ip != i && ip - i < 4) answer *= pow(2, ip - i - 1);
        else if(ip - i == 4) answer *= 7;
        i = ip;
    }
    cout << answer;
}

//Answer = 3947645370368