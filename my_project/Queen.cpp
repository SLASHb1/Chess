#include "piece.h"
#include <utility>
#include "queen.h"

using namespace std;

Queen::Queen(const int Tile, string alliance, const int chess[]) {
    for (int i = 0; i < 64; ++i) {
        arrOfChess[i] = chess[i];
    }
    this->pieceTile = Tile;
    this->alliance = move(alliance);
}

bool Queen::isValidTileCoordinate(int currentCandidate) {
    return currentCandidate >= 0 && currentCandidate < 64;
}

bool Queen::firstColumn(int tile, int offset) {
    int firstColumnArr[] = { 0, 8, 16, 24, 32, 40, 43, 56 };
    bool temp;
    for (int i : firstColumnArr) {
        if (tile == i) {
            temp = true;
            break;
        }
        else {
            temp = false;
        }
    }
    return temp && (offset == -1 || offset == 7 || offset == -9);
}

bool Queen::eighthColumn(int tile, int offset) {
    int eighthColumnArr[] = { 7, 15, 23, 31, 39, 47, 55, 63 };
    bool temp;
    for (int i : eighthColumnArr) {
        if (tile == i) {
            temp = true;
            break;
        }
        else {
            temp = false;
        }
    }
    return temp && (offset == 1 || offset == -7 || offset == 9);
}

vector<int> Queen::getLegalMoves() {
    Piece destinationTile(arrOfChess);
    int possibleDestinationTile;
    vector<int> legalMoves;
    for (int offset : CANDIDATE_MOVE_COORDINATES) {
        possibleDestinationTile = this->pieceTile;
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
                    if (!(this->alliance == destinationTile.pieceAlliance(possibleDestinationTile, alliance))) {
                        legalMoves.push_back(possibleDestinationTile);
                    }
                    break;
                }
            }
        }
    }
    return legalMoves;
}