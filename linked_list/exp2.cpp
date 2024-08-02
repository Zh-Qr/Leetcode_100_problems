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
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         map<int,ListNode*> mp;
//         int i=0;

//         ListNode* current = head;
        
//         while(current){
//             mp[i] = current;
//             current = current->next;
//             i++;
//         }
//         int s = mp.size();
//         for(int i=s-1;i>0;i--){
//             mp[i]->next = mp[i-1];
//         }
//         // 处理最后一个节点
//         mp[0]->next = nullptr;

//         return mp[s-1];
//     }
// };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* next = curr->next; // 先保存下一个节点
            curr->next = prev; // 当前节点指向前一个节点，反转指针
            prev = curr; // 更新前一个节点为当前节点
            curr = next; // 移动到下一个节点
        }
        return prev; // 最终 prev 指向新链表的头
    }
};

int main(void){
    cout<<"hello world! "<<endl;
}