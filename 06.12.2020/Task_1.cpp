#include <bits/stdc++.h>
using namespace std;

int countAnswers(vector <string> input)
{
    int numbersOfLetters[26];
    for(int i = 0; i < 26; i++) numbersOfLetters[i] = 0;
    for(auto s: input){
        for(int i = 0; i < s.length(); i++) numbersOfLetters[s[i] - 'a'] ++;
    }
    int counter = 0;
    for(int i = 0; i < 26; i++) {
        if(numbersOfLetters[i] > 0) counter ++;
    }
    return counter;
}

int main(){
    freopen("Puzzle_Input.txt", "r", stdin);
    string s;
    int answer = 0;
    vector <string> input;
    while(getline(cin, s)){
        if(s.length() == 0){
            answer += countAnswers(input);
            input.clear();
        }
        else {
            input.push_back(s);
        }
    }
    cout << answer;
}