#include <bits/stdc++.h>
using namespace std;


queue <int> subqueue(queue <int> input, int length){
    queue <int> answer;
    while(length --){
        answer.push(input.front());
        input.pop();
    }
    return answer;
}

bool subGame(queue <int> player1,  queue <int> player2) // Returns true, if 1st player won the subgame, and vice versa
{
    if(player1.size() == 0) return false;
    if(player2.size() == 0) return true;
    set <queue <int>> queueDatabase;
    while(!player1.empty() && !player2.empty()){
        if(queueDatabase.count(player1) || queueDatabase.count(player2)) {
            return true;
            break;
        }
        queueDatabase.insert(player1);
        queueDatabase.insert(player2);
        int first = player1.front(), second = player2.front();
        player1.pop();
        player2.pop();
        if(first <= player1.size() && second <= player2.size()) {
            bool roundWinner = subGame(subqueue(player1, first), subqueue(player2, second));
            if(roundWinner){
                player1.push(first);
                player1.push(second);
            }
            else
            {
                player2.push(second);
                player2.push(first);
            }
        }
        else if(first > second) {
            player1.push(first);
            player1.push(second);
        }
        else
        {
            player2.push(second);
            player2.push(first);
        }
    }
    return player1.size() > player2.size();
}

int mainGame(queue <int> player1,  queue <int> player2)
{
    set <queue <int>> queueDatabase;
    while(!player1.empty() && !player2.empty()){
        if(queueDatabase.count(player1) || queueDatabase.count(player2)) break;
        queueDatabase.insert(player1);
        queueDatabase.insert(player2);
        int first = player1.front(), second = player2.front();
        player1.pop();
        player2.pop();
        if(first <= player1.size() && second <= player2.size()) {
            bool roundWinner = subGame(subqueue(player1, first), subqueue(player2, second));
            if(roundWinner){
                player1.push(first);
                player1.push(second);
            }
            else
            {
                player2.push(second);
                player2.push(first);
            }
        }
        else if(first > second) {
            player1.push(first);
            player1.push(second);
        }
        else
        {
            player2.push(second);
            player2.push(first);
        }
    }
    int answer = 0;
    if(player1.size() < player2.size()) swap(player2, player1);
    for(int i = player1.size(); i >= 1; i--){
        answer += i*player1.front();
        player1.pop();
    }
    return answer;
}

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
    cout << mainGame(player1, player2);
}