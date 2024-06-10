#include "../Mq-sv/sv_mq.h"
#include "unistd.h"

int main(){
  mpdu m,*m1;
  string s,nom;
  nom=to_string(getpid());
  sv_mq mutex("/mutexB");
  sv_mq pedidos("/pedidos");
  cout<<"Usando cola "<<mutex<<endl;
  cout<<"Intento entrar"<<endl;
  m.setHdr("EntB");
  m.setSdu("B"+nom);
  cout<<"Usando cola "<<mutex<<endl;
  cout<<"Intento entrar .."<<endl;
  pedidos.send(m);
  cout<<"Enviado "<<m<<endl;
  m1=mutex.receive();
     cout<<"... en la seccion critica ..."<<endl;
     cin>>s;
  m.setHdr("ChauB");
  pedidos.send(m);
  cout<< "terminando"<<endl;  
}