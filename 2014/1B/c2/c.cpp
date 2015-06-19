#include <iostream>
using namespace std;

typedef long long ll;
#define dim 1330 
struct z {
  ll code;
  ll status;
  ll parent;
};
z zip[dim];
ll verticies[dim][dim];
string ans;


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
    if (zip[i] != -1) {
      bestidx = i;
      break;
    }
  for (ll i = 0; i < dim; i++)
    if (zip[i] != -1 && zip[i] < zip[bestidx])
      bestidx = i;

  recurse(bestidx);
}

int main () {
  ll tcases;
  cin >> tcases;
  for (ll cas = 1; cas <= tcases; cas++)
    doit(cas);
  return 0;
}
