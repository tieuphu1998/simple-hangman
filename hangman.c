#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char b[10],tu[10]; // tu[10] la 1 mang ki tu, la tu random duoc chon. b[10] la mang ki tu ***

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

int hien_tu(char nhap, int n) // n = so ki tu nhap tu dau
{
	int dem,dem1,i;
	dem1 = 0;
  dem = 0;
	for(i=0;i<=n;i++) if(nhap==tu[i])
	{
	b[i] = tu[i];
	dem1++;
  dem++;
	}
  if(dem == 0) return 1;
  else return 0;
}
void cong_chao()
{
	printf("CHAO MUNG DEN VOI TRO CHOI\n");
	printf("\n****   ****      ***      ****   ****  **********         **************************    ");
	printf("\n*  *   *  *     *   *     *   *  *  *  *        *         *                        *    ");
	printf("\n*  *****  *    *  *  *    *     **  *  *   ******         *      *******************    ");
	printf("\n*         *   *       *   *         *  *   *    *****     *     *               *       ");
	printf("\n*  *****  *  *  *****  *  *  **     *  *   ******  *      *    *                *       ");
	printf("\n*  *   *  * *  *     *  * *  *  *   *  *           *      *    *               ***      ");
	printf("\n****   **** ***       *** ****   ****  *************      *    *              *   *     ");
	printf("\n                                                          *    *               ***      ");
	printf("\n****     ****      ***      ****   ****                   *    *                *       ");
	printf("\n*   *   *   *     *   *     *   *  *  *                   *    *                *       ");
	printf("\n*    * *    *    *  *  *    *     **  *                   *    *              * * *     ");
	printf("\n*           *   *       *   *         *        ************    ************     *       ");
	printf("\n*   *   *   *  *  *****  *  *  **     *        *                          *     *       ");
	printf("\n*    * *    * *  *     *  * *  *  *   *        *                          *    * *      ");
	printf("\n****     **** ***       *** ****   ****        ****************************             ");
}
int main() {
  cong_chao();
  FILE *f;
  int net_ve;
  int max = 6;
  char nhap;
  int so_tu, dem;
int ktra,i,j;
char check[10],b[10];
  printf("\n\nBan muon chon bao nhieu tu? (4/5/6): ");
  scanf("%d", &so_tu);
  for(int i=0;i<so_tu;i++) 
	  b[i] = 42;
	f = nap_file(so_tu);
  lay_random_tu(f, tu);
  while(net_ve != max) {
    printf("%s\n", b);
    printf("\nDoan 1 ki tu: ");
    i=0;i++;
	  do{
	ktra =0;
	scanf("%c", &nhap); // chuong trinh chong nhap lai
	check[i] = nhap;
	for(j=i-1;j>=0;j--) if(check[i]==check[j]) ktra = 1; 
	if(ktra == 1) printf("Da ton tai. Nhap ki tu khac: ");	
	}while(ktra==1);
    if (hien_tu(nhap, so_tu) == 0) {
      dem++;
      if(dem == so_tu) {
        printf("Chuc mung! Ban da thang!\n");
        return 0;
      }
    }
    else {
      net_ve++;
      ve_hinh(net_ve);
    }
  }
  printf("Rat tiec! Ban da thua!\n");
  return 0;
}
