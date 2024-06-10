#include "includes.h"

int main(int argc, char * argv[]){
  
  
  sv_mq papel("/Papel");
  sv_mq tabaco("/Tabaco");
  sv_mq fosforos("/Fosforos");
  
  cout<<"Eliminando "<<papel<<endl;
  papel.del();
  cout<<"Eliminando "<<tabaco<<endl;
  tabaco.del();
  cout<<"Eliminando "<<fosforos<<endl;
  fosforos.del();



}