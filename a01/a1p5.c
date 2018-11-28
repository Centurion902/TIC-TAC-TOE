#include "tictactoe.h"/*includes nescasary functions and libraries*/
#include <stdio.h>
#include <stdlib.h>

int main (){
  char name[100], b3[10] = "000000000", board[60];
  int playerSym, comSym, move;
  char choice;

  struct strategy_struct strat;/*creates a strategy_struct*/

  FILE * fp;
  fp = fopen("strategyfile", "r");/*opens strategyfile for reading*/

  printf("SHALL WE PLAY A GAME?\n\n");
  printf("PLEASE ENTER YOUR NAME: ");/*prompt*/
  fgets(name, 100, stdin);/*takes input of string 100 characters or less long*/
  printf("\nGREETINGS %s\n", name);/*adresses player*/

  do {
    printf("Which side would you like to play (X/O)? ");/*prompt*/
    scanf(" %c", &choice);/*takes input of side choice as capital char*/
    if(choice != 'O' && choice != 'X'){/*checks for valid input*/
      printf("Invalid choice.\n");/*prints if input is invalid*/
    }else if(choice== 'O'){
      comSym=2;/*sets player and com to respective sides*/
      playerSym = 1;
      printf("Ok, you will be O; I will be X.\n\n");
    }else{
      comSym=1;
      playerSym = 2;
      printf("Ok, you will be X; I will be O.\n\n");
    }
  }while(choice!= 'O' && choice != 'X');/*loops while input is invalid*/

  boardfromb3(board, b3);/*sets up empty board*/
  while(winner(b3) == ' '){/*loops till game is over*/
    if(get_turn(b3) == playerSym){/*checks whoose turn it is*/
      printf("\nYour turn; chose a move [0-8]: ");/*prompt*/
      scanf(" %d", &move);/*takes player input*/
      b3fromus(b3, next(b3tous(b3), move+'0'));/*makes move*/
    }else{
      get_record(fp, b3tous(b3), &strat);/*copies correct strategy into strat struct*/
      move = strat.best_move-'0';/*sets best move to move*/
      b3fromus(b3, next(b3tous(b3), move+'0'));/*makes move*/
      printf("\nMy turn; my move is %d:\n", move);
    }
    boardfromb3(board, b3);/*prints out next board*/
  }

  if(winner(b3) == comSym+'0'){/*prints end of game messages for winning or tying*/
      printf("\nI won!\n");/*AI gloats*/
  } else{
    printf("\nThe game is a tie.\n");
  }

  printf("\nA STRANGE GAME.\nTHE ONLY WINNING MOVE IS\nNOT TO PLAY.\n");/*AI graduates with philosophy degree*/

  fclose(fp);/*closes file*/
  return 0;
}
