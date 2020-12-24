#include <bits/stdc++.h>
using namespace std;

const int approximateWidthOfFloor = 300;
const int amountOfDays = 100;

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

set <pair <int, int>> getBlack()
{
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

int getAmountOfNeighbours(vector <bitset <approximateWidthOfFloor>> floor, int x, int y){
    int answer = 0;
    answer += (floor[x-1][y-1]);
    answer += (floor[x+1][y+1]);
    answer += (floor[x-1][y]);
    answer += (floor[x+1][y]);
    answer += (floor[x][y-1]);
    answer += (floor[x][y+1]);
    return answer;
}

vector <bitset <approximateWidthOfFloor>> getNewFloor(vector <bitset <approximateWidthOfFloor>> floor)
{
    vector <bitset <approximateWidthOfFloor>> secondFloor(approximateWidthOfFloor);
    for(int x = 10; x < approximateWidthOfFloor - 10; x++){
        for(int y = 10; y < approximateWidthOfFloor - 10; y++){
            int amountOfNeighbours = getAmountOfNeighbours(floor, x, y);
            if(floor[x][y]){
                if(amountOfNeighbours == 1 || amountOfNeighbours == 2) secondFloor[x][y] = 888;
            }
            else if(amountOfNeighbours == 2) secondFloor[x][y] = 888;
        }
    }
    return secondFloor;
}

int main(){
    set <pair <int, int>> alreadyBlack = getBlack();
    vector <bitset <approximateWidthOfFloor>> floor(approximateWidthOfFloor);
    for(auto el: alreadyBlack){
        floor[el.first + approximateWidthOfFloor/2][el.second + approximateWidthOfFloor/2] = 777;
    }
    for(int ip = 0; ip < amountOfDays; ip++){
        cout << ip << '\n';
        floor = getNewFloor(floor);
    }
    int answer = 0;
    for(auto x: floor) answer += x.count();
    cout << answer;
}