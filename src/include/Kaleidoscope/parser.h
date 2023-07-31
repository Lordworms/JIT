/*
  https://llvm.org/docs/tutorial/MyFirstLanguageFrontend/LangImpl02.html
*/
#include <Kaleidoscope/AST.h>
namespace Kaleidoscope {
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
std::unique_ptr<PrototypeAST> LogErrorP(const char *Str);
static std::unique_ptr<ExprAST> ParseExpression(); 
static std::unique_ptr<ExprAST> ParseNumberExpr();
static std::unique_ptr<ExprAST> ParseIdentifierExpr();
static std::unique_ptr<ExprAST> ParsePrimary();
static std::unique_ptr<ExprAST> ParseBinOpRHS(int ExprPrec, std::unique_ptr<ExprAST> LHS);
static std::unique_ptr<FunctionAST> ParseDefination();
static std::unique_ptr<PrototypeAST> ParsePrototype();
static std::unique_ptr<PrototypeAST> ParseExtern();
static void HandleDefinition();
}