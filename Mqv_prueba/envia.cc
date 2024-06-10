#include "../Mq-sv/sv_mq.h"

int main(){
  mpdu m1;
  string s;
  sv_mq cola("/micola");
  cout<<"Enviar ... ";
  while (cin>>s){
    m1.setHdr("Data");
    m1.setSdu(s);
    cola.send(m1);
    cout<<cola<<endl;
    cout<<"...enviado, \nEnviar ... ";
  }
  m1.setHdr("Fin");
  cola.send(m1);
  cout<<"Fin"<<endl;
}