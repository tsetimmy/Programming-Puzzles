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

int n[100];
int A, N;
int total;

int best (int a, int b) {
  if (a>b) return b; return a;
}

int go (int idx, int curr_a) {
  if (idx == N) return 0;

  if (curr_a > n[idx]) {
    return go(idx+1, curr_a+n[idx]);
  } else if (curr_a == 1) {
    return go(idx+1, curr_a)+1;
  } else {
    int c = 0;
    int temp = curr_a;

    while (temp <= n[idx]) {
      temp = temp*2-1;
      c++;
    }

    return 
    best(c+go(idx+1,temp+n[idx]),1+go(idx+1,curr_a));



  }



}

void solve (int t) {
  cin >> A >> N;
  for (int i = 0; i < N; i++) cin >> n[i];

  sort(n,n+N);
  int ans = go(0,A);
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
