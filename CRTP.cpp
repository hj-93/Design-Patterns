#include <iostream>
#include <chrono>
struct Base
{
    Base() = default;
    virtual void print() {std::cout << "this is Base!\n";}
    virtual ~Base() = default;
};

struct Derived: Base
{
    Derived() = default;
    void print() override 
    {
        /*std::cout << "this is Derived!\n";*/
    }
    ~Derived() = default;
};

template<typename T>
struct CRTPBase
{
    CRTPBase() = default;
    void print()
    {
        static_cast<T*>(this)->print();
    }
    virtual ~CRTPBase() = default;
};

struct CRTPDerived: CRTPBase<CRTPDerived>
{
    CRTPDerived() = default;
    void print() 
    {
        /*std::cout << "this is CRTPDerived!\n";*/
    }
    ~CRTPDerived() = default;
};

int main()
{
    Derived derived;
    Base* base = &derived;
    
    auto t1 = std::chrono::high_resolution_clock::now();
    for (int i = 1000; i>0; --i) {base->print();}
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
    std::cout << duration << std::endl;
    
    CRTPDerived CrtpDerived;
    CRTPBase<CRTPDerived>* CrtpBase = &CrtpDerived;
    
    t1 = std::chrono::high_resolution_clock::now();
    for (int i = 1000; i>0; --i) {CrtpBase->print();}
    t2 = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
    std::cout << duration << std::endl;
    
}
