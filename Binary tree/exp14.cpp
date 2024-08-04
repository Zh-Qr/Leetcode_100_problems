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

//找到最近公共祖先
class Solution {
public:
    TreeNode* ans;//返回结果
    //判读root是否是p和q的共同祖先
    bool dfs(TreeNode* root, TreeNode* p, TreeNode*q){
        if(root==nullptr) return false;
        bool lson = dfs(root->left,p,q);//测试左子树
        bool rson = dfs(root->right,p,q);//测试右子树
        if ((lson && rson) || ((root->val == p->val || root->val == q->val) && (lson || rson))) {
            ans = root;
        }
        return lson||rson||(root->val==p->val||root->val==q->val);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root,p,q);
        return ans;
        
    }
};

int main(void){
    cout<<"hello world! "<<endl;
    vector<int> nums = {3,5,1,6,2,0,8,NULL,NULL,7,4};
    TreeNode* root = insertLevelOrder(nums,0,nums.size());


}