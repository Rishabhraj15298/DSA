class MyQueue {
public:
        stack<int>s1;
        stack<int>s2;
    // steps to follow:
    // s1->s2 , x->s1 , s2->s1
    MyQueue() {
       
    }
    
    void push(int x) {
        if(!s1.empty()){
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
                
            }
        }
        s1.push(x);

        while(s2.size()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        if(s1.empty())return -1;
        int ans = s1.top();
        s1.pop();
        return ans;
    }
    
    int peek() {
        int ans = s1.top();
        return ans;
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