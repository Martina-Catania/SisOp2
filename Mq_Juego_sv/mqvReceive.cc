#include "includes.h"

int main(int argc, char *argv[]){
  if (argc !=2){
      cerr<<"uso:"<<argv[0]<<" <Cola de Mensajes> "<<endl;exit(1);}
  mpdu *m1; //declaro puntero a mpdu llamado m1
  string s; //declaro string
  sv_mq cola(argv[1]); // crea una instancia de message queue llamada cola
  m1= cola.receive(); // asigna resultado de recibir mensaje al puntero m1
  cout<<"Recibido "<<(*m1) << endl;
}