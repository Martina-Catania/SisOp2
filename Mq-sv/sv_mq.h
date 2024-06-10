#include "includes.h"
#include "mpdu.h"
#ifndef SV_MQ_H
#define SV_MQ_H
#define K 1024
#define	MAXMSG	(6*K + sizeof(long))
#ifndef __USE_GNU
struct msgbuf {
  long mtype;       /* message type, must be > 0 */
  char mtext[1];    /* message data */
};
#endif

class sv_mq{
  string clave;
  key_t ktclave;
  int mq;			//mqd message queue descriptor
  public:
    sv_mq(string cla="/default");
    void del();
    string getnom() {return clave;}
    int getmq()  {return mq;}
    void send(mpdu msg);
    mpdu* receive();
   friend ostream& operator <<(ostream& os, sv_mq mq);
 };

sv_mq::sv_mq(string cla){
  char * nom;
  int  oflag;
  oflag = 0644 | IPC_CREAT;
  if (cla[0] != '/') cla='/'+cla;
  clave="/tmp"+cla;
  string cmd="touch "+clave;
  system(cmd.c_str());         // en System V la clave DEBE ser un archivo
  ktclave=ftok(clave.c_str(),1);
  mq=msgget(ktclave, oflag);
  if (mq==-1){
		cerr<<"no se puede abrir/crear la cola"<<endl;
		cerr<<"Cola <"<<clave<<","<<mq<<"> "<<endl;
		exit(1);}
}

void sv_mq::del(){
  int retcode;
  retcode=msgctl(mq, IPC_RMID, NULL);
  if (retcode==-1){
 		cerr<<"No se puede cerrar la cola"<<endl;
		cerr<<"Cola<"<<clave<<","<<mq<<"> "<<endl; 
 		exit(1);}
    string cmd="rm "+clave;
    system (cmd.c_str());
}

void sv_mq::send(mpdu msg){
  struct msgbuf *ptr;
  int type = 1;
  size_t len=msg.flatten().size();
 // char * s_msg=reinterpret_cast<char *>(&msg);
  ptr=static_cast <struct msgbuf*> (calloc(sizeof(long) + len, sizeof(char)));
  ptr->mtype = type;
  // cambio por memcpy
  memcpy(ptr->mtext,msg.flatten().c_str(),len);
  int retcode;
  //cout<<"Enviando ("<<ptr->mtype<<","<<ptr->mtext<<"len="<<len<<")"<<endl;
  retcode=msgsnd(mq, ptr, len, 0);
  if (retcode==-1){
 		cerr<<"No se pudo enviar el mensaje"<<endl;
		cerr<<"Cola<"<<clave<<","<<mq<<"> "<<endl; 
 		exit(1);}
  //devolver memoria
  free((void*) ptr);
}

mpdu* sv_mq::receive(){
  struct msgbuf * buff;
  int long_buf=MAXMSG;
  buff = static_cast<struct msgbuf*>(malloc(MAXMSG));
  int msize=0;
  int type=1;
  msize=msgrcv(mq, buff, MAXMSG, type, 0);
  if (msize==-1){
 		cerr<<"No se pudo recibir un mensaje."<<endl;
		cerr<<"Cola<"<<clave<<","<<mq<<"> "<<endl; 
 		exit(1);}
 //  cout<<"Recibido <"<<buff->mtext<<">, l="<<msize<<endl;
   buff->mtext[msize]='\0'; //poner fin de c_string
 //  cout<<"Truncado <"<<buff->mtext<<">, l="<<msize<<endl;

   mpdu *res=new mpdu();
   res->unFlatten(buff->mtext);
   free((void*) buff);
   return res;
}

ostream& operator<<(ostream& os, sv_mq msgq){
  msqid_ds mqid;
  msgctl(msgq.mq,IPC_STAT,&mqid);
  return os<<"(cola "<<msgq.mq<<"<"<<msgq.clave<<"> "<<
       mqid.msg_qnum<<" mensajes )"<<"[send "<<mqid.msg_lspid<<
       " receive "<<mqid.msg_lrpid<<"]";
}
#endif
