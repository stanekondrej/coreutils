#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Incorrect amount of arguments\n");
    exit(1);
  }

  FILE *file = fopen(argv[1], "r");
  if (file == NULL) {
    printf("The file does not exist\n");
    exit(1);
  }

  fseek(file, 0L, SEEK_END);
  long size = ftell(file);
  char buffer[size]; // buffer for the whole file
  char line[size];   // buffer for one line
  rewind(file);

  while (fgets(line, size, file)) {
    strcat(buffer, line);
  }
  fclose(file);

  printf("%s", buffer);
}
