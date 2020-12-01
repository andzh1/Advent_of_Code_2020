#include <bits/stdc++.h>
using namespace std;

int main(){
    int n = 200;
    long long input[n];
    for(int i = 0; i < n; i++) cin >> input[i];
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(input[i] + input[j] == 2020){
                cout << input[i]*input[j];
                break;
            }
        }
    }    
}