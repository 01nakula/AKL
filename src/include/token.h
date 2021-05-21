#ifndef TOKEN_H
#define TOKEN_H

typedef struct TOKEN_STRUCT {
  enum {
	TOKEN_ID,
	TOKEN_STR,
	TOKEN_ADD,
	TOKEN_SUB,
	TOKEN_MUL,
	TOKEN_DIV,
	TOKEN_POW,
	TOKEN_EQUALS,
	TOKEN_GTR,
	TOKEN_LESS,
	TOKEN_SEMI,
	TOKEN_COLON,
	TOKEN_IF,
	TOKEN_COMMA,
	TOKEN_PIPE,
	TOKEN_LPAREN,
	TOKEN_RPAREN,
	TOKEN_LBRACE,
	TOKEN_RBRACE
  } type;
  char* value;
} token_T;

token_T* init_token(int type, char* value);
#endif
