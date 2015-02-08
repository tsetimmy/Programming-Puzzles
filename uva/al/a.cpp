#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <cassert>
using namespace std;

typedef unsigned long long ll;

ll fact[21];
ll hash[26];
ll lessthan[26];
vector<pair<ll,ll> > numerator;
vector<pair<ll,ll> > denominator;

bool isprime (ll num) {
  if (num == 1 || num == 2 || num == 3) return true;
  if (num % 2 == 0) return false;

  for (ll i = 2; i <= num - 1; i++) {
    if (num % i == 0) return false;
  }

  return true;



}

ll get () {
  ll nn = 1;
  ll dd = 1;
  if (numerator.empty()) return 0;

  for (ll i = 0; i < numerator.size(); i++) {
    if (numerator[i].second == 0) {
      continue;
    }
    assert(isprime(numerator[i].first));
    nn *= pow(numerator[i].first, numerator[i].second);
  }

  for (ll i = 0; i < denominator.size(); i++) {
    if (denominator[i].second == 0) {
      continue;
    }
    assert(isprime(denominator[i].first));
    dd *= pow(denominator[i].first, denominator[i].second);
  }

  if (nn % dd != 0) {
    cout << "WARNING" << endl;
  }
  assert(dd == 1);
  return nn / dd;
}

void put (vector<pair<ll,ll> >* ptr, ll num) {
  pair<ll, ll> temp;
  if (ptr->empty()) {
    goto ADDNEW;
  }

  for (ll i = 0; i < ptr->size(); i++) {
    if ((*ptr)[i].first == num) {
      (*ptr)[i].second++;
      return;
    }
  }

  ADDNEW:
  temp.first = num;
  temp.second = 1;
  ptr->push_back(temp);
}

void factorenter (vector<pair<ll,ll> >* ptr, ll num) {
  ll divisor = 2;
  if (num == 1) {
    put(ptr, num);
  }
  while (num != 1) {
    while (num % divisor == 0) {
      put(ptr, divisor);
      num /= divisor;
    }
    divisor++;
  }
}

void insert (vector<pair<ll,ll> >* ptr, ll num) {
  while (num >= 1) {
    factorenter(ptr, num);
    num--;
  }
}

void simplify () {
  for (ll i = 0; i < denominator.size(); i++) {
    for (ll j = 0; j < numerator.size(); j++) {
      if (denominator[i].second == 0) break;
      if (numerator[j].second == 0) continue;

      if (denominator[i].first == numerator[j].first) {
        if (denominator[i].second > numerator[j].second) {
          denominator[i].second -= numerator[j].second;
          numerator[j].second = 0;
        } else if (denominator[i].second < numerator[j].second) {
          numerator[j].second -= denominator[i].second;
          denominator[i].second = 0;
        } else {
          numerator[j].second = 0;
          denominator[i].second = 0;
        }
        break;
      }
    }
  }
}

ll doit (string line) {
  if (line.size() == 1) {
    return 0;
  }

  for (ll i = 0; i < 26; i++) {
    hash[i] = 0;
    lessthan[i] = 0;
  }

  ll ret = 0;

  for (ll i = 0; i < line.size(); i++) {
    if (line[i] < line[0]) {
      lessthan[(ll)(line[i] - 'a')] = 1;
    }
    hash[(ll)(line[i] - 'a')]++;
  }

  numerator.clear();
  denominator.clear();
  for (ll i = 0; i < 26; i++) {
    if (lessthan[i]) {
      insert(&numerator, line.size() - 1);
      for (ll j = 0; j < 26; j++) {

        if (i == j && hash[j] != 0) {
          insert(&denominator, hash[j] - 1);
        } else if (hash[j] != 0) {
          insert(&denominator, hash[j]);
        }
      }
      simplify();
      ret += get();
      denominator.clear();
      numerator.clear();

    }
  }
 return ret + doit(line.substr(1, line.size() - 1));
}

void print (ll num) {
  ll t = num;
  ll count = 0;
  while (t != 0) {
    t /= 10;
    count++;
  }

  for (ll i = 0; i < 10 - count; i++) {
    cout << " ";
  }
  cout << num << endl;
}



int main () {
  fact[0] = 1;
  for (ll i = 1; i <= 20; i++) {
    fact[i] = i * fact[i - 1];
  }

//  for (ll i = 1; i <= 20; i++) {
//    cout << fact[i] << endl;
//  }



  string line;

  while (true) {
    cin >> line;
    if (line == "#") break;
    print(doit(line) + 1);
  }


  return 0;
}
