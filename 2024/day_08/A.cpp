#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define nl "\n"

using str = string;
using ll = long long;
using ld = long double;

int const MOD = 1e9 + 7;
int n;
std::vector<str> s;
std::vector<str> antinodesMap;
std::vector<std::vector<pair<int, int>>> antennas(62);

bool inBound(pair<int, int> point) {
   return (point.first > -1 && point.first < n && point.second > -1 && point.second < n);
}

void drawTwoAntinodes(pair<int, int> a, pair<int, int> b) {
   pair<int, int> x, y;
   int xDelta = (a.first - b.first);
   int yDelta = (a.second - b.second);
   x = {a.first + xDelta, a.second + yDelta};
   y = {b.first - xDelta, b.second - yDelta};
   if (inBound(x)) {
      antinodesMap[x.first][x.second] = '#';
   }
   if (inBound(y)) {
      antinodesMap[y.first][y.second] = '#';
   }
}

void drawAntinodesInLine(pair<int, int> a, pair<int, int> b) {
   pair<int, int> x, y;
   int xDelta = (a.first - b.first);
   int yDelta = (a.second - b.second);
   pair<int, int> startPoint = {a.first - xDelta * 50, a.second - yDelta * 50};
   pair<int, int> point = startPoint;
   for (int i = 0; i < 100; i++, point.first += xDelta, point.second += yDelta) {
      if (inBound(point)) {
         antinodesMap[point.first][point.second] = '#';
      }
   }
}

void solve() {

   cin >> n;
   s.resize(n);
   antinodesMap.resize(n);
   for (int i = 0; i < n; i++) {
      antinodesMap[i].resize(n, '.');
   }
   for (int i = 0; i < n; i++) {
      cin >> s[i];
   }
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         char c = s[i][j];
         if (c != '.') {
            if (c < 65) {
               antennas[c - 48].pb({i, j});
            } else if (c < 97) {
               antennas[c - 55].pb({i, j});
            } else {
               antennas[c - 61].pb({i, j});
            }
         }
      }
   }
   for (int i = 0; i < 62; i++) {
      for (int j = 0; j < antennas[i].size(); j++) {
         for (int k = j + 1; k < antennas[i].size(); k++) {
            drawAntinodesInLine(antennas[i][j], antennas[i][k]);
         }
      }
   }
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         cout << antinodesMap[i][j];
      }
      cout << nl;
   }
   int ans = 0;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         if (antinodesMap[i][j] == '#') {
            ans++;
         }
      }
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