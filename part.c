#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void in_het_ra(FILE *f) {
  char line[20];
  while(fgets(line, 20, f) != NULL) printf("%s", line);
  fclose(f);
}

void ve_hinh(int net_ve) {
  FILE *f;
  switch (net_ve) {
    case 1:
    f = fopen("net1.txt", "r");
    in_het_ra(f);
    break;
    case 2:
    f = fopen("net2.txt", "r");
    in_het_ra(f);
    break;
    case 3:
    f = fopen("net3.txt", "r");
    in_het_ra(f);
    break;
    case 4:
    f = fopen("net4.txt", "r");
    in_het_ra(f);
    break;
    case 5:
    f = fopen("net5.txt", "r");
    in_het_ra(f);
    break;
    case 6:
    f = fopen("net6.txt", "r");
    in_het_ra(f);
    break;
    default:
    printf("May ong lam cai me j the?\n");
    exit(1);
  }
}

FILE *nap_file(int so_tu) {
  FILE *f;
  switch (so_tu) {
    case 4:
    f = fopen("4tu.txt", "r");
    break;
    case 5:
    f = fopen("5tu.txt", "r");
    break;
    case 6:
    f = fopen("6tu.txt", "r");
    break;
    default:
    printf("Tuan lam cai me j day?\n");
    exit(1);
  }
  return f;
}

void lay_random_tu (FILE *f, char str[]) {
  int a, b = 0;
  char line[10];
  srand(time(NULL));
  a = (rand()%10) + 1;
  while(b != a) {
    fgets(line, 10, f);
    b++;
  }
  strcpy(str, line);
  fclose(f);
}

int main() {
  FILE *f;
  char str[15];
  for(int a = 1; a <= 6; a++) {
    ve_hinh(a);
    printf("\n");
  }
  f = nap_file(4);
  lay_random_tu(f, str);
  printf("%s\n", str);
  return 0;
}
