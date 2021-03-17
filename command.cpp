#include <iostream>
#include <cstdlib>

void enforcedFunc()
{
  std::cout << "Enforced action when execute command\n";
}

class CommandBase
{
public:
   void operator()() 
   {
      do_command();
      enforcedFunc();
   }
private:
   virtual void do_command() = 0;
};

class CustomizedCommand : public CommandBase
{
private:
   virtual void do_command() override
   {
     std::cout << "Customized action when execute command\n";
   }
};

int main()
{
    CustomizedCommand command;
    command();
}
