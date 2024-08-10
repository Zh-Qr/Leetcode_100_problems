#include<iostream>
#include<stdlib.h>
#include<vector>
#include<stack>
#include<unordered_map>
#include<map>
#include<queue>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        long ans = INT_MIN;
        vector<long> db_max(len,1);
        vector<long> db_min(len,1);
        for(int i=0;i<len;i++){
            if(i==0){
                db_max[i] = nums[i];
                db_min[i] = nums[i];
                ans = db_max[i];
                continue;
            }
            db_max[i] = max(db_max[i-1]*long(nums[i]),max(long(nums[i]), db_min[i-1]*nums[i]));

            db_min[i] = min(db_min[i-1]*long(nums[i]),min(long(nums[i]),db_max[i-1]*long(nums[i])));

            if(db_min[i]<INT_MIN) {
                db_min[i]=nums[i];
            }

            ans = max(ans,long(db_max[i]));
        }
        return ans;

    }
};

// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int len = nums.size();
//         int ans = INT_MIN;
//         vector<int> db_max(len,1);
//         vector<int> db_min(len,1);
//         for(int i=0;i<len;i++){
//             if(i==0){
//                 db_max[i] = nums[i];
//                 db_min[i] = nums[i];
//                 ans = db_max[i];
//                 continue;
//             }
//             db_max[i] = max(db_max[i-1]*nums[i],nums[i]);
//             db_max[i] = max(db_min[i-1]*nums[i],db_max[i]);

//             db_min[i] = min(db_min[i-1]*nums[i],nums[i]);
//             db_min[i] = min(db_max[i-1]*nums[i],db_min[i]);

//             ans = max(ans,db_max[i]);
//         }
//         return ans;

//     }
// };

// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         vector <long> maxF(nums.begin(),nums.end()), minF(nums.begin(), nums.end());
//         for (int i = 1; i < nums.size(); ++i) {
//             maxF[i] = max(maxF[i - 1] * nums[i], max((long)nums[i], minF[i - 1] * nums[i]));
//             minF[i] = min(minF[i - 1] * nums[i], min((long)nums[i], maxF[i - 1] * nums[i]));
//             if(minF[i]<INT_MIN) {
//                 minF[i]=nums[i];
//             }
//         }
//         return *max_element(maxF.begin(), maxF.end());
//     }
// };

int main(){
    cout<<"hello world!"<<endl;

    vector<int> nums = {2,-5,-2,-4,3};

    Solution sol;
    auto result = sol.maxProduct(nums);
    cout<<"result: "<<result<<endl;
}