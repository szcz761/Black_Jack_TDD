//
// Created by szymon on 18.11.17.
//

#ifndef GAMEAPP_IDECKLOADER_H
#define GAMEAPP_IDECKLOADER_H

#include <vector>
#include <istream>
#include "card.h"


namespace loader
{
    class IDeckLoader
    {
    public:
        virtual ~IDeckLoader()= default;
        virtual std::vector<GameCore::Card> load() = 0;
    };
}




#endif //GAMEAPP_IDECKLOADER_H
