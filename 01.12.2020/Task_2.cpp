#include <bits/stdc++.h>
using namespace std;

int main(){
    int n = 200;
    long long input[n];
    for(int i = 0; i < n; i++) cin >> input[i];
    for(int i = 0; i < n - 2; i++){
        for(int j = i + 1; j < n-1; j++){
                for(int k = j + 1; k < n; k++){
                    if(input[i] + input[j] + input[k] == 2020){
                    cout << input[i]*input[j]*input[k];
                    break;
                }
            }
        }
    } 
}