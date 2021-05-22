//Question Link: https://leetcode.com/problems/min-stack/

//Method 1 - O(n) space
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




//Method 2 - O(1) space
class MinStack {
    stack<long> st;
    int min;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty())
            min = val;
        if(val >= min)
            st.push(val);
        else{
            st.push((long)2*val - min);
            min = val;
        }
    }
    
    void pop() {
        long t = st.top();
        if(t < min)
            min = min - t + min; //new_min = x, t = 2*x - old_min So old_min = 2*new_min - t
        st.pop();
    }
    
    int top() {
        long t = st.top();
        if(t < min)
            t = min;
        return t;
    }
    
    int getMin() {
        return min;
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
