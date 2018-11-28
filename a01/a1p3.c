#include "tictactoe.h"/*includes nescasary functions and libraries*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  unsigned short us = atoi(argv[1]), i;/*takes command line argument*/
  char b3[10];

  struct strategy_struct strat;

  FILE * fp;
  fp = fopen("strategyfile", "r+");/*opens file for reading and writing*/

  if (argc != 2) {/*makes sure number of arguments is correct*/
    printf("Error, usage: %s <board number>\n", argv[0]);
    exit(-1);
  }

  for(i = 0; i<19683; i++){/*loops through all posiible boards*/
    b3fromus(b3, i);/*converts board number to trinary represantation*/
    if(us == get_move(b3)&&winner(b3)!=' '){/*checks if game has ended*/
      printf("[%d]\n", i);
      strat.best_move = -1;/*writes no best move and writes the winner of the game to the strategyfile*/
      strat.winner = winner(b3);
      set_record(fp, i, &strat);
    } else if(us == get_move(b3)){
      printf("%d\n", i);
      evaluate_move(i, &strat);/*evaluates all possible moves and returns the best*/
      set_record(fp, i, &strat);/*writes best move and determines winner to strategyfile*/
    }
  }
  
  fclose(fp);/*closes file*/
  return 0;
}
