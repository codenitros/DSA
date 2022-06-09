// https://leetcode.com/problems/implement-queue-using-stacks/


class MyQueue {
    private Stack<Integer> mStack1, mStack2;
    public MyQueue() {
         mStack1 = new Stack<Integer>();
         mStack2 = new Stack<Integer>();
    }
    
    public void push(int x) {
        mStack1.push(x);
    }
    
    public int pop() {
        if(!mStack2.empty()){
            return mStack2.pop();
        }else{
            while(!mStack1.empty()){
                mStack2.push(mStack1.peek());
                mStack1.pop();
            }
            return mStack2.pop();
        }
    }
    
    public int peek() {
        if(!mStack2.empty()){
            return mStack2.peek();
        }else{
            while(!mStack1.empty()){
                mStack2.push(mStack1.peek());
                mStack1.pop();
            }
            return mStack2.peek();
        }
    }
    
    public boolean empty() {
        return (mStack1.empty() && mStack2.empty());
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */