#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>
#include "../Mq-sv/mpdu.h"
#include "../Mq-sv/sv_mq.h"
#include "Mensajes.h"
using namespace std;

int main(int argc, char * argv[]){
	sv_mq portero("puerta");
	cout<<portero<<endl;
	sv_mq cola_rdr("readers");
	cout<<cola_rdr<<endl;
	sv_mq cola_wtr("writers");
	cout<<cola_wtr<<endl;
}