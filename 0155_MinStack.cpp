/**
Runtime: 24 ms, Beats: 80.74%
Memory: 16.4 MB, Beats: 65.79%
**/
class MinStack {
private:
    stack<int> mStack;
    stack<int> mMinStack;
    
public:
    MinStack() 
    {
    }
    
    void push(int val) {
        mStack.push(val);
        if(mMinStack.empty() || mMinStack.top()>=val)
            mMinStack.push(val);
    }
    
    void pop() {
        if(mStack.top() == mMinStack.top())
            mMinStack.pop();
        mStack.pop();
    }
    
    int top() {
        return mStack.top();
    }
    
    int getMin() {
        return mMinStack.top();
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
