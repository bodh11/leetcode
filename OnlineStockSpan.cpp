class StockSpanner {
public:
    
    // value and the index
    stack<pair<int, int >>* st;
    int index;
    StockSpanner() {
        index = 0;
        st = new stack<pair<int, int>> ();
    }
    
    int next(int price) {
        
        // 1. monotonic decreasing
        // 2. we will compute span for a position while popping it out from stack
        // 3. while pushing a new value in the stack; stack.top() > new_value
        // cout << "price " << price << " : " << " size : " << st->size() << endl;
        int ans = -1;
        if(st->empty()) {
            st->push(make_pair(price, index));
            index++;
            return 1;
        }
        if(price >= st->top().first) {
            // pop values
            while(!st->empty() && price >= st->top().first) {
                st->pop();
            }
            // assert(st.empty() == 1)
            // assert(price < st.top().first)
            
            if(st->empty()) {
                ans = index + 1; // 3
            } else {
                pair<int, int> tp = st->top();
                int prevIndex = tp.second;
                ans = (index - prevIndex);
            }
            st->push(make_pair(price, index));
        } else {
            // price < st.top().first
           
           pair<int, int> tp = st->top();
           int prevIndex = tp.second;
           ans = (index - prevIndex);
            // cout << price << " @ " << prevIndex << " @ " << index << " @ " << ans << endl;
           st->push(make_pair(price, index));
        }
        index++; // 3
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */