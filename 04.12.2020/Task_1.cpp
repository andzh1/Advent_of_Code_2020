#include <bits/stdc++.h>
using namespace std;

typedef string inputType;



int main(){
    freopen("Puzzle_Input.txt", "r", stdin);
    inputType x;
    int amountOfFields = 0;
    bool hasCid = false;
    int answer = 0;
    for(int i = 0; i < 1160; i++){
        getline(cin, x);
        if(x != ""){
            vector <string> tokens; 
            stringstream input(x); 
            string currentInput; 
            char delimiter = ' ';
            while(getline(input, currentInput, delimiter)) 
            { 
                tokens.push_back(currentInput); 
            } 
            for(auto cur: tokens) {
                amountOfFields ++;
                if(cur.substr(0, 3) == "cid") hasCid = true;
            }
        } 
        else {
            if((!hasCid && amountOfFields == 7) || (amountOfFields == 8)) answer ++;
            hasCid = false;
            amountOfFields = 0;
        }
    }
    cout << answer;
}