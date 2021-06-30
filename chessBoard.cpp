#include "headerFile.h"

int main() {
    string chessBoardCoords[ROWS][COLUMNS];
    string chessBoardPieces[ROWS][COLUMNS];
    string chessBoardActual[ROWS][COLUMNS];
    string pieceBank[TOTALPIECES];
    bool endGame = false;
    
    initializePieces(chessBoardPieces);
    initializeCoords(chessBoardCoords);

    initializeChessBoard(chessBoardPieces, chessBoardCoords, chessBoardActual);

    printTopBorder();
    printActualBoard(chessBoardActual);
    printBottomBorder();

    //Looping through the game until one player resigns **to add: when one player wins/when they draw/insuffcient material, etc, etc.
    while (endGame == false) {

        cout << "---- WHITE'S TURN ----" << endl;
        if (resignOption()) {
            cout << "---- White resigned the game. ----" << endl;
            break;
        }

        whiteToMove(chessBoardActual);
        printScreen(chessBoardActual);

        cout << "---- BLACK's TURN ----" << endl;
        if (resignOption()) {
            cout << "---- Black resigned the game. ----" << endl;
            break;
        }

        blackToMove(chessBoardActual);
        printScreen(chessBoardActual);
    }
    return 0;
}

/* NEED TO ADD:
- Bank for captured pieces, w/ display information

- Simple UI instead of console grids (ASCII/color fonts are even better than current 'console board')
- Illegal moves warning
- Resign/draw options
- For misc. features, refer to README.md document for: https://github.com/niklasf/python-chess
*/
