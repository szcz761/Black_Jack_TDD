//
// Created by szymon on 18.11.17.
//

#ifndef GAMEAPP_DECKLOADER_H
#define GAMEAPP_DECKLOADER_H

#include "IDeckLoader.h"
#include <istream>

namespace loader
{
    class TextDeckLoader : public IDeckLoader
    {
    public:
        explicit TextDeckLoader(std::istream &stream);

        ~TextDeckLoader() override = default;

        std::vector<GameCore::Card> load() override;

        bool addCard(std::string card,std::vector<GameCore::Card> &Deck);

    private:
        std::istream &stream;
    };

}
#endif //GAMEAPP_DECKLOADER_H
