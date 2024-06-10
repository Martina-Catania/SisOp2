#include "includes.h"

int main(int argc, char *argv[]){
  if (argc <2){ //check argumentos, si hay menos de 2:
    cerr<<"uso:"<<argv[0]<<" <Cola de Mensajes>";exit(1);} //print a error stream
  sv_mq cola(argv[1]); // else crea una instancia de message queue llamada cola
  cola.del(); // borra message queue
}
