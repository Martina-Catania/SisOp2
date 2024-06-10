#include  "../Mq-sv/sv_mq.h"

int main(){
  mpdu m1, *p_pedido; // define dos mpdus: m1 y un puntero a p_pedido
  string pedido,s; // define dos strings: pedido y sa
  m1.setSdu("chau");
  sv_mq control("control");  // crea message queue con id control
  cout<<"esperando en "<<control<<endl;
  p_pedido=control.receive(); // espero recibir mensajes y asigno a p_pedido
  pedido=p_pedido->getSdu(); // string pedido = contenido recibido recién y almacenado en p_pedido
  cout<<(*p_pedido)<<endl;
  sv_mq privada(pedido); //crea cola privada e id = pedido
  cout <<"Proceso detenido en "<<privada<<" string para liberar... "<<endl;
  cin>>s; // detiene proceso hasta recibir user input
  privada.send(m1); // envia mensaje a cola privada
  cout<<" Liberado"<<endl;
  
  
}