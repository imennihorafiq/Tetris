#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#define KORN "\x1B[31m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"
#define KMAG "\x1B[35m"
#define KCYN "\x1B[36m"
#define KWHT "\x1B[37m"
#define KRED "\x1B[91m"
void fiqur(int i, int j, int g[j][j], int o, int u) { //i kordinat, j arrayin boyutu, g array, o parcanin numarasi, u parcanin yaratilacagi yukseklik
  switch (o) {
  case 1:
    g[u][i] = 1;
    g[u - 1][i] = 1;
    g[u - 2][i] = 1;
    break;
  case 2:
    g[u][i] = 1;
    g[u - 1][i] = 1;
    break;
  case 3:
    g[u][i] = 1;
    break;
  case 4:
    g[u][i] = 1;
    g[u - 1][i] = 1;
    g[u - 2][i] = 1;
    g[u][i + 1] = 1;
    break;
  case 5:
    g[u][i] = 1;
    g[u][i + 1] = 1;
    g[u - 1][i + 1] = 1;
    g[u - 1][i + 2] = 1;
    break;
  case 6:
    g[u][i] = 1;
    g[u][i + 1] = 1;
    g[u - 1][i + 1] = 1;
    g[u - 1][i] = 1;
    break;
  case 7:
    g[u][i] = 1;
    g[u][i + 1] = 1;
    g[u][i + 2] = 1;
    break;
  case 8:
    g[u][i] = 1;
    g[u][i + 1] = 1;
    break;
  case 10:
    g[u][i] = 1;
    g[u - 1][i] = 1;
    g[u - 1][i + 1] = 1;
    g[u - 1][i + 2] = 1;
    break;
  case 11:
    g[u][i] = 1;
    g[u - 1][i] = 1;
    g[u - 1][i - 1] = 1;
    g[u - 2][i - 1] = 1;
    break;
  case 16:
    g[u][i] = 1;
    g[u - 1][i] = 1;
    g[u - 2][i] = 1;
    g[u - 2][i - 1] = 1;
    break;
  case 22:
    g[u][i] = 1;
    g[u][i + 1] = 1;
    g[u][i + 2] = 1;
    g[u - 1][i + 2] = 1;
    break;
  }
}
void fiqur_show(int o) {
  printf("shape:\n");
  switch (o) {
  case 1:
    printf("[ ]\n[ ]\n[-]\n");
    break;
  case 2:
    printf("[ ]\n[-]\n");
    break;
  case 3:
    printf("[-]\n");
    break;
  case 4:
    printf("[ ]\n[ ]\n[-][ ]\n");
    break;
  case 5:
    printf("   [ ][ ]\n[-][ ]\n");
    break;
  case 6:
    printf("[ ][ ]\n[-][ ]\n");
    break;
  case 7:
    printf("[-][ ][ ]\n");
    break;
  case 8:
    printf("[-][ ]\n");
    break;
  case 10:
    printf("[ ][ ][ ]\n[-]\n");
    break;
  case 11:
    printf("[ ]\n[ ][ ]\n   [-]\n");
    break;
  case 16:
    printf("[ ][ ]\n   [ ]\n   [-]\n");
    break;
  case 22:
    printf("      [ ]\n[-][ ][ ]\n");
    break;
  }
}
int fiqur_rotate(int o) {
  if (o == 1 || o == 2 || o == 4 || o == 5 || o == 10 || o == 16) {
    o += 6;
  } else if (o == 7 || o == 8 || o == 11) {
    o -= 6;
  } else if (o == 22) {
    o = 4;
  }
  return o;
}
void oyun(int x);
void menu(int x) {
  int f;
  printf(" _______________ \n|    %sT%sE%sT%sR%sI%sS%s     |\n|1.play new game|\n|2.exit the game|\n|_______________|\n", KRED, KORN, KYEL, KGRN, KCYN, KMAG, KWHT);
  scanf("%d", & f);
  switch (f) {
  case 1:
    oyun(x);
    break;
  case 2:
    exit(EXIT_FAILURE);
    break;
  }
}
void oyun(int x) {
  int a, b, q, z, w, n, m, i, u, o, v, y, h, p, e;
  w = a = q = 0;
  e = x;
  char l;
  int fiqurs[12] = {
    1,
    2,
    3,
    4,
    5,
    6,
    7,
    8,
    10,
    11,
    16,
    22
  };
  srand(time(NULL));
  while (a == 0) {
    printf("%senter the gamefield size(3-10)\n", KWHT);
    scanf("%d", & m); //2D array boyutunu al
    if (m > 3 && m < 11) {
      a = 1;
    } else {
      printf("invalid input\n");
    }
  }
  int array[m][m]; //2D array yarat
  int yukseklik[m];
  for (a = 0; a < m; a++) //2D array 0li yarat
  {
    for (b = 0; b < m; b++) {
      array[a][b] = 0;
    }
  }
  for (b = 0; b < m; b++) {
      yukseklik[b] = 0;
    }
  for (a = 0; a < m; a++) //2D array yazdir
  {
    for (b = 0; b < m; b++) {
      if (array[a][b] == 1) {
        printf("%s[ ]", KGRN);
      } else if (array[a][b] == 0) {
        printf("%s * ", KRED);
      }
    }
    printf("\n");
  }
  for (a = 0; a < m; a++) //altdaki rakamlari yaz
  {
    printf("%s %d ", KWHT, a);
  }
  printf("%s\nR or r to rotate the shape\nM or m to enter the menu\nQ or q to exit the game\n%s", KGRN, KWHT);
  while (q < 1) {
    q = n = 0;
    o = fiqurs[rand() % 12];
    printf("\n%scurrent score:%d\n", KWHT, w);
    while (n == 0) {
      fiqur_show(o);
      scanf(" %c", & l);
      i = (int)(l) - 48;
      if (i < m && i > -1) {
        if (o == 4 || o == 6 || o == 8) {
          if (i < m - 1) {
            n = 1;
          } else {
            printf("\ninvalid input\n");
          }
        } else if (o == 5 || o == 7 || o == 10 || o == 22) {
          if (i < m - 2) {
            n = 1;
          } else {
            printf("\ninvalid input\n");
          }
        } else if (o == 11 || o == 16) {
          if (i > 0) {
            n = 1;
          } else {
            printf("\ninvalid input\n");
          }
        } else {
          n = 1;
        }
      } else if (i == 34 || i == 66) { //r
        o = fiqur_rotate(o);
      } else if (i == 29 || i == 61) { //m
        menu(e);
      } else if (i == 33 || i == 65) { //q
        exit(EXIT_FAILURE);
      } else {
        printf("\ninvalid input\n");
      }
    }
    n = 0;
    for (y = 0; y < m; y++) {
      v = 0;
      u = 0;
      while (u == 0) {
        u = array[v][y];
        v++;
      }
      yukseklik[y] = v - 2;
    }
    if (o == 4 || o == 8 || o == 6) {
      if (yukseklik[i] > yukseklik[i + 1]) {
        u = yukseklik[i + 1];
      } else {
        u = yukseklik[i];
      }
    } else if (o == 5) {
      if (yukseklik[i] > yukseklik[i + 1] || yukseklik[i] - 1 > yukseklik[i + 2]) {
        if (yukseklik[i + 1] > yukseklik[i + 2]) {
          u = yukseklik[i + 2] + 1;
        } else {
          u = yukseklik[i + 1]; 
        }
      } else {
        u = yukseklik[i];
      }
    } else if (o == 7 || o == 22) {
      if (yukseklik[i] > yukseklik[i + 1] || yukseklik[i] > yukseklik[i + 2]) {
        if (yukseklik[i + 1] > yukseklik[i + 2]) {
          u = yukseklik[i + 2];
        } else {
          u = yukseklik[i + 1];
        }
      } else {
        u = yukseklik[i];
      }
    } else if (o == 10) {
      if (yukseklik[i] > yukseklik[i + 1] || yukseklik[i] > yukseklik[i + 2]) {
        if (yukseklik[i + 1] > yukseklik[i + 2]) {
          u = yukseklik[i + 2] + 1;
        } else {
          u = yukseklik[i + 1] + 1;
        }
      } else {
        u = yukseklik[i];
      }
    } else if (o == 11) {
      if (yukseklik[i] > yukseklik[i - 1] + 1) {
        u = yukseklik[i - 1] + 1;
      } else {
        u = yukseklik[i];
      }
    } else if (o == 16) {
      if (yukseklik[i] > yukseklik[i - 1] + 2) {
        u = yukseklik[i - 1] + 2;
      } else {
        u = yukseklik[i];
      }
    } else {
      u = yukseklik[i];
    }
    fiqur(i, m, array, o, u);
    w = w + 10;
    for (b = m; b > 0; b--) {
      z = 0;
      for (a = 0; a < m; a++) //kirmak icin sira ara ve kir
      {
        z = z + array[b][a];
        if (z == m) //sira 1ler varsa
        {
          for (h = b; h > 0; h--) //sirayi kir ve yerleri degis
          {
            for (p = 0; p < m; p++) {
              array[h][p] = array[h - 1][p];
            }
          }
          for (p = 0; p < m; p++) {
            array[0][p] = 0;
          }
          w = w + 50;
        }
      }
    }
    for (a = 0; a < m; a++) //ilk sirayi denetle
    {
      q = q + array[0][a];
    }
    for (a = 0; a < m; a++) //2D array yazdir
    {
      for (b = 0; b < m; b++) {
        if (array[a][b] == 1) {
          printf("%s[ ]", KGRN);
        } else if (array[a][b] == 0) {
          printf("%s * ", KRED);
        }
      }
      printf("\n");
    }
    for (a = 0; a < m; a++) //altdaki rakamlari yaz
    {
      printf("%s %d ", KWHT, a);
    }
    printf("%s\nR or r to rotate the shape\nM or m to enter the menu\nQ or q to exit the game\n%s", KGRN, KWHT);
  }
  if (e < w) {
    e = w;
  }
  printf("\n%sGAME OVER%s\nHIGH SCORE:%d\n", KRED, KWHT, e);
  menu(e);
}
int main() {
  int x = 0;
  menu(x);
  return 0;
}