#include "tictactoe.h"/*includes functions and Nescecary libraries*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  unsigned short us = atoi(argv[1]);/*takes command line arument*/

  if (argc != 2) {/*makes sure number of arguments is correct*/
    printf("Error, usage: %s <board number>\n", argv[0]);
    exit(-1);
  }

  debug2(us);/*calls debug2*/
  return 0;
}
