#include "includes.h"

  int main(int argc, char *argv[]){
    if (argc <3){ // check argumentos
        cerr<<"uso:"<<argv[0]<<" <Cola de Mensajes> <mensaje> [f]"<<endl;exit(1);}
    mpdu m1; // declaro mpdu
  string s(argv[2]); // string con contenido del mensaje
  sv_mq cola(argv[1]); // crea una instancia de message queue llamada cola e id = argv[1]
  if (argc==4)m1.setHdr("Fin"); // si hay 4 argumentos header = fin
        else  m1.setHdr("Data"); // else header = data
  m1.setSdu(s); // set data de m1 al string s
  cola.send(m1); // envío m1 por la cola de mensajes
  cout<<cola<<endl; // print estado de cola
  cout<<"Enviado "<<m1<<endl;
}
  