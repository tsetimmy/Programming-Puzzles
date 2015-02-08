// C++
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <vector>
#include <limits>
#include <queue>
#include <utility> // pair
// C
#include <stdlib.h> // atoi, qsort
#include <math.h>
#include <assert.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define ullmax std::numeric_limits<unsigned long long>::max()
#define llmax std::numeric_limits<long long>::max()
#define intmax std::numeric_limits<int>::max()
string tokenize (string &target, string delimiter);

int hash[10];
int A, B;
int ans;

bool rotation (int i, int j) {
  stringstream ss1, ss2;

  ss1 << i;
  ss2 << j;

  string i_st = ss1.str();
  string j_st = ss2.str();

  i_st += i_st;
  size_t found = i_st.find(j_st);
  if (found != std::string::npos) {
    return true;
  } else {
    return false;
  }


}

void solve (int t) {
  cin >> A >> B;
  ans = 0;
  for (int i = A; i < B; i++) {
    for (int j = i+1; j <= B; j++) {
      if (rotation(i,j)) {
        ans++;
      }
    }
  }
  cout << "Case #" << t << ": " << ans << endl;
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
