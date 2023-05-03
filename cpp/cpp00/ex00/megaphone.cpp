//
// Created by Yong Min Back on 2023/04/24.
//

#include <iostream>
#include <cstring>

int main(int ac, char **av) {
    if (ac < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else {
        for (int i = 1; i < ac; i++) {
            for (int j = 0; j < static_cast<int>(strlen(av[i])); j++) {
                std::cout << static_cast<char>(std::toupper(av[i][j]));
            }
        }
        std::cout << std::endl;
    }
}
