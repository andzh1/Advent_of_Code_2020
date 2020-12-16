#include <bits/stdc++.h>
using namespace std;

/* This program outputs only valid tickets (we need them in task 2) into output.txt.
Thats why in Task_2.cpp we read input from output.txt.*/

vector <pair<int, int>> getRanges(vector <string> input){
    vector <pair<int, int>> ranges;
    for(auto str: input){
        int ip = 0;
        while(str[ip] != ':') ip++;
        string s = str.substr(ip + 1, str.length() - ip);
        stringstream parser(s);
        // int number;
        vector <string> numbers;
        string x;
        while(getline(parser, x, '-')) numbers.push_back(x);
        for(int i = 0; i < numbers.size(); i += 2){
            ranges.push_back({stoi(numbers[i]), stoi(numbers[i+1])});
        }
    }
    return ranges;
}

vector <int> parseTicket(string ticket){
    stringstream input(ticket);
    string s;
    vector <int> answer;
    while(input >> s) answer.push_back(stoi(s));
    return answer;
}

bool isValid(vector <pair<int, int>> ranges, int field){
    for(auto range: ranges){
        if(field >= range.first && field <= range.second) return true;
    }
    return false;
}



int main(){
    freopen("Puzzle_Input.txt", "r", stdin);
    string s;
    vector <string> requiredValues;
    for(int i = 0; i < 20; i++){
        getline(cin, s);
        requiredValues.push_back(s);
    }
    vector <pair <int, int>> ranges = getRanges(requiredValues);
    string myTicket;
    while(s.substr(0, 4) != "your") getline(cin, s) ;
    getline(cin, myTicket);
    vector <vector <int>> otherTickets;
    while(s.substr(0, 6) != "nearby") getline(cin, s) ;
    while(getline(cin, s)) {
        otherTickets.push_back(parseTicket(s));
    }
    long answer = 0;
    bool validTickets[otherTickets.size()];
    for(int i = 0; i < otherTickets.size(); i++){
        validTickets[i] = true;
        for(auto field: otherTickets[i]) 
            if(!isValid(ranges, field)) validTickets[i] = false;
    }
    freopen("output.txt", "w", stdout);
    for(int i = 0; i < otherTickets.size(); i++){
        if(validTickets[i]){
            for(auto x: otherTickets[i]) cout << x << " ";
            cout << '\n';
        }
    }
    cout << answer;
}