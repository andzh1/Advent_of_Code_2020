#include <bits/stdc++.h>
using namespace std;

string ltos(long input){
    string preanswer;
    while(input > 0){
        preanswer += input%10 + '0';
        input /= 10;
    }
    string answer;
    for(int i = preanswer.length() - 1; i >= 0; i--) answer.push_back(preanswer[i]);
    return answer;
}

bool containsParentheses(string input){
    for(int i = 0;  i < input.length(); i++) if(input[i] == '(') return true;
    return false;
}

string oldcount(string input){
    stringstream operations(input);
    vector <string> expression;
    string s;
    while(operations >> s) expression.push_back(s);
    long answer = stol(expression[0]);
    for(int i = 1; i < expression.size(); i += 2){
        string operation = expression[i];
        long value = stol(expression[i+1]);
        answer += value;
    }
    return ltos(answer);
}   

string newcount(string input){
    stringstream operations(input);
    vector <string> expression;
    string s;
    while(getline(operations, s, '*')) expression.push_back(s);
    long answer = stol(oldcount(expression[0]));
    for(int i = 1; i < expression.size(); i ++){
        long value = stol(oldcount(expression[i]));
        answer *= value;
    }
    return ltos(answer);
}   

string calculator(string input){
    string newExpression = "";
    int parenthesesDifference = 0, ip = 0;
    if(!containsParentheses(input)) return newcount(input);
    while(input[ip] != '(' && ip < input.length()) ip++;
    if(ip > 0 && ip < input.length()) {
        newExpression += ((input.substr(0, ip)));
    }
    for(int i = ip; i < input.length(); i++){
        if(input[i] == '(') parenthesesDifference++;
        if(input[i] == ')') parenthesesDifference--;
        if(parenthesesDifference == 0) {
            string betweenParentheses = input.substr(ip+1, i - ip - 1);
            ip = i + 1;
            newExpression += newcount(calculator(betweenParentheses));
            if(ip + 1 < input.length()) {
                newExpression += input.substr(ip);
            }
            break;
        }
    }
    return calculator(newExpression);
}

int main(){
    freopen("Puzzle_Input.txt", "r", stdin);
    string s;
    long long answer = 0;
    while(getline(cin, s)){
        answer += stol(calculator(s));
    }
    cout << answer;
}