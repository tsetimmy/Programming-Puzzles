// Works for both small and large inputs.
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int absolute (int a) {
  if (a < 0) return -a;
  return a;
}

int minimum (int a, int b) {
  if (a < b) return a; return b;
}

int count (vector<int> v) {
  sort(v.begin(), v.end());
  int max = v[v.size() - 1];
  int min = v[0];
  int best = max * v.size();
  int candidate;
  for (int i = min; i <= max; i++) {
    candidate = 0;
    for (int j = 0; j < v.size(); j++) {
      candidate += absolute(i - v[j]);
    }
    best = minimum(best, candidate);
  }
  return best;
}

void doit (int cas) {
  cout << "Case #" << cas << ": ";
  int n;
  cin >> n;
  cin.clear();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  vector<string> v;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    v.push_back(s);
  }
  vector<string> u;
  u = v;
  for (int i = 0; i < n; i++) {
    u[i].erase(std::unique(u[i].begin(), u[i].end()), u[i].end());
  }

  for (int i = 0; i < u.size(); i++) {
    for (int j = i + 1; j < u.size(); j++) {
      if (u[i] != u[j]) {
        cout << "Fegla Won" << endl;
        return;
      }
    }
  }

  vector<int> z;
  int ans = 0;
  char c;
  for (int i = 0; i < u[0].size(); i++) {
    z.clear();
    for (int j = 0; j < v.size(); j++) {
      c = v[j][0];
      int counter = 0;
      while (v[j] != "" && v[j][0] == c) {
        counter++;
        v[j].erase(v[j].begin());
      }
      z.push_back(counter);
    }
    ans += count(z);
  }
  cout << ans << endl;
}

int main () {
  int T;
  cin >> T;
  for (int cas = 1; cas <= T; cas++)
    doit(cas);
  return 0;
}
