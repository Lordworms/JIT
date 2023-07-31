#include <iostream>
#include <cctype>
#include <cstdio>
#include <map>
#include <memory>
#include <string>
#include <utility>
#include <vector>
#include <string>
namespace {
class ExprAST {
 public:
  virtual ~ExprAST() = default;
};

class NumberExprAST : public ExprAST {
 public:
  NumberExprAST(double Val) : Val(Val) {}

 private:
  double Val;
};

class VariableExprAST : public ExprAST {
 public:
  VariableExprAST(const std::string &name) : Name(name) {}
 private:
  std::string Name;
};

class BinaryExprAST : public ExprAST {
 public:
  BinaryExprAST(char Op, std::unique_ptr<ExprAST> LHS,
                 std::unique_ptr<ExprAST> RHS)
      : Op(Op), LHS(std::move(LHS)), RHS(std::move(RHS)) {}

 private:
  char Op;
  std::unique_ptr<ExprAST> LHS, RHS;
};

class CallExprAST : public ExprAST {
 public:
  CallExprAST(const std::string &Callee,
              std::vector<std::unique_ptr<ExprAST>> Args)
      : Callee(Callee), Args(std::move(Args)) {}

 private:
  std::string Callee;
  std::vector<std::unique_ptr<ExprAST>> Args;
};

class PrototypeAST {
 public:
  PrototypeAST(const std::string &Name, std::vector<std::string> Args)
      : Name(Name), Args(std::move(Args)) {}

 private:
  std::string Name;
  std::vector<std::string> Args;
};

class FunctionAST {
 public:
  FunctionAST(std::unique_ptr<PrototypeAST> Proto,
              std::unique_ptr<ExprAST> Body)
      : Proto(std::move(Proto)), Body(std::move(Body)) {}

 private:
  std::unique_ptr<PrototypeAST> Proto;
  std::unique_ptr<ExprAST> Body;
};
};  // namespace