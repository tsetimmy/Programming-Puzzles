// Works for both small and large inputs.
#include <iostream>
using namespace std;

typedef unsigned long long ull;
bool table[10];

void populate (ull in) {
  ull digit;
  while (in > 0) {
    digit = in % 10;
    in /= 10;
    table[digit] = true;
  }
}

bool done () {
  for (ull i = 0; i < 10; i++) {
    if (!table[i])
      return false;
  }
  return true;
}

void doit (ull in, ull cas) {
  if (in == 0) {
    cout << "Case #" << cas << ": " << "INSOMNIA" << endl;
    return;
  }
  ull original = in;
  for (ull i = 0; i < 10; i++)
    table[i] = false;

  while (true) {
    populate(in);
    if (done()) {
      cout << "Case #" << cas << ": " << in << endl;
      return;
    }
    in += original;
  }
}

int main () {
  ull tcases;
  cin >> tcases;
  for (ull cas = 1; cas <= tcases; cas++) {
    ull in;
    cin >> in;
    doit(in, cas);
  }
  return 0;
}
