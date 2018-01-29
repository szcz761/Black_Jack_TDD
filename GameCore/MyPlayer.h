//
// Created by szymon on 09.01.18.
//

#ifndef GAMEAPP_MYPLAYER_H
#define GAMEAPP_MYPLAYER_H

#include "IPlayer.h"
#include <memory>

namespace blackjack {
    class MyPlayer : public IPlayer {
    public:
        bool informAboutStartingMatch(const blackjack::startingCards& Cards) override;
        bool informDrowingCard(int roundPlayerPoints) override;
        void getCard(GameCore::Card card) override;
        void croupierCard(GameCore::Card card) override;
        void informAboutWiningByGame(bool win) override;
        const std::vector<GameCore::Card> &getCurrentHand() const;
        void setCurrentHand(const std::vector<GameCore::Card> &CurrentHand);
        const std::vector<GameCore::Card> &getCroupierHand() const;
        void setCroupierHand(const std::vector<GameCore::Card> &CroupierHand);
        int calculateCroupierPoints();

    private:
        std::vector<GameCore::Card> CurrentHand;
        std::vector<GameCore::Card> CroupierHand;


    };
}


#endif //GAMEAPP_MYPLAYER_H
