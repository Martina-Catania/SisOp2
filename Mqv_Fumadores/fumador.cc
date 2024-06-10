#include "includes.h"

int main(int argc, char * argv[]){
  string nom,auxrta;
  nom="Fumador-"+to_string(getpid());
  cout<<nom<<endl;
  mpdu *m1;
  sv_mq papel("/Papel");
  sv_mq tabaco("/Tabaco");
  sv_mq fosforos("/Fosforos");
  cout<<"Busco papel"<<endl;
  m1=papel.receive();
  delete(m1);
  cout<<"Busco tabaco"<<endl;
  m1=tabaco.receive();
  delete(m1);
  cout<<"Busco fosforos"<<endl;
  m1=fosforos.receive();
  delete(m1);
  cout<<"Fumando."<<endl;
}

