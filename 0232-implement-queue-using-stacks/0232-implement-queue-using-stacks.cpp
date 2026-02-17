class MyQueue {
public:
stack<int> one, two;
    MyQueue() {
         
    }
    
    void push(int x) {
        one.push(x);
    }
    
    int pop() {
        if(two.empty()){
            while(!one.empty()){
                two.push(one.top());
                one.pop();
            }
        }
        int x = two.top();
        two.pop();
        return x;
    }
    
    int peek() {
        if(two.empty()){
            while(!one.empty()){
                two.push(one.top());
                one.pop();
            }
        }
        return two.top();
    }
    
    bool empty() {
        return one.empty() && two.empty();
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