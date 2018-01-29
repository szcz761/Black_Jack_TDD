//
// Created by szymon on 19.11.17.
//

#include <gmock/gmock.h>
#include <BlackJackGame.h>
#include "mock/PlayerMock.h"
#include <test/mock/DeckMock.h>


namespace blackjack {
    namespace test {
        using namespace testing;

        using PlayerMockType = NiceMock<mock::PlayerMock>;
        using DeckLoaderMockType = loader::test::mock::DeckLoaderMock;

        class BlackJackGameTestWithAddedPlayer : public ::testing::Test {
        public:
        protected:
            BlackJackGame sut;
            std::shared_ptr<mock::PlayerMock> player;
            DeckLoaderMockType *deckloader;

            virtual void SetUp() {
                player = std::make_shared<PlayerMockType>();
                sut.addplayer(player);
                auto Loader = std::make_unique<DeckLoaderMockType>();
                deckloader = Loader.get();
                sut.setDeckLoader(std::move(Loader));
                std::vector<GameCore::Card> defaultDeck(12, GameCore::Card::C2);
                EXPECT_CALL(*deckloader, load()).WillRepeatedly(Return(defaultDeck));
            }
        };


        MATCHER_P4(StartPackEq, c1, c2, c3, c4, "")
        {
            return arg.firstPlayerCard == c1
                   && arg.firstCroupierCard == c2
                   && arg.secendPlayerCard == c3
                   && arg.secendCroupierCard == c4;
        }
        TEST(BlackJackGameTest, GameCantStartWithoutPlayer) {
            //give
            BlackJackGame sut;
            //when
            const auto result = sut.startgame();
            //expected
            EXPECT_THAT(result, Eq(false));
        }

        TEST(BlackJackGameTestWithDeck, GameMustHaveDeckToStart) {
            //give
            BlackJackGame sut;
            auto player = std::make_shared<mock::PlayerMock>();
            sut.addplayer(player);
            //expected
            const auto result = sut.startgame();
            //expected
            EXPECT_THAT(result, Eq(false));
        }

        TEST_F(BlackJackGameTestWithAddedPlayer, GameCanStartWithPlayer) {
            //give
            //when
            const auto result = sut.startgame();
            //expected
            EXPECT_THAT(result, Eq(true));
        }

        TEST_F(BlackJackGameTestWithAddedPlayer, GameInformPlayerAboutStartingRoundWithThisFirstCards) {
            //give
            std::vector<GameCore::Card> cards{GameCore::Card::C3, GameCore::Card::C6,
                                              GameCore::Card::C4, GameCore::Card::C3};

            EXPECT_CALL(*deckloader, load()).WillRepeatedly(Return(cards));

            //expected
            EXPECT_CALL(*player, informAboutStartingMatch(StartPackEq(GameCore::Card::C3, GameCore::Card::C6,
                                                                      GameCore::Card::C4, GameCore::Card::C3)));
            //when
            sut.startgame();
        }

        TEST_F(BlackJackGameTestWithAddedPlayer, GameAskPlayerAboutMakingDessisionOfDrowingCard) {
            //give
            //expected
            EXPECT_CALL(*player, informDrowingCard(_));

            //when
            sut.startgame();
        }

        TEST_F(BlackJackGameTestWithAddedPlayer, GameDontGiveCardsPlayerWhenHeRefuse) {
            //give

            //expected
            testing::InSequence s;
            EXPECT_CALL(*player, informDrowingCard(_)).WillOnce(Return(false));
            EXPECT_CALL(*player, getCard(_)).Times(0);


            //when
            sut.startgame();
        }

        TEST_F(BlackJackGameTestWithAddedPlayer, GameInformPlayerAboutCroupierNewCardWhenHeReRefuseCards) {
            //give
            EXPECT_CALL(*player, informDrowingCard(_)).WillOnce(Return(false));

            //expected
            EXPECT_CALL(*player, croupierCard(_)).Times(AtLeast(1));

            //when
            sut.startgame();
        }



        TEST_F(BlackJackGameTestWithAddedPlayer, GameInformPlayerAboutWiningWhenHeGotBlackJack){
            //give
            std::vector<GameCore::Card> cards{GameCore::Card::A,GameCore::Card::C10,
                                              GameCore::Card::J, GameCore::Card::C3,};
            EXPECT_CALL(*deckloader, load()).WillRepeatedly(Return(cards));

            //expected
            EXPECT_CALL(*player,informAboutWiningByGame(true));

            //when
            sut.startgame();
        }

        TEST_F(BlackJackGameTestWithAddedPlayer, GameInformPlayerAboutLosingWhenCroupierGotBlackJack){
            //give
            std::vector<GameCore::Card> cards{GameCore::Card::A,GameCore::Card::C10,
                                              GameCore::Card::C2, GameCore::Card::A};
            EXPECT_CALL(*deckloader, load()).WillRepeatedly(Return(cards));

            //expected
            EXPECT_CALL(*player,informAboutWiningByGame(false));

            //when
            sut.startgame();
        }


        TEST_F(BlackJackGameTestWithAddedPlayer, GameInformPlayerAboutLosingWhenHeHaveToMuchPoints){
            //give
            std::vector<GameCore::Card> cards{GameCore::Card::Q,GameCore::Card::C10,
                                              GameCore::Card::C2, GameCore::Card::C3,
                                              GameCore::Card::J,};
            EXPECT_CALL(*deckloader, load()).WillRepeatedly(Return(cards));
            EXPECT_CALL(*player, informDrowingCard(_)).WillOnce(Return(true));

            //expected
            EXPECT_CALL(*player,informAboutWiningByGame(false));

            //when
            sut.startgame();
        }

        TEST_F(BlackJackGameTestWithAddedPlayer, CroupierDrowCardUntillHeHave17Points){
            //give

            EXPECT_CALL(*player, informDrowingCard(_)).WillOnce(Return(false));

            //expected
            EXPECT_CALL(*player,croupierCard(GameCore::Card::C2)).Times(7);

            //when
            sut.startgame();
        }

        TEST_F(BlackJackGameTestWithAddedPlayer, RoundIsStopedWhenIsEndOfCards){
            //give
            std::vector<GameCore::Card> cards{GameCore::Card::Q,GameCore::Card::C10,
                                              GameCore::Card::C2, GameCore::Card::C3,
                                              GameCore::Card::C2,};
            EXPECT_CALL(*deckloader, load()).WillRepeatedly(Return(cards));
            EXPECT_CALL(*player, informDrowingCard(_)).WillOnce(Return(false));

            //expected
            EXPECT_CALL(*player,croupierCard(GameCore::Card::C2)).Times(1);

            //when
            sut.startgame();
        }

        TEST_F(BlackJackGameTestWithAddedPlayer, RoundCantStartWhenIsLessThan4Cards){
            //give
            std::vector<GameCore::Card> cards{GameCore::Card::Q,GameCore::Card::C10,
                                              GameCore::Card::C2};
            EXPECT_CALL(*deckloader, load()).WillRepeatedly(Return(cards));

            //expected
            EXPECT_CALL(*player, informDrowingCard(_)).Times(0);

            //when
            sut.startgame();
        }

        TEST_F(BlackJackGameTestWithAddedPlayer, GameInformPlayerAboutWiningWhenHeGotBlackJackWithAButNoForStart){
            //give
            std::vector<GameCore::Card> cards{GameCore::Card::Q, GameCore::Card::C10,
                                              GameCore::Card::J, GameCore::Card::C3,
                                              GameCore::Card::A};
            EXPECT_CALL(*deckloader, load()).WillRepeatedly(Return(cards));
            EXPECT_CALL(*player, informDrowingCard(_)).WillOnce(Return(true));
            //expected
            EXPECT_CALL(*player,informAboutWiningByGame(true));

            //when
            sut.startgame();
        }

        TEST_F(BlackJackGameTestWithAddedPlayer, GameInformPlayerAboutLosingWhenCroupierGotBlackJackWithAButNoForStart){
            //give
            std::vector<GameCore::Card> cards{GameCore::Card::Q, GameCore::Card::C10,
                                              GameCore::Card::J, GameCore::Card::C2,
                                              GameCore::Card::A, GameCore::Card::C8};
            EXPECT_CALL(*deckloader, load()).WillRepeatedly(Return(cards));
            EXPECT_CALL(*player, informDrowingCard(_)).WillOnce(Return(false));
            //expected
            EXPECT_CALL(*player,informAboutWiningByGame(false));

            //when
            sut.startgame();
        }

        TEST_F(BlackJackGameTestWithAddedPlayer, GameInformPlayerAboutLosingWhenCroupierGotMorePoints){
            //give
            std::vector<GameCore::Card> cards{GameCore::Card::C4, GameCore::Card::C10,
                                              GameCore::Card::C4, GameCore::Card::C8};
            EXPECT_CALL(*deckloader, load()).WillRepeatedly(Return(cards));
            EXPECT_CALL(*player, informDrowingCard(_)).WillOnce(Return(false));
            //expected
            EXPECT_CALL(*player,informAboutWiningByGame(false));

            //when
            sut.startgame();
        }

        TEST_F(BlackJackGameTestWithAddedPlayer, GameInformPlayerAboutWiningWhenHeGotMorePoints){
            //give
            std::vector<GameCore::Card> cards{GameCore::Card::C10, GameCore::Card::C10,
                                              GameCore::Card::C9, GameCore::Card::C8};
            EXPECT_CALL(*deckloader, load()).WillRepeatedly(Return(cards));
            EXPECT_CALL(*player, informDrowingCard(_)).WillOnce(Return(false));
            //expected
            EXPECT_CALL(*player,informAboutWiningByGame(true));

            //when
            sut.startgame();
        }

        TEST_F(BlackJackGameTestWithAddedPlayer, GameCanPlayUntilHaveMoreThan4Cards){
            //give
            std::vector<GameCore::Card> cards(30, GameCore::Card::C2);
            EXPECT_CALL(*deckloader, load()).WillRepeatedly(Return(cards));
            //expected
            EXPECT_CALL(*player, informDrowingCard(_)).Times(17)
                    .WillOnce(Return(true))
                    .WillOnce(Return(true))
                    .WillOnce(Return(true))
                    .WillOnce(Return(true))
                    .WillOnce(Return(true))
                    .WillOnce(Return(true))
                    .WillOnce(Return(true))
                    .WillOnce(Return(true))
                    .WillOnce(Return(false))
                    .WillOnce(Return(true))
                    .WillOnce(Return(true))
                    .WillOnce(Return(true))
                    .WillOnce(Return(true))
                    .WillOnce(Return(true))
                    .WillOnce(Return(true))
                    .WillOnce(Return(true))
                    .WillOnce(Return(true));
            //when
            sut.startgame();
        }

        TEST_F(BlackJackGameTestWithAddedPlayer, GameCanPlayCountPoint){
            //give
            std::vector<GameCore::Card> cards{GameCore::Card::C10, GameCore::Card::C10,
                                              GameCore::Card::C9, GameCore::Card::C8,
                                              GameCore::Card::C10, GameCore::Card::C10,
                                              GameCore::Card::C8, GameCore::Card::C9,
                                              GameCore::Card::C10, GameCore::Card::C10,
                                              GameCore::Card::C9, GameCore::Card::C8};
            EXPECT_CALL(*deckloader, load()).WillRepeatedly(Return(cards));
            EXPECT_CALL(*player, informDrowingCard(_)).Times(3)
                    .WillOnce(Return(false))
                    .WillOnce(Return(false))
                    .WillOnce(Return(false));
            //when
            sut.startgame();
            //expected
            EXPECT_THAT(sut.getCroupierPoints(),Eq(1));
            EXPECT_THAT(sut.getPlayerPoints(),Eq(2));
        }

        TEST_F(BlackJackGameTestWithAddedPlayer, GameCanDecideWhoWin){
            //give
            std::vector<GameCore::Card> cards{GameCore::Card::C10, GameCore::Card::C10,
                                              GameCore::Card::C9, GameCore::Card::C8,
                                              GameCore::Card::C10, GameCore::Card::C10,
                                              GameCore::Card::C8, GameCore::Card::C9,
                                              GameCore::Card::C10, GameCore::Card::C10,
                                              GameCore::Card::C9, GameCore::Card::C8};
            EXPECT_CALL(*deckloader, load()).WillRepeatedly(Return(cards));
            EXPECT_CALL(*player, informDrowingCard(_)).Times(3)
                    .WillOnce(Return(false))
                    .WillOnce(Return(false))
                    .WillOnce(Return(false));
            //when
            sut.startgame();
            //expected
            EXPECT_THAT(sut.isPlayerWin(),Eq(true));
        }



    }
}