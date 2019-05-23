// Source : https://leetcode-cn.com/problems/implement-queue-using-stacks/
// Author : Lianfeng Shen
// Date   : 2019-05-23

class MyQueue {
private:
    stack<int> in;
    stack<int> out;
    
    void transfer() {
        if (out.empty()) {
            while (in.size()) {
                out.push(in.top()); in.pop();
            }
        }
    }
public:
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        in.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (out.empty()) transfer();
        int temp = out.top(); out.pop();
        
        return temp;
    }
    
    /** Get the front element. */
    int peek() {
        if (out.empty()) transfer();
        
        return out.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return in.empty() && out.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */