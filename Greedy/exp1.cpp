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
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for(int i = 0;i<prices.size();i++){
            if(maxProfit<prices[i] - minPrice){
                maxProfit = prices[i] - minPrice;
            }
            if(prices[i]<minPrice){
                minPrice = prices[i];
                continue;
            }
        }
        return maxProfit;
    }
};

int main(){
    cout<<"hello world!"<<endl;
    vector<int> nums = {7,1,5,3,6,4};

    Solution sol;
    int result = sol.maxProfit(nums);
    cout<<"result: "<<result;
}