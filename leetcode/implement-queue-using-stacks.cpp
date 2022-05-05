class MyQueue {
public:
    stack<int> s1, s2;
    MyQueue() {
        
    }
    
    void build1() {
        while(s1.size() != 1) {
            s2.push(s1.top());
            s1.pop();
        }
    }
    
    void build2() {
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        } 
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        build1();
        int x = s1.top();
        s1.pop();
        build2();
        return x;
    }
    
    int peek() {
        build1();
        int x = s1.top();
        build2();
        return x;
    }
    
    bool empty() {
        return s1.empty();
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
