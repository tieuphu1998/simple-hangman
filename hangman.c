#include <stdio.h>

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
