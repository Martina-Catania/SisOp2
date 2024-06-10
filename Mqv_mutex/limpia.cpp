#include "../Mq-sv/sv_mq.h"

int main(){
	mpdu m1;
	string s;
	sv_mq mutex("/mutex");
	mutex.del();
}