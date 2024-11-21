#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;
using vb = vector<bool>;

ll N;
vb sieve;
vl primes;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  sieve = vb(1000001, true);
  sieve[0] = false;
  sieve[1] = false;
  for (auto i = 2; i <= 1000000; ++i) {
    if (!sieve[i]) continue;

    primes.push_back(i);
    for (auto j = i + i; j <= 1000000; j += i) {
      sieve[j] = false;
    }
  }

  cin >> N;
  while (0 < (N--)) {
    ll S;
    cin >> S;

    auto div = false;
    for (const auto& p : primes) {
      if (S % p == 0) {
        cout << "NO\n";
        div = true;
        break;
      }
    }

    if (!div) {
      cout << "YES\n";
    }
  }

  return 0;
}