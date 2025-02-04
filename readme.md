<table align="center">
  <tr>
    <td><img src="image.png" width="100"></td>
    <td align="center">
      <b>Embarca Tech - CEPEDI</b><br>
      Capacitação Inicial em Sistemas Embarcados<br>
      U1 - Introdução à Educação a Distância<br>
      <b>Discente - Rodrigo Damasceno Sampaio (Grupo 9)</b>
    </td>
    <td><img src="image2.png" width="100"></td>
  </tr>
</table>


# 🚦 Semáforo com Temporizador Periódico

Este projeto implementa um **semáforo automatizado** utilizando a placa **Raspberry Pi Pico W** e a biblioteca **Pico SDK**. O sistema **controla três LEDs** para simular um semáforo real, alternando entre os estados **vermelho, amarelo e verde a cada 3 segundos**, utilizando um **temporizador repetitivo (`add_repeating_timer_ms()`)**.

---

## 🎯 **Objetivos**
✅ Compreender o funcionamento e a aplicação de **temporizadores em microcontroladores**.  
✅ Manipular e controlar LEDs para **simular um semáforo real**.  
✅ Implementar um **temporizador periódico** para alternar os LEDs **a cada 3 segundos**.  
✅ Exibir **mensagens no terminal serial** a cada **1 segundo**.  

---

## 📚 **Descrição do Projeto**
Utilizamos a placa **BitDogLab (RP2040)** para **controlar três LEDs**. Cada LED **liga e desliga** seguindo um ciclo de **3 segundos**:
- **Vermelho** → Indica "Pare".
- **Amarelo** → Indica "Atenção".
- **Verde** → Indica "Siga".

O **temporizador repetitivo (`add_repeating_timer_ms()`)** alterna os LEDs automaticamente sem interromper o código principal. Enquanto isso, o **loop principal imprime mensagens** a cada **1 segundo**, simulando o funcionamento de um sistema de tempo real.

---

## 🛠 **Componentes e Conexões**
| Componente        | Pino GPIO |
|-------------------|-----------|
| 🔴 LED Vermelho   | GPIO 13   |
| 🟡 LED Amarelo    | GPIO 12   |
| 🟢 LED Verde      | GPIO 11   |

---

## 🔧 **Configuração do Código**
### 📌 **1️⃣ Inicialização dos LEDs**
Os LEDs são configurados como **saída digital (GPIO_OUTPUT)** no **RP2040**:
```c
gpio_init(LED_RED);
gpio_set_dir(LED_RED, GPIO_OUT);
gpio_init(LED_YELLOW);
gpio_set_dir(LED_YELLOW, GPIO_OUT);
gpio_init(LED_GREEN);
gpio_set_dir(LED_GREEN, GPIO_OUT);
```

## 🚀 Como Rodar o Projeto

### 📌 **1️⃣ Clonar o Repositório**
```bash
git clone https://github.com/Rodrigodsgit/U4-semaforo.git
cd semaforo
```

### 📌 **2️⃣ Configurar o Ambiente**
Instale a extensão da Raspberry Pi Pico Project no VsCode  

### 📌 3️⃣ Compilar o Código
Através da extensão, use o acesso rapido e clique em "Compile Project"

### 📌 4️⃣ Rode o Código
Através da extensão, use o acesso rapido e clique em "Run Project (USB)"

## 📝  Saída esperada

<p align="center">
  <img src="placa.gif" width="300">
</p>
