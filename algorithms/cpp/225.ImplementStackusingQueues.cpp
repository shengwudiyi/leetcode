// Source : https://leetcode-cn.com/problems/implement-stack-using-queues/
// Author : Lianfeng Shen
// Date   : 2019-05-23

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        que.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int size = que.size();
        while (--size) {
            que.push(que.front());
            que.pop();
        }
        
        int temp = que.front();
        que.pop();
        return temp;
    }
    
    /** Get the top element. */
    int top() {
        return que.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty();
    }
private:
    queue<int> que;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */