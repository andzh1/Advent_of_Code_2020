#include <bits/stdc++.h>
using namespace std;

const int amountOfMoves = 100;
const int amountOfCups = 9;

int getPosOfDestination(string input){
    char currentCup = input[0];
    int minDif = amountOfCups, ipMin;
    bool allBigger = true;
    for(int i = 4; i < input.length(); i++){
        if(currentCup > input[i] && currentCup - input[i] < minDif){
            minDif = currentCup - input[i];
            allBigger = false;
            ipMin = i;
        }
    }
    if(allBigger){
        int max = 0, ipMax;
        for(int i = 4; i < input.length(); i++){
            if(input[i] > max){
                max = input[i];
                ipMax = i;
            }
        }
        return ipMax;
    }
    else return ipMin;
}

string move(string input){
    string pickup = input.substr(1, 3);
    char currentCup = input[0];
    int destinationPosition = getPosOfDestination(input);
    string preAnswer = input[0] + input.substr(4, destinationPosition - 3) + pickup + input.substr(destinationPosition + 1);
    string answer = "";
    for(int i = 1; i <= amountOfCups; i++) answer.push_back(preAnswer[i % amountOfCups]);
    return answer;
}

int main(){
    string inputFile = "716892543";
    string order = inputFile;
    for(int i = 0; i < amountOfMoves; i++){
        int ip = i % 10;
        order = move(order);
    }
    int posOf1 = order.find('1');
    string answer = order.substr(posOf1 + 1) + order.substr(0, posOf1);
    cout << answer;
}