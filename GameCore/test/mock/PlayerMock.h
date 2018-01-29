//
// Created by szymon on 19.11.17.
//

#ifndef GAMEAPP_PLAYERMOCK_H
#define GAMEAPP_PLAYERMOCK_H

#include "../../IPlayer.h"
#include <gmock/gmock.h>

namespace blackjack{
    namespace test {
    namespace mock
    {
        class PlayerMock:public IPlayer
        {
        public:
            ~PlayerMock() override = default;
            MOCK_METHOD1(informAboutStartingMatch, bool(const startingCards&));
            MOCK_METHOD1(informDrowingCard, bool(int roundPlayerPoints));
            MOCK_METHOD1(getCard, void(GameCore::Card));
            MOCK_METHOD1(croupierCard, void(GameCore::Card));
            MOCK_METHOD1(informAboutWiningByGame, void(bool));
        };
    }
    }
    }




#endif //GAMEAPP_PLAYERMOCK_H
