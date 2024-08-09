#include<iostream>
#include<stdlib.h>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

class MinStack {
private:
    stack<int> x_stack;
    stack<int> min_stack;
public:
    MinStack() {
        min_stack.push(INT_MAX);
    }
    
    void push(int val) {
        x_stack.push(val);
        min_stack.push(min(val,min_stack.top()));
    }
    
    void pop() {
        x_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return x_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};

int main(){
    cout<<"hello world!"<<endl;
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);

    auto minnum = minStack.getMin();
    cout<<"min: "<<minnum;

}