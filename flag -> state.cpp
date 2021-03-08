#include <iostream>

class IState 
{
public:
    virtual IState* nextState(bool fresh) = 0;
    virtual std::string getColor() = 0;
    virtual ~IState() {};
    
};

class FreshAppleState : public IState 
{
public:
    IState* nextState(bool fresh) override;
    std::string getColor() override;
};
    
class OldAppleState: public IState 
{
public:
    IState* nextState(bool fresh) override 
    {
        return fresh ? static_cast<IState*>(new FreshAppleState()) : static_cast<IState*>(this);
    }
    std::string getColor() override 
    {
        return "brown";
    }
};

IState* FreshAppleState::nextState(bool fresh) 
{
    return fresh ? static_cast<IState*>(this) : static_cast<IState*>(new OldAppleState());
}
std::string FreshAppleState::getColor() 
{
    return "green";
}

class Apple 
{
public:
    Apple() 
    { 
        m_state = new OldAppleState(); 
    }
    
    std::string getColor() 
    {
        return m_state->getColor();
    }

    void setFresh(bool fresh) 
    {
        m_state = m_state->nextState(fresh);
    }
private:
    IState* m_state;
};

int main()
{
    Apple apple;
    std::cout << apple.getColor() << std::endl;
    apple.setFresh(true);
    std::cout << apple.getColor() << std::endl;
    return 0;
}
