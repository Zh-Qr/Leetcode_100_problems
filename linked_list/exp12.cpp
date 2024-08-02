#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
    ListNode dummy;
    ListNode* p = &dummy;
    p->next = head;
    map<int, vector<ListNode*>> mp;  // 使用 vector 存储相同值的节点
    while (p->next) {
        mp[p->next->val].push_back(p->next);
        p = p->next;
    }
    p = &dummy;
    for (auto& it : mp) {
        for (ListNode* node : it.second) {
            p->next = node;
            p = p->next;
        }
    }
    p->next = nullptr;

    return dummy.next;
}
};


int main(void){
    cout<<"hello world! "<<endl;
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    Solution solution;
    auto result = solution.sortList(head);

    while(result){
        cout<<result->val<<" ";
        result = result->next;
    }
}