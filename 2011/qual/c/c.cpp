#include <iostream>
using namespace std;

int N, XOR, sum, lowest;
int main () {
  int T; cin >> T;
  for (int tcase = 1; tcase <= T; tcase++) {
    cin >> N;
    XOR = 0;
    sum = 0;
    lowest = 1000000;

    int in;
    for (int n = 0; n < N; n++) {
      cin >> in;
      XOR ^= in;
      sum += in;
      if (in < lowest) {
        lowest = in;
      }
    }
    cout << "Case #" << tcase << ": ";
    if (XOR == 0) {
      cout << sum-lowest;
    } else {
      cout << "NO";
    }
    cout << endl;
  }
  return 0;
}
