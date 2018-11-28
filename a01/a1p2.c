#include "tictactoe.h"/*includes nescasary method*/

int main(){
  FILE * st;

  int i;

  struct strategy_struct strat; /*creates trategy struct and fills it with no best move and no winner*/

  strat.best_move = -1;
  strat.winner = ' ';

  st = fopen("strategyfile", "w");/*opens file to write to*/

  for(i = 0; i<19683; i++){/*fills every all board positions in the strategyfile with the spacefillling struct*/
    fwrite(&strat, sizeof(char), 2, st);
  }

  fclose(st);/*coses file*/
  return 0;
}
