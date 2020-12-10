#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("Puzzle_Input.txt", "r", stdin);
    string s;
    vector <int> input;
    input.push_back(0);
    while(cin >> s) input.push_back(stoi(s));
    sort(input.begin(), input.end());
    int dif1 = 0, dif3 = 1;
    for(int i = 1; i < input.size(); i++){
        if(input[i] - input[i-1] == 1) dif1 ++;
        if(input[i] - input[i-1] == 3) dif3 ++;
    }
    cout << dif1*dif3;
}