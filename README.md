# 📇 Projeto: Semáforo Periódico

Desenvolvimento de um semáforo utilizando um **Raspberry Pi Pico W (RP2040)** para construção da solução em embarcados.

## 🎯 Objetivo

Projetar um semáforo com temporização de 3 segundos para cada alteração de sinal. Onde é empregado o uso da: **Pico SDK**, e das funções: `add_repeating_timer_ms()` e `repeating_timer_callback()`.

## 🛠️ Dispositivos utilizados

Para o projeto serão utilizados os seguintes dispositivos:

- 1️⃣ Microcontrolador **Raspberry Pi Pico W**;
- 2️⃣ 03 LEDs (vermelho, amarelo e verde);
- 3️⃣ 03 Resistores de 330 Ω.
  
## 📌 Requisitos

- 1️⃣ O acionamento dos LEDs (sinais do semáforo) deve iniciar na cor vermelha;
- 2️⃣ Deve ser alterado de vermelho para amarela e de amarela para verde, nesta sequência;
- 3️⃣ O temporizador deve ser ajustado para um atraso de 3 segundos (3.000ms);
- 4️⃣ A mudança de estado dos LEDs deve ser implementa na função de call-back do temporizador [`repeating_timer_callback()`];
- 5️⃣ A rotina principal, deve imprimir algum tipo de informação a cada segundo (1.000 ms) - a mensagem enviada pela porta serial fica a critério do **discente**;
- 6️⃣ Com o emprego da Ferramenta Educacional BitDogLab, faça um experimento com o código deste exercício utilizando o LED RGB – GPIOs 11, 12 e 13.

## 🧩 Funcionalidades

É implementado uma função com um temporizador, que ao alcançar um tempo determinado altera os estados dos LEDs, ou do LED RGB existente na placa BitDogLab, para simular o estado de um semáforo.

É criada uma variável de nome: `bitdoglab`, que possui valor inicial `= 0`, onde pode ser alterado o seu valor, para quelquer valor válido `> 0`, permitindo que seja utilizado o LED RGB da placa BitDogLab.

A função: `traffic_light_callback(struct repeating_timer *t)` é responsável por realizar a alteração da cor dos LEDs, os quais é executada com um _delay_ de `3000ms`. E a cada intervalo é verificado se o tempo atual ultrapassou o tempo determinado para a próxima interrupção, como pode ser verificado na comparação: `(absolute_time_diff_us(now, to_ms_since_boot(next_time)) < 0)`. Sendo então, constatado ter excedido o tempo determinado a alteração na cor dos LEDs é realizada. 

## ☑️ Conclusão

Com a implementação é possível simular o semáforo, o qual detém 3 cores: Vermelho, Amarelo e Verde. E cada cor é acionada por um tempo de 3 segundo.

A prática também permite a obtenção de conhecimento sobre temporizadores.

## 🌟 Créditos

Desenvolvido por Jônatas da Silva, como parte de um projeto prático, onde é usado o microcontrolador Raspberry Pi Pico W (RP2040). Na iniciativa o projeto EmbarcaTech.
