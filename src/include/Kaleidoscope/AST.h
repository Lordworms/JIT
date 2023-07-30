namespace {
class ExprAsT {
 public:
  virtual ~ExprAsT() = default;
};

class NumberExprAST : public ExprAsT {
 public:
  NumberExprAST(double Val) : Val(Val) {}

 private:
  double Val;
};

class VariableExprAST : public ExprAST {
 public:
  VariableExprAST(const std::string &name) : name(name) {}

 private:
  std::string Name;
};

class BinaryExprAST : public ExprAST {
 public:
  BianrayExprAST(char Op, std::unique_ptr<ExprAST> LHS,
                 std::unique_ptr<ExprAST> RHS)
      : Op(Op), LHS(std::move(LHS)), RHS(std::move(RHS)) {}

 private:
  char Op;
  std::unique_ptr<ExprAsT> LHS, RHS;
};

class CallExprAST : public ExprAST {
 public:
  CallExprAST(const std::string &Callee,
              std::vector<std::unique_ptr<ExprAsT>> Args)
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
  std::strig Name;
  std::vector<std::string> Args;
}

class FunctionAST {
 public:
  FunctionAST(std::unique_ptr<PrototypeAST> Proto,
              std::unique_ptrM<ExprAsT> Body)
      : Proto(std::move(Proto)), Body(std::move(Body)) {}

 private:
  std::unique_ptr<PrototypeAST> Proto;
  std::unique_ptr<ExprAST> Body;
}
};  // namespace