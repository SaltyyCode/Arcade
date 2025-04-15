/*
** EPITECH PROJECT, 2024
** OOP
** File description:
** Arcade project
*/

#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdint>

#define SCORES_DIR "./scores"

namespace Arc
{
struct Score
{
    std::string game;
    std::string player;
    int bs;
};

std::ofstream &operator <<(std::ofstream &stream, const Score &score)
{
    stream << score.game << ":";
    stream << score.player << ":";
    stream << score.bs << std::endl;
    return stream;
}

std::ifstream &operator >>(std::ifstream &stream, Score &score)
{
    std::string game, player, value;

    std::getline(stream, game, ':');
    std::getline(stream, player, ':');
    std::getline(stream, value);
    if (game.empty() || player.empty() || value.empty())
        return stream;
    score.game = game;
    score.player = player;
    score.bs = std::atoi(value.c_str());
    return stream;
}

void operator >>(std::string &string, Score &score)
{
    std::string game, player, value;
    std::stringstream ss(string);

    std::getline(ss, game, ':');
    std::getline(ss, player, ':');
    std::getline(ss, value);
    if (game.empty() || player.empty() || value.empty())
        return;
    score.game = game;
    score.player = player;
    score.bs = std::atoi(value.c_str());
}
}