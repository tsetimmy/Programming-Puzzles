// Works for both small and large inputs.
#include <iostream>
#include <limits>
using namespace std;

void doit (int cas) {
  string s;
  cin >> s;
  int ans = 0;
  for (int i = 1; i < s.size(); i++) {
    if (s[i] != s[i - 1]) {
      ans++;
    }
  }
  if (s[s.size() - 1] == '-')
    ans++;
  cout << "Case #" << cas << ": " << ans << endl;
}

int main () {
  int tcases;
  cin >> tcases;
  cin.clear();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  for (int cas = 1; cas <= tcases; cas++) {
    doit(cas);
  }
  return 0;
}
