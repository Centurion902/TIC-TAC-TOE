#include "tictactoe.h"/*includes nescesary functions and libraries*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  unsigned short us = atoi(argv[1]);/*takes command line argument*/

  if (argc != 2) {/*makes sure correct number of arguments*/
    printf("Error, usage: %s <board number>\n", argv[0]);
    exit(-1);
  }

  debug(us);/*calls debug to write move information*/

  return 0;
}
