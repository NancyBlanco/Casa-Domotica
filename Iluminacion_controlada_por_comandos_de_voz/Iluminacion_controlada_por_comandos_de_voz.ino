/*EQUIPO 2*/
/*INTEGRANTES: - Miguel Salvador López López
               - Miguel Angel Olea Mártinez
               - Juan Manuel Linares
               - Nancy Blanco Hernández
*/          
String voice;
int
led1 = 4, //Conectado al PIN #4
led2 = 7, //Conectado al PIN #7
led3 = 10, //Conectado al PIN #10
led4 = 11, //Conectado al PIN #11
led5 = 8; //Conectado al PIN #8

//-----------funciona que enciende todas las luces-------------------------
void encenderTodo(){
     digitalWrite(led1, HIGH);
     digitalWrite(led2, HIGH);
     digitalWrite(led3, HIGH);
     digitalWrite(led4, HIGH);
     digitalWrite(led5, HIGH);
     
}
void apagarTodo(){
     digitalWrite(led1, LOW);
     digitalWrite(led2, LOW);
     digitalWrite(led3, LOW);
     digitalWrite(led4, LOW);
     digitalWrite(led5, LOW);
     
}
//-----------------------------------------------------------------------// 
void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
   
}
//-----------------------------------------------------------------------// 
void loop() {
  while (Serial.available()){  
  delay(10); 
  char c = Serial.read(); 
  if (c == '#') {break;} 
  voice += c; 
  } 
  if (voice.length() > 0) {
    Serial.println(voice);
    
//------------------ CONTROL DE LEDS -----------------------------------//   
  if(voice == "*encender luces") {encenderTodo();}  
  else if(voice == "*Apagar luces"){apagarTodo();}
 
  //---------------- ENCENDER LAS LUCES  ---------------------------//
  else if(voice == "*encender sala") {digitalWrite(led1, HIGH);}
  else if(voice == "*encender estudio") {digitalWrite(led2, HIGH);}
  else if(voice == "*encender cuarto") {digitalWrite(led3, HIGH);}
  else if(voice == "*encender baño") {digitalWrite(led4, HIGH);}
  else if(voice == "*encender comedor") {digitalWrite(led5, HIGH);}
  
  //---------------- APAGAR LAS LUCES  ---------------------------//
  else if(voice == "*Apagar sala") {digitalWrite(led1, LOW);}
  else if(voice == "*Apagar estudio") {digitalWrite(led2, LOW);}
  else if(voice == "*Apagar cuarto") {digitalWrite(led3, LOW);}
  else if(voice == "*Apagar baño") {digitalWrite(led4, LOW);}
  else if(voice == "*Apagar comedor") {digitalWrite(led5, LOW);}
 
voice="";}} 
