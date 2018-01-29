//
// Created by szymon on 09.12.17.
//

#include <stdexcept>
#include "SafePlayer.h"

namespace blackjack{

bool SafePlayer::informAboutStartingMatch(const startingCards &Cards) {
   return true;
}

bool SafePlayer::informDrowingCard(int roundPlayerPoints) {
    if(roundPlayerPoints<safeLimit){
        return true;
    }
    else {
        return false;
    }
}
//safe player dont need implement it
void SafePlayer::getCard(GameCore::Card card) {
    ;
}

void SafePlayer::croupierCard(GameCore::Card card) {
    ;
}

void SafePlayer::informAboutWiningByGame(bool win) {
   ;
}

}