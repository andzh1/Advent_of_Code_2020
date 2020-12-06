#include <bits/stdc++.h>
using namespace std;

int solution(vector <string> input)
{
    int array[26];
    for(int i = 0; i < 26; i++) array[i] = 0;
    for(auto s: input){
        for(int i = 0; i < s.length(); i++) array[s[i] - 'a'] ++;
    }
    int counter = 0;
    for(int i = 0; i < 26; i++) {
        if(array[i] > 0) counter ++;
    }
    return counter;
}

int main(){
    freopen("Puzzle_Input.txt", "r", stdin);
    string s;
    int summ = 0, cursum = 0;
    vector <string> input;
    while(getline(cin, s)){
        if(s.length() == 0){
            summ += solution(input);
            input.clear();
        }
        else {
            input.push_back(s);
        }
    }
    cout << summ;
}