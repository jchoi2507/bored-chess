#include "headerFile.h"

void initializePieces(string chessBoardPieces[ROWS][COLUMNS]) {

    string whitePieces[8] = {"Left_Rook", "Left_Knight", "Left_Bishop", "Queen", "King", "Right_Bishop", "Right_Knight", "Right_Rook"};
    string blackPieces[8] = {"Right_Rook", "Right_Knight", "Right_Bishop", "Queen", "King", "Left_Bishop", "Left_Knight", "Left_Rook"};
    string pawns[8] = {"pawn1", "pawn2", "pawn3", "pawn4", "pawn5", "pawn6", "pawn7", "pawn8"};

    //Initializing the black pieces
    for (int j = 0; j < COLUMNS; j = j + 1) {
        chessBoardPieces[0][j] = blackPieces[j];
        chessBoardPieces[1][j] = pawns[7 - j];
    }

    //Initializing the white pieces
    for (int j = 0; j < COLUMNS; j = j + 1) {
        chessBoardPieces[7][j] = whitePieces[j];
        chessBoardPieces[6][j] = pawns[j];
    }
    return;
}

void initializeCoords(string chessBoardCoords[ROWS][COLUMNS]) {

    string letter[8] = {"a", "b", "c", "d", "e", "f", "g", "h"};
    string number[8] = {"1", "2", "3", "4", "5", "6", "7", "8"};

    for (int i = 0; i < ROWS; i = i + 1) {
        for (int j = 0; j < COLUMNS; j = j + 1) {
            chessBoardCoords[7 - i][j] = letter[j] + number[i];
        }
    }
    return;
}

void initializeChessBoard(string chessBoardPieces[ROWS][COLUMNS], string chessBoardCoords[ROWS][COLUMNS], string chessBoardActual[ROWS][COLUMNS]) {

    for (int i = 0; i < ROWS; i = i + 1) {
        for (int j = 0; j < COLUMNS; j = j + 1) {
            chessBoardActual[i][j] = chessBoardPieces[i][j] + " " + chessBoardCoords[i][j] + " ";
        }
    }
    return;
}

void printActualBoard(string chessBoardActual[ROWS][COLUMNS]) {

    int rowCounter = 0;

    for (int i = 0; i < ROWS; i = i + 1) {
        for (int j = 0; j < COLUMNS; j = j + 1) {

            if (rowCounter == 1) {
                printPawns(7, chessBoardActual);
                break;
            }

            if (rowCounter == 2 || rowCounter == 3 || rowCounter == 4 || rowCounter == 5) {
                printNeutralGround(rowCounter, chessBoardActual);
                break;
            }

            else if (rowCounter == 6) {
                printPawns(2, chessBoardActual);
                break;
            }

            else {
                cout << chessBoardActual[i][j] << " | ";
            }
        }
        rowCounter ++;
        cout << endl;
    }
    return;
}

void printPawns(int rowNum, string chessBoardActual[ROWS][COLUMNS]) {

    if (rowNum == 7) {
        for (int j = 0; j < COLUMNS; j = j + 1) {
            cout << "  " << chessBoardActual[1][j] << " | " << "  ";
        }
    }

    else if (rowNum == 2) {
        for (int j = 0; j < COLUMNS; j = j + 1) {
            cout << "  " << chessBoardActual[6][j] << " |  " << "  ";
        }
    }

    return;
}

void printNeutralGround(int rowNum, string chessBoardActual[ROWS][COLUMNS]) {

    switch(rowNum) {
        case 2:
            for (int j = 0; j < COLUMNS; j = j + 1) {
                cout << "   " << chessBoardActual[2][j] << "          ";
            }
            break;


        case 3:
            for (int j = 0; j < COLUMNS; j = j + 1) {
                cout << "   " << chessBoardActual[3][j] << "          ";
            }
            break;

        case 4:
            for (int j = 0; j < COLUMNS; j = j + 1) {
                cout << "   " << chessBoardActual[4][j] << "          ";
            }
            break;

        case 5:
            for (int j = 0; j < COLUMNS; j = j + 1) {
                cout << "   " << chessBoardActual[5][j] << "          ";
            }
    }
    cout << endl;
    return;
}

/*bool playerTurn() {
    bool playerTurn = false;



    return playerTurn;
}*/




/* NEED TO ADD:
- An "eraser" function that deletes the position the piece just left
- Equivalent for black's turn
- Implement playerTurn function and utilize a while loop to continually ask for moves until bool endGame = true
- Capturing pieces functions
- Bank for captured pieces, w/ display information

- Simple UI instead of console grids (ASCII/color fonts are even better than current 'console board')
- Illegal moves warning
- Resign/draw options



*/

void whiteToMove(string chessBoardActual[ROWS][COLUMNS]) {

    string piece;
    string targetPosition;
    string initialPosition;

    cout << "Enter the piece you wish to move: " << endl;
    cin >> piece;
    cout << "Enter the current position of the piece: " << endl;
    cin >> initialPosition;
    cout << "Enter the target position of the piece: " << endl;
    cin >> targetPosition;

    int targetRowCoord = rowFindInArray(1, piece, targetPosition, chessBoardActual);
    int targetColumnCoord = columnFindInArray(1, piece, targetPosition, chessBoardActual);

    // TESTING PURPOSES: cout << targetRowCoord << " " << targetColumnCoord << endl;

    updateArray(piece, targetRowCoord, targetColumnCoord, targetPosition, chessBoardActual);

    return;
}
/*void blackToMove(string chessBoardActual[ROWS][COLUMNS]) {



    return;
} */

int rowFindInArray(int targetPositionOrNot, string piece, string position, string chessBoardActual[ROWS][COLUMNS]) {

    int rowCoord;
    int rowCounter = 0;

    if (targetPositionOrNot != 1) {
        for (int i = 0; i < ROWS; i = i + 1) {
            for (int j = 0; j < COLUMNS; j = j + 1) {
                if (chessBoardActual[i][j] == piece + " " + position + " ") {
                    rowCoord = rowCounter;
                }
            }
            rowCounter++;
        }
    }

    else if (targetPositionOrNot == 1) {
        for (int i = 0; i < ROWS; i = i + 1) {
            for (int j = 0; j < COLUMNS; j = j + 1) {
                if (chessBoardActual[i][j] == " " + position + " ") {
                    rowCoord = rowCounter;
                }
            }
            rowCounter++;
        }
    }

    return rowCoord;
}

int columnFindInArray(int targetPositionOrNot, string piece, string position, string chessBoardActual[ROWS][COLUMNS]) {
    
    int columnCoord;
    int columnCounter = 0;

    if (targetPositionOrNot != 1) {
        for (int i = 0; i < ROWS; i = i + 1) {
            for (int j = 0; j < COLUMNS; j = j + 1) {
                if (chessBoardActual[i][j] == piece + " " + position + " ") {
                    columnCoord = columnCounter;
                }
                columnCounter++;
            }
            columnCounter = 0;
        }
    }

    else if (targetPositionOrNot == 1) {
        for (int i = 0; i < ROWS; i = i + 1) {
            for (int j = 0; j < COLUMNS; j = j + 1) {
                if (chessBoardActual[i][j] == " " + position + " ") {
                    columnCoord = columnCounter;
                }
                columnCounter++;
            }
            columnCounter = 0;
        }
    }

    return columnCoord;
}


// Have to create some kind of temporary variable so that the original piece does not suddenly get erased, or a 'bank' of some sorts to display the captured pieces
void updateArray(string piece, int row, int column, string targetPosition, string chessBoardActual[ROWS][COLUMNS]) {

    chessBoardActual[row][column] = piece + " " + targetPosition;

    return;
}
