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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int groupNum = lists.size();
        map<int,vector<ListNode*>> mp;
        for(int i=0;i<groupNum;i++){
            ListNode* p = lists[i];
            while(p){
                mp[p->val].push_back(p);
                p = p->next;
            }
        }
        ListNode dummy;
        ListNode* p = &dummy;
        for(auto it:mp){
            for (ListNode* node : it.second) {
            p->next = node;
            p = p->next;
        }
        }
        return dummy.next;

    }
};

int main(void){
    cout<<"hello world! "<<endl;
}