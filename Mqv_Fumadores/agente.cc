#include "includes.h"

int main(int argc, char * argv[]){
  if (argc < 4) { // check argumentos
      cerr<<"Uso: "<<argv[0]<<" papel tabaco fosforos"<<endl; 
      exit(2);
  }
  string p=argv[1], t=argv[2], f=argv[3];  // guardo argumentos 
  string entrada;
  int ip=atoi(p.c_str()); // paso cantidades de strings a ints para almacenar
  int it=atoi(t.c_str());  
  int ifo=atoi(f.c_str()); 
  cout<<"Agente pone "<<ip<<" papel, "<<it<<" tabaco y "
      <<ifo<<" fosforos."<<endl;
      
  sv_mq papel("/Papel"); // message queue de papel
  sv_mq tabaco("/Tabaco"); // message queue de tabaco
  sv_mq fosforos("/Fosforos"); // message queue de fósforos
  mpdu m; 
  for (int i=0; i<ip; i++) papel.send(m); // agente pone papel en la queue
  for (int i=0; i<it; i++) tabaco.send(m); // agente pone tabaco en la queue
  for (int i=0; i<ifo; i++) fosforos.send(m); // agente pone fosforos en la queue

}