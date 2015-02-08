#include <iostream>
#include <iomanip>
#include <cassert>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ull C, N;
double total;
ull count;
ull binomial[51][51];

// This function fills in a binomial coefficient array of size N by K.
void binomial_coefficient (int N, int K) {
  for (int k = 1; k <= K; k++) {
    binomial[0][k] = 0;
  }
  for (int n = 0; n <= N; n++) {
    binomial[n][0] = 1;
  }
  for (int n = 1; n <= N; n++) {
    for (int k = 1; k <= K; k++) {
      binomial[n][k] = binomial[n-1][k-1] + binomial[n-1][k];
    }
  }
}

void doit (ull amount) {
  if (amount <= 0) {
    //total += sum;
    //count++;
    return;
  }

  double num;
  double denom;
  for (ull i = 1; i <= min(amount, N); i++) {

    num = (double)binomial[amount][i] * (double)binomial[C-amount][N-i];
    denom = (double)binomial[C][N];
    assert(denom > 0.0);
    total += (num/denom) * (double)(C-amount);
    doit(amount-i);
    //doit(amount-i,sum+denom/num);
  }

}

void solve (ull cas) {
  cin >> C >> N;

  total = 1.0;
  count = 0;
  doit(C-N);

  cout << "Case #" << cas << ": " << total << endl;
}



int main () {
  cout << std::fixed;
  cout << std::setprecision(12);
  binomial_coefficient(50,50);
  ull cases; cin >> cases;
  for (ull cas = 1; cas <= cases; cas++) {
    solve(cas);
  }
  return 0;
}

