#include "segment.hpp"

int nombre[16] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};

pair<double, double> coord[7][4] = {{{-2.0, 5.0}, {-2.0, 4.5}, {2.0, 4.5}, {2.0, 5.0}},
                                    {{2.2, 4.5}, {2.7, 4.5}, {2.7, 0.5}, {2.2, 0.5}},
                                    {{2.2, 0.0}, {2.2, -4.0}, {2.7, -4.0}, {2.7, 0.0}},
                                    {{-2.0, -4.0}, {-2.0, -4.5}, {2.0, -4.5}, {2.0, -4.0}},
                                    {{-2.7, 0.0}, {-2.7, -4.0}, {-2.2, -4.0}, {-2.2, 0.0}},
                                    {{-2.7, 4.5}, {-2.2, 4.5}, {-2.2, 0.5}, {-2.7, 0.5}},
                                    {{-2.0, 0.5}, {-2.0, 0.0}, {2.0, 0.0}, {2.0, 0.5}}};

Segment::Segment(const char& c) : num(c)
{
    if (c < 'a' || c > 'g') std::cerr << "Error" << std::endl;
    else
    {
        coordonnees = num - 'a';
        masque = 1 << coordonnees;
        on = false;
    }
}

const int& Segment::getCoordonnees() const
{
    return coordonnees;
}

const bool& Segment::isOn() const
{
    return on;
}

void Segment::turnOn()
{
    on = true;
}

void Segment::turnOff()
{
    on = false;
}

bool Segment::isContained(const int& n) const
{
    return (n & masque);
}

void Segment::afficher() const
{
    if (on) 
    {
        for (int i=0; i<4; i++) glVertex2f(coord[coordonnees][i].first, coord[coordonnees][i].second);
    }
}