#include <bits/stdc++.h>
using namespace std;

typedef string inputType;

bool isPresent(string input)
{
    string field = input.substr(0,3);
    string value = input.substr(4, input.length()-4);
    string newValue;
    if(field == "byr"){
        if(stoi(value) < 1920 || stoi(value) > 2002) return false;
    }
    if(field == "iyr"){
        if(stoi(value) < 2010 || stoi(value) > 2020) return false;
    }
    if(field == "eyr"){
        if(stoi(value) < 2020 || stoi(value) > 2030) return false;
    }
    if(field == "hgt"){
        string s = value.substr(value.length() - 2, 2);
        newValue = value.substr(0, value.length() - 2);
        if(s == "cm"){
            if(stoi(newValue) < 150 || stoi(newValue) > 193) return false;
        }
        else if(s == "in"){
            if(stoi(newValue) < 59 || stoi(newValue) > 76) return false;
        } else return false;
    }
    if(field == "hcl"){
        if(value[0] != '#') return false;
        newValue = value.substr(1, value.length() - 1);
        if(newValue.length() != 6) return false;
        for(int i = 0; i < 6; i++) 
            if((newValue[i] < '0' || newValue[i] > '9') && (newValue[i] < 'a' || newValue[i] > 'f')) return false;    
        }
    if(field == "ecl"){
        if(value != "amb" && value != "blu" && value != "brn" && value != "gry" && value != "grn" && value != "hzl" && value != "oth") return false;
    }
    if(field == "pid"){
        if(value.length() != 9) return false;
        for(int i = 0; i < 9; i++){
            if(value[i] < '0' || value[i] > '9') return false;
        }    
    }   
    return true;
}

int main(){
    freopen("Puzzle_Input.txt", "r", stdin);
    inputType x;
    int amountOfFields = 0;
    bool hasCid = false, isValid = true;
    int answer = 0;
    for(int i = 0; i < 1160; i++){
        getline(cin, x);
        if(x != ""){
            vector <string> tokens; 
            stringstream input(x); 
            string currentInput; 
            char delimiter = ' ';
            while(getline(input, currentInput, delimiter)) 
            { 
                tokens.push_back(currentInput); 
            } 
            for(auto cur: tokens) {
                amountOfFields ++;
                if(cur.substr(0, 3) == "cid") hasCid = true;
                else isValid *= isPresent(cur);
            }
        } else {
            if(((!hasCid && amountOfFields == 7) || (amountOfFields == 8)) && isValid) answer ++;
            hasCid = false;
            isValid = true;
            amountOfFields = 0;
        }
    }
    cout << answer;
}