#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>
#include "../Mq-sv/mpdu.h"
#include "../Mq-sv/sv_mq.h"
#include "Mensajes.h"
using namespace std;
/* 
 ACCESO A RECURSOS COMPARTIDOS
 en vez de usar semaforos para acceder al espacio compartido
 uso a un portero que regula quien entra y quién sale
 enviando mensajes para pedir entrar y salir
 */
int main(int argc, char * argv[]){ // check argumentos
  if (argc < 2){
      cerr<<"Uso: "<<argv[0]<<" <nombre-del-proceso>"<<endl;
      exit(1);
  }
   char auxnom[20];
  sprintf (auxnom,"%d",static_cast<int>(getpid()));
  string nom(auxnom),auxrta; // defino strings de nombre y auxrta
  nom=argv[1]+("-"+nom); // concateno nombre y pid
  cout<<"Lector "<<nom<<endl;
  mpdu m1, *rta; // defino mpdu m1 y puntero a rta
  sv_mq portero("puerta"); // defino message queue de portero
  sv_mq cola_rdr("readers"); // defino message queue de lectores
  m1.setHdr(Lector_Quiere_Entrar);
  m1.setSdu(nom);
  cout<<"Pido permiso para entrar"<<endl;
  portero.send(m1); // envio request para entrar
  //cout<<portero<<endl;
  // Entrada a la base 
    rta=cola_rdr.receive();
    auxrta=rta->getSdu();
    delete rta;
   
    cout<<"En la Base, una entrada para salir "<<endl;
    cin>>auxrta;
    m1.setHdr (Lector_Sale);
    portero.send(m1);
  // Salio de la base
  
  if (argc ==3) portero.send(mpdu("Fin",""));
  cout<<"Termina"<<endl;
}