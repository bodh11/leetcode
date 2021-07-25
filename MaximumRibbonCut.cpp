using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class CutRibbon {

public:
  int countRibbonPieces(const vector<int> &lengths, int total) {
    int n = (int)(lengths.size());

    vector<int> dp(total + 1, 0);
    // this will signify if solution is possible or not
    for(int w = 0; w <= total; w++) 
      dp[w] = -1;
    // find maximum number of pieces you can generate from the initial ribbon
    // you can only generate the given pieces

    // base case: maximum number of pieces you can generate with starting length of 0
    dp[0] = 0;
    
    for(int i = 0; i < n; i++) {
      for(int w = 0; w <= total; w++) {
        int prev = w - lengths[i];
        if(prev >= 0 && dp[prev] != -1) {
          dp[w] = max(dp[w], dp[prev] + 1);
        }
      }
    }

    return dp[total];
  }
};

int main(int argc, char *argv[]) {
  CutRibbon *cr = new CutRibbon();
  vector<int> ribbonLengths = {2, 3, 5};
  cout << cr->countRibbonPieces(ribbonLengths, 5) << endl;
  ribbonLengths = vector<int>{2, 3};
  cout << cr->countRibbonPieces(ribbonLengths, 7) << endl;
  ribbonLengths = vector<int>{3, 5, 7};
  cout << cr->countRibbonPieces(ribbonLengths, 13) << endl;
  ribbonLengths = vector<int>{3, 5};
  cout << cr->countRibbonPieces(ribbonLengths, 7) << endl;

  delete cr;
}
