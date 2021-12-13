#include <iostream>

struct Base {
    virtual void A() {std::cout << "Funciton Base\n"; }
};

struct Derive : private Base {
  void A() override {std::cout << "Funciton Derived\n"; }
      
  void Injected() const { std::cout << "Injected function!\n"; }
    
  Base const *operator -> () const { Injected(); return this; }
  Base       *operator -> ()       { Injected(); return this; }
};

int main()
{
  Derive instance;
  instance->A();
  instance->Base::A();
}
