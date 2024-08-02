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
 };
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *> set;
        // ListNode *current = head;
        while(head){
            if(set.count(head)){
                return true;
            }
            set.insert(head);
            head= head->next;
        }
        return false;
    }
};

int main(void){
    cout<<"hello world! "<<endl;
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;
    // head->next->next->next->next = new ListNode(5);
    Solution solution;

    bool result = solution.hasCycle(head);
    if(result){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }

}