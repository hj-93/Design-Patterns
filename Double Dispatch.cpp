// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <cstdlib>

class Foo;
class Bar;

void print(Foo*)
{
    std::cout << "this is foo";
}

void print(Bar*)
{
    std::cout << "this is Bar";
}

class Base 
{
public:
  virtual void call() = 0;
};

class Foo: public Base 
{
public:
  virtual void call() override 
  {
    print(this);
  }
};

class Bar : public  Base
{
public:
  virtual void call() override 
  {
    print(this);
  }
};

int main()
{
    Base* ptr = new Foo;
    ptr->call();
}
