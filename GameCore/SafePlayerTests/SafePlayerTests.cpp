//
// Created by szymon on 12.12.17.
//

#include <gmock/gmock.h>
#include <SafePlayer.h>
#include <BlackJackGame.h>
//#include <BlackJackGame.h>



namespace blackjack {
    namespace test {
        using namespace testing;

        TEST(SafePlayerTest, refuseDrowingCarfWhenHEHadMoreThan12Points) {
            //ginen
            auto player = std::make_shared<SafePlayer>();

            //when
            auto result = player->informDrowingCard(17);

            //expetted
            EXPECT_THAT(result,Eq(false));
        }

        TEST(SafePlayerTest, AcceptDrowingCarfWhenHEHadLessThan12Points) {
            //ginen
            auto player = std::make_shared<SafePlayer>();

            //when
            auto result = player->informDrowingCard(11);

            //expetted
            EXPECT_THAT(result,Eq(true));
        }
    }
}