#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define ullmax std::numeric_limits<unsigned long long>::max()
#define llmax std::numeric_limits<long long>::max()
#define intmax std::numeric_limits<int>::max()

#define smax 100
#define qmax 1000
int S, Q;
string s[smax];
string q[qmax];

int hash[smax][qmax];


int doit (int curr_s, int curr_q) {
  if (curr_q >= Q) {
    return 0;
  }

  int &val = hash[curr_s][curr_q];
  if (val != -1) {
    return val;
  }


  int best = intmax-1001;
  for (int i = 0; i < S; i++) {
    if (s[i] != q[curr_q]) {
      if (i == curr_s) {
        best = min(best, doit(curr_s, curr_q+1));
      } else {
        best = min(best, 1+doit(i, curr_q+1));
      }
    }
  }
  val = best;
  return best;
}

void solve (int tcase) {
  for (int i = 0; i < smax; i++) {
    for (int j = 0; j < qmax; j++) {
      hash[i][j] = -1;
    }
  }
  string temp;
  cin >> S;
  cin.clear();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  for (int i = 0; i < S; i++) {
    getline(cin, temp);
    s[i] = temp;
  }
  cin >> Q;
  cin.clear();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  for (int i = 0; i < Q; i++) {
    getline(cin, temp);
    q[i] = temp;
  }
  int ans = intmax - 1001;
  for (int i = 0; i < S; i++) {
    ans = min(ans, doit(i, 0));
  }
  cout << "Case #" << tcase << ": " << ans << endl;
}

int main () {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    solve(t);
  }
  return 0;
}
