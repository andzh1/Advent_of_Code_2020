#include <bits/stdc++.h>
using namespace std;

const string starting = "shinygold";

vector <string> cutOffRepeats(vector <string> input){
    sort(input.begin(), input.end());
    vector <string> output;
    output.push_back(input[0]);
    for(int i = 1; i < input.size(); i++){
        if(input[i] != input[i-1]) output.push_back(input[i]);
    }
    return output;
}

int main(){
    freopen("Puzzle_Input.txt", "r", stdin);
    string s;
    map <string, vector<string>> graph;
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
                graph[tokens[i+1] + tokens[i+2]].push_back(s1);
                avaliable.push_back(tokens[i+1] + tokens[i+2]);
                visited[tokens[i+1] + tokens[i+2]] = false;
            }
        }
        avaliable.push_back(s1);
        visited[s1] = false;
    }
    queue <string> queueOfVertexes;
    queueOfVertexes.push(starting);
    while(!queueOfVertexes.empty()){
        string s = queueOfVertexes.front();
        queueOfVertexes.pop();
        for(auto u: graph[s]){
            if(visited[u]) continue;
            visited[u] = true;
            queueOfVertexes.push(u);
        }
    }
    int answer = 0;
    avaliable = cutOffRepeats(avaliable);
    for(auto x: avaliable) 
        answer += visited[x];
    cout << answer;
}