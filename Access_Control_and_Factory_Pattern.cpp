class Object {
 private:
    Object(int x, int y) : m_x(x), m_y(y) {};
    int m_x, m_y;
 public:
    struct Factory 
    {
        static Object create(int x, int y) 
        {
            return {x, y};
        }
    };
    static Factory factory;
};
 
int main()
{
    auto obj = Object::Factory::create(10, 1);
    (void) obj;
}
