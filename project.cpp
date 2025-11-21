	#include<iostream>
	#include<string>
	#include<cctype>
	#include<chrono>
	#include<fstream>
	using namespace std;
	
	int main(){
		int op,puntos;
		char respuesta;
		string nombre;
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
			
		    cout<<endl<<"===== JUEGO DE PREGUNTAS MATEMATICAS ====="<<endl;
	        cout<<"1. Jugar"<<endl;
	        cout<<"2. Instrucciones"<<endl;
	        cout<<"3. Salir"<<endl;
	        cout<<"4. Ver historial de jugadores"<<endl;
	        cout<<"Seleccione una opcion ";
	        cin>>op;
	        switch(op){
	        	case 1:{
					cout <<endl<<"Escribe tu nombre: ";
	                cin >> nombre;
			
	        		puntos=0;
	                auto inicio = std::chrono::high_resolution_clock::now();
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
	                       cout<<"Correcto!"<<endl;
	                       puntos++;
	                    } else {
	                        cout<<"Incorrecto. La respuesta era "<< correctas[i]<<"."<<endl;
	                    }
			}
		    auto fin = std::chrono::high_resolution_clock::now();
	        auto duracion = std::chrono::duration_cast<std::chrono::seconds>(fin - inicio).count();
			cout<<endl<<"===== RESULTADOS ====="<<endl;
			cout<<"Jugador: "<<nombre<<endl;
			cout<<"Respuestas correctas: "<< puntos << " de 15"<<endl;
			cout << "Tiempo total: " << duracion << " segundos"<<endl;
			ofstream archivo("registro_jugadores.txt", ios::app);
	
	            if(archivo.is_open()){
	                archivo << "Jugador: " << nombre 
	                        << " | Puntaje: " << puntos 
	                        << "/15 | Tiempo: " << duracion << "s"<<endl;
	                archivo.close();
	                cout << "\nProgreso guardado correctamente en 'registro_jugadores.txt'."<<endl;
	            } else {
	                cout << "\nERROR: No se pudo guardar el archivo."<<endl;
	            }
	                break;
	            }
	                case 2:{
	                	    cout<<"\n===== INSTRUCCIONES ====="<<endl;
	        cout<<"1. El juego consiste en 15 preguntas de matematicas."<<endl;
	        cout<<"2. Cada pregunta tiene tres opciones: A, B y C."<<endl;
	        cout<<"3. Debes escribir la letra de la opcion que consideres correcta."<<endl;
	        cout<<"4. Cada respuesta correcta suma 1 punto."<<endl;
	        cout<<"5. Al final se mostrara tu puntaje total."<<endl;
	        cout<<"6. Habra un cronometro que medira el tiempo que tardas en completar el juego."<<endl;
	        cout<<"7. Intenta responder lo mas rapido y correcto posible!"<<endl;
	        cout<<"Presiona 1 para volver al menu principal: ";
	    cin >> op;
	
	    if(op == 1){
	        main(); 
	    } else {
	        cout << "Opcion no valida. Regresando al menu principal..."<<endl;
	        main();
	    }
	        
	        break;
	    }
	                case 3:
	                cout<<"Saliendo..."<<endl;
	                return 0;
	                break;
	    case 4: {
	    ifstream archivo("registro_jugadores.txt");
	
	    cout <<endl<<"===== HISTORIAL DE JUGADORES ====="<<endl;
	
	    if (!archivo.is_open()) {
	        cout << "No hay registros guardados."<<endl;
	    } else {
	        string linea;
	        while (getline(archivo, linea)) {
	            cout << linea << endl;
	        }
	        archivo.close();
	    }
	
	    cout <<endl<<"Presiona ENTER para volver al menu...";
	    cin.ignore();
	    cin.get();
	    main();
	    break;
	}            
	
	            default:
	                cout << "Opcion no valida."<<endl;
	}
	     return 0;
	}