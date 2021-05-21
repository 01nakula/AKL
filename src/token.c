#include <stdlib.h>
#include "include/token.h"

token_T* init_token(int type, char* value) {
  token_T* tok = calloc(1, sizeof(struct TOKEN_STRUCT));
  tok->type = type;
  tok->value = value;

  return tok;
}
