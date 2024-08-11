#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<algorithm>
#include<queue>
#include<cstring>
#include<stack>

using namespace std;

class Solution {
public:
    int binary_search(vector<int>& nums, int target,int first, int last){
        int middle = (last+first)/2;
        if(first == last){
            if(nums[first]>target){
                return first;
            }
            if(nums[first]<target){
                return first+1;
            }
        }
        int middle_num = nums[middle];
        if(middle_num == target){
            return middle;
        }
        if(middle_num<target){
            return binary_search(nums, target, middle+1,last);
        }
        if(middle_num>target){
            return binary_search(nums, target, first,middle);
        }
        return -1;
    }
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0) return 0;
        return binary_search(nums,target,0,nums.size()-1);

    }
};

int main(void){
    cout<<"hello world!"<<endl;
    vector<int> nums = {1,3,5,6};
    int target = 2;

    Solution sol;
    int result = sol.searchInsert(nums, target);
    cout<<"result: "<<result;
}