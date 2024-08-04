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

class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root){
            return;
        }
        if(!root->left&&!root->right){
            return;
        }
        if(!root->left&&root->right){
            flatten(root->right);
        }
        if(root->left){
            TreeNode* tmp = root->right;
            root->right = root->left;
            root->left = nullptr;
            flatten(root->right);
            TreeNode* check = root->right;
            while(check->right){
                check = check->right;
            }
            check->right = tmp;
            flatten(check->right);
        }
    }
};

int main(void){
    cout<<"hello world! "<<endl;

    vector<int> nums = {1,2,5,3,4,NULL,6};
    TreeNode* root = insertLevelOrder(nums,0,nums.size());

    Solution sol;
    sol.flatten(root);
    while(root){
        cout<<root->val<<" ";
        root = root->right;
    }
}