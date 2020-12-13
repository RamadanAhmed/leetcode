/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
#include <stack>
using namespace std;
class MyQueue {
private:
    std::stack<int> normal_stack;
    std::stack<int> inverse_stack;
    int current_front = 0;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if(normal_stack.empty()) {
            current_front = x;
        }
        normal_stack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(inverse_stack.empty()) {
            while (!normal_stack.empty()) {
                inverse_stack.push(normal_stack.top());
                normal_stack.pop();
            }
        }
        auto top = inverse_stack.top();
        inverse_stack.pop();
        return top;
    }
    
    /** Get the front element. */
    int peek() {
        if(inverse_stack.empty()) { return current_front;}
        return inverse_stack.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return normal_stack.empty() && inverse_stack.empty();
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
// @lc code=end

