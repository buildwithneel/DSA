class MyQueue {
public:
stack<int>a,b;
    MyQueue() {
        
    }
    
    void push(int x) {
        a.push(x);
    }
    
    int pop() {
        if(b.empty()){
            while(!a.empty()){
                b.push(a.top());
                a.pop();
            }
        }int x=b.top();
        b.pop();
        return x;
    }
    
    int peek() {
        if(b.empty()){
            while(!a.empty()){
                b.push(a.top());
                a.pop();

            }
        }return b.top();
    }
    bool empty(){
        return a.empty() && b.empty();
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