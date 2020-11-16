#pragma once
#include <iostream>
#include <vector>

class King {
private:
    const int CANDIDATE_MOVE_COORDINATES[8] = { -9, -8, -7, -1, 1, 8, 7, 9 };
    int pieceTile;
    std::string alliance;
    int arrOfChess[64]{};
public:
    King(int pieceTile, std::string alliance, const int chess[]);

    bool isValidTileCoordinate(int currentCandidate);

    bool firstColumn(int pieceTile, int offset);

    bool eighthColumn(int pieceTile, int offset);

    std::vector<int> getLegalMoves();
};
