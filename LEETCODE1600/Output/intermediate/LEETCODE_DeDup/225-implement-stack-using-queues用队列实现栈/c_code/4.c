class MyStack {
public:
    queue<int> Q;
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        int size=Q.size();
        Q.push(x);
        while(size--){
            int tmp=Q.front();
            Q.pop();
            Q.push(tmp);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int tmp=Q.front();
        Q.pop();
        return tmp;
    }
    
    /** Get the top element. */
    int top() {
        return Q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return Q.size()==0;
    }
};