//
// Created by najma 26.04.2022.
//

#include "UserCommands.hpp"
#include <iostream>

std::string UserCommands::next_command() {
    std::cout << "Wybierz co chcesz zrobić\n[change] - zmień stan komórki\n[next] - kolejny ruch\n[quit] - wyjdź " << std::endl;
    std::string wybor;
    std::cin >> wybor;

    if (wybor == "change")
    {
        return "change";
    }
    else if (wybor == "next")
    {
        return "next";
    }
    else if (wybor == "quit")
    {
        return "quit";
    }
    else
    {
        std::cout << "Wybierz odpowiednią komendę!" << std::endl;
    }
    return "quit";
}