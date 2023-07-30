/*
  https://llvm.org/docs/tutorial/MyFirstLanguageFrontend/LangImpl02.html
*/
#include <AST.h>

#include <cctype>
#include <cstdio>
#include <map>
#include <memory>
#include <string>
#include <utility>
#include <vector>
enum Token {
  tok_eof = -1,

  tok_def = -2,
  tok_extern = -3,

  tok_identifier = -4,
  tok_number = -5
};

static std::string IdentifierStr;
static double NumVal;
static int CurTok;
static int getNextToken();
static std::map<char, int> BinopPrecedence;
static int GetTokPrecedence();
std::unique_ptr<ExprAST> LogError(const char *Str);
static std::unique_ptr<ExprAST> ParseExpression(); 
static std::unique_ptr<ExprAST> ParseNumberExpr();