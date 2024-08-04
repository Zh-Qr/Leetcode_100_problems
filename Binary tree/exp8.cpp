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

//层次遍历插入
TreeNode* insertLevelOrder(vector<int>& elements, int i, int n) {
    if (elements[i]!=NULL && i < n) {
        TreeNode* temp = new TreeNode(elements[i]);
        temp->left = insertLevelOrder(elements, 2 * i + 1, n);
        temp->right = insertLevelOrder(elements, 2 * i + 2, n);
        return temp;
    }
    return nullptr;
}

// class Solution {
// public:
//     bool isValidBST(TreeNode* root) {
//         if(root==NULL){
//             return true;
//         }
//         bool left = true;
//         bool right = true;
//         if(root->left && root->val>root->left->val){
//             left = isValidBST(root->left);
//         }
//         else{
//             if(root->left){
//                 return false;
//             }
//         }
//         if(root->right && root->val<root->right->val){
//             right = isValidBST(root->right);
//         }
//         else{
//             if(root->right){
//                 return false;
//             }
//         }

//         return left&&right;
//     }
// };

class Solution {
private:
    vector<int> save;
    void saveNum(TreeNode* root){
        if(root){
            saveNum(root->left);
            save.push_back(root->val);
            saveNum(root->right);
        }
    }
public:
    bool isValidBST(TreeNode* root) {
        saveNum(root);
        for(int i=0;i<save.size()-1;i++){
            if(save[i]>=save[i+1]){
                return false;
            }
        }
        return true;
    }
        
};

int main(void){
    cout<<"hello world! "<<endl;

    vector<int> nums = {5,4,6,NULL,NULL,3,7};
    TreeNode* root = insertLevelOrder(nums,0,nums.size());

    Solution solution;
    auto result = solution.isValidBST(root);

    if(result){
        cout<<"True"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
}