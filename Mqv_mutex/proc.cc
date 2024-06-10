#include "../Mq-sv/sv_mq.h"
/*
 solo puedo entrar a la sección crítica si soy el primer mensaje en mutex
*/
int main(){
  mpdu *m1;
  string s;
  sv_mq mutex("/mutex"); // declaro message queue de mutex
  cout<<"Intento entrar .."<<endl;
  m1=mutex.receive(); // recivo mensaje de mutex para empezar proceso
     cout<<"... en la seccion critica ..."<<endl;
     cin>>s;
  mutex.send(*m1); // envío mensaje a mutex para terminar proceso
  cout<< "terminando"<<endl;
}