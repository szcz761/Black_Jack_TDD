//
// Created by szymon on 19.11.17.
//

#ifndef GAMEAPP_BLACKJACKGAME_H
#define GAMEAPP_BLACKJACKGAME_H

#include <memory>
#include "../DeckLoader/card.h"
#include <vector>

namespace loader{
    class IDeckLoader;
}


namespace blackjack {
    class IPlayer;
    struct startingCards;

    class BlackJackGame {
    public:
        void addplayer(std::shared_ptr<IPlayer> player);

        bool startgame();

        virtual ~BlackJackGame() = default;

        void setDeckLoader(std::unique_ptr<loader::IDeckLoader> deck);

        int calculatePoitsOfCard(GameCore::Card card);

        void startRound(const blackjack::startingCards &cards);

        int playerMove(int roundPlayerPoints);

        int croupierMove(int roundCroupierPoints);

        int getPlayerPoints() const;

        int getCroupierPoints() const;

        bool isPlayerWin() const;

    private:
        std::vector<GameCore::Card> CurrentDeck;
        std::shared_ptr<IPlayer> Player;
        std::unique_ptr<loader::IDeckLoader> DeckLoader;
        const int croupierLimit = 17;
        const int APoint = 1000;  //jakas wielka liczba za asa by można było rozpoznac czy as jest w recei nie można było pomylic z innymi kartami
        const int BlackJackPoint = 21;
        int PlayerPoints;
        int CroupierPoints;
        bool PlayerWin;
    };
}

#endif //GAMEAPP_BLACKJACKGAME_H
