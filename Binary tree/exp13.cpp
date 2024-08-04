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

// class Solution {
// private:
//     int rootSum(TreeNode* root, int targetSum){
//         if(!root) return 0;
//         int ret = 0;
//         if(root->val == targetSum){
//             ret++;
//         }

//         ret += rootSum(root->left,targetSum - root->val) ;
//         ret += rootSum(root->right,targetSum - root->val);

//         return ret;
//     }
// public:
//     int pathSum(TreeNode* root, int targetSum) {
//         if(!root) return 0;
//         int ret = rootSum(root,targetSum);
//         ret += rootSum(root->left,targetSum);
//         ret += rootSum(root->right,targetSum);

//         return ret;
//     }
// };

class Solution {
public:
    unordered_map<long long, int> prefix;

    int dfs(TreeNode *root, long long curr, int targetSum) {
        if (!root) {
            return 0;
        }

        int ret = 0;
        curr += root->val;
        if (prefix.count(curr - targetSum)) {
            ret = prefix[curr - targetSum];
        }

        prefix[curr]++;
        ret += dfs(root->left, curr, targetSum);
        ret += dfs(root->right, curr, targetSum);
        prefix[curr]--;

        return ret;
    }

    int pathSum(TreeNode* root, int targetSum) {
        prefix[0] = 1;
        return dfs(root, 0, targetSum);
    }
};

int main(void){
    cout<<"hello world! "<<endl;
}