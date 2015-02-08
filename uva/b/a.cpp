#include <iostream>
using namespace std;

typedef long long ll;
#define dim 105

ll a[dim][dim], sum[dim][dim];
ll N;

ll get (ll srow, ll scol, ll erow, ll ecol) {
  //return sum[erow][ecol]+sum[srow][scol]-sum[srow][ecol]-sum[erow][scol];
  ll a1, a2, a3, a4;


  if (srow < 0 || scol < 0) {
    a1 = 0;
  } else {
    a1 = sum[srow][scol];
  }
  if (srow < 0 || ecol < 0) {
    a2 = 0;
  } else {
    a2 = sum[srow][ecol];
  }
  if (erow < 0 || scol < 0) {
    a3 = 0;
  } else {
    a3 = sum[erow][scol];
  }
  if (erow < 0 || ecol < 0) {
    a4 = 0;
  } else {
    a4 = sum[erow][ecol];
  }
  return a1+a4-a2-a3;


}

int main () {
  cin >> N;

  for (ll i = 0; i < N; i++) {
    for (ll j = 0; j < N; j++) {
      cin >> a[i][j];
    }
  }

  sum[0][0] = a[0][0];
  for (ll i = 1; i < N; i++) {
    sum[0][i] = sum[0][i-1] + a[0][i];
    sum[i][0] = sum[i-1][0] + a[i][0];
  }

  for (ll i = 1; i < N; i++) {
    for (ll j = 1; j < N; j++) {
      sum[i][j] = a[i][j] + sum[i-1][j-1] + (sum[i-1][j]-sum[i-1][j-1]) + (sum[i][j-1]-sum[i-1][j-1]);
    }
  }

  //for (int i = 0; i < N; i++) {
    //for (int j = 0; j < N; j++) {
      //cout << a[i][j] << " ";
    //}
    //cout << endl;
  //}

  ll srow, scol, erow, ecol;
  ll marx = -1270100;

  for (ll i = 0; i < N; i++) {
    for (ll j = 0; j < N; j++) {
      for (ll k = i; k < N; k++) {
        for (ll m = j; m < N; m++) {
          marx = max(marx ,get(i-1,j-1,k,m));
        }
      }
    }
  }







  cout << marx << endl;





  return 0;
}
