//https://leetcode.com/problems/implement-stack-using-queues/


class MyStack {
    Queue<Integer> mQ1;
    Queue<Integer> mQ2;
    int x;
    
    public MyStack() {
         mQ1 = new LinkedList<Integer>();
         mQ2 = new LinkedList<Integer>();
    }
    
    public void push(int x) {
        if(mQ1.isEmpty()){
            mQ2.add(x);
        }else{
            mQ1.add(x);
        }
    }
    
    public int pop() {
        if(mQ1.isEmpty()){
            while(!mQ2.isEmpty()){
                int front = mQ2.peek();
                mQ2.remove();
                
                if(mQ2.isEmpty()){
                    x=front;
                    break;
                }
                
                mQ1.add(front);
            }
        }else{
            while(!mQ1.isEmpty()){
                int front = mQ1.peek();
                mQ1.remove();
                
                if(mQ1.isEmpty()){
                    x=front;
                    break;
                }
                
                mQ2.add(front);
            }            
        }
        return x;
    }
    
    public int top() {
        if(mQ1.isEmpty()){
            while(!mQ2.isEmpty()){
                int front = mQ2.peek();
                mQ2.remove();
                
                if(mQ2.isEmpty()){
                    x=front;
                }
                
                mQ1.add(front);
            }
        }else{
            while(!mQ1.isEmpty()){
                int front = mQ1.peek();
                mQ1.remove();
                
                if(mQ1.isEmpty()){
                    x=front;
                }
                
                mQ2.add(front);
            }            
        }
        return x;       
    }
    
    public boolean empty() {
        return mQ1.isEmpty() && mQ2.isEmpty();
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */