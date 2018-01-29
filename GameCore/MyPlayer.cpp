//
// Created by szymon on 09.01.18.
//

#include <vector>
#include "MyPlayer.h"

bool blackjack::MyPlayer::informAboutStartingMatch(const blackjack::startingCards &Cards) {
    CurrentHand.push_back(Cards.firstPlayerCard);
    CurrentHand.push_back(Cards.secendPlayerCard);
    CroupierHand.push_back(Cards.firstCroupierCard);
    CroupierHand.push_back(Cards.secendCroupierCard);
    return true;
}

bool blackjack::MyPlayer::informDrowingCard(int roundPlayerPoints) {//implement strategy of game.
    if((roundPlayerPoints<17 && calculateCroupierPoints()>6) || roundPlayerPoints<12){
        return true;
    }
    else {
        return false;
    }
}

void blackjack::MyPlayer::getCard(GameCore::Card card) {
    CurrentHand.push_back(card);
}

void blackjack::MyPlayer::croupierCard(GameCore::Card card) {
    CroupierHand.push_back(card);
}

void blackjack::MyPlayer::informAboutWiningByGame(bool win) {
    CroupierHand.clear();
    CurrentHand.clear();
}

void blackjack::MyPlayer::setCurrentHand(const std::vector<GameCore::Card> &CurrentHand) {
    MyPlayer::CurrentHand = CurrentHand;
}

const std::vector<GameCore::Card> &blackjack::MyPlayer::getCurrentHand() const {
    return CurrentHand;
}

const std::vector<GameCore::Card> &blackjack::MyPlayer::getCroupierHand() const {
    return CroupierHand;
}

void blackjack::MyPlayer::setCroupierHand(const std::vector<GameCore::Card> &CroupierHand) {
    MyPlayer::CroupierHand = CroupierHand;
}

int blackjack::MyPlayer::calculateCroupierPoints() {
    if(CroupierHand[0] == GameCore::Card::A)
        return 11;
    else if(CroupierHand[0] == GameCore::Card::K
            || CroupierHand[0] == GameCore::Card::Q
            || CroupierHand[0] == GameCore::Card::J
            || CroupierHand[0] == GameCore::Card::C10) {
        return 10;
    }
    else if(CroupierHand[0] == GameCore::Card::C9) {
        return 9;
    }
    else if(CroupierHand[0] == GameCore::Card::C8) {
        return 8;
    }
    else if(CroupierHand[0] == GameCore::Card::C7) {
        return 7;
    }
    else if(CroupierHand[0] == GameCore::Card::C6) {
        return 6;
    }
    else if(CroupierHand[0] == GameCore::Card::C5) {
        return 5;
    }
    else if(CroupierHand[0] == GameCore::Card::C4) {
        return 4;
    }
    else if(CroupierHand[0] == GameCore::Card::C3) {
        return 3;
    }
    else if(CroupierHand[0] == GameCore::Card::C2) {
        return 2;
    }
}

