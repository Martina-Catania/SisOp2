#include <iostream>
#include <string>
#include <cstdlib>
#include "../Mq-sv/mpdu.h"
#include "../Mq-sv/sv_mq.h"
#include "Mensajes.h"
using namespace std;

int main(int argc, char * argv[]){
  string el_pedido, quien_pide;
  int lect_espera=0, lect_activos=0;
  int esc_espera=0, esc_activos=0;
  sv_mq puerta("puerta");
  sv_mq cola_rdr("readers");
  sv_mq cola_wtr("writers");
  mpdu* pedido;
  cout<<"lect_espera="<<lect_espera<<"; lect_activos="<<lect_activos<<endl;
  cout<<"esc_espera="<<esc_espera<< " ;  esc_activos="<<esc_activos<<endl;
  cout<<"Esperando ..."<<endl;
  //cout<<puerta<<endl;
  pedido=puerta.receive();
  cout<<" Recibido "<<(*pedido)<<endl;
  el_pedido=pedido->getHdr();
  while (el_pedido!=Termina){
    // aumenta cantidad de gente en cola según quién envía el request de entrada
      quien_pide=pedido->getSdu();  delete pedido;
      if (el_pedido == Lector_Quiere_Entrar){	lect_espera++; 
                cout<<"Lector quiere entrar "<<quien_pide<<endl;}
      if (el_pedido==Lector_Sale){	lect_activos--;      
                cout<<"Lector sale "<<quien_pide<<endl;}
      if (el_pedido==Escritor_Quiere_Entrar){	esc_espera++;    
                cout<<"Escritor quiere entrar"<<quien_pide<<endl;}
      if (el_pedido==Escritor_Sale){	esc_activos--;   
                cout<<"Escritor sale "<<quien_pide<<endl;}
      cout<<"lect_espera="<<lect_espera<<"; lect_activos="<<lect_activos<<endl;
      cout<<"esc_espera="<<esc_espera<< " ;  esc_activos="<<esc_activos<<endl;
      //ahora opera segun el estado 
      if ((lect_espera !=0) and (esc_activos==0)) {
	  		while (lect_espera !=0){
	      	lect_espera--; 		lect_activos++;		cout<<"Entra un lector ";
					cola_rdr.send(mpdu(Lector_Entra,""));
					cout<<"lect_espera="<<lect_espera<<"; lect_activos="<<lect_activos<<endl;
	  		}
			}
      if ((lect_activos==0) and (esc_espera!=0) and (esc_activos==0)) {
	  		        esc_espera--;  esc_activos++;
	  	          	cout<<"Entra un escritor"<<endl;
	  		        cola_wtr.send(mpdu(Escritor_Entra,""));
			}
      cout<<"Esperando ..."<<endl;
      cout<<"lect_espera="<<lect_espera<<"; lect_activos="<<lect_activos<<endl;
      cout<<"esc_espera="<<esc_espera<< " ;  esc_activos="<<esc_activos<<endl;
      pedido=puerta.receive();
      cout<<" Recibido "<<(*pedido)<<endl;
      el_pedido=pedido->getHdr();
  }
  puerta.del();
  cola_rdr.del();
  cola_wtr.del();
  cout<<"Termina"<<endl;
}