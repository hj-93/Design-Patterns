// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <cstdlib>

class DoubleExpr;
class AddExpr;

class ExpressionVisitor
{
public:
  virtual void visit(DoubleExpr* expr) = 0;
  virtual void visit(AddExpr* expr) = 0;
};

class Expression 
{
public:
  virtual void accept(ExpressionVisitor* visitor) = 0;
};

class DoubleExpr: public Expression 
{
public:
  DoubleExpr(double v): value{v}
  {}
  
  virtual void accept(ExpressionVisitor* visitor) override 
  {
    visitor->visit(this);
  }
  double value = 0;
};

class AddExpr: public Expression 
{
public:
  AddExpr(Expression* expr1, Expression* expr2): left{expr1}, right{expr2} 
  {}
  
  virtual void accept(ExpressionVisitor* visitor) override 
  {
    visitor->visit(this);
  }
  
  Expression* left;
  Expression* right;
};

class ExprPrinter : ExpressionVisitor
{
public:
  virtual void visit(DoubleExpr* expr) override 
  {
    std::cout << expr->value;
  }
  virtual void visit(AddExpr* expr) override 
  {
    expr->left->accept(this);
    std::cout << "+";
    expr->right->accept(this);
  }
};

int main()
{
    auto exprPtr = new AddExpr{new DoubleExpr{3}, new DoubleExpr{5}};
    ExprPrinter exprPrinter;
    exprPrinter.visit(exprPtr);
}
