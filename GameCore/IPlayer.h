//
// Created by szymon on 19.11.17.
//

#ifndef GAMEAPP_IPLAYER_H
#define GAMEAPP_IPLAYER_H

#include "../DeckLoader/card.h"

namespace blackjack{
    struct startingCards{
        GameCore::Card firstPlayerCard;
        GameCore::Card firstCroupierCard;
        GameCore::Card secendPlayerCard;
        GameCore::Card secendCroupierCard;
    };

    class IPlayer {
    public:
        virtual ~IPlayer() = default;
        virtual bool informAboutStartingMatch(const startingCards& Cards) = 0;
        virtual bool informDrowingCard(int roundPlayerPoints) = 0;
        virtual void getCard(GameCore::Card card) = 0;
        virtual void croupierCard(GameCore::Card card) = 0;
        virtual void informAboutWiningByGame(bool win) = 0;
    };
}

#endif //GAMEAPP_IPLAYER_H
