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
    std::vector<float>::iterator value_plus;
    std::vector<float>::iterator value_moins;
    std::vector<float> tmp_diff;
    std::vector<float> tmp_index;
    size_t i = 0;

    value = index.begin();
    value_plus = boolplus.begin();
    value_moins = boolmoins.begin();

    while (value != index.end())
    {
        if (*value > *value_plus)
        {
            tmp_diff.push_back(*value - *value_plus);
            tmp_index.push_back(i);
        }
        else if (*value < *value_moins)
        {
            tmp_diff.push_back(*value_moins - *value);
            tmp_index.push_back(i);
        }
        i += 1;
        value++;
    }
    i = 0;
    std::vector<float>::iterator it = tmp_index.begin();
    while (i < tmp_index.size() && i < 5)
    {

        weird.push_back(index[*it]);
        i += 1;
        it++;
    }
    return (weird);
}

void print_weird_value(std::vector<float> weird)
{
    std::vector<float>::iterator it = weird.begin();

    std::cout << weird.size() << " weirdest values are [";
    for (int i = 0; i < weird.size() && i < 5; i += 1)
    {
        std::cout << *it;
        if (i < weird.size() - 1)
            std::cout << ", ";
        it++;
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