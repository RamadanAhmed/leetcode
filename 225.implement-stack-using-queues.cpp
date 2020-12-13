/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */
#include <queue>
using namespace std;
// @lc code=start
class MyStack {
    std::queue<int> q;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        auto q_size = q.size();
        while(q_size > 1) {
            q.push(q.front());
            q.pop();
            --q_size;
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        auto top = q.front();
        q.pop();
        return top;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

