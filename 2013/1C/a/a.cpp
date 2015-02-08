#include <iostream>
using namespace std;
typedef unsigned long long ull;

string s;
ull c;

bool iscon (char a) {
  if (a == 'a' ||
      a == 'e' ||
      a == 'i' ||
      a == 'o' ||
      a == 'u')
    return false;
  return true;
}

void solve (int t) {
  cin >> s;
  cin >> c;

  ull p1, p2, p3;
  p1 = 0;
  p2 = 0;
  p3 = 0;


  ull ans = 0;
  bool inc;
  while (1) {

    inc = true;

    if (s.length() - p2 < c) break;
    if (iscon(s[p2])) {
      ull con = 1;
      p3 = p2 + 1;
      while (con < c && iscon(s[p3])) {
        con++;
        p3++;
      }
      if (con == c) {
        p3--;
        ans += (p2 - p1 + 1)*(s.length() - p3);

        while (1) {
          inc = false;
          p2++;
          p3++;
          p1 = p2;
          if (p3 == s.length()) break;
          if (!iscon(s[p3])) break;
          ans += s.length() - p3;
        }

      } else {
        p2 = p3;
      }
    }
    if (inc) p2++;
  }
  cout << "Case #" << t << ": " << ans << endl;
}

int main () {
  int T; cin >> T;
  for (int t = 1; t <= T; t++)
    solve(t);
  return 0;
}
