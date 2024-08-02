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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> st;
        ListNode *it =headA;
        while(it!=nullptr){
            st.insert(it);
            it = it->next;
        }
        it = headB;
        while(it!=nullptr){
            if(st.count(it)>0){
                return it;
            }
            it = it->next;
        }
        return nullptr;
    }
};


int main(void){
    cout<<"hello world! "<<endl;
}