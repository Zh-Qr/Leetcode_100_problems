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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 创建一个哨兵节点
        ListNode dummy;
        ListNode* p = &dummy;
        int flag = 0;
        while(l1||l2||flag){
            if(l1&&l2){
                p->next = new ListNode(flag+l2->val+l1->val);
                p = p->next;
                l1 = l1->next;
                l2 = l2->next;
            }
            else{
                if(!l1&&l2){
                    p->next = l2;
                    l2->val += flag;
                    break;
                }
                if(l1&&!l2){
                    p->next = l1;
                    l1->val += flag;
                    break;
                }
                if(!l1&&!l2){
                    p->next = new ListNode(flag);
                }

            }
        }
        ListNode *q = &dummy;
        while(q->next||q->val>9){
            if(q->val>9){
                q->val -=10;
                if(q->next){
                    q->next->val+=1;
                }
                else{
                    q->next = new ListNode(1);
                }
            }
            q = q->next;
        }
        return dummy.next;
    }
    
};


int main(void){
    cout<<"hello world! "<<endl;

    ListNode* head1 = new ListNode(2);
    head1->next = new ListNode(4);
    head1->next->next = new ListNode(3);

    ListNode* head2 = new ListNode(5);
    head2->next = new ListNode(6);
    head2->next->next = new ListNode(4);

    Solution solution;
    auto result = solution.addTwoNumbers(head1,head2);

    while(result){
        cout<<result->val<<" ";
        result = result->next;
    }
}
