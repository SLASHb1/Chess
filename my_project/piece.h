#pragma once
#include <iostream>

using namespace std;

class piece {
private:
    int arrayOfChess[64]{};
public:
    explicit piece(const int Chess[]);

    bool isTileOccupied(int tile);

    string pieceAlliance(int tile, const string& alliance);
};

piece::piece(const int* Chess) {
    for (unsigned i = 0; i < 64; ++i) {
        arrayOfChess[i] = Chess[i];
    }
}

bool piece::isTileOccupied(int tile) {
    if (arrayOfChess[tile] == 0) {
        return false;
    }
    else {
        return true;
    }
}

string piece::pieceAlliance(int tile, const string& alliance) {
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
