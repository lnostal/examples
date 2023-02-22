#include "patterns/singleton.cpp"
#include "patterns/decorator.cpp"
#include <iostream>

class Patterns
{
public:
    Patterns();
    ~Patterns();
    void SingletoneIllustration();
    void DecoratorIllustration();
    void StrategyIllustration();
    void TemplateMethodIllustration();
};

Patterns::Patterns(){}

Patterns::~Patterns(){}

void Patterns::SingletoneIllustration(){
    Singleton* first_instance = Singleton::Instance();
    Singleton* second_instance = Singleton::Instance();

    std::cout << first_instance << " & " << second_instance << std::endl;

    if (first_instance == second_instance) {
        std::cout << "Singletone confirmed" << std::endl;
    }
}

void Patterns::DecoratorIllustration(){

    std::cout << "\n\t❀ base component ❀\n";
    std::string testString = "Spread your wings and fly away";

    BaseComponent* line = new TextLine(testString);
    std::cout << '\n' << line->draw() << std::endl;

    std::cout << "\n\n\n\t❀ add border ❀\n";
    BaseComponent* lineWithBorder = new BorderedDecorator(new TextLine(testString), 'x');
    std::cout << '\n' << lineWithBorder->draw() << std::endl;

    std::cout << "\n\n\n\t❀ add sparkles ❀\n";
    BaseComponent* lineWithSparkles = new SparkleDecorator(line);
    std::cout << '\n' << lineWithSparkles->draw() << std::endl;

    std::cout << "\n\n\n\t❀ combinations ❀";
    BaseComponent* beautyLine = new BorderedDecorator(new SparkleDecorator(line), '~');
    std::cout << '\n' << std::right << '\n' << beautyLine->draw() << std::endl;

    BaseComponent* notSoBeautyLine = new SparkleDecorator(new BorderedDecorator(line, '.'));
    std::cout << '\n' << notSoBeautyLine->draw() << std::endl;
}

void Patterns::StrategyIllustration()
{
}

void Patterns::TemplateMethodIllustration()
{
}



using namespace std;

int main() {

    Patterns* p = new Patterns();
    p->SingletoneIllustration();
    cout << "------------------------------------------------------------" << endl;
    p->DecoratorIllustration();
    cout << "------------------------------------------------------------" << endl;
    cout << "------------------------------------------------------------" << endl;
}