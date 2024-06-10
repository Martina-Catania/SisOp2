#include "../Mq-sv/sv_mq.h"

int main(){
	mpdu m1;
	string s;
	sv_mq mutexA("/mutexA");
	sv_mq mutexB("/mutexB");
	cout<<"Borrando "<<mutexA<<endl;
	mutexA.del();
	cout<<"Borrando "<<mutexB<<endl;
	mutexB.del();
}