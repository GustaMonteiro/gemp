#include <bits/stdc++.h>
using namespace std;

/* NOT WORKING YET */

#define MAXN (int)1e6
#define MAXM (int)1e6

typedef struct {
  int x, y, p;
} Edge;

bool comp(Edge a, Edge b) { return a.p < b.p; }

int root[MAXN];

Edge rod[MAXM];
Edge fer[MAXM];
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

  int n, f, r;
  cin >> n >> f >> r;

  for (int i = 0; i < f; i++)
    cin >> fer[i].x >> fer[i].y >> fer[i].p;

  sort(fer, fer + f, comp);

  int pos = 0;
  for (int i = 0; i < f; i++) {
    if (find(fer[i].x) != find(fer[i].y)) {
      mst[pos++] = fer[i];
      join(fer[i].x, fer[i].y);
    }
  }

  for (int i = 0; i < f; i++)
    cin >> rod[i].x >> rod[i].y >> rod[i].p;

  sort(rod, rod + r, comp);

  for (int i = 0; i < r; i++) {
    if (find(rod[i].x) != find(rod[i].y)) {
      mst[pos++] = rod[i];
      join(rod[i].x, rod[i].y);
    }
  }

  int sum = 0;
  for (int i = 0; i < pos; i++)
    sum += mst[i].p;

  cout << sum << endl;

  return 0;
}
