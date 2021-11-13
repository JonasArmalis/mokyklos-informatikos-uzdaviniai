#pragma once
#include <fstream>
#include <iostream>

const int maxKiekis = 20;
void skaitymas(int Mas[][maxKiekis], int &, std::ifstream &);
void spausdinti2D(int Mas[][maxKiekis], int, int, std::ofstream &data);
void spausdinti(double Mas[], int eilutes, std::ofstream &rez);
void skaiciavimas(double Vidurkiai[], int Mas[][maxKiekis], int eilutes);

template <class T> // ğablono formatas - T
double vidurkis(T[]);


