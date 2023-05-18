//Definindo os pinos de entrada

int sensorMovimento = 2;

int luzVermelha = 3;
int luzAmarela = 4;
int luzVerde = 5;

//Contador de carros a nível de simular apenas
int carroContador;


void setup()
{
  pinMode(sensorMovimento, INPUT);
  
  pinMode(luzVermelha,OUTPUT);
  pinMode(luzAmarela,OUTPUT);
  pinMode(luzVerde,OUTPUT);
  
  Serial.begin(9600);
}

void loop()
{
  
    // Verifica se há carro detectado pelo sensor de movimento
    if (digitalRead(sensorMovimento) == HIGH) {
      carroContador++;  // Incrementa o contador de carros
      delay(1000);  // Espera 1 segundo para evitar múltiplas contagens por um único carro
    }
  else if(digitalRead(sensorMovimento) == LOW){
    delay(1000);
    carroContador = 0;
  }
  
  	Serial.println(carroContador);

    // Atualiza os LEDs com base no estado do tráfego
    VerificaTrafego();
  	delay(1000);
}

void VerificaTrafego() {
  // Lógica para controlar os LEDs com base no valor do contador de carros
  if (carroContador <= 5) {
    // Pouco tráfego - LED verde ligado, os outros desligados
    digitalWrite(luzVerde, HIGH);
    digitalWrite(luzAmarela, LOW);
    digitalWrite(luzVermelha, LOW);
  } else if (carroContador <= 10) {
    // Tráfego moderado - LED amarelo ligado, os outros desligados
    digitalWrite(luzVerde, LOW);
    digitalWrite(luzAmarela, HIGH);
    digitalWrite(luzVermelha, LOW);
  } else {
    // Tráfego intenso - LED vermelho ligado, os outros desligados
    digitalWrite(luzVerde, LOW);
    digitalWrite(luzAmarela, LOW);
    digitalWrite(luzVermelha, HIGH);
  }
}
