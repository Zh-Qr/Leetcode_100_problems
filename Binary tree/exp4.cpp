#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// class Solution {
// public:
//     bool check(TreeNode *p, TreeNode *q) {
//         if (!p && !q) return true;
//         if (!p || !q) return false;
//         return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
//     }

//     bool isSymmetric(TreeNode* root) {
//         return check(root, root);
//     }
// };

class Solution {
public:
    bool check(TreeNode* p, TreeNode* q){
        if(!p&&!q) return true;
        if(!p||!q) return false;
        return p->val == q->val && check(p->left,q->right) && check(p->right,q->left);
    }
    bool isSymmetric(TreeNode* root) {
        return check(root,root);
    }
};



int main(void){
    cout<<"hello world! "<<endl;
}