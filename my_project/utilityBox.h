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
        unique_ptr<King> king(new King(initialTile, alliance, arrOfChess));
        vector<int> vtr = king->getLegalMoves();
        for (vector<int>::iterator it = vtr.begin(); it != vtr.end(); ++it) {
            if (*it == finalTile) {
                return true;
            }
        }
        return false;
    }

    static bool chessQueen(int initialTile, int finalTile, string alliance, int* arrOfChess) {
        unique_ptr<Queen> queen(new Queen(initialTile, alliance, arrOfChess));
        vector<int> vtr = queen->getLegalMoves();
        for (vector<int>::iterator it = vtr.begin(); it != vtr.end(); ++it) {
            if (*it == finalTile) {
                return true;
            }
        }
        return false;
    }

    static bool chessPawn(int initialTile, int finalTile, string alliance, int* arrOfChess) {
        unique_ptr<Pawn> pawn(new Pawn(initialTile, alliance, arrOfChess));
        vector<int> vtr = pawn->getLegalMoves();
        for (vector<int>::iterator it = vtr.begin(); it != vtr.end(); ++it) {
            if (*it == finalTile) {
                return true;
            }
        }
        return false;
    }

    static bool chessRook(int initialTile, int finalTile, string alliance, int* arrOfChess) {
        unique_ptr<Rook> rook(new Rook(initialTile, alliance, arrOfChess));
        vector<int> vtr = rook->getLegalMoves();
        for (vector<int>::iterator it = vtr.begin(); it != vtr.end(); ++it) {
            if (*it == finalTile) {
                return true;
            }
        }
        return false;
    }

    static bool chessBishop(int initialTile, int finalTile, string alliance, int* arrOfChess) {
        unique_ptr<Bishop> bishop(new Bishop(initialTile, alliance, arrOfChess));
        vector<int> vtr = bishop->getLegalMoves();
        for (vector<int>::iterator it = vtr.begin(); it != vtr.end(); ++it) {
            if (*it == finalTile) {
                return true;
            }
        }
        return false;
    }

    static bool chessKnight(int initialTile, int finalTile, string alliance, int* arrOfChess) {
        unique_ptr<Knight> knight(new Knight(initialTile, alliance, arrOfChess));
        vector<int> vtr = knight->getLegalMoves();
        for (vector<int>::iterator it = vtr.begin(); it != vtr.end(); ++it) {
            if (*it == finalTile) {
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
