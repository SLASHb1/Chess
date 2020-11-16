#pragma once
#include <vector>
#include <iostream>

class Bishop {
private:
    const int CANDIDATE_MOVE_COORDINATES[4] = { -9, -7, 9, 7 };
    int pieceTile;
    std::string alliance;
    int arrOfChess[64]{};
public:
    Bishop(int pieceTile, std::string alliance, const int chess[]);

    bool isValidTileCoordinate(int currentCandidate);

    bool firstColumn(int pieceTile, int offset);

    bool eighthColumn(int pieceTile, int offset);

    std::vector<int> getLegalMoves();
};