//
// Created by szymon on 18.11.17.
//

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <TextDeckLoader.h>


namespace loader {
    namespace test {
        using namespace testing;

        TEST(DeckLoaderTest, TextLoaderReturnEmptyVectorWhenEmptyStringIsGiven) {
            //give
            std::stringstream emptyStream;
            TextDeckLoader sut{emptyStream};
            //when
            const auto result = sut.load();
            //expected
            EXPECT_THAT(result.empty(), Eq(true));

        }

        TEST(DeckLoaderTest, TextLoaderReturnVectorWhenGivenIs8K) {
            //give
            std::stringstream K8{"K;K;K;K;K;K;K;K"};
            TextDeckLoader sut{K8};
            //when
            const auto result = sut.load();
            //expect
            ASSERT_THAT(result.size(), 8);
            EXPECT_THAT(result.at(0), Eq(GameCore::Card::K));
            EXPECT_THAT(result.at(1), Eq(GameCore::Card::K));
            EXPECT_THAT(result.at(2), Eq(GameCore::Card::K));
            EXPECT_THAT(result.at(3), Eq(GameCore::Card::K));
            EXPECT_THAT(result.at(4), Eq(GameCore::Card::K));
            EXPECT_THAT(result.at(5), Eq(GameCore::Card::K));
            EXPECT_THAT(result.at(6), Eq(GameCore::Card::K));
            EXPECT_THAT(result.at(7), Eq(GameCore::Card::K));
        }

        TEST(DeckLoaderTest, TextLoaderReturnEmptyWhenGivenWrongInput) {
            //give
            std::stringstream input{"K;K;Q;Ala psa   ; ;"};
            TextDeckLoader sut{input};
            //when
            const auto result = sut.load();
            //expect
            EXPECT_THAT(result.empty(), Eq(true));
        }

        TEST(DeckLoaderTest, TextLoaderReturnVectorOfCardsInOrderWhenGivenEveryFigure) {
            //give
            std::stringstream input{"K;K;Q;2;3;4;5;6;7;8;9;10;J;A"};
            TextDeckLoader sut{input};
            //when
            const auto result = sut.load();
            //expect
            ASSERT_THAT(result.size(), 14);
            EXPECT_THAT(result.at(0), Eq(GameCore::Card::K));
            EXPECT_THAT(result.at(1), Eq(GameCore::Card::K));
            EXPECT_THAT(result.at(2), Eq(GameCore::Card::Q));
            EXPECT_THAT(result.at(3), Eq(GameCore::Card::C2));
            EXPECT_THAT(result.at(4), Eq(GameCore::Card::C3));
            EXPECT_THAT(result.at(5), Eq(GameCore::Card::C4));
            EXPECT_THAT(result.at(6), Eq(GameCore::Card::C5));
            EXPECT_THAT(result.at(7), Eq(GameCore::Card::C6));
            EXPECT_THAT(result.at(8), Eq(GameCore::Card::C7));
            EXPECT_THAT(result.at(9), Eq(GameCore::Card::C8));
            EXPECT_THAT(result.at(10), Eq(GameCore::Card::C9));
            EXPECT_THAT(result.at(11), Eq(GameCore::Card::C10));
            EXPECT_THAT(result.at(12), Eq(GameCore::Card::J));
            EXPECT_THAT(result.at(13), Eq(GameCore::Card::A));
        }

        TEST(DeckLoaderTest, DISABLED_TextLoaderReturnVectorOfCardsInOrderWhenGivenEveryFigureAndWhiteSymbolsIsIgnore) {
            //give
            std::stringstream input{" K;K;Q;2;3;4;5;6;7;8;9;10;J;A;\n;\t;  ;;"};
            TextDeckLoader sut{input};
            //when
            const auto result = sut.load();
            //expect
            ASSERT_THAT(result.size(), 14);
            EXPECT_THAT(result.at(0), Eq(GameCore::Card::K));
            EXPECT_THAT(result.at(1), Eq(GameCore::Card::K));
            EXPECT_THAT(result.at(2), Eq(GameCore::Card::Q));
            EXPECT_THAT(result.at(3), Eq(GameCore::Card::C2));
            EXPECT_THAT(result.at(4), Eq(GameCore::Card::C3));
            EXPECT_THAT(result.at(5), Eq(GameCore::Card::C4));
            EXPECT_THAT(result.at(6), Eq(GameCore::Card::C5));
            EXPECT_THAT(result.at(7), Eq(GameCore::Card::C6));
            EXPECT_THAT(result.at(8), Eq(GameCore::Card::C7));
            EXPECT_THAT(result.at(9), Eq(GameCore::Card::C8));
            EXPECT_THAT(result.at(10), Eq(GameCore::Card::C9));
            EXPECT_THAT(result.at(11), Eq(GameCore::Card::C10));
            EXPECT_THAT(result.at(12), Eq(GameCore::Card::J));
            EXPECT_THAT(result.at(13), Eq(GameCore::Card::A));
        }

    }
};