//
// Created by szymon on 09.12.17.
//

#ifndef GAMEAPP_SAFEPLAYER_H
#define GAMEAPP_SAFEPLAYER_H


#include "IPlayer.h"
#include <memory>

namespace blackjack {
    class SafePlayer : public IPlayer {
    public:
        bool informAboutStartingMatch(const blackjack::startingCards& Cards) override;
        bool informDrowingCard(int roundPlayerPoints) override;
        void getCard(GameCore::Card card) override;
        void croupierCard(GameCore::Card card) override;
        void informAboutWiningByGame(bool win) override;

    private:
    const int safeLimit = 12;
    };
}

#endif //GAMEAPP_PLAYER_H
