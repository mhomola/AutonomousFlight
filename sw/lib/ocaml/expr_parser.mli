type token =
  | INT of (int)
  | FLOAT of (float)
  | IDENT of (string)
  | EOF
  | DOT
  | COMMA
  | SEMICOLON
  | LP
  | RP
  | LC
  | RC
  | LB
  | RB
  | DEREF
  | AND
  | COLON
  | OR
  | EQ
  | GT
  | LT
  | ASSIGN
  | GEQ
  | LEQ
  | NOT
  | PLUS
  | MINUS
  | MULT
  | DIV
  | MOD
  | EXPO

val expression :
  (Lexing.lexbuf  -> token) -> Lexing.lexbuf -> Expr_syntax.expression
