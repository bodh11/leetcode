class Solution {
public:
    vector<int> countBits(int n) {
                vector<int> A;
        for(int i = 0; i <= n; i++) {
            // count number of set bits
            int m = i;
            int count = 0;
            while(m) {
                if(m % 2)
                 count++;
                m /= 2;
            }
            A.push_back(count);
        }
        return A;      
    }
};