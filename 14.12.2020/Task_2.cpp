#include <bits/stdc++.h>
using namespace std;

string lltos2(string value){
    string answer;
    long long intValue = stoll(value);
    for (int i = 0; i < 36; i++)
    {
        (intValue % 2 == 1) ? answer.push_back('1') : answer.push_back('0');
        intValue /= 2;
    }
    for(int i = 0; i < 18; i++) swap(answer[i], answer[35-i]);
    return answer;
}

vector <int> getPosOfX(string mask){
    vector <int> positionsOfX;
    for(int i = 0;  i < 36; i++) {
        if(mask[i] == 'X') 
            positionsOfX.push_back(35 - i);
    }
    return positionsOfX;
}

long long getValueAfterMask(string mask, string value){
    long long answer = 0;
    string newValue = "";
    for(int i = 0; i < 36; i++){
        if(mask[i] == '1') newValue.push_back('1');
        if(mask[i] == 'X') newValue.push_back('0');
        if(mask[i] == '0') newValue.push_back(value[i]);
    }
    for(int i = 0; i < 36; i++) answer = 2*answer + newValue[i] - '0';
    return answer;
}

vector <long long> getAddresses(vector <int> positionsOfX, long long value)
{
    vector <long long> addresses;
    for(int i = 0; i < ((long)1<<positionsOfX.size()); i++){
        addresses.push_back(value);
        int ip = i;
        for(int j = 0; j < positionsOfX.size(); j++){
            if(ip % 2 == 1) addresses[i] += (long)1<<positionsOfX[j];
            ip /= 2;
        }
    }
    return addresses;
}

int main(){
    freopen("Puzzle_Input.txt", "r", stdin);
    string s;
    map <long long, long long> memory;
    string mask = "";
    while(getline(cin, s)){
        string address, ch, value;
        stringstream input(s);
        input >> address >> ch >> value;
        if(address == "mask"){
            mask = value;
            continue;
        }
        else {
            stringstream addressInput(address);
            while(getline(addressInput, address, '['));
            address.pop_back();
            string newValue = lltos2(address);
            vector <int> positionsOfX = getPosOfX(mask);
            long long answerValue = getValueAfterMask(mask, newValue);
            vector <long long> addresses = getAddresses(positionsOfX, answerValue);
            for(auto addr: addresses){
                memory[addr] = stoll(value);
            }
        }
    }
    long long answer = 0;
    for(auto x: memory) answer += x.second;
    cout << answer;
}
