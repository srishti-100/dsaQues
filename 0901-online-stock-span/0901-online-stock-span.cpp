class StockSpanner {
public:
    stack<pair<int,int>> st;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(st.empty()){
            st.push({price,1});
            return 1;
        }
        else{
            int cnt = 0;
            while(!st.empty() && st.top().first <= price){
                int val = st.top().second;
                st.pop();
                cnt += val;
            }
            st.push({price,cnt+1});            
        }

        return st.top().second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */