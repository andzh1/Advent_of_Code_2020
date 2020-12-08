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




int main(){
    freopen("Puzzle_Input.txt", "r", stdin); 
    vector <string> input;
    string s;
    while(getline(cin, s)) input.push_back(s);
    bool processed[input.size()];
    for(int i = 0; i < input.size(); i++) processed[i] = false;
    cout << operation(input, 0, 0, processed);
}