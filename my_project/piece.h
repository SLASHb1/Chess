#pragma once
#include <iostream>

class Piece {
private:
    int arrayOfChess[64]{};
public:
    Piece(const int Chess[]);

    bool isTileOccupied(int tile);

    std::string pieceAlliance(int tile, const std::string& alliance);
};

