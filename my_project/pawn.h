#include <iostream>
#include <utility>
#include <vector>
#include "piece.h"

using namespace std;

class Pawn {
private:
    const int CANDIDATE_MOVE_COORDINATES[4] = { 7, 8, 9, 16 };
    int pieceTile;
    int arrOfChess[64]{};
    string alliance;
    signed int direction;

public:
    Pawn(int Tile, string alliance, const int chess[]);

    static bool isValidTileCoordinate(int currentCandidate);

    static bool eighthColumn(int tile);

    static bool firstColumn(int tile);

    bool isFirstMove(int tile);

    vector<int> getLegalMoves();

};

Pawn::Pawn(int Tile, string alliance, const int* chess) {
    for (int i = 0; i < 64; ++i) {
        arrOfChess[i] = chess[i];
    }
    this->pieceTile = Tile;
    this->alliance = move(alliance);
    if (this->alliance == "white") {
        direction = -1;
    }
    else if (this->alliance == "black") {
        direction = 1;
    }
}

bool Pawn::isValidTileCoordinate(int currentCandidate) {
    return currentCandidate >= 0 && currentCandidate < 64;
}

bool Pawn::eighthColumn(int tile) {
    int eighthColumnArr[] = { 7, 15, 23, 31, 39, 47, 55, 63 };
    bool temp = false;
    for (int i : eighthColumnArr) {
        if (tile == i) {
            temp = true;
            break;
        }
        else {
            temp = false;
        }
    }
    return temp;
}

bool Pawn::firstColumn(int tile) {
    int firstColumnArr[] = { 0, 8, 16, 24, 32, 40, 43, 56 };
    bool temp = false;
    for (int i : firstColumnArr) {
        if (tile == i) {
            temp = true;
            break;
        }
        else {
            temp = false;
        }
    }
    return temp;
}

bool Pawn::isFirstMove(int tile) {
    int secondRowArr[] = { 8, 9, 10, 11, 12, 13, 14, 15 };
    int seventhRowArr[] = { 48, 49, 50, 51, 52, 53, 54, 55 };
    if (alliance == "black") {
        for (int i : secondRowArr) {
            if (tile == i) {
                return true;
            }
        }
    }
    else if (alliance == "white") {
        for (int i : seventhRowArr) {
            if (tile == i) {
                return true;
            }
        }
    }
    return false;
}

vector<int> Pawn::getLegalMoves() {
    Piece destinationTile(arrOfChess);
    int possibleDestinationTile;
    vector<int> legalMoves;
    for (int offset : CANDIDATE_MOVE_COORDINATES) {
        possibleDestinationTile = this->pieceTile + (direction * offset);
        if (!isValidTileCoordinate(possibleDestinationTile)) {
            continue;
        }
        if (offset == 8 && !destinationTile.isTileOccupied(possibleDestinationTile)) {
            legalMoves.push_back(possibleDestinationTile);
        }
        if (offset == 16 && isFirstMove(this->pieceTile)) {
            int behindCandidate = this->pieceTile + (this->direction * 8);

            if (!destinationTile.isTileOccupied(behindCandidate) &&
                !destinationTile.isTileOccupied(possibleDestinationTile)) {
                legalMoves.push_back(possibleDestinationTile);
            }
        }
        if (offset == 7 && !((eighthColumn(this->pieceTile) && this->alliance == "white") ||
            (firstColumn(this->pieceTile) && this->alliance == "black"))) {
            if (destinationTile.isTileOccupied(possibleDestinationTile)) {
                if (this->alliance != destinationTile.pieceAlliance(possibleDestinationTile, alliance)) {
                    legalMoves.push_back(possibleDestinationTile);
                }
            }
        }
        if (offset == 9 && !((firstColumn(this->pieceTile) && this->alliance == "white") ||
            (eighthColumn(this->pieceTile) && this->alliance == "black"))) {
            if (destinationTile.isTileOccupied(possibleDestinationTile)) {
                if (this->alliance != destinationTile.pieceAlliance(possibleDestinationTile, alliance)) {
                    legalMoves.push_back(possibleDestinationTile);
                }
            }
        }
    }
    return legalMoves;
}
