#include <iostream>
#include <sstream>
#include <cstdlib>

struct Shape
{
    virtual std::string str() const = 0;
};

struct Square : Shape
{
    Square(int size) : m_size{size}
    {}
    std::string str() const override
    {
        std::ostringstream oss;
        oss << "A square with size " << m_size ;
        return oss.str();
    }
    
    void resize(int size)
    {
        m_size = size;
    }
    
    int m_size;
};

template <typename T>
struct ColoredShape : T
{
    template <typename... Args>
    ColoredShape(std::string color, Args ...args) : T(std::forward<Args>(args)...), m_color{color}
    {}
    
    std::string str() const override
    {
        std::ostringstream oss;
        oss << T::str() << " has color " << m_color;
        return oss.str();
    }
    
    std::string m_color;
};

template <typename T>
struct TransparentShape : T
{
    template <typename... Args>
    TransparentShape(int transparency, Args ...args) : T(std::forward<Args>(args)...), m_transparency{transparency}
    {}
    
    std::string str() const override
    {
        std::ostringstream oss;
        oss << T::str() << " has transparency " << m_transparency;
        return oss.str();
    }
    
    int m_transparency;
};

int main()
{
    TransparentShape<ColoredShape<Square>> sq1 = {50, "red", 5};
    ColoredShape<TransparentShape<Square>> sq2 = {"red", 50, 5};
    std::cout << sq1.str() << std::endl;
    std::cout << sq2.str();
}
