#include "includes.h"

int main(int argc, char *argv[]) {
	if (argc < 2) {
		cerr << "Uso: " << argv[0] << " numero del filosofo" << endl;
		exit(2);
	}
	int yo = atoi(argv[1]);
	int yoid = getpid();
	cout << "soy el filosofo " << yo << " pid=" << yoid << endl;
  mpdu m1, *p_pedido;
  string pedido, s;
  m1.setSdu(to_string(yo));
  sv_mq f_yo(string("Filo") + to_string(yo));
  cout << "Filosofo " << yo <<" cola "<<f_yo<<endl;
  sv_mq control("control");

  cout << "Filosofo " << yo << " pensando .... (un string para comer)" << endl;
  string rta;
  cin >> rta;

  m1.setHdr(COMER);
  cout << "Mensaje a control " << m1 << endl;
  control.send(m1);

  p_pedido = f_yo.receive();

  cout << "Filosofo " << yo << " comiendo .... (un string para pensar)" << endl;
  cin >> rta;

  m1.setHdr(PENSAR);
  m1.setSdu(to_string(yo));
  cout << "mensaje " << m1 << endl;
  control.send(m1);
}
