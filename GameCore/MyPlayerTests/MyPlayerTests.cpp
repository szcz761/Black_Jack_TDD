//
// Created by szymon on 09.01.18.
//

#include <gmock/gmock.h>
#include <MyPlayer.h>
#include <BlackJackGame.h>




namespace blackjack {
    namespace test {
        using namespace testing;

        TEST(MyPlayerTest, PlayerKnowWhatCardHeGetAtStart) {
            //given
            auto player = std::make_shared<MyPlayer>();
            startingCards pack = {GameCore::Card::C3,
                                  GameCore::Card::K,
                                  GameCore::Card::A,
                                  GameCore::Card::C2};

            //when
            player->informAboutStartingMatch(pack);

            auto Card1 = player->getCurrentHand()[0];
            auto Card2 = player->getCurrentHand()[1];
            size_t HandCount = player->getCurrentHand().size();

            //expetted
            ASSERT_THAT(HandCount, 2);
            EXPECT_THAT(Card1, Eq(GameCore::Card::C3));
            EXPECT_THAT(Card2, Eq(GameCore::Card::A));
        }

        TEST(MyPlayerTest, PlayerKnowWhatCardCriupierGetAtStart) {
            //ginen
            auto player = std::make_shared<MyPlayer>();
            startingCards pack = {GameCore::Card::C3,
                                  GameCore::Card::K,
                                  GameCore::Card::A,
                                  GameCore::Card::C2};

            //when
            player->informAboutStartingMatch(pack);

            auto Card1 = player->getCroupierHand()[0];
            auto Card2 = player->getCroupierHand()[1];
            size_t HandCount = player->getCroupierHand().size();

            //expetted
            ASSERT_THAT(HandCount, 2);
            EXPECT_THAT(Card1, Eq(GameCore::Card::K));
            EXPECT_THAT(Card2, Eq(GameCore::Card::C2));
        }

        TEST(MyPlayerTest, PlayerKnowWhatCardGetAWhilePlaingRoundAndRememberIt) {
            //ginen
            auto player = std::make_shared<MyPlayer>();
            startingCards pack = {GameCore::Card::C3,
                                  GameCore::Card::K,
                                  GameCore::Card::A,
                                  GameCore::Card::C2};

            //when
            player->informAboutStartingMatch(pack);
            player->getCard(GameCore::Card::Q);
            player->getCard(GameCore::Card::J);
            auto Card1 = player->getCurrentHand()[2];
            auto Card2 = player->getCurrentHand()[3];
            size_t HandCount = player->getCurrentHand().size();

            //expetted
            ASSERT_THAT(HandCount, 4);
            EXPECT_THAT(Card1, Eq(GameCore::Card::Q));
            EXPECT_THAT(Card2, Eq(GameCore::Card::J));
        }

        TEST(MyPlayerTest, PlayerKnowWhatCardGetCroupierWhilePlaingRoundAndRememberIt) {
            //ginen
            auto player = std::make_shared<MyPlayer>();
            startingCards pack = {GameCore::Card::C3,
                                  GameCore::Card::K,
                                  GameCore::Card::A,
                                  GameCore::Card::C2};

            //when
            player->informAboutStartingMatch(pack);
            player->croupierCard(GameCore::Card::C7);
            player->croupierCard(GameCore::Card::C5);
            player->croupierCard(GameCore::Card::A);
            auto Card1 = player->getCroupierHand()[2];
            auto Card2 = player->getCroupierHand()[3];
            auto Card3 = player->getCroupierHand()[4];
            size_t HandCount = player->getCroupierHand().size();

            //expetted
            ASSERT_THAT(HandCount, 5);
            EXPECT_THAT(Card1, Eq(GameCore::Card::C7));
            EXPECT_THAT(Card2, Eq(GameCore::Card::C5));
            EXPECT_THAT(Card3, Eq(GameCore::Card::A));
        }

        TEST(MyPlayerTest, PlayerKnowWhenRoundIsEndAndThrowCards) {
            //ginen
            auto player = std::make_shared<MyPlayer>();
            startingCards pack = {GameCore::Card::C3,
                                  GameCore::Card::K,
                                  GameCore::Card::A,
                                  GameCore::Card::C2};
            player->informAboutStartingMatch(pack);
            player->croupierCard(GameCore::Card::C7);
            player->getCard(GameCore::Card::C5);


            //when
            player->informAboutWiningByGame(true);
            size_t MyHandCount = player->getCroupierHand().size();
            size_t CriupierHandCount = player->getCurrentHand().size();

            //expetted
            ASSERT_THAT(MyHandCount, 0);
            ASSERT_THAT(CriupierHandCount, 0);
        }

        TEST(MyPlayerTest, PlayerRefuseDrowingCardWhenHeHaveMoreThan17Points) {
            //ginen
            auto player = std::make_shared<MyPlayer>();

            //when
            auto result = player->informDrowingCard(17);

            //expetted
            EXPECT_THAT(result,Eq(false));
        }

        TEST(MyPlayerTest, PlayerAcceptDrowingCardWhenHeHavefom12to17AndCroupierHaveMoreThan6Points) {
            //ginen
            auto player = std::make_shared<MyPlayer>();
            startingCards pack = {GameCore::Card::C3,
                                  GameCore::Card::C8,
                                  GameCore::Card::C5,
                                  GameCore::Card::C6};
            player->informAboutStartingMatch(pack);

            //when
            auto result = player->informDrowingCard(15);

            //expetted
            EXPECT_THAT(result,Eq(true));
        }

        TEST(MyPlayerTest, PlayerAcceptDrowingCardWhenHeHaveLessThan12PointsAndCroupierHandsIsNoMatter) {
            //ginen
            auto player = std::make_shared<MyPlayer>();
            startingCards pack = {GameCore::Card::C3,
                                  GameCore::Card::C8,
                                  GameCore::Card::C5,
                                  GameCore::Card::C6};
            player->informAboutStartingMatch(pack);

            //when
            auto result = player->informDrowingCard(10);

            //expetted
            EXPECT_THAT(result,Eq(true));
        }
    }
}