#include <bits/stdc++.h>
using namespace std;

/* I replaced all ',' in input to ' ', and it became much more easier to read all ints.
I also replaces "_or_" to '-' with same purpose. */

vector <pair<int, int>> getRanges(vector <string> input){
    vector <pair<int, int>> ranges;
    for(auto str: input){
        int ip = 0;
        while(str[ip] != ':') ip++;
        string s = str.substr(ip + 1, str.length() - ip);
        stringstream parser(s);
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
    for(auto ticket: otherTickets){
        for(auto field: ticket) 
            if(!isValid(ranges, field)) answer += field;
    }
    cout << answer;
}