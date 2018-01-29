//
// Created by szymon on 19.11.17.
//

#include "BlackJackGame.h"
#include "IPlayer.h"
#include <IDeckLoader.h>


namespace blackjack {

    void BlackJackGame::addplayer(std::shared_ptr<IPlayer> player) {
        Player = std::move(player);
    }

    void BlackJackGame::setDeckLoader(std::unique_ptr<loader::IDeckLoader> deck) {
        DeckLoader = std::move(deck);
    }

    bool BlackJackGame::startgame() {
        if (!Player || !DeckLoader) {
            return false;
        }
        CurrentDeck = DeckLoader->load();
        CroupierPoints = 0;
        PlayerPoints = 0;
        PlayerWin = false;
        while(CurrentDeck.size() >= 4) {
            startingCards cards = {CurrentDeck[0], CurrentDeck[1], CurrentDeck[2], CurrentDeck[3]};
            CurrentDeck.erase(CurrentDeck.begin(), CurrentDeck.begin() + 4);
            startRound(cards);
        }
        if(PlayerPoints > CroupierPoints){
            PlayerWin = true;
        }
        return true;
    }

    void BlackJackGame::startRound(const startingCards &cards){
        Player->informAboutStartingMatch(cards);
        int roundPlayerPoints = calculatePoitsOfCard(cards.firstPlayerCard) + calculatePoitsOfCard(cards.secendPlayerCard);
        int roundCroupierPoints = calculatePoitsOfCard(cards.firstCroupierCard) + calculatePoitsOfCard(cards.secendCroupierCard);
        if(roundPlayerPoints >= APoint + 10) {
            Player->informAboutWiningByGame(true);
            ++PlayerPoints;
            return;
        }
        else if(roundCroupierPoints == APoint + 10) {
            Player->informAboutWiningByGame(false);
            ++CroupierPoints;
            return;
        }

        roundPlayerPoints = playerMove(roundPlayerPoints);
        if(roundPlayerPoints == -1){
            CurrentDeck.erase(CurrentDeck.begin(),CurrentDeck.begin()+1);
            Player->informAboutWiningByGame(false);
            ++CroupierPoints;
            return;
        }
        else if(roundPlayerPoints == 1){
            CurrentDeck.erase(CurrentDeck.begin(),CurrentDeck.begin()+1);
            Player->informAboutWiningByGame(true);
            ++PlayerPoints;
            return;
        }

        roundCroupierPoints = croupierMove(roundCroupierPoints);
        if(roundCroupierPoints == -1){
            CurrentDeck.erase(CurrentDeck.begin(),CurrentDeck.begin()+1);
            Player->informAboutWiningByGame(false);
            ++CroupierPoints;
            return;
        }
        else if(roundCroupierPoints == 1){
            CurrentDeck.erase(CurrentDeck.begin(),CurrentDeck.begin()+1);
            Player->informAboutWiningByGame(true);
            ++PlayerPoints;
            return;
        }
        if(roundPlayerPoints > roundCroupierPoints){
            Player->informAboutWiningByGame(true);
            ++PlayerPoints;
            return;
        }
        else{
            Player->informAboutWiningByGame(false);
            ++CroupierPoints;
            return;
        }

    }

    int BlackJackGame::playerMove(int roundPlayerPoints) {
        while(Player->informDrowingCard(roundPlayerPoints)){
            if(CurrentDeck.size() == 0){
                return 0;
            }
            Player->getCard(CurrentDeck[0]);
            roundPlayerPoints += calculatePoitsOfCard(CurrentDeck[0]);
            if(roundPlayerPoints > APoint){
                roundPlayerPoints -= (APoint - 1);
            }
            if(roundPlayerPoints > BlackJackPoint) {
                return -1;
            }
            if(roundPlayerPoints == BlackJackPoint) {
                return 1;
            }
            CurrentDeck.erase(CurrentDeck.begin(),CurrentDeck.begin()+1);
        }
        return roundPlayerPoints;
    }

    int BlackJackGame::croupierMove(int roundCroupierPoints) {
        while(roundCroupierPoints < croupierLimit) {
            if(CurrentDeck.size() == 0){
                return 0;
            }
            Player->croupierCard(CurrentDeck[0]);
            roundCroupierPoints += calculatePoitsOfCard(CurrentDeck[0]);
            if(roundCroupierPoints > APoint){
                roundCroupierPoints -= (APoint - 1);
            }
            if(roundCroupierPoints == BlackJackPoint) {
                return -1;
            }
            if(roundCroupierPoints > BlackJackPoint) {
                return 1;
            }
            CurrentDeck.erase(CurrentDeck.begin(),CurrentDeck.begin()+1);
        }
        return roundCroupierPoints;
    }

    int BlackJackGame::calculatePoitsOfCard(GameCore::Card card) {
        if(card == GameCore::Card::A)
            return APoint;
        else if(card == GameCore::Card::K
                || card == GameCore::Card::Q
                || card == GameCore::Card::J
                || card == GameCore::Card::C10) {
            return 10;
        }
        else if(card == GameCore::Card::C9) {
            return 9;
        }
        else if(card == GameCore::Card::C8) {
            return 8;
        }
        else if(card == GameCore::Card::C7) {
            return 7;
        }
        else if(card == GameCore::Card::C6) {
            return 6;
        }
        else if(card == GameCore::Card::C5) {
            return 5;
        }
        else if(card == GameCore::Card::C4) {
            return 4;
        }
        else if(card == GameCore::Card::C3) {
            return 3;
        }
        else if(card == GameCore::Card::C2) {
            return 2;
        }
    }

    int BlackJackGame::getPlayerPoints() const {
        return PlayerPoints;
    }

    int BlackJackGame::getCroupierPoints() const {
        return CroupierPoints;
    }

    bool BlackJackGame::isPlayerWin() const {
        return PlayerWin;
    }

}