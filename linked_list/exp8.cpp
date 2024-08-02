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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy;
        ListNode* p = &dummy;
        p->next = head;
        int len = 0;
        while(p->next){
            len++;
            p = p->next;
        }
        int cnt = len-n;
        p = &dummy;
        while(cnt){
            p = p->next;
            cnt--;
        }
        p->next = p->next->next;
        return dummy.next;

    }
};

int main(void){
    cout<<"hello world! "<<endl;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    int n = 2;

    Solution solution;
    auto result = solution.removeNthFromEnd(head,n);

    while(result){
        cout<<result->val<<" ";
        result = result->next;
    }
}