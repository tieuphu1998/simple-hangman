#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void scan_char(char input[]){
  char c[20];
  scanf("%[^\n]", c);
  getchar();
  strcpy(input, c);
}

void print_all_file(FILE *f) {
  char line[60];
  while(fgets(line, 60, f) != NULL) printf("%s", line);
  fclose(f);
}

void draw(int hp) {
  FILE *f;
  char file_head[20] = "net";
  char file_tail[5] = ".txt";
  char file_mid = '0' + hp;
  file_head[3] = file_mid;
  strcat(file_head, file_tail);
  if((f = fopen(file_head, "r")) == NULL) {
    printf("File missing!\n");
    exit(1);
  }
  print_all_file(f);
}

void take_random(char word[]) {
  FILE *f;
  if((f = fopen("lib.txt", "r")) == NULL) {
    printf("File missing!\n");
    exit(1);
  }
  int a, b = 0;
  char line[20];
  srand(time(NULL));
  a = (rand()%10) + 1;
  while(b != a){
    fgets(line, 20, f);
    b++;
  }
  strcpy(word, line);
  fclose(f);
}

int check(char word[], char hidden_word[],char word_used[], char input[]) {
  int i = 0, mode = 0;
  while(1) {
    if(input[0] == word_used[i]) {
      printf("You used this letter before\n");
      return -1;
    }
    i++;
    if(i == strlen(word_used)) break;
  }
  for(i = 0; i <= strlen(word) - 1; i++) {
    if(input[0] == word[i]) {
      hidden_word[i] = word[i];
      word_used[strlen(word_used)] = word[i];
      mode++;
    }
  }
  if(mode != -1) {
    printf("Good job!\n");
    return mode;
  }
  else {
    printf("Wrong answer!\n");
    return -1;
  }
}

void main_gate() {
  FILE *f;
  if((f = fopen("maingate.txt", "r")) == NULL) {
    printf("File missing!\n");
    exit(1);
  }
  print_all_file(f);
  printf("\nEnter any key to play: ");
  char c[20];
  scan_char(c);
}

int main() {
  system("clear");
  main_gate();
  int hp = 0, point = 0;
  char word[30], hidden_word[30], word_used[10], input[20];
  word_used[0] = 42;
  take_random(word);
  word[strlen(word + 1)] = '\0';
  int i;
  for(i = 0; i <= (strlen(word) - 1); i++) hidden_word[i] = 42;
  hidden_word[i + 1] = '\0';
  while(1){
    printf("%s\n", hidden_word);
    if(point == strlen(word)){
      printf("You win!\n");
      break;
    }
    printf("Enter a letter: ");
    scan_char(input);
    int a;
    if((a = check(word, hidden_word, word_used, input)) == -1){
      hp++;
      draw(hp);
      if(hp == 6){
        printf("You lose!\n");
        break;
      }
    }
    else point += a;
  }
  return 0;
}
