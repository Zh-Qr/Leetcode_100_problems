#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<algorithm>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* makeTree(vector<int>& nums, int left, int right) {
        if(left>right){
            return nullptr;
        }
        int middle = (left+right)/2;
        TreeNode* root = new TreeNode(nums[middle]);
        root->left = makeTree(nums,left,middle-1);
        root->right = makeTree(nums,middle+1,right);
        return root;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return makeTree(nums,0,nums.size()-1);

    }
};

// class Solution {
// public:
//     TreeNode* sortedArrayToBST(vector<int>& nums) {
//         return helper(nums, 0, nums.size() - 1);
//     }

//     TreeNode* helper(vector<int>& nums, int left, int right) {
//         if (left > right) {
//             return nullptr;
//         }

//         // 总是选择中间位置左边的数字作为根节点
//         int mid = (left + right) / 2;

//         TreeNode* root = new TreeNode(nums[mid]);
//         root->left = helper(nums, left, mid - 1);
//         root->right = helper(nums, mid + 1, right);
//         return root;
//     }
// };

int main(void){
    cout<<"hello world! "<<endl;
    vector<int> nums = {-10,-3,0,5,9};
}