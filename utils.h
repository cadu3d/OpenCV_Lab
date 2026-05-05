//
// Created by cadu3d on 3/29/2026.
//

#ifndef COMP_VISION_INTRO_UTILS_H
#define COMP_VISION_INTRO_UTILS_H

#include <filesystem>
#include <opencv2/core.hpp>
#include <string>
#include <vector>

void mostrarImagem(std::string janela, cv::Mat imageRGB, int seconds);
std::filesystem::path buscarImagem();
std::vector<cv::Mat> buscarImagens();
std::string pegarNome();
cv::Mat gerarImagemCinza();
void gravaImagem(cv::Mat result);
void gravaImagem(cv::Mat result, int index);
void gravaImagem(cv::Mat result, int index, std::string folder);
std::filesystem::path verificarOutput();
void limparOutput();

#endif //COMP_VISION_INTRO_UTILS_H
