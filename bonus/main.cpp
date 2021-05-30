/*
** EPITECH PROJECT, 2019
** test affichage ground ligne
** File description:
** main
*/

#include "groundhog.hpp"

int my_strlen(char *a)
{
    int i = 0;

    while (a[i])
        i += 1;
    return (i);
}

void print_h(void)
{
    std::cout << "SYNOPSIS" << std::endl;
    std::cout << "\t./groundhog period" << std::endl;
    std::cout << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "\tperiod\tthe number of days defining a period" << std::endl;
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    else if (ac == 2)
    {
        if (my_strlen(av[1]) == 2 && av[1][0] == '-' && av[1][1] == 'h')
        {
            print_h();
            return (0);
        }
        else if (av[1][0] != '-')
            return (do_predic(atoi(av[1])));
        else
            return (84);
    }
    return (0);
}