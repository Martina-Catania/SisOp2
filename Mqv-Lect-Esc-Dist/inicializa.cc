#include "includes.h"

int main(int argc, char *argv[]) {
	sv_mq repo("repo");
	mpdu msg;
	estado e;
	msg.setHdr("");
	msg.setSdu(e.serialize());
	repo.send(msg);
	cout<<"Inicializa, enviado el mensaje "<<e<<endl;
}

