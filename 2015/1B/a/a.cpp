// Works for both small and large inputs.
#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

typedef long long ll;
ll n, d;
ll c, ans;

ll get_digits (ll num) {
  ll ret = 0;
  while (num != 0) {
    num /= 10;
    ret++;
  }
  return ret;
}

ll reverse (ll num) {
  while (num % 10 == 10)
    num /= 10;
  ll digits = get_digits(num);
  ll ret = 0;
  while (digits > 0) {
    ret += pow(10, digits - 1) * (num % 10);
    num /= 10;
    digits--;
  }
  return ret;
}

ll get_subset (ll num, ll amount) {
  ll ret = 0;
  for (ll i = 0; i < amount; i++) {
    ret += pow(10, i) * (num % 10);
    num /= 10;
  }
  return ret;
}

bool lagging_zeros_and_begin_one (ll tmp) {
  ll digits = get_digits(tmp);
  for (ll i = 0; i < digits - 1; i++) {
    if (tmp % 10 != 0)
      return false;
    tmp /= 10;
  }
  if (tmp == 1)
    return true;
  return false;
}

bool half_zeros (ll tmp, ll half) {
  for (ll i = 0; i < half; i++) {
    if (tmp % 10 != 0)
      return false;
    tmp /= 10;
  }
  return true;
}

void inc_base (ll target) {
  assert(get_digits(c) == get_digits(target));
  ll digits_c = get_digits(c);
  ll half = digits_c / 2;
  if (digits_c % 2 != 0)
    half++;

  ll half_c = get_subset(c, half);
  ll half_t = get_subset(reverse(target), half);

  assert(half_t - half_c > 0);
  ans += half_t - half_c;
  c += half_t - half_c;

  ans++;
  c = reverse(c);

  ans += target - c;
  c = target;
}

void inc_to_n (ll target) {
  assert(get_digits(c) == get_digits(target));
  ll digits = get_digits(c);
  ll half = digits / 2;
  if (digits % 2 != 0)
    half++;

  ll tmp = target - 1;
  for (ll i = 0; i < half; i++)
    tmp /= 10;
  if (lagging_zeros_and_begin_one(tmp)) {
    ans += target - c;
    c = target;
    return;
  }

  tmp = target;
  if (half_zeros(tmp, half)) {
    tmp--;
    ans++;
    inc_base(tmp);
    c++;
    return;
  }
  inc_base(tmp);
}

void doit (ll cas) {
  cin >> n;
  d = get_digits(n);

  c = 10;
  ans = 10;

  cout << "Case #" << cas << ": ";

  if (n <= 20) {
    cout << n << endl;
    return;
  }

  if (d != 2) {
    ll target = 9;
    ll e = 10;
    for (ll i = 0; i < d - 2; i++) {
      target += 9 * e;
      inc_base(target);
      c++;
      ans++;
      e *= 10;
    }
  }
  if (c != n) {
    inc_to_n(n);
  }
  cout << ans << endl;
}

int main () {
  ll tcases;
  cin >> tcases;
  for (ll cas = 0; cas < tcases; cas++)
    doit(cas + 1);
  return 0;
}
