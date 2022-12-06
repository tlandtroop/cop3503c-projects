#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Tile {
    bool shown = false;
    bool isBomb = false;
    bool isFlagged = false;
    int adjBombs = 0;
    vector<Tile*> neighbors;

    Sprite* sprite = new Sprite;
    Sprite* sprite2 = new Sprite;
    Sprite* flag = new Sprite;
public:
    // Tile Constructor
    Tile(Texture& texture, Texture& flagTexture);

    // Accessors
    Sprite* getSprite();
    Sprite* getSprite2();
    Sprite* getFlagSprite();
    bool getIsBomb();
    bool getIsShown();
    bool getIsFlagged();
    int getAdjBombs();
    vector<Tile*>* getNeighbors();

    // Mutators
    void setNeighbors(vector<Tile*> &neighborTiles);
    void setIsBomb(bool change);
    void setIsShown(bool change);
    void setIsFlagged(bool change);

    // Functions
    void move(float x, float y);
    void makeBomb();
};
