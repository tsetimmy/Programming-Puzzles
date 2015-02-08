#include <iostream>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define maxn 1000000

ull array[maxn];

ull doit (ull num) {
  ull counter = 0;
  while (num != 1) {
    if (num%2 == 0) num = num/2;
    else num = 3*num + 1;
    counter++;
  }
  return counter+1;
}

int main () {
  ull a, b;

  for (ull i = 1; i < maxn; i++) {
    array[i] = doit(i);
  }

  ull m;
  while (cin >> a >> b) {
    cout << a << " " << b << " ";
    if (a > b) {
      ull t = a;
      a = b;
      b = t;
    }
    m = 0;
    for (ull i = a; i <= b; i++) {
      if (array[i] > m) {
        m = array[i];
      }
    }
    cout << m << endl;
  }

  return 0;
}
