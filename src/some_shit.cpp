#include <iostream>

int main() {

    int a = 2;

    int* b;

    b = &a;

    std::cout << "b: \t" << b << std::endl;
    std::cout << "a: \t"<< a << std::endl;
    std::cout << "&b: \t" <<  &b << std::endl;
    std::cout << "&a: \t" <<  &a << std::endl;
    std::cout << "*b: \t" <<  *b << std::endl;

    return 0;
}