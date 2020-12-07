#include <bits/stdc++.h>
using namespace std;

const string starting = "shinygold";

int counter(map <string, vector<pair<string, int>>> graph, string start){
    int answer = 1;
    for(auto x: graph[start]){
        int amount = x.second;
        string next = x.first;
        answer += amount* (counter(graph, next));
    }
    return answer;
}

int main(){
    freopen("Puzzle_Input.txt", "r", stdin);
    string s;
    map <string, vector<pair<string, int>>> graph;
    vector <string> avaliable;
    map <string, bool> visited;
    while(getline(cin, s)){
        vector <string> tokens; 
        stringstream input(s); 
        string currentInput; 
        char delimiter = ' ';
        while(getline(input, currentInput, delimiter)) 
        { 
            tokens.push_back(currentInput); 
        } 
        string s1 = tokens[0] + tokens[1];
        for(int i = 4; i < tokens.size(); i+= 4){
            if(tokens[i] != "no") {
                graph[s1].push_back({tokens[i+1] + tokens[i+2], stoi(tokens[i])});
                avaliable.push_back(tokens[i+1] + tokens[i+2]);
                visited[tokens[i+1] + tokens[i+2]] = false;
            }
        }
        avaliable.push_back(s1);
        visited[s1] = false;
    }
    cout << counter(graph, starting) - 1;//-1 - because we also count our starting "shiny gold" bag
}
