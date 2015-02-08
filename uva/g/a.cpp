#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
#define dim 1000001
ll hash[dim];

// This function calculates the greatest common divisor (GCD) between two numbers.
ll gcdr (ll a, ll b) {
  if (a == 0) {
    return b;
  } else {
    return gcdr(b%a, a);
  }
}

ll gcd_iter (ll u, ll v) {
  ll t;
  while (v) {
    t = u;
    u = v;
    v = t % v;
  }
  return u < 0 ? -u : u;
}

void solve (ll N) {
  ll fuck = 0;
  ll s = 0;
  for (ll i = 0; i < dim; i++)
    hash[i] = -1;

//  for (ll x = 1; x <= N; x++)
//    for (ll y = x+1; y <= N; y++) {
//      //for (ll z = y+1; z <= N; z++)
//        //if (x*x+y*y==z*z) {
//          //if (x != y && x != z && y != z) s += 3;
//          //else if (x == y) s += 2;
//
//          ll z = (ll)sqrt(x*x+y*y);
//          if (z <= N && z*z == x*x+y*y) {
//
//
//          hash[x] = 1;
//          hash[y] = 1;
//          hash[z] = 1;
//          if (gcd_iter(x,y)==1 && gcd_iter(x,z) == 1 && gcd_iter(y,z) == 1) {
//            f++;
//          }
//          }
//
//
//        }





  ll a,b,c;
  for (ll m = 2; m*m <= N; m++) {
    for (ll n = 1; n < m; n++) {
      if ((ll)abs(m-n)%2==1&&gcd_iter(m,n)==1) {
        a = m*m-n*n;
        b = 2*m*n;
        c = m*m+n*n;

//        if (a > b) {
//          cout << a << " " << b << " " << c << endl;
//          cout << "FUCK" << endl;
//        }

        if (c>N||b>N||a>N)continue;
//        if (!(a<b&&b<c)){cout<<"FUCK AGAIN"<<endl; continue;}
 
 //if (hash[a]==-1|| hash[b] == -1 || hash[c] == -1)



        fuck++;

        hash[a] = 1;
        hash[b] = 1;
        hash[c] = 1;

        ll a1,b1,c1;
        c1 = 2*c;
        for (ll i = 2; ;i++) {
          a1=i*a;
          b1=i*b;
          c1=i*c;
        if (a1>N||b1>N||c1>N)break;
          if (a1<=N)hash[a1] = 1;
          if(b1<=N)hash[b1] = 1;
          if(c1<=N)hash[c1] = 1;
        }




      }

//        hash[a] = 1;
//        hash[b] = 1;
//        hash[c] = 1;
//
//        ll a1,b1,c1;
//        c1 = 2*c;
//        for (ll i = 2; c1 <= N;i++) {
//          a1=i*a;
//          b1=i*b;
//          c1=i*c;
//          hash[a1] = 1;
//          hash[b1] = 1;
//          hash[c1] = 1;
//        }
      //a = m*m-n*n;
      //b = 2*m*n;
      //c = m*m+n*n;
      //cout << a << " " << b << " " << c << endl;
//
      //if (a <= N) hash[a]=1;
      //if (b <= N) hash[b]=1;
      //if (c <= N) hash[c]=1;
//
        //if (a == 9) cout << "a is 9" << endl;
        //if (b == 9) cout << "b is 9" << endl;
        //if (c == 9) cout << "c is 9" << endl;
        //if (c*c == 226)while(true);

    }
  }






  for (ll i = 1; i <= N; i++)
    if (hash[i] == -1) {
      s++;
    }
  cout << fuck << " " << s << endl;
}

int main () {
  ll in;
  while (cin >> in) {
    solve(in);
  }
  return 0;
}

