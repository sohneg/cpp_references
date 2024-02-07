// main.cpp

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char input_password[20];
  printf("What's your password?\n");
  scanf("%19s", input_password);

  if (strcmp(input_password, "password") == 0) {
    printf("Well done\n");
  } else {
    printf("Wrong password\n");
  }
  return 0;
}