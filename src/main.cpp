/*
** EPITECH PROJECT, 2024
** OOP
** File description:
** Arcade project
*/

#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Core/Core.hpp"

int main(int ac, char **av, char **env)
{
    bool tty = true;

    if (ac != 2) {
        std::cerr << "Wrong arguments" << std::endl;
        return 84;
    }
    for (int i = 0; env[i]; i++) {
        if (!std::string(env[i]).starts_with("DISPLAY"))
            continue;
        tty = false;
        break;
    }
    try {
        Arc::Core core(av[1], tty);
        core.run();
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
