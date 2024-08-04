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
private:
    vector<int> order;
    void getOrder(TreeNode* root){
        if(!root){
            return;
        }
        if(root->left) getOrder(root->left);
        order.push_back(root->val);
        if(root->right) getOrder(root->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        getOrder(root);
        return order[k-1];

    }
};


int main(void){
    cout<<"hello world! "<<endl;
    int k = 1;
    vector<int> nums = {3,1,4,NULL,2};
    TreeNode* root = insertLevelOrder(nums,0,nums.size());

    Solution solution;
    int result = solution.kthSmallest(root,k);
    cout<<"result: "<<result;
}