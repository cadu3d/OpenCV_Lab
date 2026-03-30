#include <iostream>

void Lab2Exercicio1();
void Lab2Exercicio2();


void runLab2()
{
    int Exercicio;

    std::cout << "\n";
    std::cout << "LAB 02 - Selecione um EXERCÍCIO de 1 a x, (0 -> VOLTAR): " << std::endl;
    std::cin >> Exercicio;

    switch (Exercicio)
    {
    case 0:
        return;
    case 1:
        Lab2Exercicio1();
        break;
    case 2:
        Lab2Exercicio2();
        break;
    default:
        std::cout << "Exercício Inválido" << std::endl;
        runLab2();
        break;
    }
}

void Lab2Exercicio1()
{

}
void Lab2Exercicio2()
{

}
