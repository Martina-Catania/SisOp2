#include <iostream>
#include <unistd.h>
#include "../Mq-sv/sv_mq.h"
#include "../Mq-sv/mpdu.h"
/* libera */

using namespace std;
int main(int argc, char *argv[]) {
	sv_mq figaro("/Barbero");
	sv_mq cliente ("/Cliente");
	sv_mq salida ("/Salida");
	cout<<"Borrando"<<endl<<figaro<<endl<<cliente<<endl<<salida<<endl;
	figaro.del();
	cliente.del();
	salida.del();
}
	
