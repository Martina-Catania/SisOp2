#include "../Mq-sv/sv_mq.h"

using namespace std;

int main(){
  sv_mq control("control");
  control.del();
}
