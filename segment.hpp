#ifndef SEGMENT__HPP
#define SEGMENT__HPP

#include <iostream>
#include <utility>
#include <GL/gl.h>

using std::pair;

extern int nombre[16];

extern pair<double, double> coord[7][4];

class Segment
{
    char num;
    int coordonnees;
    int masque;
    bool on;

public:
    Segment(const char&);
    const int& getCoordonnees() const;
    const bool& isOn() const;
    void turnOn();
    void turnOff();
    bool isContained(const int&) const;
    void afficher() const;
};

#endif