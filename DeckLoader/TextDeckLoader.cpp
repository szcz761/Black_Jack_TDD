
#include "TextDeckLoader.h"
#include <algorithm>

namespace loader {

    TextDeckLoader::TextDeckLoader(std::istream &stream)
    : stream{stream}
    {

    }

    bool TextDeckLoader::addCard(std::string card,std::vector<GameCore::Card> &Deck) {
        //card.erase(std::remove_if(card.begin(), card.end()," "), card.end());
        if (card == "A") {
            Deck.push_back(GameCore::Card::A);
        }
        else if (card == "K") {
            Deck.push_back(GameCore::Card::K);
        }
        else if (card == "Q") {
            Deck.push_back(GameCore::Card::Q);
        }
        else if (card == "J") {
            Deck.push_back(GameCore::Card::J);
        }
        else if (card == "2") {
            Deck.push_back(GameCore::Card::C2);
        }
        else if (card == "3") {
            Deck.push_back(GameCore::Card::C3);
        }
        else if (card == "4") {
            Deck.push_back(GameCore::Card::C4);
        }
        else if (card == "5") {
            Deck.push_back(GameCore::Card::C5);
        }
        else if (card == "6") {
            Deck.push_back(GameCore::Card::C6);
        }
        else if (card == "7") {
            Deck.push_back(GameCore::Card::C7);
        }
        else if (card == "8") {
            Deck.push_back(GameCore::Card::C8);
        }
        else if (card == "9") {
            Deck.push_back(GameCore::Card::C9);
        }
        else if (card == "10") {
            Deck.push_back(GameCore::Card::C10);
        }
        else if(card == ""){
            return true;
        }
        else {
            return false;
        }
        return true;
    }

    std::vector<GameCore::Card> TextDeckLoader::load() {
        std::vector<GameCore::Card> Deck;
        std::string card;
        while(!stream.eof()) {
            getline(stream, card, ';');
            if(!addCard(card,Deck)){
                return {};
            }
        }
        return Deck;

    }
}