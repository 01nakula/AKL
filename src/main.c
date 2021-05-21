#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "include/lexer.h"

#define MAX 20

char* read_filepath(const char* filepath);
void print_help();

int main(int argc, char* argv[]) {
  if (argc >= 2) { /*read from file*/
    for (int i = 1; i < argc; i++) {
      int l = strlen(argv[i]);
      char* exten = &argv[i][l - 4];

      /*verify akl extension*/
      if (strcmp(exten, ".akl") == 0) {
        printf("--READING FROM: %s --\n", argv[i]);
        lexer_T* lexer = init_lex(read_filepath(argv[i]));
        token_T* tok = (void*)0;

        while ((tok = lex_get_n_token(lexer)) != (void*)0) {
	  printf("TOKEN(%d, %s)\n", tok->type, tok->value);
        }
        printf("\n\n");
      } else {
	print_help();
      }
    }
  } else { /*read from stdin*/
    char input[MAX];
    printf("AKL language v. 0.0.1\nCreated by Neelam Akula\n>>> ");
  }

  return 0;
}

/*print usage instructions*/
void print_help() {
  printf("Usage:\nakl <filename1>.akl [<filename2>.akl] ...\n");
  exit(1);
}

/*return string from filepath*/
char* read_filepath(const char* filepath) {
  char* buffer = 0;
  long length;

  FILE* f = fopen(filepath, "rb");

  if (f) {
    fseek(f, 0, SEEK_END);
    length = ftell(f);
    fseek(f, 0, SEEK_SET);

    buffer = calloc(length, length);

    if (buffer)
      fread(buffer, 1, length, f);

    fclose(f);
    return buffer;
  }

  printf("Error reading file: %s\n", filepath);
  exit(2);
}

