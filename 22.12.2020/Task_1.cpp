#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("Puzzle_Input.txt", "r", stdin);
    string s;
    getline(cin, s);
    getline(cin, s);
    queue <int> player1, player2;
    while(s != "") {
        player1.push(stoi(s));
        getline(cin, s);
    } 
    getline(cin, s);
    while(getline(cin, s)) {
        player2.push(stoi(s));
    } 
    while(!player1.empty() && !player2.empty()){
        int first = player1.front(), second = player2.front();
        player1.pop();
        player2.pop();
        if(first > second) {
            player1.push(first);
            player1.push(second);
        }
        else
        {
            player2.push(second);
            player2.push(first);
        }
    }
    long long answer = 0;
    if(player1.size() == 0) swap(player2, player1);
    for(int i = player1.size(); i >= 1; i--){
        answer += i*player1.front();
        player1.pop();
    }
    cout << answer;
}