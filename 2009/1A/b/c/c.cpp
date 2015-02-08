#include <iostream>
#include <iomanip>
using namespace std;

typedef unsigned long long ull;

void binomial_coefficient(int,int);

ull C, N;
ull binomial[50][50];

double total;
ull count;

void doit (ull amount, double sum) {
  if (amount == 0) {
    total += sum;
    count++;
    return;
  }

  double expected;
  for (ull i = 1; i <= min(amount,N); i++) {
    expected = 1.0;
    for (ull j = 0; j < i; j++) {
      expected *= (double)(amount-j)/(double)(C-j);
    }
    expected = 1/expected;
    doit(amount-i, sum+expected);
  }



}


void solve (ull cas) {
  cin >> C >> N;

  count = 0;
  total = 0.0;
  doit(C-N, 1.0);

  cout << "Case #" << cas << ": " << total/(double)count << endl;
}

int main () {
  cout << std::fixed;
  cout << std::setprecision(12);
  ull cases; cin >> cases;
  for (ull cas = 1; cas <= cases; cas++) {
    solve(cas);
  }
  return 0;
}



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
