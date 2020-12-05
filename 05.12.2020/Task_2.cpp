#include <bits/stdc++.h>
using namespace std;

bool charDecoder(char ch){
    if(ch == 'B') return true;
    if(ch == 'F') return false;
    if(ch == 'R') return true;
    if(ch == 'L') return false;
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
    vector <int> IDs;
    while(cin >> s){
        int currentID = decoder(s);
        IDs.push_back(currentID);
    }
    sort(IDs.begin(), IDs.end());
    for(int i = 1; i < IDs.size(); i++){
        if(IDs[i] - IDs[i-1] == 2) cout << IDs[i] - 1;
    }    
}