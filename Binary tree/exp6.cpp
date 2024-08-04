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
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector <vector <int>> ret;
//         if (!root) {
//             return ret;
//         }

//         queue <TreeNode*> q;
//         q.push(root);
//         while (!q.empty()) {
//             int currentLevelSize = q.size();
//             ret.push_back(vector <int> ());
//             for (int i = 1; i <= currentLevelSize; ++i) {
//                 auto node = q.front(); q.pop();
//                 ret.back().push_back(node->val);
//                 if (node->left) q.push(node->left);
//                 if (node->right) q.push(node->right);
//             }
//         }
        
//         return ret;
//     }
// };

class Solution{
public:
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
};

int main(void){
    cout<<"hello world! "<<endl;
    vector<int> nums = {3,9,20,NULL,NULL,15,7};
    TreeNode* root = insertLevelOrder(nums,0,nums.size());

    Solution solution;
    auto result = solution.levelOrder(root);

    for(auto it:result){
        for(auto it2: it){
            cout<<it2<<" ";
        }
        cout<<endl;
    }
}