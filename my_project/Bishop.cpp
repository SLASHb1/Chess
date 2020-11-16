#include <utility>
#include "piece.h"
#include "bishop.h"

using namespace std;

Bishop::Bishop(int pieceTile, string alliance, const int chess[]) {
    for (int i = 0; i < 64; ++i) {
        arrOfChess[i] = chess[i];
    }
    this->pieceTile = pieceTile;
    this->alliance = move(alliance);
}

bool Bishop::isValidTileCoordinate(int currentCandidate) {
    return currentCandidate >= 0 && currentCandidate < 64;
}

bool Bishop::firstColumn(int pieceTile, int offset) {
    int firstColumnArr[] = { 0, 8, 16, 24, 32, 40, 43, 56 };
    bool temp = false;
    for (int i : firstColumnArr) {
        if (pieceTile == i) {
            temp = true;
            break;
        }
        else
            temp = false;
    }
    return temp && (offset == 7 || offset == -9);
}

bool Bishop::eighthColumn(int pieceTile, int offset) {
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
    return temp && (offset == -7 || offset == 9);
}

vector<int> Bishop::getLegalMoves() {
    Piece destinationTile(arrOfChess);
    int possibleDestinationTile;
    vector<int> legalMoves;
    for (int offset : CANDIDATE_MOVE_COORDINATES) {
        possibleDestinationTile = this->pieceTile;
        if (firstColumn(possibleDestinationTile, offset) || eighthColumn(possibleDestinationTile, offset)) {
            continue;
        }
        while (isValidTileCoordinate(possibleDestinationTile)) {
            int temp = possibleDestinationTile;
            possibleDestinationTile += offset;
            if (firstColumn(temp, offset) || eighthColumn(temp, offset)) {
                continue;
            }
            if (isValidTileCoordinate(possibleDestinationTile)) {
                if (!destinationTile.isTileOccupied(possibleDestinationTile)) {
                    legalMoves.push_back(possibleDestinationTile);
                }
                else {
                    if (!(this->alliance == destinationTile.pieceAlliance(possibleDestinationTile, this->alliance))) {
                        legalMoves.push_back(possibleDestinationTile);
                    }
                    break;
                }
            }
        }
    }
    return legalMoves;
}