#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> a1;
vector<int> a2;
int ans;
int N;

int main () {
  int T; cin >> T;
  for (int tcase = 1; tcase <= T; tcase++) {
    ans = 0;
    cin >> N;
    int in;
    a1.clear();
    a2.clear();
    for (int n = 0; n < N; n++) {
      cin >> in;
      a1.push_back(in);
      a2.push_back(in);
    }
    sort(a2.begin(), a2.end());
    for (int n = 0; n < N; n++) {
      if (a1[n] != a2[n]) {
        ans++;
      }
    }
    cout << "Case #" << tcase << ": " << ans << endl;

  }
  return 0;
}
