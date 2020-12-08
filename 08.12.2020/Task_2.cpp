#include <bits/stdc++.h>
using namespace std;

int operation(vector <string> operations, int accumulator, int ip, bool processed[]){
    processed[ip] = true;
    stringstream input(operations[ip]);
    string typeOfOperation, value;
    input >> typeOfOperation >> value;
    bool isPlus = (value[0] == '+');
    int number = stoi(value.substr(1, value.size() - 1));
    if(typeOfOperation == "acc") {
        if(isPlus) accumulator += number;
        else accumulator -= number;
    }
    else if(typeOfOperation == "jmp") {
        if(isPlus) ip += number;
        else ip -= number;
        ip--;
    }
    ip++;
    if(!processed[ip] && ip < operations.size()) return accumulator + operation(operations, 0, ip, processed);       
    return accumulator; 
}

bool canProcess(vector <string> operations, int ip, bool processed[]){
    processed[ip] = true;
    stringstream input(operations[ip]);
    string typeOfOperation, value;
    input >> typeOfOperation >> value;
    bool isPlus = (value[0] == '+');
    int number = stoi(value.substr(1, value.size() - 1));
    if(typeOfOperation == "jmp") {
        if(isPlus) ip += number - 1;
        else ip -= number+1;
    }
    ip ++;
    if(ip == operations.size()) return true;
    if(processed[ip]) return false;       
    else return canProcess(operations, ip, processed); 
}

bool isPossibleToChange(string s){
    return s.substr(0, 3) == "nop" || s.substr(0, 3) == "jmp";
}

string swapper(string input){
    string answer = "";
    if(input.substr(0, 3) == "nop") answer = "jmp" + input.substr(3, input.length() - 3);
    else if(input.substr(0, 3) == "jmp") answer = "nop" + input.substr(3, input.length() - 3);
    return answer;
}

int main(){
    freopen("Puzzle_Input.txt", "r", stdin); 
    vector <string> input;
    string s;
    while(getline(cin, s)) input.push_back(s);
    bool processed[input.size()];
    vector <string> currentInput;
    for(int ip = 0; ip < input.size(); ip++){
        if(isPossibleToChange(input[ip])){
            for(int i = 0; i < input.size(); i++) processed[i] = false;
            currentInput = input;
            currentInput[ip] = swapper(currentInput[ip]);
            if(canProcess(currentInput, 0, processed)) {
                break;
            }
        }
    }
    for(int i = 0; i < input.size(); i++) processed[i] = false;
    cout << operation(currentInput, 0, 0, processed);
}