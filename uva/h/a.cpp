#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
using namespace std;

typedef long long ll;

ll power (ll v, ll p) {
  ll ret = 1;
  for (ll i = 0; i < p; i++) {
    ret *= v;
  }
  return ret;
}

//ll doit (ll a, ll b) {
//  ll upper = b;
//  ll lower = 1;
//  ll mid = (b+1)/2;
//
//  ll val;
//  while (true) {
//
//    val = power((ll)pow(a,(double)(1/mid))-1,mid);
//    cout << upper << endl;
//    cout << lower << endl;
//    cout << mid << endl;
//    cout << val << endl;
//
//    cout << pow(a,(double)(1/mid))-1 << endl;
//
//
//
//    while (true);
//    if (val > b) {
//      lower = mid;
//    } else if (val < b) {
//      upper = mid;
//    } else {
//      return mid;
//    }
//  }
//
//}


void doit (ll h, ll nk, ll &kk, ll &NN) {



  ll r;
  ll other;
  for (ll n = 1; ; n++) {
    for (ll k = 0; ; k++) {
      //cout << "before" << endl;
      r = power(n+1,k);
      other = power(n,k);
      //cout << "here" << endl;
      if (r == h && other == nk) {
        kk = k;
        NN = n;
        return;
      } else if (r > h || other > nk) {
        break;
      }
    }
  }
}

int main () {
  cout << std::fixed;
  cout << std::setprecision(0);
  ll a, b;
  ll k;
  ll N;
  while (true) {
    cin >> a >> b;
    if (a == 0 && b == 0) break;
    if (a == 1 && b == 1) {
      cout << "0 1" << endl;
      continue;
    }

//    if (b == 1) {
//      N = a-1;
//      k = 1;
//      //assert(N!=1);
//    }
//    else {
//      doit(a,b,k,N);
//      //assert(N!=1);
//
//
//
//    }
//      if (N==1)
//        cout << "1";
//        else cout << (b-1)/(N-1);
//      cout << " ";
//      cout << fixed;
//      cout << setprecision(0);
//
//      double hi;
//
//      if (N == 1)
//        hi = (double)N*(double)a/(double(N)+1);
//     else  
//       hi = 
//      (-(double)pow(N,k+1)*(1/(double)pow(N+1,k))+N+1)*a;
//      cout << hi << endl;


//    if (b == 1) {
//      N = a - 1;
//      k = 1;
//      cout << "1";
//      cout << " ";
//      cout << (double)a + (double)a*(double)N/((double)N+1.0) << " " << "here";
//      cout << endl;
//    } else {
      doit(a,b,k,N);
//      if (a == 81 && b == 64) cout << "k: " << k << " N: " << N << endl;


      ll nowork = 0;
      double totheight = 0.0;
      for (ll i = 0; i <= k-1; i++) {
        nowork += power(N,i);
      }
      for (ll i = 0; i <= k; i++) {
        totheight += pow(N,i)/pow(N+1,i);
      }
      totheight *= (double)a;
      cout << nowork;
      cout << " ";
      cout << totheight;
      cout << endl;




//    }



  }
  return 0;
}
