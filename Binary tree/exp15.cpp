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


//层次遍历读取
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if(!root){
        return result;
    }
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int currentLevelSize = q.size();
        result.push_back(vector<int>());
        for(int i=0;i<currentLevelSize;i++){
            auto node = q.front();//取出队列头
            q.pop();
            result.back().push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
    return result;
}

class Solution {
private:
    int maxPathSum(TreeNode* root, int &val){
        if(root==nullptr) return 0;
        int left = max(0,maxPathSum(root->left,val));
        int right = max(0,maxPathSum(root->right,val));

        int lmr = root->val+left+right;
        int ret = root->val+max(left,right);
        // val = max(val,max(left,right));
        val = max(val,ret);
        val = max(val,lmr);
        return ret;
    }
public:
    int maxPathSum(TreeNode* root) {
        int val = INT_MIN;
        maxPathSum(root,val);
        return val;
    }
};

int main(void){
    cout<<"hello world! "<<endl;
    vector<int> nums = {-3};
    TreeNode* root = insertLevelOrder(nums,0,nums.size());

    Solution sol;
    int result = sol.maxPathSum(root);
    cout<<"result: "<<result;
}