#pragma once
#include <iostream>
#include <vector>

class Rook {
private:
    const int CANDIDATE_MOVE_COORDINATES[4] = { -8, -1, 1, 8 };
    int pieceTile;
    std::string alliance;
    int arrOfChess[64]{};
public:
    Rook(int Tile, std::string alliance, const int chess[]);

    bool isValidTileCoordinate(int currentCandidate);

    bool firstColumn(int tile, int offset);

    bool eighthColumn(int tile, int offset);

    std::vector<int> getLegalMoves();
};
