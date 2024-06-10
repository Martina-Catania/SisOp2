#include "includes.h"
/*
supervisor = lector en patrón lector escritor distribuido
*/
int main(int argc, char *argv[]) {
	string nom="Supervisor-"+to_string(getpid());
	sv_mq repo("repo");
	mpdu *recibo, envio;
	estado est;
	string est_ser,st;
	bool primera=true;
	cout<<nom<<" pidiendo entrada "<<endl;
	while (true){
		recibo=repo.receive();
		est.deserialize(recibo->getSdu());
		cout<<nom<<" recibe al querer entrar "<<est<<endl;
		if (primera){
			est.llegaSupervisor();
			primera=false;
		}
		if (est.puedeEntrarSupervisor()) break;
		envio.setHdr(recibo->getHdr());
		envio.setSdu(est.serialize());
		repo.send(envio);
		delete (recibo);
		sleep(4);
		}
	est.entraSupervisor();
	envio.setHdr(recibo->getHdr());
	envio.setSdu(est.serialize());
	repo.send(envio);

	cout<<nom<<" Supervisando "<<endl;
	cin>>st;
	cout<<nom<<" Sale "<<endl;
	delete (recibo);
	recibo=repo.receive();
	est.deserialize(recibo->getSdu());
	cout<<nom<<" recibe al irse "<<est<<endl;
	est.saleSupervisor();
	envio.setHdr(recibo->getHdr());
	envio.setSdu(est.serialize());
	repo.send(envio);
	cout<<nom<<" Termina "<<endl;

}