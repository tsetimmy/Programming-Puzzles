// C++
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <limits>
#include <queue>
#include <utility> // pair
// C
#include <stdlib.h> // atoi, qsort
#include <math.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define ullmax std::numeric_limits<unsigned long long>::max()
#define llmax std::numeric_limits<long long>::max()
#define intmax std::numeric_limits<int>::max()
string tokenize (string &target, string delimiter);

int pos[4] = {2,3,4,5};

int narray[3];

int R,N,M,K;
int a[100][7];

vector<string> ans;
void gen (int idx, int rr) {
  if (idx == 3) {

    bool ok;
    for (int i = 0; i < K; i++) {
      ok = true;

      if (a[rr][i] != 1 &&
          !(a[rr][i] == narray[0]*narray[1] ||
          a[rr][i] == narray[0]*narray[2] ||
          a[rr][i] == narray[1]*narray[2] ||
          a[rr][i] == narray[0]*narray[1]*narray[2] ||
          a[rr][i] == narray[0] ||
          a[rr][i] == narray[1] ||
          a[rr][i] == narray[2])) {

        ok = false;
        break;
      }

    }

    if (ok) {
      string okok = "";
      okok.push_back(narray[0]+'0');
      okok.push_back(narray[1]+'0');
      okok.push_back(narray[2]+'0');
      ans.push_back(okok);
    }


    return;
  } 

  for (int i = idx; i < 4; i++) {
    narray[idx] = pos[i];
    gen(idx+1, rr);
  }

}


void solve (int t) {
  cout << "Case #" << t << ": " << endl;
  cin>>R>>N>>M>>K;

  for (int r = 0; r < R; r++) {
    for (int k = 0; k < K; k++) {
      cin >> a[r][k];
    }
  }

  for (int r = 0; r < R; r++) {
    ans.clear();
    gen(0,r);
    if (!ans.empty()) {
      cout << ans[0] << endl;
    } else {
      cout << "222" << endl;
    }
  }



}

int main () {
  int T; cin >> T;
  for (int t = 1; t <= T; t++)
    solve(t);
  return 0;
}







































































































string tokenize (string &target, string delimiter) {
  if (target == "")
    return target;

    string ret = "";
    size_t found = target.find(delimiter);
    if (found == std::string::npos && target != "") {
      ret = target;
      target = "";
    } else {
      ret = target.substr(0, found);
      target = target.substr(found+1,target.length());
    }
    return ret;
}
