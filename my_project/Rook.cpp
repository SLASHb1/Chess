#include "piece.h"
#include <utility>
#include "rook.h"

using namespace std;

Rook::Rook(const int Tile, string alliance, const int chess[]) {
    for (int i = 0; i < 64; ++i) {
        arrOfChess[i] = chess[i];
    }
    this->pieceTile = Tile;
    this->alliance = move(alliance);
}

bool Rook::isValidTileCoordinate(int currentCandidate) {
    return currentCandidate >= 0 && currentCandidate < 64;
}

bool Rook::firstColumn(int tile, int offset) {
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
    return temp && (offset == -1);
}

bool Rook::eighthColumn(int tile, int offset) {
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
    return temp && (offset == 1);
}

vector<int> Rook::getLegalMoves() {
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