#include <iostream>
#include <sstream>
#include <cassert>
using namespace std;

typedef long long ll;
#define dim 1330 
struct z {
  ll code;
  ll status;
  ll parent;
};
z zip[dim];
z zip_copy[dim];
ll verticies[dim][dim];
string ans;

string tostring (ll integer) {
  string ret;
  ostringstream convert;
  convert << integer;
  ret = convert.str();
  return ret;
}

ll get (ll idx) {
  for (ll i = 0; i < dim; i++) {
    if (verticies[idx][i] != -1 && zip[i].code != -1 && zip[i].status == 0) {
      goto NEX;
    }
  }
  return -1;

  NEX:
  ll bidx;
  for (ll i = 0; i < dim; i++)
    if (verticies[idx][i] != -1 && zip[i].code != -1 && zip[i].status == 0) {
      bidx = i;
      break;
    }
  for (ll i = 0; i < dim; i++)
    if (verticies[idx][i] != -1 && zip[i].code != -1 && zip[i].status == 0 && zip[i].code < zip[bidx].code)
      bidx = i;
  return bidx;
}

ll get_next (ll curr) {
  for (ll i = 0; i < dim; i++)
    if (zip[i].code != -1 && zip[i].status == 0)
      goto NEXT;
  return -1;

  NEXT:
  ll bidx;
  for (ll i = 0; i < dim; i++)
    if (zip[i].code != -1 && zip[i].status == 0) {
      bidx = i;
      break;
    }
  for (ll i = 0; i < dim; i++)
    if (zip[i].code != -1 && zip[i].status == 0 && zip[i].code < zip[bidx].code)
      bidx = i;
  return bidx;
}

void recurse_check (ll idx) {
  assert(zip_copy[idx].code != -1);
  assert(zip_copy[idx].status != 2);
  zip_copy[idx].status = 2;
  for (ll i = 0; i < dim; i++)
    if (verticies[idx][i] != -1 && zip_copy[i].status != 2) {
      assert(zip_copy[i].code != -1);
      recurse_check(i);
    }
}

bool check_connected (ll curr) {
  for (ll i = 0; i < dim; i++) {
    zip_copy[i].code = zip[i].code;
    zip_copy[i].status = zip[i].status;
    zip_copy[i].parent = zip[i].parent;
  }
  recurse_check(curr);
  for (ll i = 0; i < dim; i++)
    if (zip_copy[i].code != -1 && zip_copy[i].status != 2)
      return false;
  return true;
}

void recurse (ll idx, ll p) {
  ans += tostring(zip[idx].code);
  zip[idx].status++;

  ll next;
  while ((next = get_next(idx)) != -1) {
    bool flag = false;
    for (ll i = 0; i < dim; i++)
      if (verticies[idx][i] == 1 && i == next) {
        recurse(i, idx);
        flag = true;
        break;
      }
    if (p == -1 && flag == false) {
      ll n;
      while ((n = get(idx)) != -1) {
        recurse(n, idx);
      }
    } else {
      if (flag == false) {
        ll curr_status = zip[idx].status;
        zip[idx].status = 2; // DEAD status
        bool connected = check_connected(p);
        zip[idx].status = curr_status;
        if (connected) {
          zip[idx].status = 2;
          return;
        } else {
          ll n;
          while ((n = get(idx)) != -1) {
            recurse(n, idx);
          }
        }
      }
    }
  }
  zip[idx].status = 2;
}

void initialize () {
  ans = "";
  for (ll i = 0; i < dim; i++) {
    zip[i].code = -1;
    zip[i].status = 0;
    zip[i].parent = -1;
  }
  for (ll i = 0; i < dim; i++)
    for (ll j = 0; j < dim; j++)
      verticies[i][j] = -1;
}

void doit (ll cas) {
  initialize();
  ll M, N;
  cin >> M >> N;
  for (ll i = 0; i < M; i++)
    cin >> zip[i + 1].code;
  ll t1, t2;
  for (ll i = 0; i < N; i++) {
    cin >> t1 >> t2;
    verticies[t1][t2] = 1;
    verticies[t2][t1] = 1;
  }

  ll bestidx;
  for (ll i = 0; i < dim; i++)
    if (zip[i].code != -1) {
      bestidx = i;
      break;
    }
  for (ll i = 0; i < dim; i++)
    if (zip[i].code != -1 && zip[i].code < zip[bestidx].code)
     bestidx = i;

  recurse(bestidx, -1);
  cout << "Case #" << cas << ": " << ans << endl;
}

int main () {
  ll tcases;
  cin >> tcases;
  for (ll cas = 1; cas <= tcases; cas++)
    doit(cas);
  return 0;
}
