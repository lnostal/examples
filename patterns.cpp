#include "patterns/singleton.cpp"
#include <iostream>

class Patterns
{
private:
    /* data */
public:
    Patterns();
    ~Patterns();
    void SingletoneIllustration();
};

Patterns::Patterns()
{
}

Patterns::~Patterns()
{
}

void Patterns::SingletoneIllustration(){
    Singleton* first_instance = Singleton::Instance();
    Singleton* second_instance = Singleton::Instance();

    std::cout << first_instance << " & " << second_instance << std::endl;

    if (first_instance == second_instance) {
        std::cout << "Singletone confirmed" << std::endl;
    }
}

