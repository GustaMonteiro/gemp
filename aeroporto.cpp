#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main() {
  int teste = 1;
  while (true) {
    int a, v;
    cin >> a >> v;
    if (!a and !v)
      return 0;

    vector<int> arestas[a + 1];
    for (int i = 1; i <= v; i++) {
      int x, y;
      cin >> x >> y;
      arestas[x].push_back(y);
      arestas[y].push_back(x);
    }

    int maior = 0;
    for (int i = 1; i <= a; i++) {
      if (arestas[i].size() > maior)
        maior = arestas[i].size();
    }

    printf("Teste %d\n", teste);
    bool flag = false;
    for (int i = 1; i <= a; i++) {
      if (arestas[i].size() == maior) {
        if (flag)
          printf(" ");
        printf("%d", i);
        flag = true;
      }
    }

    printf("\n\n");

    teste++;
  }
  return 0;
}
