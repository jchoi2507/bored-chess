                // Header File

// Preprocessor directives
#ifndef HEADERFILE_H_
#define HEADERFILE_H_

#include <iostream>
#include <string>
#include <fstream>
using namespace std; 

// Global constants, enums, classes, etc, etc.

const int ROWS = 8;
const int COLUMNS = 8;
const int TOTALPIECES = 32;

// Function statements

    // Initialization functions
void initializeChessBoard(string chessBoardPieces[ROWS][COLUMNS], string chessBoardCoords[ROWS][COLUMNS], string chessBoardActual[ROWS][COLUMNS]);
void initializePieces(string chessBoardPieces[ROWS][COLUMNS]);
void initializeCoords(string chessBoardCoords[ROWS][COLUMNS]);

    // Printing functions
void printActualBoard(string chessBoardActual[ROWS][COLUMNS]);
void printPawns(int rowNum, string chessBoardActual[ROWS][COLUMNS]);
void printNeutralGround(int rowNum, string chessBoardActual[ROWS][COLUMNS]);
void printTopBorder();
void printBottomBorder();
void errorMessage();
void printScreen(string chessBoardActual[ROWS][COLUMNS]);

    // Game & piece-moving functions
bool resignOption();
void whiteToMove(string chessBoardActual[ROWS][COLUMNS]);
void blackToMove(string chessBoardActual[ROWS][COLUMNS]);
int rowFindInArray(int targetPositionOrNot, string piece, string targetPiece, string position, string chessBoardActual[ROWS][COLUMNS]);
int columnFindInArray(int targetPositionOrNot, string piece, string targetPiece, string position, string chessBoardActual[ROWS][COLUMNS]);
void updateArray(int captureOrNot, string piece, int row, int column, string targetPosition, string chessBoardActual[ROWS][COLUMNS]);
void clearOriginalPosition(int originalRow, int originalColumn, string initialPosition, string chessBoardActual[ROWS][COLUMNS]);

#endif
