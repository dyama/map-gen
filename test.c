#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define W 64
#define H 32

void gen_map(short* map, int w, int h)
{
  for (int i = 0; i < w * h; i++) {
    map[i] = 1;
  }
  short* p = (map + w * h / 2 + w / 2);
  int c = w * H;
  srand(time(NULL));
  int pd = -1;
  while (c) {
    switch (pd = rand() % 4) {
      case 0:
        if (p - w * 2 < map) {
          continue;
        }
        p -= w;
        *p = 0;
        break;
      case 1:
        if (p + w * 2 > map + w * h) {
          continue;
        }
        p += w;
        *p = 0;
        break;
      case 2:
        if ((p - map) % w - 2 < 0) {
          continue;
        }
        p -= 1;
        *p = 0;
        break;
      case 3:
        if ((p - map) % w + 2 > w) {
          continue;
        }
        p += 1;
        *p = 0;
        break;
    }
    c--;
  }
  *p = 2;
  return;
}

int
main()
{
  short map[W * H];
  char chip[] = { ' ', '#', '%' };

  gen_map(map, W, H);

  for (int i = 0; i < W * H; i++) {
    if (i % W == 0) {
      fprintf(stdout, "\n");
    }
    fprintf(stdout, "%c", chip[map[i]]);
  }

  return 0;
}
