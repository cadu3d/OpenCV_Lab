#include <iostream>
#include <string>
#include <vector>

#include <opencv2/opencv.hpp>

#include "utils.h"



void Lab2Exercicio1();
void Lab2Exercicio2();


void runLab2()
{
    int Exercicio;

    std::cout << "\n";
    std::cout << "LAB 02 - Aplicar Transformada de Hough, (0 -> VOLTAR): " << std::endl;
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
    std::cout << "Reading Image and " << std::endl;

    std::string path = std::string(PROJECT_ROOT) + "/sourceAssets/Lab_2/0.jpg";

    cv::Mat imagem = cv::imread(path, cv::IMREAD_COLOR); // IMREAD_COLOR é uma constante, valor 1
    cv::Mat imagemCinza = cv::imread(path, cv::IMREAD_GRAYSCALE);

    if (imagem.empty())
    {
        std::cout << "Erro: imagem nao foi carregada!" << std::endl;
        return;
    }

    std::vector<cv::Vec3f>  coordCirculos;//vetor com tres parametros centro (x,y) + raio

    cv::HoughCircles(
        imagemCinza,
         coordCirculos,
        cv::HOUGH_GRADIENT, // Metodo escolhido, o mais rápido e otimizado
        1.2,
        100,
        120,
        34,
        80,
        250
    );

    cv::Mat result = imagem.clone();

    for (const cv::Vec3f& circle : coordCirculos)
    {
        cv::Point center(cvRound(circle[0]), cvRound(circle[1]));
        int radius = cvRound(circle[2]);

        cv::circle(result, center, radius, cv::Scalar(0, 255, 0), 3);
        cv::circle(result, center, 3, cv::Scalar(0, 0, 255), -1);
    }

    mostrarImagem("Imagem Processada", result, 6);


    runLab2();
}
void Lab2Exercicio2()
{

}
