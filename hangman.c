#include <stdio.h>

//#include<stdio.h>
char b[10],tu[10]; // tu[10] la 1 mang ki tu, la tu random duoc chon. b[10] la mang ki tu ***
void in_ra_man_hinh(int n)
{
	int i;
	for(i=1;i<=n;i++) b[i] = 42;
	for(i=1;i<=n;i++) printf("%c ",b[i]); 
}

void hien_tu(char &nhap, int n) // n = so ki tu nhap tu dau
{
	int dem1,i;
	dem1 = 0;
	for(i=1;i<=n;i++) if(nhap==tu[i]) 
	{
	b[i] = tu[i];
	dem1++;
	}
	if(dem1) for(i=1;i<=n;i++) printf("%c ",b[i]);
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
  int net_ve;
  char nhap;
  char tu = lay_random_tu();
  while(net_ve != max) {
    in_ra_man_hinh(tu);
    nhap = nhap_1_ki_tu();
    if(dung) {
      tu = hien_tu(nhap);
      if(full(tu)) {
        printf("Thang\n");
        return 0;
      }
    }
    else {
      ve_1_net();
      net_ve++;
    }
  }
  printf("Thua\n");
  return 0;
}

