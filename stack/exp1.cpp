#include<iostream>
#include<stdlib.h>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> pairs = {
                {')', '('},
                {']', '['},
                {'}', '{'}
            };
    for(char ch:s){
        if(pairs.count(ch)){
            if(stk.empty()||stk.top()!=pairs[ch]){
                return false;
            }
            stk.pop();
        }
        else{
            stk.push(ch);
        }
    }
    return stk.empty();

    }
};

int main(){
    cout<<"hello world!"<<endl;
    string s = "()[]{}";

    Solution sol;
    bool result = sol.isValid(s);
    if(result){
        cout<<"success";
    }
    else{
        cout<<"error";
    }
}