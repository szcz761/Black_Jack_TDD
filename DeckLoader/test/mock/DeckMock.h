

//
// Created by szymon on 19.11.17.
//

#ifndef GAMEAPP_DECKLOADERMOCK_H
#define GAMEAPP_DECKLOADERMOCK_H

#include <gmock/gmock.h>
#include "../../IDeckLoader.h"

namespace loader{
    namespace test {
        namespace mock
        {
            class DeckLoaderMock : public IDeckLoader
            {
            public:
                ~DeckLoaderMock() override = default;
                MOCK_METHOD0(load,std::vector<GameCore::Card>());
            };
        }
    }
}

#endif //GAMEAPP_DECKLOADERMOCK_H
