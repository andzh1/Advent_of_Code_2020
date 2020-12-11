#include <bits/stdc++.h>
using namespace std;

bool isAvavliable(int a, int b, int maxA, int maxB){
    return (a < maxA && a >= 0 && b < maxB && b >= 0);
}

vector <string> operation(vector <string> input){
    int length = input[0].length();
    vector <string> output;
    for(int i = 0; i < input.size(); i++){
        for(int j = 0; j < length; j++){
            if(j == 0) output.push_back("");
            int counter = 0, x, y;
            bool seeSeat = false;
            if(input[i][j] != '.'){
                y = i-1; x = j-1;
                while(isAvavliable(y, x, input.size(), length)) {
                    if(input[y][x] != '.') {counter += input[y][x] == '#'; break;}
                    x--; y--;
                }
                y = i; x = j-1;
                while(isAvavliable(y, x, input.size(), length)) {
                    if(input[y][x] != '.') {counter += input[y][x] == '#'; break;}
                    x--;
                }
                y = i+1; x = j-1;
                while(isAvavliable(y, x, input.size(), length)) {
                    if(input[y][x] != '.') {counter += input[y][x] == '#'; break;}
                    x-- ; y++ ;
                }
                y = i+1; x = j;
                while(isAvavliable(y, x, input.size(), length)) {
                    if(input[y][x] != '.') {counter += input[y][x] == '#'; break;}
                    y++ ;
                }
                y = i+1; x = j+1;
                while(isAvavliable(y, x, input.size(), length)) {
                    if(input[y][x] != '.') {counter += input[y][x] == '#'; break;}
                    x++ ; y++ ;
                }
                y = i; x = j+1;
                while(isAvavliable(y, x, input.size(), length)) {
                    if(input[y][x] != '.') {counter += input[y][x] == '#'; break;}
                    x++ ; 
                }
                y = i-1; x = j+1;
                while(isAvavliable(y, x, input.size(), length)) {
                    if(input[y][x] != '.') {counter += input[y][x] == '#'; break;}
                    x++ ; y-- ;
                }
                y = i-1; x = j;
                while(isAvavliable(y, x, input.size(), length)) {
                    if(input[y][x] != '.') {
                        counter += input[y][x] == '#';
                        break;
                    }
                    y-- ;
                }
                if((counter == 0 && input[i][j] == 'L')) output[i] += '#';
                else if((counter >= 5 && input[i][j] == '#')) output[i] += 'L';
                else output[i] += input[i][j];
            }
            else output[i] += '.';
        }
    }
    return output;
}

bool areEqual(vector <string> input1, vector <string> input2){
    bool answer = true;
    for(int i = 0; i < input1.size(); i++){
        if(input1[i] != input2[i]) answer = false;
    }
    return answer;
}

int main(){
    freopen("Puzzle_Input.txt", "r", stdin);
    string inputString;
    vector <string> input;
    vector <string> output;
    while(getline(cin, inputString)) input.push_back(inputString);
    bool equal = false;
    while(!equal) {
        output = operation(input);
        equal = areEqual(input, output);
        input = output;
    }
    int answer = 0;
    for(auto x: input){
        for(int i = 0; i < x.length(); i++) answer += x[i] == '#';
    }
    cout << answer;
}