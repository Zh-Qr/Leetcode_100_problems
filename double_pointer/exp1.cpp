#include<iostream>
#include<stdlib.h>
#include<vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(auto it1=nums.begin();it1!=nums.end();++it1){
            if (*it1==0)
            {
                for (auto it2 = it1+1; it2!=nums.end() ; ++it2)
                {
                    if (*it2!=0)
                    {
                        int tmp = *it1;
                        *it1 = *it2;
                        *it2 = tmp;
                        break;
                    }
                    
                }
                
            }
            
        }

    }
};

int main(void){

    vector<int> nums = {0,1,0,3,12};
    Solution solution;
    solution.moveZeroes(nums);
    for(int num:nums){
        cout<<num<<" "<<endl;
    }
    cout<<"hello world"<<endl;
}