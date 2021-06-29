#include "headerFile.h"

int main() {
    string chessBoardCoords[ROWS][COLUMNS];
    string chessBoardPieces[ROWS][COLUMNS];
    string chessBoardActual[ROWS][COLUMNS];
    
    initializePieces(chessBoardPieces);
    initializeCoords(chessBoardCoords);

    initializeChessBoard(chessBoardPieces, chessBoardCoords, chessBoardActual);

    cout << "***********************************************************************************************************************************" << endl;
    printActualBoard(chessBoardActual);
    cout << "***********************************************************************************************************************************" << endl;
    whiteToMove(chessBoardActual);
    cout << "***********************************************************************************************************************************" << endl;
    printActualBoard(chessBoardActual);
    cout << "***********************************************************************************************************************************" << endl;

    return 0;
}
