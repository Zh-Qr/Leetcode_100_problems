#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         map<int,int> map;
//         for(int i=0;i<nums.size();i++){
//             map[nums[i]] = i;
//         }
//         vector<vector<int>> result;
//         for(int i=0;i<nums.size();i++){
//             for(int j=i+1;j<nums.size();j++){
//                 if (map.count(0-i-j)==0)
//                 {
//                     continue;
//                 }
//                 else{
//                     if (map[-(nums[i] + nums[j])]!=i && map[-(nums[i] + nums[j])]!=j)
//                     {
//                         result.push_back({i,j,map[-i-j]});
//                     }
                    
//                 }
                
//             }
//         }
//         return result;
//     }
// };

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> result;
//         sort(nums.begin(), nums.end());
        
//         for (int i = 0; i < nums.size(); ++i) {
//             if (i > 0 && nums[i] == nums[i-1]) continue;
            
//             int left = i + 1;
//             int right = nums.size() - 1;
            
//             while (left < right) {
//                 int sum = nums[i] + nums[left] + nums[right];
                
//                 if (sum == 0) {
//                     result.push_back({nums[i], nums[left], nums[right]});
                    
//                     while (left < right && nums[left] == nums[left + 1]) ++left;
//                     while (left < right && nums[right] == nums[right - 1]) --right;
                    
//                     ++left;
//                     --right;
//                 } else if (sum < 0) {
//                     ++left;
//                 } else {
//                     --right;
//                 }
//             }
//         }
        
//         return result;
//     }
// };

class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i+1;
            int right = nums.size()-1;

            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                
                
                if(sum == 0){
                    result.push_back({nums[i],nums[left],nums[right]});
                    while (left < right &&nums[left] == nums[left+1])
                {
                    left++;
                }
            
                
                while (left < right &&nums[right] == nums[right-1])
                {
                    right--;
                }
                    left++;
                    right--;
                }
                if (sum<0)
                {
                    left++;
                }
                if (sum>0){
                    right--;
                }
                              
            }
                        
        }
        return result;
        
    }

};



int main(void){
    cout<<"hello world"<<endl;

    vector<int> nums = {-1,0,1,2,-1,-4};
    Solution solution;
    vector<vector<int>> result;
    result = solution.threeSum(nums);
    for (const auto& trip : result) {
        for (int num : trip) {
            cout << num << " ";
        }
        cout << endl;
    }

    cout<<"hello world"<<endl;

}