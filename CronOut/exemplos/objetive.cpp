/*
exemplo completo usando a biblioteca CronOut, onde um sensor DHT11 monitora a temperatura. 
Se a temperatura ultrapassar 30 graus Celsius, um exaustor é acionado usando um relé. Se 
a temperatura não baixar em 30 minutos, um timeout é acionado para desligar o exaustor 
e gerar um aviso.
*/

#include <CronOut.h>
#include <DHT.h>

#define DHTPIN 2     // Pino digital onde o DHT11 está conectado
#define DHTTYPE DHT11   // Definindo o tipo de sensor como DHT11
#define RELAYPIN 3   // Pino digital onde o relé está conectado
#define TIMEOUT_TIME 30*60*1000 //30 minutos X 60 segundos X 1000 Ms
#define MAX_TEMPERATURE 30

DHT dht(DHTPIN, DHTTYPE);
CronOut fanTimeout(TIMEOUT_TIME, CallBack); // Timeout de 30 minutos

bool fan_active = false;

void setup() {
    Serial.begin(9600);
    dht.begin();
    pinMode(RELAYPIN, OUTPUT);
    digitalWrite(RELAYPIN, LOW); // Exaustor desligado inicialmente
}

void loop() {
    // Lê a temperatura do sensor DHT11
    float temperature = dht.readTemperature();

    // Verifica se a leitura é válida
    if (isnan(temperature)) {
        Serial.println("Falha ao ler do sensor DHT!");
        return;
    }

    // Exibe a temperatura lida
    Serial.print("Temperatura: ");
    Serial.print(temperature);
    Serial.println(" *C");

    // Verifica se a temperatura ultrapassa 30 graus Celsius
    if (temperature > MAX_TEMPERATURE) {
        if (fan_active == false) {//se temperatura alta e exaustores desligdos, entao liga
            digitalWrite(RELAYPIN, HIGH); // Liga o exaustor
            fanTimeout.start(); // Inicia o timeout de 30 minutos
            fan_active = true;
            Serial.println("Exaustor ligado.");
        }
    } else {
        if (fan_active == true) { //se a temperatura estivar mais baixo que 30 graus e tiver ligado
            digitalWrite(RELAYPIN, LOW); // Desliga o exaustor
            fanTimeout.cancel(); // Cancela o timeout
            fan_active = false;
            Serial.println("Exaustor desligado.");
        }
    }

    // Verifica se o timeout foi atingido
    if (fanTimeout.hasTimedOut()) {
        Serial.println("Exaustor desligado após 30 minutos sem baixar a temperatura!");
        digitalWrite(RELAYPIN, LOW); // Desliga o exaustor
        fan_active = false;
    }

    delay(2000); // Espera 2 segundos antes da próxima leitura
}

void CallBack() {
    Serial.println("Timeout atingido: Temperatura não baixou em 30 minutos.");
}
