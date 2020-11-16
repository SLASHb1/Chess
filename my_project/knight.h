#pragma once
#include <iostream>
#include <vector>


class Knight {
private:
    const int CANDIDATE_MOVE_COORDINATES[8] = { -17, -15, -10, -6, 6, 10, 15, 17 };
    int pieceTile;
    std::string alliance;
    int arrOfChess[64]{};

public:
    Knight(int pieceTile, std::string alliance, const int chess[]);

    bool isValidTileCoordinate(int currentCandidate);

    bool firstColumn(int pieceTile, int offset);

    bool secondColumn(int pieceTile, int offset);

    bool seventhColumn(int pieceTile, int offset);

    bool eighthColumn(int pieceTile, int offset);

    std::vector<int> getLegalMoves();
};
