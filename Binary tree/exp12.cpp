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
//     unordered_map<int, int> index;

// public:
//     TreeNode* myBuildTree(const vector<int>& preorder, const vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
//         if (preorder_left > preorder_right) {
//             return nullptr;
//         }
        
//         // 前序遍历中的第一个节点就是根节点
//         int preorder_root = preorder_left;
//         // 在中序遍历中定位根节点
//         int inorder_root = index[preorder[preorder_root]];
        
//         // 先把根节点建立出来
//         TreeNode* root = new TreeNode(preorder[preorder_root]);
//         // 得到左子树中的节点数目
//         int size_left_subtree = inorder_root - inorder_left;
//         // 递归地构造左子树，并连接到根节点
//         // 先序遍历中「从 左边界+1 开始的 size_left_subtree」个元素就对应了中序遍历中「从 左边界 开始到 根节点定位-1」的元素
//         root->left = myBuildTree(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree, inorder_left, inorder_root - 1);
//         // 递归地构造右子树，并连接到根节点
//         // 先序遍历中「从 左边界+1+左子树节点数目 开始到 右边界」的元素就对应了中序遍历中「从 根节点定位+1 到 右边界」的元素
//         root->right = myBuildTree(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right);
//         return root;
//     }

//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         int n = preorder.size();
//         // 构造哈希映射，帮助我们快速定位根节点
//         for (int i = 0; i < n; ++i) {
//             index[inorder[i]] = i;
//         }
//         return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
//     }
// };

class Solution{
private:
    unordered_map<int,int> index;
public:
    TreeNode* makeTree(const vector<int>& preorder, const vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right){
        if(preorder_left>preorder_right){
            return nullptr;
        }

        //前序遍历第一个节点
        int preorder_root = preorder_left;
        int inorder_root = index[preorder[preorder_root]];

        //建立根节点
        TreeNode* root = new TreeNode(preorder[preorder_root]);
        //左子树节点个数
        int size_left_subTree = inorder_root - inorder_left;
        root->left = makeTree(preorder,inorder,preorder_left+1,preorder_left+size_left_subTree,inorder_left,inorder_root-1);
        root->right = makeTree(preorder,inorder,preorder_left+size_left_subTree+1,preorder_right,inorder_root+1,inorder_right);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i=0;i<n;i++){
            index[inorder[i]] = i;
        }

        return makeTree(preorder,inorder,0,n-1,0,n-1);

    }
};


int main(void){
    cout<<"hello world! "<<endl;
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode* root = new TreeNode();
    
    Solution sol;
    root = sol.buildTree(preorder,inorder);

    auto result = levelOrder(root);

    for(auto it:result){
        for(auto it2: it){
            cout<<it2<<" ";
        }
        cout<<endl;
    }
}
