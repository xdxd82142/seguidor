int IN1 = 2;
int IN2 = 3;
int INA = 5;
int IN3 = 7;
int IN4 = 8;
int INB = 9;

// Infrarojo
int infrarojo_izquierdo = 10;
int infrarojo_derecho = 11;
int infrarojo_medio = 6;

// Variables de entorno
int velocidad = 150;
int tiempo_ejecucion = 150;
int negro = 0;
int blanco = 1;

// Variables para los sensores
int valor_inicial_infrarojo_izq = 0;
int valor_inicial_infrarojo_der = 0;
int valor_inicial_infrarojo_med = 0;

void setup(){
  Serial.begin(9600);

  pinMode(infrarojo_izquierdo, INPUT);
  pinMode(infrarojo_derecho, INPUT);
  pinMode(infrarojo_medio, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(INA, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(INB, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

void loop(){

  valor_inicial_infrarojo_izq = digitalRead(infrarojo_izquierdo);
  valor_inicial_infrarojo_der = digitalRead(infrarojo_derecho);
  valor_inicial_infrarojo_med = digitalRead(infrarojo_medio);

  Serial.println("Variables:::::: ");
  Serial.println("El valor izquierdo "); Serial.println(valor_inicial_infrarojo_izq);
  Serial.println("El valor derecho "); Serial.println(valor_inicial_infrarojo_der);
  Serial.println("El valor medio "); Serial.println(valor_inicial_infrarojo_med);
 
  if (valor_inicial_infrarojo_izq == blanco && valor_inicial_infrarojo_med == negro && valor_inicial_infrarojo_der == blanco){
    movimiento_delante();
    Serial.println("primer if");

  }

  else if (valor_inicial_infrarojo_izq == negro && valor_inicial_infrarojo_med == negro && valor_inicial_infrarojo_der == negro){
    movimiento_delante();
    Serial.println("segundo if delante");
  }
  
  // Girar izquierda
  else if (valor_inicial_infrarojo_izq == blanco && valor_inicial_infrarojo_med == blanco && valor_inicial_infrarojo_der == negro){
    movimiento_izquierda();
    Serial.println("primer elif izquierda");
 
  }

  else if (valor_inicial_infrarojo_izq == blanco && valor_inicial_infrarojo_med == negro && valor_inicial_infrarojo_der == negro){
    movimiento_izquierda();
    Serial.println("segundo elif izquierda");
  }

  // Girar derecha
  else if (valor_inicial_infrarojo_izq == negro && valor_inicial_infrarojo_med == blanco && valor_inicial_infrarojo_der == blanco){
    movimiento_derecha();
    Serial.println("primer elif derecha");
  }

  else if (valor_inicial_infrarojo_izq == negro && valor_inicial_infrarojo_med == negro && valor_inicial_infrarojo_der == blanco){
    movimiento_derecha();
    Serial.println("primer elif derecha");
  }

  else if (valor_inicial_infrarojo_izq == blanco && valor_inicial_infrarojo_med == blanco && valor_inicial_infrarojo_der == blanco){
    movimiento_derecha();
    Serial.println("elif para el caso en que este fuera de la linea ");
  }

  else{
    movimiento_delante();
    Serial.println("Else ");
  }
  

  detenerse();
  

}

void movimiento_delante(){
  
  digitalWrite(INB, velocidad);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);


  digitalWrite(INA, velocidad);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  delay(tiempo_ejecucion);

}

void movimiento_derecha(){
  digitalWrite(INB, velocidad);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(tiempo_ejecucion);

}

void movimiento_izquierda(){

  digitalWrite(INA, velocidad);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  delay(tiempo_ejecucion);

}

void detenerse(){
  digitalWrite(INA, LOW);
  digitalWrite(INB, LOW);
  delay(100);
}




