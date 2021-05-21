#ifndef LEXER_H
#define LEXER_H

#include "token.h"

typedef struct LEXER_STRUCT {
  char c;
  unsigned int i;
  char* contents;
} lexer_T;

lexer_T* init_lex(char* contents);

void lex_adv(lexer_T* lexer);

void lex_whitespace(lexer_T* lexer);

token_T* lex_get_n_token(lexer_T* lexer);

token_T* lex_get_str(lexer_T* lexer);

token_T* lex_get_id(lexer_T* lexer);

token_T* lex_adv_token(lexer_T* lexer, token_T* token);

char* lex_get_char_str(lexer_T* lexer);
#endif
