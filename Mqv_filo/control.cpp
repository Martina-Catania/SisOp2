#include "includes.h"
/* coordinador*/

// retorna índice del filósofo a la izquierda
int izq(int x){
	int r=x-1;
	if (r==-1) r=4;
	return r;
}
// retorna índice del filosofo a la derecha
int der(int x){
	int r=x+1;
	if (r==5) r=0;
	return r;
}

enum est {pen,ham,com}; // estados

using namespace std;
int main(int argc, char *argv[]) {
	est estado[5] ={pen,pen,pen,pen,pen}; // estado inicial de los filósofos
	mpdu m1, *p_pedido;
	string pedido,s;
	int filo;
	m1.setSdu("siga"); // mpdu con datos = siga
	sv_mq* mq_filo[5]; // defino array de punteros a message queue de filosofos
	for (int i=0;i<5;i++){ // creo 5 filósofos
		mq_filo[i]=new sv_mq(string("Filo")+to_string(i));
		cout<<"Tomada la cola Filo["<<i<<"]="<<* mq_filo[i]<<endl;
	}
	sv_mq control("control");  // message queue de control
	cout<<"Cola de control"<<control<<endl;
	p_pedido=control.receive(); // leo el primer mensaje de la cola de control
	pedido=p_pedido->getHdr();
	cout<<(*p_pedido)<<endl;
	while (pedido!=FIN){ 
		filo=stoi(p_pedido->getSdu()); //get contenido del mensaje
		if (pedido==COMER){ // manejo comer
			estado[filo]=ham;
			if ((estado[der(filo)]!=com) and
				(estado[izq(filo)]!=com)){
				cout<<"Filosofo "<<filo<<" puede comer"<<endl;
				estado[filo]=com;
				mq_filo[filo]->send (m1);
			} 		
		}
		if (pedido==PENSAR){ // manejo pensar
			estado[filo]=pen;
			if ((estado[der(filo)]==ham) and
				(estado[der(der(filo))]!=com)){
					cout<<"Filosofo "<<der(filo)<<" puede comer"<<endl;
					estado[der(filo)]=com;
					mq_filo[der(filo)]->send (m1);
				}
			if ((estado[izq(filo)]==ham) and
				(estado[izq(izq(filo))])!=com){
					cout<<"Filosofo "<<izq(filo)<<" puede comer"<<endl;
					estado[izq(filo)]=com;
					mq_filo[izq(filo)]->send (m1);
			}	
		}
		delete(p_pedido);
		p_pedido=control.receive();
		pedido=p_pedido->getHdr();
		cout<<(*p_pedido)<<endl;
	}
	control.del();
}	