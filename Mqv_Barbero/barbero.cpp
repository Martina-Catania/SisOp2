#include <iostream>
#include "../Mq-sv/sv_mq.h"
#include "../Mq-sv/mpdu.h"

/* Barbero */

using namespace std;
int main(int argc, char *argv[]) {
	mpdu msg, *msgrcvd;
	sv_mq figaro("/Barbero");
	sv_mq cliente ("/Cliente");
	sv_mq salida ("/Salida");
	string rta="s"; // defino string respuesta como s (letra es irrelevante mientras no sea f)
	msg.setHdr("Pel");
	
	while (rta!="f" ){
		cout<<"Figaro listo para afeitar."<<endl;;
		msgrcvd=cliente.receive(); // recibe info de la cola cliente
		cout<<"Recibido"<<*msgrcvd<<endl;
		delete (msgrcvd);
		msg.setSdu("Hola");
		figaro.send(msg);
		cout<<" Afeitando ... (f termina)"<<endl;
		cin>>rta; // nuevo valor para respuesta
		msg.setSdu("Chau");
		salida.send(msg);
	}
	figaro.del();
	cliente.del();
	salida.del();
}