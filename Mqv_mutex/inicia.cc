#include "../Mq-sv/sv_mq.h"
// inicio mutex
int main(){
  mpdu m1;
  string s;
  sv_mq mutex("/mutex"); // declaro message queue para mutex
  mutex.send(m1); // envío mensaje a mutex
}