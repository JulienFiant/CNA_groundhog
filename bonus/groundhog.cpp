/*
** EPITECH PROJECT, 2019
** bootstrap
** File description:
** groundhog
*/

#include "groundhog.hpp"

float do_mean(std::vector<float> index, int period)
{
    float add = 0;
    int i = 0;
    auto it = index.end();

    --it;
    for (it; i < period; --it)
    {
        add = add + (float)*it;
        i += 1;
    }
    return (add / period);
}

std::vector<float> do_moyenne(std::vector<float> index)
{
    std::vector<float> moy;
    std::vector<float>::iterator it = index.begin();
    std::vector<float>::iterator ti = index.end();
    --ti;

    if (index.size() < 2)
        return (moy);
    while (it != ti)
    {
        float a = *it;
        ++it;
        float b = *it;
        moy.push_back((a + b) / 2);
    }
    return (moy);
}

float do_variance(std::vector<float> index, int period)
{
    float sum = do_mean(index, period);
    float add = 0;
    int i = 0;
    auto it = index.end();

    --it;
    for (it; i < period; --it)
    {
        add += ((float)*it - sum) * ((float)*it - sum);
        i += 1;
    }
    return (add / period);
}

float do_ecart(std::vector<float> index, int period)
{
    float variance = do_variance(index, period);

    return (sqrt(variance));
}

std::vector<float> boolingplus(std::vector<float> index)
{
    std::vector<float> moy = do_moyenne(index);
    float ecart = 0.0;
    std::vector<float> boolplus;
    std::vector<float> tmp;
    std::vector<float>::iterator it = index.begin();
    std::vector<float>::iterator it2 = index.begin();
    std::vector<float>::iterator it_moy = moy.begin();
    int size = index.size();

    if (moy.empty() == 1)
        return (boolplus);
    for (int i = 0; i < size - 1; i += 1)
    {
        tmp.push_back(*it);
        ++it2;
        tmp.push_back(*it2);
        ecart = do_ecart(tmp, 2);
        boolplus.push_back((float)*it_moy + ecart * 2);
        ++it_moy;
        ++it;
    }
    return (boolplus);
}

std::vector<float> boolingmoins(std::vector<float> index)
{
    std::vector<float> moy = do_moyenne(index);
    float ecart = 0.0;
    std::vector<float> boolmoins;
    std::vector<float> tmp;
    std::vector<float>::iterator it = index.begin();
    std::vector<float>::iterator it2 = index.begin();
    std::vector<float>::iterator it_moy = moy.begin();
    int size = index.size();

    if (moy.empty() == 1)
        return (boolmoins);
    for (int i = 0; i < size - 1; i += 1)
    {
        tmp.push_back(*it);
        ++it2;
        tmp.push_back(*it2);
        ecart = do_ecart(tmp, 2);
        boolmoins.push_back((float)*it_moy - ecart * 2);
        ++it_moy;
        ++it;
    }
    return (boolmoins);
}

void do_s(std::vector<float> index, int period)
{
    std::cout.precision(3);
    float ecart = 0.0;

    if (period > index.size())
        std::cout << "s=nan";
    else
    {
        ecart = do_ecart(index, period);
        if (ecart < 1 && ecart > -1)
            std::cout.precision(2);
        std::cout << "s=" << ecart;
    }
}

float do_r(std::vector<float> index, int period)
{
    int i = 0;
    float sous = 0;
    std::vector<float>::iterator nb1;
    std::vector<float>::iterator nb2;

    std::cout.precision(2);
    if (period + 1 > index.size())
        std::cout << "r=nan%\t";
    else
    {
        nb1 = index.end();
        nb2 = index.end();
        --nb1;
        --nb2;
        while (i < period)
        {
            i += 1;
            --nb2;
        }
        sous = (float)*nb1 - (float)*nb2;
        std::cout << "r=";
        sous = (sous * 100) / (float)*nb2;
        if (sous > -10 && sous < 10)
            std::cout.precision(1);
        std::cout << sous << "%\t";
        return (sous);
    }
}

void do_g(std::vector<float> index, int period)
{
    int i = 0;
    float add = 0.0;
    std::vector<float>::iterator nb1;
    std::vector<float>::iterator nb2;

    std::cout.precision(3);
    if (period + 1 > index.size())
        std::cout << "g=nan\t";
    else
    {
        nb1 = index.end();
        nb2 = index.end();
        --nb1;
        --nb2;
        while (i < period)
        {
            --nb2;
            i += 1;
        }
        std::cout << "g=";
        add = ((float)*nb1 - (float)*nb2) / period;
        if (add < 1)
            std::cout.precision(1);
        if (add < 0.0)
            std::cout << "0.0\t";
        else
            std::cout << add << "\t";
    }
}

int do_predic(int period)
{
    std::vector<float> index;
    std::string s;
    int i = 0;
    std::vector<float> save_r;
    int tendency = 0;
    std::vector<float> boolplus;
    std::vector<float> boolmoins;
    std::vector<float> weird;

    while (1)
    {
        getline(std::cin, s);
        if (s.compare("STOP") == 0)
            break;
        index.push_back(strtof((s).c_str(), 0));
        do_g(index, period);
        save_r.push_back(do_r(index, period));
        do_s(index, period);
        tendency += check_tendency(save_r);
        weird = check_weird(index, boolplus, boolmoins, weird);
        boolplus = boolingplus(index);
        boolmoins = boolingmoins(index);
    }
    print_tendency_report(tendency);
    print_weird_value(weird);
    do_SFML(do_moyenne(index), boolplus, boolmoins, index);
    return (0);
}
