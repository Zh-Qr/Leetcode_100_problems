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
    // ListNode* reverseKGroup(ListNode* head, int k){
    //     ListNode dummy;
    //     ListNode* p = &dummy;
    //     p->next = head;
    //     int len = 0;
    //     while(p->next){
    //         len++;
    //         p = p->next;
    //     }
    //     cout<<"len: "<<len<<endl;

    //     int cnt = len/k;
    //     ListNode* curr = head;
    //     for(int i=0;i<cnt;i++){
    //         ListNode* prev = nullptr;
            
    //         for(int j=0;j<k;j++){
    //             ListNode* next = curr->next;
    //             curr->next = prev; // 当前节点指向前一个节点，反转指针
    //             prev = curr; // 更新前一个节点为当前节点
    //             curr = next;
    //         }

    //         while(prev->next){
    //             prev = prev->next;
    //         }
    //         prev->next = curr;
            
    //     }

    //     return dummy.next;
    // }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1 || head == nullptr) {
            return head;
        }
        
        ListNode dummy(0);  // 使用带参数的构造函数初始化哨兵节点
        dummy.next = head;
        ListNode* prevGroupEnd = &dummy;  // 上一个组的结尾节点

        while (true) {
            ListNode* groupStart = prevGroupEnd->next;
            ListNode* groupEnd = prevGroupEnd;
            // 找到当前组的结尾
            for (int i = 0; i < k && groupEnd != nullptr; i++) {
                groupEnd = groupEnd->next;
            }
            if (groupEnd == nullptr) {
                break; // 不足 k 个节点，停止反转
            }

            ListNode* nextGroupStart = groupEnd->next;
            // 反转当前组
            ListNode* prev = nullptr;
            ListNode* curr = groupStart;
            while (curr != nextGroupStart) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            // 连接反转后的组
            prevGroupEnd->next = groupEnd;
            groupStart->next = nextGroupStart;

            // 移动到下一个组
            prevGroupEnd = groupStart;
        }

        return dummy.next;
    }
};




int main(void){
    cout<<"hello world! "<<endl;
    // ListNode* head = new ListNode(0);
    int k = 2;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;
    auto result = solution.reverseKGroup(head,k);
    while(result){
        cout<<result->val<<" ";
        result = result->next;
    }
}