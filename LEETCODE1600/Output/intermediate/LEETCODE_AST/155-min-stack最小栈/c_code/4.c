class MinStack {
public:
    /** initialize your data structure here. */
    const static int maxn=1e4+10;
    int a[maxn],p;
    int st[maxn];
    MinStack() {
        p=0;
    }
    
    void push(int x) {
        st[p]=x;
        a[p]=min((p-1>=0?a[p-1]:(1<<31)-1),x);
        p++;
    }
    
    void pop() {
        p--;
    }
    
    int top() {
        return st[p-1];
    }
    
    int getMin() {
        return a[p-1];
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