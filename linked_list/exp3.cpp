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
    bool isPalindrome(ListNode* head) {
        int len = 0;
        vector<int> val;
        while(head){
            val.push_back(head->val);
            len++;
            head = head->next;
        }
        for(int i=0;i<len/2;i++){
            if(val[i]!=val[len-i-1]){
                return false;
            }
        }
        return true;
    }
};

int main(void){
    cout<<"hello world! "<<endl;
    ListNode* head = new ListNode(7);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    // head->next->next->next->next = new ListNode(5);
    Solution solution;

    bool result = solution.isPalindrome(head);
    if(result){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    cout<<head->val;

}