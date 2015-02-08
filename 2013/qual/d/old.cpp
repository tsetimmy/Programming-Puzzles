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


struct chest {
  int type;
  int kcount;
  vector<int> keys;
};

#define num 201
int K; // No. of keys
int N; // No. of chests you need to open
int keys[201];
chest chests[201];
bool taken[201];

vector<int> s;
string best1 = "";
string best2 = "";

void doit (bool& done) {
  if (done) return;
  if (s.size() == N) {
    best2 = "";
    for (int i = 0; i < s.size(); i++) {
      best2.push_back(s[i]+'0');
    }
    if (best1 == "") {
      best1 = best2;
    } else if (best1 > best2) {
      best1 = best2;
    }
    done = true;
    return;
  }

  for (int k = 1; k <= num; k++) {
    if (keys[k]) {
      for (int n = 1; n <= N; n++) {
        if (k == chests[n].type && !taken[n]) { // equal, let's open the chest.
          for (int j = 0; j < chests[n].kcount; j++) {
            keys[chests[n].keys[j]]++;
          }
          keys[k]--;
          s.push_back(n);
          taken[n] = true;
          doit(done);
          taken[n] = false;
          s.pop_back();
          keys[k]++;
          for (int j = 0; j < chests[n].kcount; j++) {
            keys[chests[n].keys[j]]--;
          }
        }
      }
    }
  }
}

void solve (int t) {
  best1 = "";
  best2 = "";
  for (int i = 0; i < 201; i++) keys[i] = 0;
  cin >> K >> N;
  int k;
  for (int i = 1; i <= K; i++) {
    cin >> k;
    keys[k]++;
  }
  for (int i = 1; i <= N; i++) {
    cin >> chests[i].type;
    cin >> chests[i].kcount;
    chests[i].keys.clear();
    for (int j = 1; j <= chests[i].kcount; j++) {
      cin >> k;
      chests[i].keys.push_back(k);
    }
  }
  for (int i = 0; i < 201; i++) taken[i] = false;

  bool done = false;


  cout << "doing it" << endl;
  doit(done);
  cout << "Case #" << t << ": ";
  if (best1 == "") cout << "IMPOSSIBLE";
  else {
    for (int i = 0; i < best1.length(); i++) {
      if (i != best1.length()) cout << best1[i] << " ";
      else cout << best1[i];
    }
  }
  cout << endl;

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
