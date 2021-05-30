/*
** EPITECH PROJECT, 2019
** test affichage ground ligne
** File description:
** check
*/

#include "groundhog.hpp"

void print_tendency_report(int tendency)
{
    std::cout << "Global tendency switched " << tendency << " times" << std::endl;
}

std::vector<float> check_weird(std::vector<float> index, std::vector<float> boolplus, std::vector<float> boolmoins, std::vector<float> weird)
{
    std::vector<float>::iterator value;
    std::vector<float>::iterator plus;
    std::vector<float>::iterator moins;

    if (boolplus.empty() == 1 || boolmoins.empty() == 1)
        return (weird);
    value = index.end()--;
    plus = boolplus.end()--;
    moins = boolmoins.end()--;
    if (*value > *plus || *value < *moins)
        weird.push_back(*value);
    return (weird);
}

void print_weird_value(std::vector<float> weird)
{
    std::vector<float>::iterator it = weird.begin();

    std::cout << weird.size() << " weirdest values are [";
    for (it; it != weird.end(); it++)
    {
        if (it != weird.end()--)
            std::cout << *it << ", ";
    }
    std::cout << "]" << std::endl;
}

int check_tendency(std::vector<float> save_r)
{
    auto it = save_r.end();
    auto it2 = save_r.end();

    --it;
    --it2;
    --it2;
    if ((*it > 0 && *it2 < 0) || (*it < 0 && *it2 > 0))
    {
        std::cout << "\ta switch occurs" << std::endl;
        return (1);
    }
    else
        std::cout << std::endl;
    return (0);
}