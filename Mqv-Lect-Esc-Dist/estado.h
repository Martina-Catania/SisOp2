#ifndef estado_h
#define estado_h
class estado{ 
	int supervisor_espera, supervisor_activos;
  	int modificador_espera, modificador_activos;
public:
    estado():supervisor_espera(0), supervisor_activos(0),modificador_espera(0), modificador_activos(0) {};
				
	
    string serialize(){
	   stringstream sale;
	   sale<< to_string(supervisor_espera)<<" "<<
			  to_string(supervisor_activos)<<" "<<to_string(modificador_espera)<<" "<<
			  to_string(modificador_activos);
	    return sale.str();
	}
	void deserialize(string s){
		stringstream entra; 
		entra<<s;
		entra>>supervisor_espera>>supervisor_activos>>modificador_espera>>modificador_activos;
    }

    void llegaSupervisor(){supervisor_espera++;}
	void entraSupervisor(){supervisor_espera--; supervisor_activos++;}
    void saleSupervisor(){supervisor_activos--;}
	void llegaModificador(){modificador_espera++;}
	void entraModificador(){modificador_espera--; modificador_activos++;}
	void saleModificador(){modificador_activos--;}
   
	bool puedeEntrarSupervisor(){return modificador_activos <1;}
	bool puedeEntrarModificador(){return (supervisor_activos==0) and (modificador_activos==0);}
		
	friend ostream&operator<<(ostream& os, estado e){
		return os<<"(lect_espera="<<e.supervisor_espera<<
		", lect_activos="<<e.supervisor_activos<<
		"; esc_espera="<<e.modificador_espera<<", esc_activos="<<e.modificador_activos<<
		")"<<endl;
	}
};
#endif