#include <iostream>
using namespace std;


long long N, K;

long long power (long long a, long long b) {
  long long ret = 1;
  for (long long i = 0; i < b; i++) {
    ret *= a;
  }
  return ret;
}

void solve (int tcase) {
  cin >> N >> K;
  cout << "Case #" << tcase << ": ";
  if ((K+1)%power(2,N) == 0) {
    cout << "ON";
  } else {
    cout << "OFF";
  }
  cout << endl;
}

int main () {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    solve(t);
  }
  return 0;
}
