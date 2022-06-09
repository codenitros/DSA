// https://leetcode.com/problems/min-stack/


class MinStack {
public:
    /** initialize your data structure here. */

    stack<int> a;
    stack<int> b;
        
    MinStack() {
        b.push(INT_MAX);
    }
    
    void push(int val) {
        a.push(val);
        if(val<b.top())
        {
            b.push(val);
        }
        else
        {
            // push same element
            b.push(b.top());
        }
    }
    
    void pop() {
        a.pop();
        b.pop();
    }
    
    int top() {
        return a.top();
    }
    
    int getMin() {
        return b.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
