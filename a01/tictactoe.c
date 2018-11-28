/* tictactoe.c
	Nescecary methods
	Name: Eli Henry Dykhne
	Email: edykhne@uoguelph.ca
	Student ID: 0996524
*/

#include "tictactoe.h" /*including function definitions*/

/*
Name: b3tous
Inputs: one char of length 10
Outputs: one unsined short
Function: Converts a string containing the base 3 representation of a number in decimal format.
*/
unsigned short b3tous( char b3[10] ){
	int i; /*variables. multi is 3^8*/
	int multi = 6561;
	int deci = 0;
	for(i=0; i<=8; i++){ /*multiplies each digit by the corresponding power of three*/
		deci+=multi*(b3[i]-'0');
		multi/=3;/*adjusts multiplier for next input*/
	}
	return deci;
}

/*
Name: b3fromus
Inputs: char length 10 and an unsigned short
Outputs: N/A
Function: Converts an unsigned integer to its base 3 representation and stores it in a string.
*/
void b3fromus( char b3[10], unsigned short us ){
	int i;/*variables*/
	b3[9] = '\0';/*tacks on an null terminator*/
	for(i=8; i>=0; i--){
		b3[i]=us%3+'0';/*places the correct digit in the positions after converting to char*/
		us/=3;/*adjusts us for next input*/
	}
}

/*
Name: boardfromb3
Inputs: string of length 60 and string of length 10
Outputs: N/A
Function: Prints the visual representation of the current board state
*/
void boardfromb3(char board[60], char b3[10]){
	int i;/*counter*/
	strcpy(board, "   |   |   \n---+---+---\n   |   |   \n---+---+---\n   |   |   \0");/*copies empty board layout into board*/

	for(i = 0; i < 10; i++){/*fills each space with the correct game piece*/
		if(b3[i]=='1'){
			board[4*i+(i)/3*12+1]='O';/*linear function with jumps facilitated by integer division*/
		} else if(b3[i]=='2'){
			board[4*i+(i)/3*12+1]='X';/*ditto*/
		}
	}
	printf("%s\n", board);/*prints board*/
}

/*
Name: get_move
Inputs: string of length 10
Outputs:  integer
Function: returns move number that current board is on
*/
int get_move(char b3[10]){
	int i, move = 9;
	for(i=0; i<9; i++){/*loops through all 9 spaces*/
		if (b3[i]=='0'){ /*removes one from move if an empty space is found on the board*/
			move--;
		}
	}
	return move;
}

/*
Name: get_turn
Inputs: string of length 10
Outputs: integer
Function: returns the whoose turn it is at a particular board stage
*/
int get_turn(char b3[10]){
	int turn = 1;
	if (get_move(b3)%2 == 0){/*checks if the move number is even*/
		turn = 2;
	}
	return turn;
}

/*
Name: winner
Inputs: strong of length 10
Outputs: integer
Function: returns the winner of the board at its current state
*/
char winner(char b3[10]){
	char win =' ';/*in case the game is not done yet*/
	if(('1' == b3[0] && b3[0] == b3[1] && b3[1] == b3[2])||('1' == b3[3] && b3[3] == b3[4] && b3[4] == b3[5])||('1' == b3[6] && b3[6] == b3[7] && b3[7] == b3[8])||('1' == b3[0] && b3[0] == b3[4] && b3[4] == b3[8])||('1' == b3[2] && b3[2] == b3[4] && b3[4] == b3[6])||('1' == b3[0] && b3[0] == b3[3] && b3[3] == b3[6])||('1' == b3[1] && b3[1] == b3[4] && b3[4] == b3[7])||('1' == b3[2] && b3[2] == b3[5] && b3[5] == b3[8])){
		win = '1';/*sets to 1 if a winning state for O is found*/
	}else if(('2' == b3[0] && b3[0] == b3[1] && b3[1] == b3[2])||('2' == b3[3] && b3[3] == b3[4] && b3[4] == b3[5])||('2' == b3[6] && b3[6] == b3[7] && b3[7] == b3[8])||('2' == b3[0] && b3[0] == b3[4] && b3[4] == b3[8])||('2' == b3[2] && b3[2] == b3[4] && b3[4] == b3[6])||('2' == b3[0] && b3[0] == b3[3] && b3[3] == b3[6])||('2' == b3[1] && b3[1] == b3[4] && b3[4] == b3[7])||('2' == b3[2] && b3[2] == b3[5] && b3[5] == b3[8])){
		win = '2';/*ditto but for X*/
	} else if (get_move(b3) == 9){
		win = '0';/*sets to zero if board is filled up*/
	}
	return win;
}

/*
Name: next
Inputs: unsigned short and char
Outputs: unsigned short
Function: determines decimal representattion of the board after the specified move is made
*/
unsigned short next(unsigned short us, char pos){
	char b3[10];
	b3fromus(b3, us);/*creates trenary representation of board*/
	if(b3[pos-'0']=='1' || b3[pos-'0']=='2'){/*checks if position attempting to be played at is free*/
		us = 0;/*sends to start if position is not free*/
	}else{
		b3[pos-'0']=get_turn(b3)+'0';/*sets position to players piece*/
		us = b3tous(b3);/*converts new board to decimal representation*/
	}
	return us;
}

/*
Name: debug
Inputs: unsigned short
Outputs: N/A
Function: printf board number, board image, move, turn, current winner and all possible boards that the next move can take you too
*/
void debug(unsigned short us){
	char b3[10], board[60];
  int i;

	printf( "Board number: %d\n", us );/*prints decimal board representation*/
  b3fromus(b3, us);/*determens trenary representation*/
  printf( "Board b3: %s\n", b3 );/*prints trenary representation*/
  printf("Board pic:\n");
	boardfromb3(board, b3);/*prints visual representation of board*/
  printf("Move: %d\n", get_move(b3));/*prints out move number*/
  printf("Turn: %d\n", get_turn(b3));/*prints whose turn it is*/
  printf("Winner: %c\n", winner(b3));/*prints current winner*/

  for(i = 0; i<9; i++){/*prints all possible moves and the boards they take you to*/
    printf("%d -> %d\n", i, next(us, i+'0'));
  }
}

/*
Name: debug 2
Inputs: unsigned short
Outputs: N/A
Function: same as debug but also prints best move and predicted winner
*/
void debug2(unsigned short us){
  struct strategy_struct record;/*creates strategy_struct*/
	char b3[10], board[60];
  int i;
  FILE * fp;

	printf( "Board number: %d\n", us );/*prints board number*/
  b3fromus(b3, us);/*converts trenary form*/
  printf( "Board b3: %s\n", b3 );/*prints trenary representation*/
  printf("Board pic:\n");
	boardfromb3(board, b3);/*prints graphical representation of board*/
  printf("Move: %d\n", get_move(b3));/*prints current move number*/
  printf("Turn: %d\n", get_turn(b3));/*prints whoose turn it is */
  printf("Winner: %c\n", winner(b3));/*prints current winner*/

  fp = fopen("strategyfile", "r");/*opens strategyfile*/
  get_record(fp, us, &record);/*places best move and predicted winner into strategystruct*/
  printf("best_move=%c, winner=%c\n", record.best_move, record.winner); /*prints best move and predicted winner*/

  for(i = 0; i<9; i++){/*prints all possible moves and the boards they take you to*/
    printf("%d -> %d\n", i, next(us, i+'0'));
  }
}

/*
Name: get_record
Inputs: pointer to a file, unsigned short, pointer to a struct
Outputs: N/A
Function: reads predicted winner and best move from file into the corresponding values of the struct
*/
void get_record( FILE *fp, unsigned short us, struct strategy_struct *record){
   fseek(fp, us * sizeof(struct strategy_struct), SEEK_SET);/*places our read head at the correct position in the file*/
   fread(record, 1, 2, fp);/*reads best move and predicted winner from strategyfile into the strategy_struct*/
}

/*
Name: set_record
Inputs: pointer to a file, unsigned short, pointer to a struct
Outputs: N/A
Function: writes predicted winner and best move from struct into the corresponding position in the file
*/
void set_record(FILE *fp, unsigned short us, struct strategy_struct *record){
  fseek(fp, us * sizeof(struct strategy_struct), SEEK_SET);/*places our write head at the correct position in the file*/
  fwrite(record, sizeof(char), 2, fp); /*writes best move and predicted winner from the strategy_struct to the strategyfile*/
}

/*
Name: evaluate_move
Inputs: unsigned short, pointer to a struct
Outputs: N/A
Function: checks all possible moves for best move and writes it to the strategy file as well as the predicted winner
*/
void evaluate_move(unsigned short us, struct strategy_struct *record){
  unsigned int i, found_tie= 0, tie, legal_move, nextBoard;/*variables*/
	char b3[10];

	struct strategy_struct temp;/*strategy holder*/

	FILE * fp;

	fp = fopen("strategyfile", "rb+");/*Opening file to read and write*/
  for(i=0; i<9; i++){/*cycles through every move*/
    b3fromus(b3, us);/*creates trenary represanation of board*/
		nextBoard = next(us, i+'0');/*sets us value of the board this move takes us to*/

    if(nextBoard!= 0){/*filters for valid moves*/
      get_record(fp, nextBoard, &temp);/*stores winner value and best move value in temp for this move*/

      if(temp.winner == get_turn(b3)+'0'){/*if winner matches the person who is moving, strategy is dominant and is writen to the strategyfiel*/
        record->best_move = i+'0';
        record->winner = temp.winner;
				fclose(fp);/*closes strategy file. missing this causes a segfault when memory runs out*/
        return;/*returns to call*/
      } else if(temp.winner == '0'){/*if iits a tie, stores tying position in tie and sets found ties to 1*/
        found_tie = 1;
        tie = i;
      } else{/*saves the move as a legal move*/
        legal_move = i;
      }
    }
  }

  if (found_tie==1){/*if a tie has been found, sets the tying move to best move and sets winner to 0 in the strategyfile*/
    record->best_move = tie+'0';
    record->winner = '0';
  } else if(found_tie == 0){/*if no tie has been found, legal move is set to best move and winner is set to the opponenet in strategyfile*/
    record->best_move = legal_move+'0';
    if(get_turn(b3)+'0'=='1'){/*setting winner to opponent in strategyfile*/
      record->winner = '2';
    } else{
      record->winner = '1';
    }
  }
  fclose(fp);/*closing file*/
}
