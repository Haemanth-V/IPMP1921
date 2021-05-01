//Question link: https://leetcode.com/problems/online-stock-span/

class StockSpanner {
    vector<int> stocks, span;
    stack<int> st;
    int n;
public:
    StockSpanner() {
        n=0;
    }
    
    int next(int price) {
        stocks.push_back(price);
        n++;
        while(!st.empty() && stocks[st.top()] <= price)
            st.pop();
        if(st.empty())
            span.push_back(n);
        else
            span.push_back(n-1-st.top());
        st.push(n-1);
        return span[n-1];
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
