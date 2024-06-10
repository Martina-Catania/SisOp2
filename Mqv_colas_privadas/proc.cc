#include <unistd.h>
#include "../Mq-sv/sv_mq.h"

int main(int argc, char * argv[]){
  if (argc < 2){ // check argumentos
      cerr<<"Uso: "<<argv[0]<<" <nombre-del-proceso>"<<endl;
      exit(1);
  }
   char auxnom[20];
  sprintf (auxnom,"%d",static_cast<int>(getpid()));  // el to_string de antes del c++11
  string nom(auxnom),auxrta;  // defino dos strings: nom (en base a auxnom) y auxrta
  nom=argv[1]+("-"+nom); //nom=argv[1]+"-"+to_string(getpid())  || concatena nombre y id de proceso
  cout<<"Proceso "<<nom<<endl;
  mpdu m1, *p_rta; // define dos mpdus: m1 y puntero a *p_rta
  string s;
  sv_mq cola_pr(nom.c_str()); // define message queue cola_pr con id = nombre concatenado
  sv_mq control ("/control"); // define message queue control con id /control
  m1.setSdu(nom); // datos en m1 = nombre concatenado
  cout<<"Mensaje <"<<m1<<">"<<endl;
  control.send(m1); // envía m1 a control
  cout<<"...Control avisado"<<endl;
  p_rta=cola_pr.receive(); // espera a recibir mensaje de cola_pr
  cout<<"...Liberado"<<endl;
  cola_pr.del();
}