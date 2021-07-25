using namespace std;

#include <iostream>
#include <vector>

class Staircase {

public:
  int CountWays(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
      for(int j = 0; j < 4; j++) {
        int prev = i - j;
        if(prev >= 0)
         dp[i] += dp[prev];
      }
    }
    return dp[n];
  }
};

int main(int argc, char *argv[]) {
  Staircase *sc = new Staircase();
  cout << sc->CountWays(3) << endl;
  cout << sc->CountWays(4) << endl;
  cout << sc->CountWays(5) << endl;

  delete sc;
}
