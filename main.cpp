#include <iostream>
#include <opencv2/core.hpp>

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main()
{
    int exercise;
    auto lang = "C++";
    std::cout << "Hello and welcome to Visual Computing Lab" << lang << "!\n";

    std::cout << "OpenCV version: " << CV_VERSION << std::endl;

    std::cout << "Selecione um exercicio de 1 a 8" << std::endl;
    std::cin >> exercise;

    ChooseLab(exercise);
}

void ChooseLab(int exercise)
{
    switch (exercise)
    {
    case 1:
        std::cout << "Run Exercise " << exercise << std::endl;
    case 2:
        std::cout << "Run Exercise " << exercise << std::endl;
    case 3:
        std::cout << "Run Exercise " << exercise << std::endl;
    case 5:
        std::cout << "Run Exercise " << exercise << std::endl;
    case 4:
        std::cout << "Run Exercise " << exercise << std::endl;

    default: ;
    }
}


void Exercise1(int exercise)
{
    std::cout << "Run Exercise " << exercise << std::endl;
}

void Exercise2(int exercise1)
{
    std::cout << "Run Exercise " << exercise1 << std::endl;
}


void Exercise3(int exercise1)
{
    std::cout << "Run Exercise " << exercise1 << std::endl;
}

void Exercise4(int exercise1)
{
    std::cout << "Run Exercise " << exercise1 << std::endl;
}

void Exercise5(int exercise1)
{
    std::cout << "Run Exercise " << exercise1 << std::endl;
}

void Exercise6(int exercise1)
{
    std::cout << "Run Exercise " << exercise1 << std::endl;
}

void Exercise7(int exercise1)
{
    std::cout << "Run Exercise " << exercise1 << std::endl;
}

void Exercise8(int exercise1)
{
    std::cout << "Run Exercise " << exercise1 << std::endl;
}
