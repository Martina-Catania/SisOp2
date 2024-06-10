#include <iostream>
#include <string>
#include <cstdlib>
#include "../Mq-sv/mpdu.h"
#include "../Mq-sv/sv_mq.h"
using namespace std;

int main(){
  cout<<"Limpieza general "<<endl;
  sv_mq uno("puerta");
  uno.del();
  cout<<"puerta ..."<<endl;
  sv_mq rdr("readers");
  rdr.del();
  cout<<"readers..."<<endl;
  sv_mq wtr("writers");
  wtr.del();
  cout<<"writers..."<<endl;
}