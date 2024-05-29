# CronOut Library
CronOut é uma biblioteca para Arduino que facilita a criação e gerenciamento de timeouts em milissegundos. Com esta biblioteca, você pode definir um timeout para uma função específica, reiniciar, cancelar e verificar se o timeout foi atingido, e executar uma função de callback ao atingir o timeout.

## Funcionalidades
- Definição de timeouts em milissegundos.
- Execução de função de callback ao atingir o timeout.
- Reiniciar e cancelar timeouts.
- Verificação se o timeout foi atingido.

## Instalação
- Faça o download do arquivo ZIP da biblioteca.
- No Arduino IDE, vá para Sketch > Include Library > Add .ZIP Library.
- Selecione o arquivo ZIP baixado.


## Como usar
Inclua a biblioteca no início do seu sketch:
```cpp
#include <CronOut.h>
```


Crie uma instância da classe CronOut especificando a duração do timeout em milissegundos e a função de callback a ser chamada:
```cpp
CronOut myTimeout(5000, onTimeout);  // Timeout de 5 segundos
```

Inicie o timeout no setup ou em qualquer outra parte do seu código:
```cpp
myTimeout.start();
```

Defina a função de callback que será chamada ao atingir o timeout:
```cpp
void onTimeout() {
    Serial.println("Timeout atingido!");
}
```

No loop principal, verifique se o timeout foi atingido e reinicie-o se necessário:
```cpp
void loop() {
    if (myTimeout.hasTimedOut()) {
        Serial.println("Timeout atingido!");
        myTimeout.restart();  // Reinicia o timeout
    }

    // Exemplo de como cancelar o timeout
    // if (someCondition) {
    //     myTimeout.cancel();
    // }
}
```

## Exemplo completo
```cpp
#include <CronOut.h>

CronOut myTimeout(5000, onTimeout);  // Timeout de 5 segundos com a função de callback `onTimeout`

void setup() {
    Serial.begin(9600);
    myTimeout.start();  // Inicia o timeout
}

void loop() {
    if (myTimeout.hasTimedOut()) {
        Serial.println("Timeout atingido!");
        myTimeout.restart();  // Reinicia o timeout
    }
}

void onTimeout() {
    Serial.println("Callback de timeout chamado!");
    // Aqui você pode alterar uma variável interna ou executar outra lógica
}
```

## Licença
Este projeto está licenciado sob a MIT License.
