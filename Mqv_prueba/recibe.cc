#include "../Mq-sv/sv_mq.h"

int main(){
  mpdu *m1;
  string s;
  sv_mq cola("/micola");
  m1= cola.receive();
  cout<<cola<<endl;
  while (m1->getHdr()!="Fin"){
    cout<<"Recibido "<<m1->getSdu() << endl;
    delete(m1);
    m1=cola.receive();
    cout<<cola<<endl;
  }
  cola.del();
  cout<<"Terminado"<<endl;
}