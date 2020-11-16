#pragma once
class Identity {
public:
    bool chessKing(int initialTile, int finalTile, std::string alliance, int* arrOfChess);
    bool chessQueen(int initialTile, int finalTile, std::string alliance, int* arrOfChess);
    bool chessPawn(int initialTile, int finalTile, std::string alliance, int* arrOfChess);
    bool chessRook(int initialTile, int finalTile, std::string alliance, int* arrOfChess);
    bool chessBishop(int initialTile, int finalTile, std::string alliance, int* arrOfChess);
    bool chessKnight(int initialTile, int finalTile, std::string alliance, int* arrOfChess);
    std::string checkAlliance(int piece);
    bool identifier(int initialTile, int finalTile, int piece, int* arrOfChess);
};

