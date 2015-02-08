#include <iostream>
using namespace std;

typedef long long ll;

ll n, L;
string s;
ll count;
bool done;
//string alpha;

void print () {
  for (ll i = 0; i < s.size(); i++) {
    if (i != 0 && i%(4*16) == 0) cout << endl;
    else if (i != 0 && i%4 == 0) cout << " ";
    cout << s[i];
  }
  cout << endl;
  cout << s.size();
  cout << endl;
  return;
}

bool same (ll start, ll end, ll len) {
  for (ll i = 0; i < len; i++) {
    if (s[start + i] != s[end + i]) {
      return false;
    }
  }
  return true;
}

bool ok () {
  if (s.size() == 1 || s.size() == 0) return true;

  ll len = s.size()/2;
  ll end;

  for (ll l = 1; l <= len; l++) {
    for (ll start = 0; true; start++) {
      end = start + l - 1;
      end++;
      end = end + l - 1;
      if (end >= s.size()) break;
      if (same(start,start + l, l)) return false;
    }
  }

  return true;
}

void recurse () {
  if (!ok()) return;

  count++;
  if (count == n) {
    print();
    done = true;
    return;
  }

  for (ll i = 0; i < L; i++) {
    s.push_back('A' + i);
    recurse();
    if (done) return;
    s = s.substr(0, s.size() - 1);
//    s.pop_back();
  }
}

void doit () {
  count = 0;
  done = false;
  s = "";
  for (ll i = 0; i < L; i++) {
    s.push_back('A' + i);
    recurse();
    if (done) return;
    s = s.substr(0, s.size() - 1);
//    s.pop_back();
  }
}

int main () {
//  alpha = "";
//  for (ll i = 0; i < 26; i++) {
//    alpha.push_back((char) 'A' + i);
//  }


  while (true) {
    cin >> n >> L;
    if (n == 0 && L == 0) break;
    doit();
  }
  return 0;
}
