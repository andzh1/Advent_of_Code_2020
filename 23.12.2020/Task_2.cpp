#include <bits/stdc++.h>
using namespace std;

const int amountOfCups = 1000000;
const int lengthOfGivenLabels = 9;

int getDistinition(int pickup[], int start){
    int possibleReturns[4];
    for(int i = 1; i <= 4; i++){
        if(start - i > 0) possibleReturns[i-1] = start - i;
        else possibleReturns[i-1] = amountOfCups - i + 1;
    }
    for(int i = 0; i < 4; i++){
        bool exists = true;
        for(int j = 0; j < 3; j++)
            if(pickup[j] == possibleReturns[i]) exists = false;
        if(exists) return possibleReturns[i];
    }
}

int main(){
    string inputFile = "716892543";
    int nextCups[amountOfCups+1];
    for(int i = 1; i < lengthOfGivenLabels; i++) nextCups[inputFile[i-1] - '0'] = inputFile[i] - '0';
    nextCups[inputFile[lengthOfGivenLabels - 1] - '0'] = lengthOfGivenLabels + 1;
    for(int i = lengthOfGivenLabels + 1; i < amountOfCups; i++) nextCups[i] = i+1;
    nextCups[amountOfCups] = inputFile[0] - '0';
    int start = inputFile[0] - '0';
    int amountOfMoves = 10000000;
    while(amountOfMoves--){
        int pickup[3];
        pickup[0] = nextCups[start];
        pickup[1] = nextCups[pickup[0]];
        pickup[2] = nextCups[pickup[1]];
        int destinition = getDistinition(pickup, start);
        nextCups[start] = nextCups[pickup[2]];
        nextCups[pickup[2]] = nextCups[destinition];
        nextCups[destinition] = pickup[0];
        start = nextCups[start];
    }
    int firstStar = nextCups[1];
    int secondStar = nextCups[firstStar];
    long long answer = (long long)firstStar * (long long)secondStar;
    cout << answer;

}