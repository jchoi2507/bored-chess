#include "headerFile.h"

void whiteToMove(string chessBoardActual[ROWS][COLUMNS]) {

    string piece;
    string targetPosition;
    string initialPosition;
    char capturing;

    cout << "Enter the piece you wish to move: " << endl;
    cin >> piece;
    cout << "Enter the current position of the piece: " << endl;
    cin >> initialPosition;
    cout << "Enter the target position of the piece: " << endl;
    cin >> targetPosition;
    cout << "Capturing? y/n. " << endl;
    cin >> capturing;

    string targetPiece;
    bool capture;

    if (capturing == 'y') {
        capture = true;
        cout << "Enter the captured piece: " << endl;
        cin >> targetPiece;
    }
    else if (capturing == 'n') {
        capture = false;
    }
    else {
        errorMessage();
    }

    int originalRowCoord = rowFindInArray(0, piece, "", initialPosition, chessBoardActual);
    int originalColumnCoord = columnFindInArray(0, piece, "", initialPosition, chessBoardActual);

    int targetRowCoord = rowFindInArray(1, piece, "", targetPosition, chessBoardActual);
    int targetColumnCoord = columnFindInArray(1, piece, "", targetPosition, chessBoardActual);

    if (capture == true) {

        int capturedRowCoord = rowFindInArray(1, piece, targetPiece, targetPosition, chessBoardActual);
        int capturedColumnCoord = columnFindInArray(1, piece, targetPiece, targetPosition, chessBoardActual);
    
        updateArray(1, piece, capturedRowCoord, capturedColumnCoord, targetPosition, chessBoardActual);
        clearOriginalPosition(originalRowCoord, originalColumnCoord, initialPosition, chessBoardActual);
    }

    else if (capture == false) {
        updateArray(0, piece, targetRowCoord, targetColumnCoord, targetPosition, chessBoardActual);
        clearOriginalPosition(originalRowCoord, originalColumnCoord, initialPosition, chessBoardActual);
    }
    return;
}

void blackToMove(string chessBoardActual[ROWS][COLUMNS]) {

    string piece;
    string targetPosition;
    string initialPosition;
    char capturing;

    cout << "Enter the piece you wish to move: " << endl;
    cin >> piece;
    cout << "Enter the current position of the piece: " << endl;
    cin >> initialPosition;
    cout << "Enter the target position of the piece: " << endl;
    cin >> targetPosition;
    cout << "Capturing? y/n. " << endl;
    cin >> capturing;

    string targetPiece;
    bool capture;

    if (capturing == 'y') {
        capture = true;
        cout << "Enter the captured piece: " << endl;
        cin >> targetPiece;
    }
    else if (capturing == 'n') {
        capture = false;
    }
    else {
        errorMessage();
    }

    int originalRowCoord = rowFindInArray(0, piece, "", initialPosition, chessBoardActual);
    int originalColumnCoord = columnFindInArray(0, piece, "", initialPosition, chessBoardActual);

    int targetRowCoord = rowFindInArray(1, piece, "", targetPosition, chessBoardActual);
    int targetColumnCoord = columnFindInArray(1, piece, "", targetPosition, chessBoardActual);

    if (capture == true) {

        int capturedRowCoord = rowFindInArray(1, piece, targetPiece, targetPosition, chessBoardActual);
        int capturedColumnCoord = columnFindInArray(1, piece, targetPiece, targetPosition, chessBoardActual);

        updateArray(1, piece, capturedRowCoord, capturedColumnCoord, targetPosition, chessBoardActual);
        clearOriginalPosition(originalRowCoord, originalColumnCoord, initialPosition, chessBoardActual);
    }

    else if (capture == false) {
        updateArray(0, piece, targetRowCoord, targetColumnCoord, targetPosition, chessBoardActual);
        clearOriginalPosition(originalRowCoord, originalColumnCoord, initialPosition, chessBoardActual);
    }
    return;
}

// This function finds the row coordinates for a piece to move to an EMPTY position + finds the row coordinates for the piece's original position to
// delete it
int rowFindInArray(int targetPositionOrNot, string piece, string targetPiece, string position, string chessBoardActual[ROWS][COLUMNS]) {

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
                if (chessBoardActual[i][j] == targetPiece + " " + position + " ") {
                    rowCoord = rowCounter;
                }
            }
            rowCounter++;
        }
    }
    return rowCoord;
}

// This function finds the column coordinates for a piece to move to an EMPTY position + finds the column coordinates for the piece's original position to
// delete it
int columnFindInArray(int targetPositionOrNot, string piece, string targetPiece, string position, string chessBoardActual[ROWS][COLUMNS]) {
    
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
                if (chessBoardActual[i][j] == targetPiece + " " + position + " ") {
                    columnCoord = columnCounter;
                }
                columnCounter++;
            }
            columnCounter = 0;
        }
    }
    return columnCoord;
}

//This function either updates an empty coordinate with the piece, or, captures a piece
void updateArray(int captureOrNot, string piece, int row, int column, string targetPosition, string chessBoardActual[ROWS][COLUMNS]) {

    if (captureOrNot == 1) {
        string tempVal;
        tempVal = chessBoardActual[row][column];

        cout << "Captured piece: " << tempVal << endl;
        chessBoardActual[row][column] = piece + " " + targetPosition + " ";
    }

    else if (captureOrNot != 1) {
        chessBoardActual[row][column] = piece + " " + targetPosition + " ";
    }
    return;
}

void clearOriginalPosition(int originalRow, int originalColumn, string initialPosition, string chessBoardActual[ROWS][COLUMNS]) {

    chessBoardActual[originalRow][originalColumn] = " " + initialPosition + " ";
    return;
}

bool resignOption() {
    char response;
    cout << "Resign? y/n. " << endl;
    cin >> response;

    if (response == 'y') {
        return true;
    }
    else {
        return false;
    }
}
