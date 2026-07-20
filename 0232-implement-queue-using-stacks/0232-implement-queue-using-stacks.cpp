class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    // steps to follow:
    // s1->s2 , x->s1 , s2->s1
    MyQueue() {}

    void push(int x) { s1.push(x); }

    int pop() {
        if(empty()) return -1;
        if (s2.empty()) {
            while (s1.size()) {
                s2.push(s1.top());
                s1.pop();
            }
           
        }
         int ans = s2.top();
            s2.pop();
            return ans;
       
     
    }

    int peek() {
        if(empty()) return -1;
        if (s2.empty()) {
            while (s1.size()) {
                s2.push(s1.top());
                s1.pop();
            }
          
        } 
          int ans = s2.top();
           
            return ans;
    }


    
    bool empty() {
    return s1.empty() && s2.empty();
}
}
;

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */