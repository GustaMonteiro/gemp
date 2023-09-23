#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define MAXINT 101

struct Sistema {
  int k;
  int pontos[MAXINT];

  Sistema() { memset(pontos, 0, sizeof(int) * MAXINT); }
};

int main() {
  while (true) {
    int g, p;
    cin >> g >> p;
    if (!g && !p)
      break;

    int chegadas[MAXINT][MAXINT];

    for (int i = 0; i < g; i++)
      for (int j = 1; j <= p; j++)
        cin >> chegadas[i][j];

    int s;
    cin >> s;

    Sistema sistemas[11];

    for (int i = 0; i < s; i++) {
      cin >> sistemas[i].k;
      for (int j = 1; j <= sistemas[i].k; j++)
        cin >> sistemas[i].pontos[j];
    }

    for (int i = 0; i < s; i++) {
      int pontos[101];
      memset(pontos, 0, sizeof(int) * 101);

      auto &sistema = sistemas[i];

      int pontuacaoMaxima = 0;

      for (int j = 0; j < g; j++)
        for (int k = 1; k <= p; k++) {
          pontos[k] +=
              sistema.k >= chegadas[j][k] ? sistema.pontos[chegadas[j][k]] : 0;
          if (pontos[k] > pontuacaoMaxima)
            pontuacaoMaxima = pontos[k];
        }
      bool jaPrintou = false;
      for(int i=1; i <= p; i++) {
        if(pontos[i] == pontuacaoMaxima){
            if(jaPrintou) cout << " ";
            cout << i;
            jaPrintou = true;
        }
      }
      cout << '\n';
    }
  }

  return 0;
}