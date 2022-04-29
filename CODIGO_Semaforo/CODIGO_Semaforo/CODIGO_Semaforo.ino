//Definimos las compuertas que vayamos a utilizar

//Semaforo A
#define S1_LED_Rojo 2 //El numero determina el PIN OUT
#define S1_LED_Amarillo 3 
#define S1_LED_Verde 4 

//Semaforo B
#define S2_LED_Rojo 5 
#define S2_LED_Amarillo 6 
#define S2_LED_Verde 7 

//Semaforo C
#define S3_LED_Rojo 8 
#define S3_LED_Amarillo 9 
#define S3_LED_Verde 10

//Semaforo D
#define S4_LED_Rojo 11
#define S4_LED_Amarillo 12
#define S4_LED_Verde 13

void setup(){
//Inicilizamos las compuertas

pinMode(S1_LED_Rojo, OUTPUT);
pinMode(S1_LED_Amarillo, OUTPUT);
pinMode(S1_LED_Verde, OUTPUT);

pinMode(S2_LED_Rojo, OUTPUT);
pinMode(S2_LED_Amarillo, OUTPUT);
pinMode(S2_LED_Verde, OUTPUT);

pinMode(S3_LED_Rojo, OUTPUT);
pinMode(S3_LED_Amarillo, OUTPUT);
pinMode(S3_LED_Verde, OUTPUT);

pinMode(S4_LED_Rojo, OUTPUT);
pinMode(S4_LED_Amarillo, OUTPUT);
pinMode(S4_LED_Verde, OUTPUT);
}

void loop() {
  
  
  digitalWrite(S1_LED_Verde, HIGH); digitalWrite(S2_LED_Rojo, HIGH); digitalWrite(S3_LED_Rojo, HIGH); digitalWrite(S4_LED_Rojo, HIGH);
  delay(2000);

  //off Verde
  digitalWrite(S1_LED_Verde, LOW);
  
  digitalWrite(S1_LED_Amarillo, HIGH); digitalWrite(S2_LED_Rojo, HIGH); digitalWrite(S3_LED_Rojo, HIGH); digitalWrite(S4_LED_Rojo, HIGH);
  delay(2000);

  //off Amarillo y Rojo
  digitalWrite(S1_LED_Amarillo, LOW);
  digitalWrite(S2_LED_Rojo, LOW);
  
  digitalWrite(S1_LED_Rojo, HIGH); digitalWrite(S2_LED_Verde, HIGH); digitalWrite(S3_LED_Rojo, HIGH); digitalWrite(S4_LED_Rojo, HIGH);
  delay(2000);

  //off Verde
  digitalWrite(S2_LED_Verde, LOW);
  
  digitalWrite(S1_LED_Rojo, HIGH); digitalWrite(S2_LED_Amarillo, HIGH); digitalWrite(S3_LED_Rojo, HIGH); digitalWrite(S4_LED_Rojo, HIGH);
  delay(2000);  

  //off Amarillo y Rojo
  digitalWrite(S2_LED_Amarillo, LOW);
  digitalWrite(S3_LED_Rojo, LOW);
    
  digitalWrite(S1_LED_Rojo, HIGH); digitalWrite(S2_LED_Rojo, HIGH); digitalWrite(S3_LED_Verde, HIGH); digitalWrite(S4_LED_Rojo, HIGH);
  delay(2000);  

  //off Verde
  digitalWrite(S3_LED_Verde, LOW);
  
  digitalWrite(S1_LED_Rojo, HIGH); digitalWrite(S2_LED_Rojo, HIGH); digitalWrite(S3_LED_Amarillo, HIGH); digitalWrite(S4_LED_Rojo, HIGH);
  delay(2000);  

  //off Amarillo y Rojo
  digitalWrite(S3_LED_Amarillo, LOW);
  digitalWrite(S4_LED_Rojo, LOW);
  
  digitalWrite(S1_LED_Rojo, HIGH); digitalWrite(S2_LED_Rojo, HIGH); digitalWrite(S3_LED_Rojo, HIGH); digitalWrite(S4_LED_Verde, HIGH);
  delay(2000);  

  //off Verde
  digitalWrite(S4_LED_Verde, LOW);
  
  digitalWrite(S1_LED_Rojo, HIGH); digitalWrite(S2_LED_Rojo, HIGH); digitalWrite(S3_LED_Rojo, HIGH); digitalWrite(S4_LED_Amarillo, HIGH);
  delay(2000);    

  //off Amarillo y Rojo
  digitalWrite(S4_LED_Amarillo, LOW);
  digitalWrite(S4_LED_Rojo, LOW);
  digitalWrite(S1_LED_Rojo, LOW);
}
