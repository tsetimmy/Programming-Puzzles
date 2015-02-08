// C++
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <limits>
#include <queue>
#include <stack>
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

bool map[1000+1];

void solve (int t) {
  int N,M;
  cin >> N >> M;
  int count = 0;
  for (int i = N; i <= M; i++) {
    if (map[i]) count++;
  }
  cout << "Case #" << t << ": " << count << endl;
}

bool ispal (int a) {
  stringstream ss;
  ss << a;
  string aa = ss.str();
  string bb = "";

  for (int i = aa.length()-1; i >= 0; i--) {
    bb.push_back(aa[i]);
  }

  return (aa == bb);
}

int compute (int a) {
  if (ispal(a) && ispal(a*a))
    return a*a;
  return -1;
}

int main () {
  for (int i = 0; i < 1000; i++) map[i] = false;

  for (int i = 1; i <= 31; i++) {
    int ret = compute(i);
    if (ret != -1)
      map[ret] = true;
  }


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
