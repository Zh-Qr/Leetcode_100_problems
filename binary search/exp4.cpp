#include<iostream>
#include<stdlib.h>
#include<vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(!n) return -1;
        if(n==1){
            return target == nums[0]?0:-1;
        }
        int l=0, r=n-1;

        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid]==target) return mid;
            if(nums[0]<=nums[mid]){
                if(nums[0]<=target&&target<nums[mid]){
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
            else{
                if(nums[mid]<target&&target<=nums[n-1]){
                    l = mid+1;
                }
                else{
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main(){
    cout<<"hello world!"<<endl;
    int arr[] = {4,5,6,7,0,1,2};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));

    int target = 0;

    Solution sol;
    int result = sol.search(nums,target);
    cout<<"result: "<<result;
}