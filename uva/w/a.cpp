#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long ull;
#define dim 102
void getprimes();
void doit(ull);
void factorize(ull);
void print(ull);
void printjustify(ull);
bool isprime(ull);

vector<ull> primes;
ull map[dim];

int main () {
  getprimes();

  ull input;

  while (true) {
    cin >> input;
    if (input == 0) break;
    doit(input);
    print(input);
  }



  return 0;
}

bool isprime (ull num) {
  if (num == 2 || num == 3) {
    return true;
  }
  if ((num - 1)%6 != 0 && (num + 1)%6 != 0) {
    return false;
  }

  for (ull i = 2; i * i <= num; i++) {
    if (num % i == 0) {
      return false;
    }
  }

  return true;
}

void doit (ull num) {
  for (ull i = 0; i < dim; i++) {
    map[i] = 0;
  }

  while (num > 1) {
    factorize(num);
    num--;
  }

}

void factorize (ull num) {
  ull idx = 0;

  while (num > 1) {
    while (num % primes[idx] == 0) {
      num /= primes[idx];
      map[idx]++;
    }
    idx++;
  }
}

void getprimes() {
  primes.clear();
  ull count = 0;
  ull test = 2;

  while (count < dim) {
    if (isprime(test)) {
      primes.push_back(test);
      count++;
    }
    test++;
  }

}

void printjustify (ull num) {
  ull t = num;
  ull count = 0;

  while (t > 0) {
    count++;
    t /= 10;
  }

  for (ull i = 0; i < 3 - count; i++) {
    cout << " ";
  }
  cout << num;
}

void print (ull num) {
  ull idx;

  for (ull i = dim - 1; i >= 0; i--) {
    if (map[i] != 0) {
      idx = i;
      break;
    }
  }

  printjustify(num);
  cout << "! =";
  for (ull i = 0; i <= idx; i++) {
    if (i != 0 && i % 15 == 0) {
      cout << endl;
      cout << "      ";
    }
    printjustify(map[i]);
  }
  cout << endl;
}
