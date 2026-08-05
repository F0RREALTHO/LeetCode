class MinStack {
public:
    long long mini; 
    stack<long long> st;

    MinStack() {
        mini = LLONG_MAX;
    }
    
    void push(int val) {
        long long v = val;
        if(st.empty()){
            mini = v;
            st.push(v);
        }else{
            if(v > mini) st.push(v);
            else {
                st.push(2*v - mini); 
                mini = v;
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long x = st.top(); st.pop();
        if(x < mini){ 
            mini = 2*mini - x; 
        }
    }
    
    int top() {
        long long x = st.top();
        if(x >= mini) return (int)x;
        return (int)mini;
    }
    
    int getMin() {
        return (int)mini;
    }
};
