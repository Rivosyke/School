#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP

#include "Die.hpp"

class LoadedDie : public Die
{
    public:
        int rollDice();
        LoadedDie(int sides);
};



#endif // LOADEDDIE_HPP
