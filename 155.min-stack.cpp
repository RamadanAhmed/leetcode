/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */
#include <vector>

static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class MinStack {
public:
    std::vector<int> stack;
    std::vector<int> min_loc;
    /** initialize your data structure here. */
    MinStack() = default;

    void push(int x) {
        stack.push_back(x);
        if(min_loc.empty() || x < stack[min_loc.back()] ) {
            min_loc.push_back(stack.size() -1 );
        }
    }

    void pop() {
        stack.pop_back();
        if(min_loc.back() == stack.size()  ) {
            min_loc.pop_back();
        }
    }

    int top() {
        return stack.back();
    }

    int getMin() {
        return stack[min_loc.back()];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

