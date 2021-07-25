// https://www.spoj.com/problems/FARIDA/

#include<iostream>
#include<vector>

typedef long long lld;

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(0);
    int t; cin >> t;
    int ca = 1;
    while(t--) {
        int n; cin >> n;
        vector<lld> coins;
        for(int i = 0; i < n; i++) {
            int coin; cin >> coin;
            coins.push_back(coin);
        }
        if(n == 0) {
            cout << "Case " << ca++ << ": " << 0 << endl;
            continue;
        }
        // you have to pass all the monsters 
        // state: prefix; max coins value which you can collect till monster i
        vector<lld> dp(n + 1, 0);
        
        dp[0] = coins[0];
        dp[1] = max(dp[0], coins[1]);
        // state transition: 
        // dp[i] = max(dp[i-2] + coins[i], dp[i])
        for(int i = 2; i < n; i++) {
            // pick coin from ith monster
            dp[i] = dp[i-2] + coins[i];
            // don't pick coins from ith monster
            dp[i] = max(dp[i], dp[i-1]);

        }
        // for(int i = 0; i <= n; i++) {
        //     cout << "dp[i] " << dp[i] << endl; 
        // }
        cout <<"Case " << ca++ << ": "<< dp[n-1] << endl;
    }
    return 0;
}