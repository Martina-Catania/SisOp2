#include "includes.h"

using namespace std;
int main(int argc, char *argv[]) {
	sv_mq control("control"); 
	mpdu m;
	sv_mq* mq_filo[5];
	m.setHdr(FIN);
	control.send(m);
	for (int i=0;i<5;i++){
		mq_filo[i]=new sv_mq(string("Filo")+to_string(i));
		cout<<"Desturida la cola Filo["<<i<<"]="<<* mq_filo[i]<<endl;
		mq_filo[i]->del();
	}
}