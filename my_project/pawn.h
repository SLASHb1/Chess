#pragma once
#include <iostream>
#include <vector>

class Pawn {
private:
    const int CANDIDATE_MOVE_COORDINATES[4] = { 7, 8, 9, 16 };
    int pieceTile;
    int arrOfChess[64]{};
    std::string alliance;
    signed int direction;

public:
    Pawn(int Tile, std::string alliance, const int chess[]);

    bool isValidTileCoordinate(int currentCandidate);

    bool eighthColumn(int tile);

    bool firstColumn(int tile);

    bool isFirstMove(int tile);

    std::vector<int> getLegalMoves();

};
