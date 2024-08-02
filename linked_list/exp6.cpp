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
    ListNode(int x) : val(x), next(NULL) {}
    ListNode() : val(0), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 创建一个哨兵节点
        ListNode dummy;
        ListNode* p = &dummy;


        while(list1||list2){
            if(!list1){
                p->next = list2;
                break;
            }
            if(!list2){
                p->next = list1;
                break;
            }

            if(list1->val>list2->val){
                p->next = list2;
                list2 = list2->next;
                p = p->next;
            }
            else{
                p->next = list1;
                list1 = list1->next;
                p = p->next;
            }  
        }
        return dummy;
        
    }
};

int main(void){
    cout<<"hello world! "<<endl;

    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(4);

    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(3);
    head2->next->next = new ListNode(4);

    Solution solution;
    auto result = solution.mergeTwoLists(head1,head2);

    while(result){
        cout<<result->val<<" ";
        result = result->next;
    }

}