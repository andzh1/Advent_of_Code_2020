#include <bits/stdc++.h>
using namespace std;

bool charDecoder(char ch){
    return (ch == 'B' || ch == 'R');
}

int decoder(string input){
    int answer = 0, n = input.length();
    for(int i = 0; i < n; i++){
        answer = answer * 2 + charDecoder(input[i]);
    }
    return answer;
}

int main(){
    freopen("Puzzle_Input.txt", "r", stdin);
    string s;
    int maxID = 0;
    while(cin >> s){
        int currentID = decoder(s);
        maxID = max(maxID, currentID);
    }
    cout << maxID;
    
}