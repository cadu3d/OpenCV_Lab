//
// Created by cadu3d on 3/29/2026.
//
#include <filesystem>
#include <iostream>
#include <stdexcept>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>

#include "utils.h"

namespace
{
    std::filesystem::path projectRoot()
    {
        return PROJECT_ROOT;
    }
}

std::vector<cv::Mat> carregarImagens(const std::filesystem::path& folder);

void mostrarImagem(std::string janela, cv::Mat imageRGB, int seconds)
{
    cv::imshow(janela, imageRGB);
    cv::waitKey(seconds * 1000);
    cv::destroyWindow(janela);
}

std::vector<cv::Mat> buscarImagens()
{
    std::filesystem::path sourceDir = verificarOutput();
    return carregarImagens(sourceDir);
}

std::vector<cv::Mat> carregarImagens(const std::filesystem::path& folder)
{
    std::vector<cv::Mat> imagens;

    for (const auto& entry : std::filesystem::directory_iterator(folder))
    {
        if (!entry.is_regular_file())
        {
            continue;
        }

        std::filesystem::path path = entry.path();
        std::string ext = path.extension().string();

        if (ext == ".jpg" || ext == ".jpeg" || ext == ".png")
        {
            cv::Mat imagem = cv::imread(path.string(), cv::IMREAD_GRAYSCALE);

            if (!imagem.empty())
            {
                imagens.push_back(imagem);
            }
        }
    }

    return imagens;
}


std::filesystem::path verificarOutput()
{
    std::filesystem::path outputDir;
    outputDir = std::filesystem::path(PROJECT_ROOT) / "output" / "Lab_2" / "preProcessadas";

    std::filesystem::path sourcetDir;
    sourcetDir = std::filesystem::path(PROJECT_ROOT) / "input" / "Lab_2" ;

    if (!std::filesystem::exists(outputDir) || std::filesystem::is_empty(outputDir))
    {
        outputDir = std::filesystem::path(PROJECT_ROOT) / "input" / "Lab_2";
        std::cout << "Pre Processando imagens originais, no dir: " + outputDir.string() << std::endl;
        return sourcetDir;
    }
    std::cout << "Pre Processando imagens já existentes, no dir: " + outputDir.string() << std::endl;
    return outputDir;

}

std::filesystem::path buscarImagem()
{

    const std::filesystem::path pathImage = std::filesystem::path(PROJECT_ROOT) / "input"/ "imagem.jpg";
    return pathImage;

}


cv::Mat gerarImagemCinza()
{
    const std::filesystem::path pathImage = buscarImagem();
    cv::Mat imagemOriginal = cv::imread(pathImage.string(), cv::IMREAD_GRAYSCALE);

    if (imagemOriginal.empty())
    {
        throw std::runtime_error("Nao foi possivel carregar a imagem em: " + pathImage.string());
    }

    const std::filesystem::path outputPath = projectRoot() / "output" / "imagem_gray.jpg";
    cv::imwrite(outputPath.string(), imagemOriginal);
    return imagemOriginal;
}

void gravaImagem(cv::Mat result)
{
    std::filesystem::path outputDir;
    outputDir = std::filesystem::path(PROJECT_ROOT) / "output" / "Lab_2" / "preProcessadas" / "result.png";
    cv::imwrite(outputDir.string() , result);
}

void gravaImagem(cv::Mat result, int index)
{
    gravaImagem(result, index, "preProcessadas");
}

void gravaImagem(cv::Mat result, int index, std::string folder)
{
    std::filesystem::path outputDir;
    outputDir = std::filesystem::path(PROJECT_ROOT) / "output" / "Lab_2" / folder;
    std::filesystem::create_directories(outputDir);

    std::filesystem::path outputPath = outputDir / ("result_" + std::to_string(index) + ".png");
    cv::imwrite(outputPath.string(), result);
}


void limparOutput()
{
    const std::filesystem::path outputDir =
        std::filesystem::path(PROJECT_ROOT) / "output";

    if (!std::filesystem::exists(outputDir))
    {
        std::cout << "Pasta output nao encontrada." << std::endl;
        return;
    }

    int removidas = 0;

    for (const auto& entry : std::filesystem::recursive_directory_iterator(outputDir))
    {
        if (!entry.is_regular_file())
        {
            continue;
        }

        const std::filesystem::path path = entry.path();
        const std::string ext = path.extension().string();

        if (
            ext == ".jpg" ||
            ext == ".jpeg" ||
            ext == ".png" ||
            ext == ".bmp" ||
            ext == ".tif" ||
            ext == ".tiff"
        )
        {
            std::filesystem::remove(path);
            ++removidas;
        }
    }

    std::cout << "Imagens removidas do output: " << removidas << std::endl;
}
