#include "../Mq-sv/sv_mq.h"

int main(){
  mpdu m1;
  string s;
  sv_mq mutexA("/mutexA");
  cout<<"Creada cola "<<mutexA<<endl;
  sv_mq mutexB("/mutexB");
  cout<<"Creada cola "<<mutexB<<endl;
}