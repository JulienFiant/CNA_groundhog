/*
** EPITECH PROJECT, 2019
** bootstrap
** File description:
** groundhog
*/

#ifndef GROUNDHOG_HPP_
#define GROUNDHOG_HPP_

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <math.h>
#include <sstream>
#include <iomanip>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

int do_predic(int period);
void do_SFML(std::vector<float> moy, std::vector<float> boolplus, std::vector<float> boolmoins, std::vector<float> index);
int check_tendency(std::vector<float> save_r);
void print_weird_value(std::vector<float> weird);
std::vector<float> check_weird(std::vector<float> index, std::vector<float> boolplus, std::vector<float> boolmoins, std::vector<float> weird);
void print_tendency_report(int tendency);

#endif /* !GROUNDHOG_HPP_ */
