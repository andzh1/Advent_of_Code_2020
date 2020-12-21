#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("Puzzle_Input.txt", "r", stdin);
    map <string, set <string>> canContain;
    string food;
    set <string> allAllergens;
    multiset <string> allIngridients;
    int counter = 0;
    while(getline(cin, food))
    {   
        counter ++;
        if(counter == 34){
            counter = 34;
        }
        
        stringstream input(food); 
        vector <string> allergens;
        set <string> ingridients;
        string s;
        set <string> newContains;
        while(input >> s){
            if(s == "(contains") break;
            ingridients.insert(s);
            allIngridients.insert(s);
        }
        while(input >> s){
            s.pop_back();
            allergens.push_back(s);
            allAllergens.insert(s);
        }
        for(auto a: allergens){
            newContains.clear();
            if(canContain[a].size() == 0){
                for(auto i: ingridients) canContain[a].insert(i);
            }
            else 
            {
                for(auto i: ingridients){
                    if(canContain[a].count(i)) newContains.insert(i);
                }
                canContain[a] = newContains;
            }
        }
    }
    int answer = allIngridients.size();
    int amountOfUnprocessedAllergens = allAllergens.size();
    while(amountOfUnprocessedAllergens > 0){
        string currentIngridient;
        for(auto allergen: allAllergens){
            if(canContain[allergen].size() == 1) {
                currentIngridient = *canContain[allergen].begin();
                break;
            }
        }
        answer -= allIngridients.count(currentIngridient);
        for(auto allergen: allAllergens){
            if(canContain[allergen].count(currentIngridient)) {
                canContain[allergen].erase(currentIngridient);
            }
        }
        amountOfUnprocessedAllergens --;
    }
    cout << answer;
}