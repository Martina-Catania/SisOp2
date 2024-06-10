#include <iostream>
#include <unistd.h>
#include "../Mq-sv/sv_mq.h"
#include "../Mq-sv/mpdu.h"

using namespace std;
int main(int argc, char *argv[]) {
	string yo;
	yo=to_string(getpid());
	
	mpdu msg, *msgrcvd;
	sv_mq figaro("/Barbero");
	sv_mq cliente ("/Cliente");
	sv_mq salida ("/Salida");
	string rta;
	cout<<"Cliente "<<yo<<" quiere afeitarse"<<endl;
	msg.setHdr("Cli");msg.setSdu(yo);
	cliente.send(msg);
	cout<<"Cliente "<<yo<<" esperando barbero."<<endl;
	msgrcvd=figaro.receive(); // recibe info de barbero
	cout<<"Recibido"<<*msgrcvd<<endl;
	cout<<" Afeitandose. "<<endl;
	delete(msgrcvd);
	msgrcvd=salida.receive();
	cout<<"Recibido"<<*msgrcvd<<endl;
	cout<<"Adios"<<endl;
}	
