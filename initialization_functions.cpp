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

void printTopBorder() {

    cout << "***************************************************************** BLACK POV *********************************************************" << endl;
    return;
}

void printBottomBorder() {

    cout << "***************************************************************** WHITE POV *********************************************************" << endl;
    return;
}

void errorMessage() {
    cout << "Entered an invalid input." << endl;
    exit(EXIT_FAILURE);

    return;
}

void printScreen(string chessBoardActual[ROWS][COLUMNS]) {

    printTopBorder();
    printActualBoard(chessBoardActual);
    printBottomBorder();

    return;
}
