#include <bits/stdc++.h>
using namespace std;

long long EulersFunction(long long n) // Returns amount of numbers x from 1 to n and gcd(x, n) = 1
{
    long long result = n;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

typedef long long intType; //mb long int or long long required

intType modpow(intType x, intType power, intType module) // Returns (x^power) % module
{
    if(power == 0) return 1%module;
    if(power % 2 == 0) return modpow(x, power/2, module)*modpow(x, power/2, module)%module;
    if(power % 2 == 1) return x * modpow(x, power - 1, module) % module;
}

intType inverceNumber(intType inputNumber, intType module) // Returns X that X * inputNumber % module = 1
{
    return modpow(inputNumber, EulersFunction(module) - 1, module) % module;
}

long long ChineseRemainerTheorem(vector <pair <intType, intType>> equations){
    long long answer = 0;
    long long X = 1;
    for(auto eq: equations) X *= eq.second;
    for(auto eq: equations) {
        long long Ai = eq.first, Mi = eq.second;
        answer += Ai * (X/Mi) * inverceNumber(X/Mi, Mi);
    }
    return answer % X;
}

int main(){
    freopen("Puzzle_Input.txt", "r", stdin);
    int n;
    cin >> n;
    string s;
    cin >> s;
    cin >> s;
    stringstream input(s);
    vector <string> tokens;
    while(getline(input, s, ',')) tokens.push_back(s);
    int length = tokens.size();
    vector <pair <intType, intType>> equationsForCRT; //CRT = Chinese Remainers Theorem 
    for(int i = 0; i < length; i++){
        if(tokens[i] != "x") {
            int mod = stoll(tokens[i]);
            equationsForCRT.push_back({(mod - i%mod)%mod, mod});
        }
    }
    long long answer = ChineseRemainerTheorem(equationsForCRT);
    cout << answer;
} 