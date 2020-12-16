#include <bits/stdc++.h>
using namespace std;

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

vector <int> getInvalidRanges(vector <pair<int, int>> ranges, int field){
    vector <int> answer;
    for(int i = 0; i < ranges.size(); i+= 2){
        if(field < ranges[i].first || (field > ranges[i].second && field < ranges[i+1].first) || field > ranges[i+1].second) answer.push_back(i/2);
    }
    return answer;
}


int main(){
    // freopen("input.txt", "r", stdin);
    freopen("output.txt", "r", stdin);
    string s;
    vector <string> requiredValues;
    int amountOfRanges = 20;
    for(int i = 0; i < amountOfRanges; i++){
        getline(cin, s);
        requiredValues.push_back(s);
    }
    vector <pair <int, int>> ranges = getRanges(requiredValues);
    vector <int> myTicket;
    while(s.substr(0, 4) != "your") getline(cin, s);
    getline(cin, s);
    myTicket = parseTicket(s);
    vector <vector <int>> otherTickets;
    while(s.substr(0, 6) != "nearby") getline(cin, s);
    while(getline(cin, s)) {
        otherTickets.push_back(parseTicket(s));
    }
    int lengthOfTicket = otherTickets[0].size();
    set <int> realFields[lengthOfTicket];
    for(auto ticket: otherTickets){
        for(int i = 0;  i < ticket.size(); i++){
            vector <int> invalidRangesForCurrentField = getInvalidRanges(ranges, ticket[i]);
            for(auto x: invalidRangesForCurrentField) realFields[i].insert(x);
        }
    }
    int counterOfAnswers = 0;
    long long answer = 1;

    while(counterOfAnswers < amountOfRanges){
        int numberOfRange = 0, ip;
        for(int i = 0; i < lengthOfTicket; i++){
            if(realFields[i].size() == amountOfRanges - 1){
                ip = i;
                for(auto range: realFields[i]) {
                    if(range != numberOfRange) break;
                    numberOfRange++;
                }
                break;
            }
        }
        for(int i = 0; i < lengthOfTicket; i++){
            realFields[i].insert(numberOfRange);
        }
        realFields[ip].clear();
        // amountOfRanges --;
        counterOfAnswers ++;
        if(numberOfRange < 6) answer *= myTicket[ip];
    }
    cout << answer;
}