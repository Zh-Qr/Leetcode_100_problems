#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<algorithm>

using namespace std;


class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         if (head == nullptr) {
//             return nullptr;
//         }

//         // 用于映射旧节点到新节点
//         unordered_map<Node*, Node*> nodeMap;

//         // 创建一个新的链表头节点
//         Node* dummy = new Node(0);
//         Node* p = dummy;
//         Node* current = head;

//         // 第一遍遍历：复制每个节点，并建立旧节点和新节点的映射
//         while (current) {
//             Node* newNode = new Node(current->val);
//             nodeMap[current] = newNode;  // 旧节点映射到新节点
//             p->next = newNode;  // 连接新节点
//             p = p->next;
//             current = current->next;
//         }

//         // 第二遍遍历：设置新节点的 random 指针
//         current = head;
//         while (current) {
//             if (current->random) {
//                 nodeMap[current]->random = nodeMap[current->random];
//             }
//             current = current->next;
//         }

//         Node* newHead = dummy->next;
//         delete dummy;  // 删除哨兵节点
//         return newHead;
//     }
// };

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return head;
        }

        unordered_map<Node*, Node*> map;

        Node* dummy = new Node(0);
        Node* p = dummy;
        Node* current = head;
        while(current){
            Node* newNode = new Node(current->val);
            map[current] = newNode;
            p->next = newNode;
            p = p->next;
            current = current->next; 
        }

        //设置randonm
        current = head;
        while(current){
            if(current->random){
                map[current]->random = map[current->random];
            }
            current = current->next;
        }

        return dummy->next;
        
        
    }
};

int main(void){
    cout<<"hello world! "<<endl;

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->random = head->next->next;  // 1's random points to 3
    head->next->random = head;        // 2's random points to 1

    Solution solution;
    Node* newHead = solution.copyRandomList(head);

    // 打印结果链表
    Node* current = newHead;
    while (current != nullptr) {
        std::cout << "Node val: " << current->val;
        if (current->random) {
            std::cout << ", Random points to: " << current->random->val;
        }
        std::cout << std::endl;
        current = current->next;
    }

    // 释放内存
    while (newHead != nullptr) {
        Node* temp = newHead;
        newHead = newHead->next;
        delete temp;
    }
}