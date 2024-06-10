#ifndef estado_h
#define estado_h
class estado{ 
	int lect_espera, lect_activos;
  	int esc_espera, esc_activos;
public:
    estado():lect_espera(0), lect_activos(0),esc_espera(0), esc_activos(0) {};
				
	
    string serialize(){
	   stringstream sale;
	   sale<< to_string(lect_espera)<<" "<<
			  to_string(lect_activos)<<" "<<to_string(esc_espera)<<" "<<
			  to_string(esc_activos);
	    return sale.str();
	}
	void deserialize(string s){
		stringstream entra; 
		entra<<s;
		entra>>lect_espera>>lect_activos>>esc_espera>>esc_activos;
    }

    void llegaLector(){lect_espera++;}
	void entraLector(){lect_espera--; lect_activos++;}
    void saleLector(){lect_activos--;}
	void llegaEscritor(){esc_espera++;}
	void entraEscritor(){esc_espera--; esc_activos++;}
	void saleEscritor(){esc_activos--;}
   
	bool puedeEntrarLector(){return esc_activos <1;}
	bool puedeEntrarEscritor(){return (lect_activos==0) and (esc_activos==0);}
		
	friend ostream&operator<<(ostream& os, estado e){
		return os<<"(lect_espera="<<e.lect_espera<<
		", lect_activos="<<e.lect_activos<<
		"; esc_espera="<<e.esc_espera<<", esc_activos="<<e.esc_activos<<
		")"<<endl;
	}
};
#endif