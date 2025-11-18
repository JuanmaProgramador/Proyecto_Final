#include<iostream>
#include<string>
#include<cctype>
using namespace std;

int main(){
	int op,puntos;
	char respuesta;
	string pregunta[15]={
		"Cual es el numero mayor?",
		"Cual es el numero menor?",
		"Cuanto es 545 - 30?",
		"Cuanto es 453 + 20?",
		"Tiene un 4 que vale 40",
		"300 + 200 + 4",
		"3 veces el numero 100",
		"10 menos que 530",
		"10 mas que 318",
		"100 mas que 400",
		"10 veces el numero 1",
		"20 veces el numero 0",
		"tiene un 5 que vale 5",
		"400 + 100 + 20 + 2",
		"Es el numero que esta entre 399 y 401"
		}; 
	 string opciones[15][3] = {
        {"A) 589", "B) 509", "C) 579"},
        {"A) 556", "B) 596", "C) 506"},
        {"A) 525", "B) 505", "C) 515"},
        {"A) 473", "B) 463", "C) 364"},
        {"A) 114", "B) 432", "C) 540"},
        {"A) 604", "B) 504", "C) 304"},
        {"A) 300", "B) 30", "C) 400"},
        {"A) 540", "B) 510", "C) 520"},
        {"A) 328", "B) 308", "C) 338"},
        {"A) 200", "B) 500", "C) 300"},
        {"A) 11", "B) 9", "C) 10"},
        {"A) 0", "B) 20", "C) 200"},
        {"A) 552", "B) 500", "C) 225"},
        {"A) 532", "B) 522", "C) 540"},
        {"A) 400", "B) 402", "C) 389"},
    };
    char correctas[15]={'A', 'C', 'C', 'A', 'C','B', 'A', 'C', 'A', 'B','C', 'A', 'C', 'B', 'A'};
		
	    cout<<"\n===== JUEGO DE PREGUNTAS MATEMATICAS =====\n";
        cout<<"1. Jugar\n";
        cout<<"2. Instrucciones\n";
        cout<<"3. Salir\n";
        cout<<"Seleccione una opcion ";
        cin>>op;
        switch(op){
        	case 1:
        		puntos=0;
        	    for(int i=0;i<15;i++){
		cout<<"Pregunta Numero "<<i+1<<endl;
		cout<<pregunta[i]<<endl;
		        for(int j=0;j<3;j++) {
                        cout<<opciones[i][j]<<endl;
                    }
                    cout<<"Elije tu respuesta: ";
                    cin>>respuesta;
                    respuesta=(char)toupper((unsigned char)respuesta);
                    
                    if(respuesta==correctas[i]) {
                       cout<<"Correcto!\n";
                       puntos++;
                    } else {
                        cout<<"Incorrecto. La respuesta era "<< correctas[i]<<".\n";
                    }
		}
		cout<<"\n===== RESULTADOS =====\n";
		cout<<"Respuestas correctas: "<< puntos << " de 15\n";
                break;
                case 2:
                cout<<"Saliendo...\n";
                return 0;
                break;

            default:
                cout << "Opcion no valida.\n";
}
     return 0;
}






