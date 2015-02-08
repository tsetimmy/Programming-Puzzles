#include <iostream>
#include <cassert>
#include <vector>
#include <utility>
using namespace std;

typedef long long ll;

ll n, A, B, C, D, x, y, M;

ll table[3][3];
ll t[9];
ll ans;

ll bin [10000][10000];

ll binomial (ll nn, ll k) {
  cout << nn << " " << k << endl;
  cout << "bin get called" << endl;
  if (nn <= 1000-1 && k <= 1000-1 && nn >= 0 && k >= 0 && bin[nn][k] != -2) return bin[nn][k];
  if (k < 0 || k > nn) {
    return 0;
  }
  if (k > nn - k) {
    k = nn - k;
  }
  if (k == 0 || nn <= 1) {
    return 1;
  }
  ll ret = binomial(nn-1,k) + binomial(nn-1,k-1);
  if (nn <= 1000-1 && k <= 1000-1 && nn >= 0 && k >= 0 && bin[nn][k] == -2) bin[nn][k] = ret;
  return ret;
}



void solve (int tcase) {
  cin >> n>> A>> B>> C>> D>> x>> y>> M;
  ans = 0;
  for (ll i = 0; i < 3; i++)
  for (ll j = 0; j < 3; j++)
    table[i][j] = 0;


  //coor.push_back(make_pair(x, y));
  table[x%3][y%3]++;
  for (ll i = 1; i <= n-1; i++) {
    x = (A * x + B) % M;
    y = (C * y + D) % M;
    //coor.push_back(make_pair(x, y));
    table[x%3][y%3]++;
  }



  ll idx = 0;
  for (ll i = 0; i < 3; i++)
    for (ll j = 0; j < 3; j++) {
      t[idx] = table[i][j];
      idx++;
    }


  for (ll i = 0; i < 9; i++) {
    for (ll j = i; j < 9; j++) {
      for (ll k = j; k < 9; k++) {
        if ((i/3+j/3+k/3)%3==0&&(i%3+j%3+k%3)%3==0) {
          if (i == j && j == k) {
            ans += (t[i]-2)*(t[i]-1)*t[i]/6;
          } else if (i != j && i != k && j == k) {
            ans += t[i]*(t[j]*(t[j]+1))/2;
          } else if (i == j && i != k && j != k) {
            ans += t[k]*(t[i])*(t[i]+1)/2;
          } else if (i == k && i != j && j != k) {
            ans += t[j]*t[k]*(t[k]+1)/2;
          } else {
            ans += t[i]*t[j]*t[k];
          }
        }
      }
    }
  }



  cout << "Case #" << tcase << ": " << ans << endl;
}

int main () {

//  for (ll i = 0; i < 10000; i++) {
//    for (ll j = 0; j < 10000; j++) {
//      bin[i][j] = -2;
//    }
//  }
  int Tcase; cin >> Tcase;
  for (int tc = 1; tc <= Tcase; tc++) {
    solve(tc);
  }
  return 0;
}
