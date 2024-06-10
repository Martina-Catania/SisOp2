#include "includes.h"

int main(int argc, char *argv[]) {
	sv_mq repo("repo");
	repo.del();
	cout<<"Liberada la cola  "<<endl;
}
