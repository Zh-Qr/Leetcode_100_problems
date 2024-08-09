#include<iostream>
#include<stdlib.h>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n,0);
        stack<int> save;
        for(int i = 0;i<n;i++){
            if(save.empty()){
                save.push(i);
                continue;
            }else if(temperatures[save.top()]<temperatures[i]){
                while(!save.empty() && temperatures[save.top()]<temperatures[i]&&!save.empty()){
                    ans[save.top()] = i-save.top();
                    save.pop();
                }
                save.push(i);
            }
            else{
                save.push(i);
            }
        }
        return ans;
    }
};

int main(){
    cout<<"hello world!"<<endl;
    vector<int> temperatures = {73,74,75,71,69,72,76,73};

    Solution sol;

    auto result = sol.dailyTemperatures(temperatures);
    for (int temp : result) {
        cout << temp << " ";
    }
    cout << endl;
}