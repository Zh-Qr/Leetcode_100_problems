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
    queue<TreeNode*> q;
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;
        q.push(root);
        int num;
        while(!q.empty()){
            int currentSize = q.size();
            for(int i=0;i<currentSize;i++){
                TreeNode* tmp = q.front();
                q.pop();
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
                num = tmp->val;
            }
            result.push_back(num);

        }
        return result;
    }
};

int main(void){
    cout<<"hello world! "<<endl;

    vector<int> nums = {1,NULL,3};
    TreeNode* root = insertLevelOrder(nums,0,nums.size());

    Solution sol;
    auto result = sol.rightSideView(root);
    for(auto it:result){
        cout<<it<<" ";
    }
}