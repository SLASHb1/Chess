#include "king.h"
#include "queen.h"
#include "pawn.h"
#include "bishop.h"
#include "rook.h"
#include "knight.h"
#include <memory>

using namespace std;

class Identity {
public:
    static bool chessKing(int initialTile, int finalTile, string alliance, int* arrOfChess) {
        unique_ptr<king> king(new king(initialTile, alliance, arrOfChess));
        vector<int> v1;
        v1 = king->getLegalMoves();
        for (vector<int>::iterator it1 = v1.begin(); it1 != v1.end(); ++it1) {
            if (*it1 == finalTile) {
                return true;
            }
        }
        return false;
    }

    static bool chessQueen(int initialTile, int finalTile, string alliance, int* arrOfChess) {
        unique_ptr<queen> queen(new queen(initialTile, alliance, arrOfChess));
        vector<int> v2;
        v2 = queen->getLegalMoves();
        for (vector<int>::iterator it2 = v2.begin(); it2 != v2.end(); ++it2) {
            if (*it2 == finalTile) {
                return true;
            }
        }
        return false;
    }

    static bool chessPawn(int initialTile, int finalTile, string alliance, int* arrOfChess) {
        unique_ptr<pawn> pawn(new pawn(initialTile, alliance, arrOfChess));
        vector<int> v3;
        v3 = pawn->getLegalMoves();
        for (vector<int>::iterator it3 = v3.begin(); it3 != v3.end(); ++it3) {
            if (*it3 == finalTile) {
                return true;
            }
        }
        return false;
    }

    static bool chessRook(int initialTile, int finalTile, string alliance, int* arrOfChess) {
        unique_ptr<rook> rook(new rook(initialTile, alliance, arrOfChess));
        vector<int> v4;
        v4 = rook->getLegalMoves();
        for (vector<int>::iterator it4 = v4.begin(); it4 != v4.end(); ++it4) {
            if (*it4 == finalTile) {
                return true;
            }
        }
        return false;
    }

    static bool chessBishop(int initialTile, int finalTile, string alliance, int* arrOfChess) {
        unique_ptr<bishop> bishop(new bishop(initialTile, alliance, arrOfChess));
        vector<int> v5;
        v5 = bishop->getLegalMoves();
        for (vector<int>::iterator it5 = v5.begin(); it5 != v5.end(); ++it5) {
            if (*it5 == finalTile) {
                return true;
            }
        }
        return false;
    }

    static bool chessKnight(int initialTile, int finalTile, string alliance, int* arrOfChess) {
        unique_ptr<knight> knight(new knight(initialTile, alliance, arrOfChess));
        vector<int> v6;
        v6 = knight->getLegalMoves();
        for (vector<int>::iterator it6 = v6.begin(); it6 != v6.end(); ++it6) {
            if (*it6 == finalTile) {
                return true;
            }
        }
        return false;
    }

    static string checkAlliance(int piece) {
        if (piece > 0) {
            return "white";
        }
        else if (piece < 0) {
            return "black";
        }
    }

    static bool identifier(int initialTile, int finalTile, int piece, int* arrOfChess) {
        string alliance = checkAlliance(piece);
        if (piece == -1 || piece == 1) {
            return chessRook(initialTile, finalTile, alliance, arrOfChess);
        }
        else if (piece == -2 || piece == 2) {
            return chessKnight(initialTile, finalTile, alliance, arrOfChess);
        }
        else if (piece == -3 || piece == 3) {
            return chessBishop(initialTile, finalTile, alliance, arrOfChess);
        }
        else if (piece == -4 || piece == 4) {
            return chessQueen(initialTile, finalTile, alliance, arrOfChess);
        }
        else if (piece == -5 || piece == 5) {
            return chessKing(initialTile, finalTile, alliance, arrOfChess);
        }
        else if (piece == -6 || piece == 6) {
            return chessPawn(initialTile, finalTile, alliance, arrOfChess);
        }
    }
};
