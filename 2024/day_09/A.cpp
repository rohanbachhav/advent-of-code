#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define nl "\n"

using str = string;
using ll = long long;
using ld = long double;

int const MOD = 1e9 + 7;
int n;
str s;

void solve() {

   cin >> n;
   cin >> s;

   std::vector<ll> new_s;

   std::vector<ll> blocksOfFile;
   ll num = 0;
   for (int i = 0; i < n; i++) {
      int len = s[i] - 48;
      if (i & 1) {
         for (int j = 0; j < len; j++) {
            new_s.pb(-1);
         }
      }
      else {
         for (int j = 0; j < len; j++) {
            new_s.pb(num);
            blocksOfFile.pb(num);
         }
         num++;
      }
   }

   int pos = blocksOfFile.size() - 1;
   int new_n = new_s.size();

   std::vector<ll> final;
   for (int i = 0; i < blocksOfFile.size(); i++) {
      if (final.size() >= new_n) break;
      if (new_s[i] != -1) {
         final.pb(new_s[i]);
      } else {
         final.pb(blocksOfFile[pos]);
         pos--;
      }
   }

   ll ans = 0;
   for (int i = 0; i < final.size(); i++) {
      if (final[i] == -1) break;
      ans += i * final[i];
   }


   cout << nl;
   cout << new_s.size() << nl;
   cout << final.size() << nl;

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