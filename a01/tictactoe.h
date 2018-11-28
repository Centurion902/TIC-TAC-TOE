/* tictactoe.h
	Header
	Name: Eli Henry Dykhne
	Email: edykhne@uoguelph.ca
	Student ID: 0996524
*/

#include <stdio.h> /*importing nescesary libreries*/
#include <string.h>
#ifndef TICTACTOE_H
#define TICTACTOE_H

/*
Name: b3tous
Inputs: one char of length 10
Outputs: one unsined short
Function: Converts a string containing the base 3 representation of a number in decimal format.
*/
unsigned short b3tous(char b3[10]);

/*
Name: b3fromus
Inputs: char length 10 and an unsigned short
Outputs: N/A
Function: Converts an unsigned integer to its base 3 representation and stores it in a string.
*/
void b3fromus(char b3[10], unsigned short us);

/*
Name: debug
Inputs: unsigned short
Outputs: N/A
Function: printf board number, board image, move, turn, current winner and all possible boards that the next move can take you too
*/
void debug(unsigned short us);

/*
Name: debug 2
Inputs: unsigned short
Outputs: N/A
Function: same as debug but also prints best move and predicted winner
*/
void debug2(unsigned short us);

/*
Name: boardfromb3
Inputs: string of length 60 and string of length 10
Outputs: N/A
Function: Prints the visual representation of the current board state
*/
void boardfromb3(char board[60], char b3[10]);

/*
Name: get_move
Inputs: string of length 10
Outputs:  integer
Function: returns move number that current board is on
*/
int get_move(char b3[10]);

/*
Name: get_turn
Inputs: string of length 10
Outputs: integer
Function: returns the whoose turn it is at a particular board stage
*/
int get_turn(char b3[10]);

/*
Name: get_winner
Inputs: strong of length 10
Outputs: integer
Function: returns the winner of the board at its current state
*/
char winner(char b3[10]);

/*
Name: next
Inputs: unsigned short and char
Outputs: unsigned short
Function: determines decimal representattion of the board after the specified move is made
*/
unsigned short next(unsigned short us, char pos);

/*structure stores predicted winner and best move at this position*/
struct strategy_struct{
    char best_move;
    char winner;
};

/*
Name: get_record
Inputs: pointer to a file, unsigned short, pointer to a struct
Outputs: N/A
Function: reads predicted winner and best move from file into the corresponding values of the struct
*/
void get_record(FILE *fp, unsigned short us, struct strategy_struct *record);

/*
Name: set_record
Inputs: pointer to a file, unsigned short, pointer to a struct
Outputs: N/A
Function: writes predicted winner and best move from struct into the corresponding position in the file
*/
void set_record(FILE *fp, unsigned short us, struct strategy_struct *record);

/*
Name: evaluate_move
Inputs: unsigned short, pointer to a struct
Outputs: N/A
Function: checks all possible moves for best move and writes it to the strategy file as well as the predicted winner
*/
void evaluate_move(unsigned short us, struct strategy_struct *record);

#endif
