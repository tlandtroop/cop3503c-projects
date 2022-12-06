#include <iostream>
#include "Tile.h"

// Constructor
Tile::Tile(sf::Texture &texture, sf::Texture &flagTexture) {
    sprite->setTexture(texture);
    sprite2->setTexture(texture);
    flag->setTexture(flagTexture);
}

// Accessors
Sprite* Tile::getSprite() {
    return sprite;
}

Sprite* Tile::getSprite2() {
    return sprite2;
}

Sprite* Tile::getFlagSprite() {
    return flag;
}

bool Tile::getIsBomb() {
    return isBomb;
}

bool Tile::getIsShown() {
    return shown;
}

bool Tile::getIsFlagged() {
    return isFlagged;
}

int Tile::getAdjBombs() {
    return adjBombs;
}

vector<Tile*>* Tile::getNeighbors() {
    return &neighbors;
}

// Mutators
void Tile::setNeighbors(vector<Tile*> &neighborTiles) {
    neighbors = neighborTiles;
    adjBombs = 0;

    for (int i = 0; i < neighbors.size(); i++) {
        Tile* current = neighbors.at(i);
        if (current->getIsBomb()) {
            adjBombs++;
        }
    }
}

void Tile::setIsBomb(bool change) {
    isBomb = change;
}

void Tile::setIsShown(bool change) {
    shown = change;
}

void Tile::setIsFlagged(bool change) {
    isFlagged = change;
}

// Functions
void Tile::move(float x, float y) {
    sprite->move(Vector2f(y, x));
    sprite2->move(Vector2f(y, x));
    flag->move(Vector2f(y, x));
}

void Tile::makeBomb() {
    isBomb = true;
}

