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

int G1_Tiempo = 4;  //Establecemos los tiempos de apertura de cada semaforo
int G2_Tiempo = 6;  
int G3_Tiempo = 8;  
int G4_Tiempo = 10; 

int Y_Tiempo = 1; //Establecemos un tiempo de apertura general

int Modo = 0;
int Segundos = 0;
word MiliSegundos = 0;

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

noInterrupts();         // Desactiva todas las interrupciones
TCCR1A = 0;             // Establece el registro de TCCR1A en 0  //Establece la interrupcion a 1kHz, 1 ms
TCCR1B = 0;             // Hacemos lo mismo con TCCR1B
TCNT1  = 0;             // Establece el conteo de incrementos de 1khz 
OCR1A = 1999;           // = (16*10^6) / (1000*8) - 1

/*
NOTA IMPORTANTE: |= Obtiene el OR inclusivo bit a bit del primer y el segundo operandos;
almacena el resultado en el objeto especificado por el primer operando.
*/
TCCR1B |= (1 << WGM12); // Establece el bit para la presscala
TCCR1B |= (1 << CS11);  // Habilita la interrupcion de comparacion del temporizador
TIMSK1 |= (1 << OCIE1A);
interrupts();           // Habilita la interrupcion

Segundos = Y_Tiempo;
Amarillo(Modo);
delay(100); // Esperamos...
}

void loop(){ 

if(Modo==0 && Segundos==0){Segundos=G1_Tiempo; Modo=1; Abrir(Modo);}
if(Modo==1 && Segundos==0){Segundos=Y_Tiempo;  Modo=2; Amarillo(Modo);}

if(Modo==2 && Segundos==0){Segundos=G2_Tiempo; Modo=3; Abrir(Modo);}
if(Modo==3 && Segundos==0){Segundos=Y_Tiempo;  Modo=4; Amarillo(Modo);}

if(Modo==4 && Segundos==0){Segundos=G3_Tiempo; Modo=5; Abrir(Modo);}
if(Modo==5 && Segundos==0){Segundos=Y_Tiempo;  Modo=6; Amarillo(Modo);}

if(Modo==6 && Segundos==0){Segundos=G4_Tiempo; Modo=7; Abrir(Modo);}
if(Modo==7 && Segundos==0){Segundos=Y_Tiempo;  Modo=0; Amarillo(Modo);}

delay(10); 
}

void Amarillo(int y){
digitalWrite(S1_LED_Rojo, 1);  
if(y==0){digitalWrite(S1_LED_Amarillo, 1);}
       else{digitalWrite(S1_LED_Amarillo, 0);}
digitalWrite(S1_LED_Verde, 0);

digitalWrite(S2_LED_Rojo, 1);  
if(y==2){digitalWrite(S2_LED_Amarillo, 1);}
       else{digitalWrite(S2_LED_Amarillo, 0);}
digitalWrite(S2_LED_Verde, 0);

digitalWrite(S3_LED_Rojo, 1);  
if(y==4){digitalWrite(S3_LED_Amarillo, 1);}
       else{digitalWrite(S3_LED_Amarillo, 0);}
digitalWrite(S3_LED_Verde, 0);

digitalWrite(S4_LED_Rojo, 1);  
if(y==6){digitalWrite(S4_LED_Amarillo, 1);}
       else{digitalWrite(S4_LED_Amarillo, 0);}
digitalWrite(S4_LED_Verde, 0);
}

void Abrir(int Set){

digitalWrite(S1_LED_Amarillo, 0);
if(Set==1){
       digitalWrite(S1_LED_Verde, 1); digitalWrite(S1_LED_Rojo, 0);
}
else{
       digitalWrite(S1_LED_Verde, 0); digitalWrite(S1_LED_Rojo, 1);
}

digitalWrite(S2_LED_Amarillo, 0);
if(Set==3){
       digitalWrite(S2_LED_Verde, 1); digitalWrite(S2_LED_Rojo, 0);
}
else{
       digitalWrite(S2_LED_Verde, 0); digitalWrite(S2_LED_Rojo, 1);
}
 
digitalWrite(S3_LED_Amarillo, 0);
if(Set==5){
       digitalWrite(S3_LED_Verde, 1); digitalWrite(S3_LED_Rojo, 0);
}
else{
       digitalWrite(S3_LED_Verde, 0); digitalWrite(S3_LED_Rojo, 1);
}

digitalWrite(S4_LED_Amarillo, 0);
if(Set==7){
       digitalWrite(S4_LED_Verde, 1); digitalWrite(S4_LED_Rojo, 0);
}
else{
       digitalWrite(S4_LED_Verde, 0); digitalWrite(S4_LED_Rojo, 1);
 }
}

ISR(TIMER1_COMPA_vect){   
MiliSegundos++;
if(MiliSegundos >= 1000){
       MiliSegundos = 0;
       Segundos = Segundos-1;
 }
}