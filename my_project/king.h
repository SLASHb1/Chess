#include <iostream>
#include <vector>
#include "piece.h"

using namespace std;

class king {
private:
    const int CANDIDATE_MOVE_COORDINATES[8] = { -9, -8, -7, -1, 1, 8, 7, 9 };
    int pieceTile;
    string alliance;
    int arrOfChess[64];
public:
    king(int pieceTile, string alliance, const int chess[]);

    bool isValidTileCoordinate(int currentCandidate);

    bool firstColumn(int pieceTile, int offset);

    bool eighthColumn(int pieceTile, int offset);

    vector<int> getLegalMoves();
};

king::king(int pieceTile, string alliance, const int chess[]) {
    for (int i = 0; i < 64; ++i) {
        arrOfChess[i] = chess[i];
    }
    this->pieceTile = pieceTile;
    this->alliance = alliance;
}

bool king::isValidTileCoordinate(int currentCandidate) {
    return currentCandidate >= 0 && currentCandidate < 64;
}

bool king::firstColumn(int pieceTile, int offset) {
    int firstColumnArr[] = { 0, 8, 16, 24, 32, 40, 43, 56 };
    bool temp = false;
    for (int i : firstColumnArr) {
        if (pieceTile == i) {
            temp = true;
            break;
        }
        else {
            temp = false;
        }
    }
    return temp && (offset == -9 || offset == -1 || offset == 7);
}

bool king::eighthColumn(int pieceTile, int offset) {
    int eighthColumnArr[] = { 7, 15, 23, 31, 39, 47, 55, 63 };
    bool temp = false;
    for (int i : eighthColumnArr) {
        if (pieceTile == i) {
            temp = true;
            break;
        }
        else {
            temp = false;
        }
    }
    return temp && (offset == -7 || offset == 1 || offset == 9);
}

vector<int> king::getLegalMoves() {
    Piece destinationTile(arrOfChess);
    int possibleDestinationTile = this->pieceTile;
    vector<int> legalMoves;
    for (int offset : CANDIDATE_MOVE_COORDINATES) {
        if (firstColumn(this->pieceTile, offset) || eighthColumn(this->pieceTile, offset)) {
            continue;
        }
        possibleDestinationTile = this->pieceTile + offset;
        if (isValidTileCoordinate(possibleDestinationTile)) {
            if (destinationTile.isTileOccupied(possibleDestinationTile)) {
                if (this->alliance != destinationTile.pieceAlliance(possibleDestinationTile, alliance)) {
                    legalMoves.push_back(possibleDestinationTile);
                }
            }
            else {
                legalMoves.push_back(possibleDestinationTile);
            }
        }
    }
    return legalMoves;
}
