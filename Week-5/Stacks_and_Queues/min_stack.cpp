//Question Link: https://leetcode.com/problems/min-stack/

//Method 1
class MinStack {
    stack<pair<int, int>> st;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int val) {
        int min = getMin();
        if(min > val)
            min = val;
        st.push(make_pair(val, min));
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        int t = st.top().first;
        return t;
    }
    
    int getMin() {
        if(st.empty())
            return INT_MAX;
        int t = st.top().second;
        return t;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
