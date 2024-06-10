#include "../Mq-sv/sv_mq.h"

int main(){
    sv_mq pedidos("/pedidos");
    mpdu m ("Fin","");
    cout<<"Envio el mensaje de fin a "<<pedidos<<endl;
    pedidos.send(m);
}