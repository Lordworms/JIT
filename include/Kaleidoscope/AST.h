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

 private:
 
};
};  // namespace