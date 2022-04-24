void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly: 
  
}


void Acelerar_Mientras_Se_Presiona (int nombre_Push){
  // Solo se acelera al pulsar el acelerador
  int estado_Push = digitalRead(nombre_Push);
  
  if(!estado_Push){
    /*
     * La unica funcion de este if que contiene un while, es contar con una variable
     * que tenga el tiempo inicial (variable Tiempo_Inicial_J1) y luego compararla con la 
     * variable de tiempo final (Tiempo_Final_J1). Con una resta de estos tiempos, se 
     * obtiene el tiempo de duracion. Esta resta se actualiza constantemente dentro del 
     * while de bajo es el que va actualizando el valor de la duracion del boton apachado.
    */
    estado_Push = digitalRead(nombre_Push); // Leer estado boton acelerador
    unsigned long Tiempo_Inicial = millis(); //Pasar el valor del millis al tiempo inicial
    unsigned long Tiempo_Actual = 0;
    unsigned long Tiempo_Duracion  = 0;
    
    // Actualiza la resta de tiempos constantemente
    while(!estado_Push){
      estado_Push = digitalRead(nombre_Push); // Leer estado boton acelerador
      // Actualiza el tiempo presente para luego comparar con el tiempo inicial al pulsar
      Tiempo_Actual = millis(); 
      Tiempo_Duracion = Tiempo_Actual - Tiempo_Inicial; // Determina el tiempo 

      // Tiempo va creciendo
      
                  
    }
  }
}
void Angulo(int Push_Izquierdo, int Push_Derecho, int *Posicion_Angular_Actual, int *Angulo){
  if(!digitalRead(Push_Izquierdo)){
    *Posicion_Angular_Actual = *Posicion_Angular_Actual + 1;
    
    if(*Posicion_Angular_Actual  > 31){
      *Posicion_Angular_Actual = 0;
    }
    
    *Posicion_Angular_Actual = PosicionMap(*Posicion_Angular_Actual);
  }
  else if(!digitalRead(Push_Derecho)){
    *Posicion_Angular_Actual = *Posicion_Angular_Actual - 1;
    if(*Posicion_Angular_Actual  < -31){
      *Posicion_Angular_Actual = 0;
    }
    *Posicion_Angular_Actual = PosicionMap(*Posicion_Angular_Actual);
  }   

  if( *Posicion_Angular_Actual == 0){
    *Angulo = 0; 
  }
  else if(*Posicion_Angular_Actual > 0 && *Posicion_Angular_Actual <= 26){
    *Angulo = (*Posicion_Angular_Actual)*10 + 10;
  }
  else if(*Posicion_Angular_Actual > 26 && *Posicion_Angular_Actual <= 31){
    *Angulo = (*Posicion_Angular_Actual)*18 + 10;
  }

  
}
int PosicionMap(int Posicion){
  if(Posicion >= 0){
    return Posicion;
  }else if(Posicion >= -31){
    return Posicion + 32;  
  }
}
void Posicion(unsigned long Tiempo, int Velocidad_Inicial, int Posicion_Inicial, int Aceleracion, int Angulo, int *Pos_X, int *Pos_Y ){
    
}
