#include "includes.h"

int main(int argc, char *argv[]){
    if (argc <2){ // check argumentos
        cerr<<"uso:"<<argv[0]<<" <Cola de Mensajes>"<<endl;exit(1);}
    sv_mq cola(argv[1]); // crea una instancia de message queue llamada cola e id = argv[1]
    cout<<cola<<endl; // print estado de cola
}
