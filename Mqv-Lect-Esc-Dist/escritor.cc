#include "includes.h"

int main(int argc, char *argv[]) {
	string nom="Escritor-"+to_string(getpid());
	sv_mq repo("repo");
	mpdu *recibo, envio;
	estado est;
	string est_ser,st;
	bool primera=true;
	cout<<nom<<" pidiendo entrada "<<endl;
	long cont=0;
	while (true){
		recibo=repo.receive();
		est.deserialize(recibo->getSdu());
		cout<<nom<<" recibe al querer entrar "<<est<<endl;
		if (primera){
			est.llegaModificador();
			primera=false;
		}
		if (est.puedeEntrarModificador()) break;
		envio.setHdr(recibo->getHdr());
		envio.setSdu(est.serialize());
		repo.send(envio);
		delete (recibo);
		//cout<<nom<<" espera.("<<cont<<")"<<endl;
		sleep(4);
		//cout<<nom<<" sigue. ("<<cont++<<")"<<endl;

		}
	est.entraModificador();
	envio.setHdr(recibo->getHdr());
	envio.setSdu(est.serialize());
	repo.send(envio);

	cout<<nom<<" Escribiendo ..."<<endl;
	cin>>st;
	cout<<nom<<" Sale "<<endl;
	delete (recibo);
	recibo=repo.receive();
	est.deserialize(recibo->getSdu());
	cout<<nom<<" recibe al irse "<<est<<endl;
	est.saleModificador();
	envio.setHdr(recibo->getHdr());
	envio.setSdu(est.serialize());
	repo.send(envio);
	cout<<nom<<" Termina "<<endl;

}