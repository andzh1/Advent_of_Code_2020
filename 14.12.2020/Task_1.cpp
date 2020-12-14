#include <bits/stdc++.h>
using namespace std;

long int getNewValue(string mask, string value)
{
    string newValue;
    long int intValue = stol(value);
    for (int i = 0; i < 36; i++)
    {
        (intValue % 2 == 1) ? newValue.push_back('1') : newValue.push_back('0');
        intValue /= 2;
    }
    for(int i = 0; i < 18; i++) swap(newValue[i], newValue[35-i]);
    string answer = "";
    for(int i = 0;  i < 36; i++) (mask[i] == 'X')? answer.push_back(newValue[i]) : answer.push_back(mask[i]);
    long int answerValue = 0;
    for(int i = 0; i < 36; i++) answerValue = 2*answerValue + answer[i] - '0';
    return answerValue;
}

int main(){
    freopen("Puzzle_Input.txt", "r", stdin);
    string s;
    long int memory[70000];
    vector <string> input;
    for(int i = 0; i < 70000; i++) memory[i] = 0;
    while(getline(cin, s)){
        input.push_back(s);
    }
    string currentMask = "";
    for(auto currentS: input){
        stringstream str(currentS);
        string adress, ch, value;
        str >> adress >> ch >> value;
        if(adress == "mask"){
            currentMask = value;
            continue;
        }
        else
        {
            stringstream getAdress(adress);
            while(getline(getAdress, s, '['));
            s.pop_back();
            memory[stoi(s)] = getNewValue(currentMask, value);
        }
    }
    long int answer = 0;
    for(int i = 0; i < 70000; i++) answer += memory[i];
    cout << answer;
}