#include<iostream>
#include<stdlib.h>
#include<vector>
#include<stack>
#include<unordered_map>
#include<map>
#include<queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        for(int i=0;i<numRows;i++){
            vector<int> cur(i+1,1);
            if(ans.empty()){
                ans.push_back(cur);
                continue;
            }
            vector<int> last = ans.back();
            int lastSize = last.size();
            for(int j=1;j<i;j++){
                cur[j] = last[j-1]+last[j];
            }
            ans.push_back(cur);
        }

        // cout<<cur[0];
        return ans;
    }
};

int main(){
    cout<<"hello world!"<<endl;

    int numRows = 1;

    Solution sol;
    auto result = sol.generate(numRows);
    for(auto group:result){
        for(auto it:group){
            cout<<it<<" ";
        }
        cout<<endl;
    }

}