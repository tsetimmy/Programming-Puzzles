// Works for small inputs.
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

typedef long long ll;
ll counter = 0;


ll is_prime (ll num) {
  if (num % 2 == 0)
    return 2;
  for (ll i = 3; i * i <= num; i += 2)
    if (num % i == 0)
      return i;
  return -1;
}

ll convert_base (ll num, ll base) {
  ll ret = 0;
  ll exp = 0;
  ll digit;
  while (num > 0) {
    digit = num % 10;
    num /= 10;
    ret += digit * pow(base, exp);
    exp++;
  }
  return ret;
}

void recurse (ll depth, string in, ll N, ll J) {
  if (counter == J)
    return;
  if (depth == N) {
    if (in[in.size() - 1] == '0')
      return;
    ll a = atol(in.c_str());
    ll prime;
    vector<ll> ans;
    for (ll i = 2; i <= 10; i++) {
      prime = is_prime(convert_base(a, i));
      if (prime == -1)
        return;
      else
        ans.push_back(prime);
    }
    cout << a << " ";
    for (ll i = 0; i < ans.size(); i++)
      cout << ans[i] << " ";
    cout << endl;
    counter++;
    return;
  }
  if (depth == 0) {
    in.push_back('1');
    recurse(depth + 1, in, N, J);
  } else {
    in.push_back('0');
    recurse(depth + 1, in, N, J);
    in = in.substr(0, in.size() - 1);
    in.push_back('1');
    recurse(depth + 1, in, N, J);
  }

}

void doit (ll N, ll J) {
  string in = "";
  recurse(0, in, N, J);
}

int main () {
  cout << "Case #1:" << endl;
  doit(16, 50);
  return 0;
}
