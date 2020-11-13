#pragma once
#include <iostream>

using namespace std;

class Piece {
private:
    int arrayOfChess[64]{};
public:
    explicit Piece(const int Chess[]);

    bool isTileOccupied(int tile);

    string pieceAlliance(int tile, const string& alliance);
};

Piece::Piece(const int* Chess) {
    for (unsigned i = 0; i < 64; ++i) {
        arrayOfChess[i] = Chess[i];
    }
}

bool Piece::isTileOccupied(int tile) {
    if (arrayOfChess[tile] == 0) {
        return false;
    }
    else {
        return true;
    }
}

string Piece::pieceAlliance(int tile, const string& alliance) {
    if (alliance == "white") {
        if (arrayOfChess[tile] < 0) {
            return "black";
        }
        else {
            return "white";
        }
    }
    else if (alliance == "black") {
        if (arrayOfChess[tile] > 0) {
            return "white";
        }
        else {
            return "black";
        }
    }
}
