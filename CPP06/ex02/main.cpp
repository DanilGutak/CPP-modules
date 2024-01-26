#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base *generate(void)
{
    srand(time(NULL));
    int i = rand() % 3;
    if (i == 0)
        return new A;
    else if (i == 1)
        return new B;
    else
        return new C;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "C\n";
}
void identify(Base& p)
{
    try{
        A a = dynamic_cast<A&>(p);
        std::cout << "A\n";
    }
    catch (std::exception &e)
    {
        try{
            B b = dynamic_cast<B&>(p);
            std::cout << "B\n";
        }
        catch (std::exception &e)
        {
            try{
                C c = dynamic_cast<C&>(p);
                std::cout << "C\n";
            }
            catch (std::exception &e)
            {
                std::cout << "Caster is broken:(\n";
            }
        }
    }
}

int main()
{
    Base *base = generate();
    identify(base);
    identify(*base);
    delete base;
    return 0;
}

