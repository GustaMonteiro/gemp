#include <bits/stdc++.h>
using namespace std;

#define MAXN (int)1e6
#define MAXM (int)1e6

typedef struct {
  int x, y, p;
} Edge;

bool comp(Edge a, Edge b) { return a.p < b.p; }

int root[MAXN];

Edge e[MAXM];
Edge mst[MAXM];

int find(int x) {
  if (root[x] == x)
    return x;
  else
    return root[x] = find(root[x]);
}

void join(int x, int y) { root[find(x)] = find(y); }

int main() {

  for (int i = 0; i < MAXN; i++)
    root[i] = i;

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++)
    cin >> e[i].x >> e[i].y >> e[i].p;

  sort(e, e + m, comp);

  int pos = 0;
  for (int i = 0; i < m; i++) {
    if (find(e[i].x) != find(e[i].y)) {
      mst[pos++] = e[i];
      join(e[i].x, e[i].y);
    }
  }

  int sum = 0;
  for (int i = 0; i < pos; i++)
    sum += mst[i].p;

  cout << sum << endl;

  return 0;
}
