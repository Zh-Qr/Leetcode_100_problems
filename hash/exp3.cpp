// 最长连续数列
#include<iostream>
#include<stdlib.h>
#include<map>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> map_set;
        for(int num:nums){
            map_set.insert(num);
        }

        int Maxcount = 0;
        for(int num :nums){
            int count = 1;
            if (map_set.count(num-1)==1)
            {
                continue;
            }
            while(map_set.count(++num)){
                count++;
            }

            if (count>Maxcount){
                Maxcount = count;
            }
        }
        return Maxcount;

    }
};


int main(void){
    cout<<"hello world!"<<endl;
    vector<int> nums = {100,4,200,1,3,2};
    Solution solution;
    int length = solution.longestConsecutive(nums);

    cout<<"the length is: "<<length<<endl;
}