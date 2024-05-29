#include <CronOut.h>

CronOut myTimeout(5000, onTimeout);  // Cria um timeout de 5 segundos com a função de callback `onTimeout`

void setup() {
    Serial.begin(9600);
    myTimeout.start();  // Inicia o timeout
}

void loop() {
    // Verifica se o timeout foi atingido
    if (myTimeout.hasTimedOut()) {
        Serial.println("Timeout atingido!");
        myTimeout.restart();  // Reinicia o timeout
    }

    // Exemplo de como cancelar o timeout
    // if (someCondition) {
    //     myTimeout.cancel();
    // }
}

void onTimeout() {
    Serial.println("Callback de timeout chamado!");
    // Aqui você pode alterar uma variável interna ou executar outra lógica
}
