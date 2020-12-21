#include <bits/stdc++.h>
using namespace std;

vector <string> getEdges(vector <string> input){
    string leftEdge = "", rightEdge = "";
    vector <string> answer;
    answer.push_back(input[0]);
    for(auto s: input){
        leftEdge.push_back(s[0]);
        rightEdge.push_back(s[s.length()-1]);
    }
    answer.push_back(leftEdge);
    answer.push_back(input[input.size() - 1]);
    answer.push_back(rightEdge);
    return answer;
}

string flip(string input){
    string answer = "";
    for(int i = input.size() - 1; i >= 0; i--) answer += input[i];
    return answer;
}

int main(){
    freopen("Puzzle_Input.txt", "r", stdin);
    string s;
    map <int, vector <string>> tiles;
    int currentTile;
    vector <int> IDs;
    while(getline(cin, s)){
        if(s[0] == 'T'){
            currentTile = stoi(s.substr(5, 4));
            IDs.push_back(currentTile);
        }
        else if(s == "") continue;
        else tiles[currentTile].push_back(s);
    }
    map <int, vector <string>> tileEdges;
    for(auto tileID: IDs){
        tileEdges[tileID] = getEdges(tiles[tileID]);
    }
    long long answer = 1;
    for(int i = 0; i < IDs.size(); i++){
        int currentID = IDs[i];
        int amountOfDifferentEdges = 0;
        for(auto edge: tileEdges[currentID]){
            bool found = false;
            for(int j = 0; j < IDs.size(); j++){
                found = false;
                if(j == i) continue;
                int matchingID = IDs[j];
                for(auto newEdge: tileEdges[matchingID]) 
                    if(newEdge == edge || edge == flip(newEdge)){
                        found = true;
                        break;
                }
                if(found) break;
            }
            amountOfDifferentEdges += (!found);
        } 
        if(amountOfDifferentEdges == 2) answer *= currentID;   
    }
    cout << answer;
}