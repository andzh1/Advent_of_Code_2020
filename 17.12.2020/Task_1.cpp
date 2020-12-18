#include <bits/stdc++.h>
using namespace std;

const int amountOfCycles = 6;
const int lengthOfInput = 8;
const int widthOfConfiguration = lengthOfInput + 2*amountOfCycles;
const string shift(amountOfCycles, '.');
const string dots(widthOfConfiguration, '.');

bool isAvaliable(int i, int j, int k){
    if(i < 0 || j < 0 || k < 0) return false;
    if(i > amountOfCycles || j >= widthOfConfiguration || k >= widthOfConfiguration) return false;
    return true;
}
int amountOfNeighbors(vector <string> input[], int y, int x, int z){
    int height = 3;
    int answer = 0;
    // if(y == amountOfCycles) height = 2;
    for(int dy = 2 - height; dy <= 1; dy++){
        for(int dx = -1; dx <= 1; dx++){
            for(int dz = -1; dz <= 1; dz++){
                if(dx == 0 && dy == 0 && dz == 0) continue;
                if(isAvaliable(y + dy, x + dx, z + dz)) {
                    answer += input[y + dy][x + dx][z + dz] == '#';
                }
            }
        }
    }
    return answer;
}

int amountOfNeighborsFor0floor(vector <string> input[], int x, int z){
    int answer = 0;
    for(int dy = 0; dy <= 1; dy++){
        for(int dx = -1; dx <= 1; dx++){
            for(int dz = -1; dz <= 1; dz++){
                if(dx == 0 && dy == 0 && dz == 0) continue;
                if(isAvaliable(dy, x + dx, z + dz)) {
                    answer += input[dy][x + dx][z + dz] == '#';
                    if(dy == 1) answer += input[dy][x + dx][z + dz] == '#';
                }
            }
        }
    }
    return answer;
}

int operation(vector <string> input[], int numberOfOperation){
    if(numberOfOperation == 0){
        int answer = 0;
        for(int i = 0; i <= amountOfCycles; i++){
            for(int j = 0; j < widthOfConfiguration; j++){
                for(int k = 0; k < widthOfConfiguration; k++){
                    answer += input[i][j][k] == '#';
                    if(i > 0) answer += input[i][j][k] == '#';
                }
            }
        }
        return answer;
    }
    else
    {
        vector <string> output[amountOfCycles + 1];
        for(int i = 0; i <= amountOfCycles; i++){
            for(int j = 0; j < widthOfConfiguration; j++) 
                output[i].push_back(dots);
        }
        for(int i = 1; i <= amountOfCycles - numberOfOperation+1; i++){
            for(int j = 0; j < widthOfConfiguration; j++){
                for(int k = 0; k < widthOfConfiguration; k++){
                    int neighbours = amountOfNeighbors(input, i, j, k);
                    char current = input[i][j][k];
                    if(current == '.'){
                        if(neighbours == 3) output[i][j][k] = '#';
                        else output[i][j][k] = '.';
                    }
                    else if(current == '#'){
                        if(neighbours == 2 || neighbours == 3) output[i][j][k] = '#';
                        else output[i][j][k] = '.';
                    }
                }
            }
        }
        for(int j = 0; j < widthOfConfiguration; j++){
                for(int k = 0; k < widthOfConfiguration; k++){
                    int neighbours = amountOfNeighborsFor0floor(input, j, k);
                    char current = input[0][j][k];
                    if(current == '.'){
                        if(neighbours == 3) output[0][j][k] = '#';
                        else output[0][j][k] = '.';
                    }
                    else if(current == '#'){
                        if(neighbours == 2 || neighbours == 3) output[0][j][k] = '#';
                        else output[0][j][k] = '.';
                    }
                }
            }
        return operation(output, numberOfOperation-1);
    }
    
}

int main(){
    freopen("Puzzle_Input.txt", "r", stdin);
    string s(lengthOfInput + 2*amountOfCycles, '.');
    vector <string> input[amountOfCycles + 1];
    for(int i = 0; i <= amountOfCycles; i++){
        for(int j = 0; j < widthOfConfiguration; j++) 
            input[i].push_back(s);
    }
    for(int i = 0; i < lengthOfInput; i++){
        cin >> s;
        input[0][amountOfCycles+i] = shift + s + shift;
    }
    int answer = operation(input, amountOfCycles);
    cout << answer;
}