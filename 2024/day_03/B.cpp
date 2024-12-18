#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define nl "\n"

using str = string;
using ll = long long;
using ld = long double;

int const MOD = 1e9 + 7;
std::vector<pair<ll, ll>> v;
str s;
int n;

ll giveNumber(int &i) {
   str num = "0";
   while (i < n && s[i] >= '0' && s[i] <= '9') {
      num += s[i];
      i++;
   }
   return stoi(num);
}

void solve() {

   getline(cin, s);
   n = s.size();
   bool canDo = true;
   for (int i = 0; i < n; i++) {
      if (s[i] == 'd') {
         if (s.substr(i, 4) == "do()") {
            canDo = true;
            i += 4;
         } else if (s.substr(i, 7) == "don't()") {
            canDo = false;
            i += 7;
         }
      }
      if (s[i] == 'm' && canDo) {
         if (s.substr(i, 4) == "mul(") {
            ll a = 0, b = 0;
            i += 4;
            a = giveNumber(i);
            if (s[i] == ',') {
               i += 1;
               b = giveNumber(i);
               if (s[i] == ')') {
                  v.pb({a, b});
               }
            }
         }
      }
   }
   ll ans = 0;
   for (int i = 0; i < v.size(); i++) {
      ans += v[i].first * v[i].second;
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