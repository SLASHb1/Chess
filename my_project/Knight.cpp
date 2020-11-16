#include "piece.h"
#include <utility>
#include "knight.h"

using namespace std;

Knight::Knight(int pieceTile, string alliance, const int chess[]) {
    for (int i = 0; i < 64; ++i) {
        arrOfChess[i] = chess[i];
    }
    this->pieceTile = pieceTile;
    this->alliance = move(alliance);
}

bool Knight::isValidTileCoordinate(int currentCandidate) {
    return currentCandidate >= 0 && currentCandidate < 64;
}

bool Knight::firstColumn(int pieceTile, int offset) {
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
    return temp && ((offset == -17) || (offset == -10) || (offset == 6) || (offset == 15));
}

bool Knight::secondColumn(int pieceTile, int offset) {
    int secondColumnArr[] = { 1, 9, 17, 25, 33, 41, 49, 55 };
    bool temp = false;
    for (int i : secondColumnArr) {
        if (pieceTile == i) {
            temp = true;
            break;
        }
        else {
            temp = false;
        }
    }
    return temp && ((offset == -10) || (offset == 6));
}

bool Knight::seventhColumn(int pieceTile, int offset) {
    int seventhColumnArr[] = { 6, 14, 22, 30, 38, 46, 54, 62 };
    bool temp = false;
    for (int i : seventhColumnArr) {
        if (pieceTile == i) {
            temp = true;
            break;
        }
        else {
            temp = false;
        }
    }
    return temp && ((offset == -6) || (offset == 10));
}

bool Knight::eighthColumn(int pieceTile, int offset) {
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
    return temp && ((offset == -15) || (offset == -6) || (offset == 10) || (offset == 17));
}

vector<int> Knight::getLegalMoves() {
    Piece destinationTile(arrOfChess);
    int possibleDestinationTile;
    vector<int> legalMoves;
    for (int offset : CANDIDATE_MOVE_COORDINATES) {
        if (firstColumn(this->pieceTile, offset) || secondColumn(this->pieceTile, offset) ||
            seventhColumn(this->pieceTile, offset) || eighthColumn(this->pieceTile, offset)) {
            continue;
        }
        possibleDestinationTile = this->pieceTile + offset;
        if (isValidTileCoordinate(possibleDestinationTile)) {
            if (destinationTile.isTileOccupied(possibleDestinationTile)) {
                if (this->alliance != destinationTile.pieceAlliance(possibleDestinationTile, this->alliance)) {
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