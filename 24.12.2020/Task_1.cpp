#include <bits/stdc++.h>
using namespace std;

vector <string> parseToMoves(string input){
    vector <string> answer;
    for(int i = 0; i < input.length(); i++){
        if(input[i] == 's') {
            answer.push_back(input.substr(i, 2));
            i++;
        }
        else if(input[i] == 'n') {
            answer.push_back(input.substr(i, 2));
            i++;
        }
        else if(input[i] == 'e') {
            answer.push_back(input.substr(i, 1));
        }
        else if(input[i] == 'w') {
            answer.push_back(input.substr(i, 1));
        }
    }
    return answer;
}

set <pair <int, int>> getBlack(){
    freopen("Puzzle_Input.txt", "r", stdin);
    string s;
    set <pair <int, int>> alreadyBlack;
    while(cin >> s){
        vector <string> moves = parseToMoves(s);
        int x = 0, y = 0;
        for(auto m: moves){
            if(m == "e") {x++; y++;}
            else if(m == "w") {x--; y--;}
            else if(m == "se") y++;
            else if(m == "nw") y--;
            else if(m == "sw") x--;
            else if(m == "ne") x++;
        }
        pair <int, int> currentPosition = {x, y};
        if(alreadyBlack.count(currentPosition)) alreadyBlack.erase(currentPosition);
        else alreadyBlack.insert(currentPosition);
    }
    return alreadyBlack;
}

int main(){
    set <pair <int, int>> alreadyBlack = getBlack();
    cout << alreadyBlack.size();
}