#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define nl "\n"

using str = string;
using ll = long long;
using ld = long double;

int const MOD = 1e9 + 7;

void solve() {

   int n = 1000;
   std::vector<ll> a(n), b(n);
   for (int i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
   }
   sort(a.begin(), a.end());
   sort(b.begin(), b.end());
   ll ans = 0;
   for (int i = 0; i < n; i++) {
      ans += abs(a[i] - b[i]);
   }
   cout << ans << nl;

}

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);

   int TESTCASES = 1;
   // cin >> TESTCASES;

   while (TESTCASES--) {
      solve();
   }
   return 0;
}