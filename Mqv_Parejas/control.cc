#include "../Mq-sv/sv_mq.h"

void impStatus(sv_mq mutexA, sv_mq mutexB, int procA, int procB){ //imprime estado de los mutex (mutexs? mutexes??)
  cout<<"mutexA="<<mutexA<<endl<<"mutexB="<<mutexB<<endl;
  cout<<"procA="<<procA<<", procB="<<procB<<endl;
}

int main(){
  mpdu m,*m1; 
  string s,ms;  
  sv_mq mutexA("/mutexA"); // message queue de mutexA
  sv_mq mutexB("/mutexB"); // message queue de mutexB
  int procA=0,procB=0; // cantidad de procesos de cada tipo en espera
  sv_mq pedidos("/pedidos"); // message queue de pedidos
  m.setHdr("Sigue");
  cout<<"Esperando pedidos"<<endl;
  m1=pedidos.receive(); // recibo mensajes en cola de pedidos
  cout<<"Recibido "<<*m1<<endl;
  s=m1->getHdr();
  while (s!="Fin"){ // mientras que el header del mensaje de pedido no sea Fin
    impStatus(mutexA,mutexB,procA,procB);
    if (s=="EntA"){procA++;}  // aumento cantidad de procesos de un tipo en espera
    if (s=="EntB"){procB++;} // según qué tipo de proceso es
    cout<<"Registrado el pedido."<<endl;
    impStatus(mutexA,mutexB,procA,procB);
    if ((procA>0)and (procB>0)){ // si tengo suficientes hago que entre una pareja
      cout <<"Entra una pareja. "<<endl;
      mutexA.send(m);mutexB.send(m); // envío mensajes a queues de ambos mutex
      procA--;procB--; // resto cantidad de procesos en espera
      impStatus(mutexA,mutexB,procA,procB);
    }
    cout<<"Esperando pedidos"<<endl;
    delete(m1); // borro contenido de ultimo mensaje recibido
    m1=pedidos.receive(); // recibo mensajes en cola de pedidos
    cout<<"Recibido "<<*m1<<endl;
    s=m1->getHdr();
  }
  cout<<"termina"<<endl;
}

  


