 <h1 align="center">
   <br>
     <img width="400px" src="https://github.com/danrleiaraujo/BitDogLab_Pwm/blob/main/src/logo.png"> 
   <br>
     Unidade 4 - Capítulo 7 - PWM
   <br>
 </h1>
 <div align="center">
 
 </div>
 
 <div align="center"> 
   
 Esta atividade tem como objetivo usar o Raspberry Pi Pico W para compreender o funcionamento e aplicação da Modulação por Largura de Pulso (PWM). O projeto envolve programação em C, integração com o SDK do Raspberry Pi Pico e o simulador Wokwi. 
 </div>
 
 <details open="open">
 <summary>Sumário</summary>
   
 - [Requisitos](#requisitos)
 - [Componentes Utilizados](#componentes-utilizados)
 - [Estrutura do Projeto](#estrutura-do-projeto)
 - [Funcionalidades](#funcionalidades)
 - [Como Executar](#como-executar)
   - [Pré-requisitos](#pré-requisitos)
   - [Passos para Execução](#passos-para-execução)
 - [Vídeo Demonstração](#vídeo-demonstração)
 - [Autor](#autor)
 
 </details>
 
 ## Requisitos
 
 O projeto deve cumprir os seguintes requisitos:
 
 1. **Definir frequencia 50hz**: Considerando a GPIO 22, defina a sua frequência de PWM para, aproximadamente, 50Hz – período de 20ms.
 2. **Ciclo Ativo MAX**: Definir o ciclo ativo inicial do módulo PWM para 2.400µs (microssegundos) – Ciclo de Trabalho (Duty Cycle) de 0,12%.
 2. **Ciclo Ativo MID**: Definir o ciclo ativo inicial do módulo PWM para 1.470µs (microssegundos) – Ciclo de Trabalho (Duty Cycle) de 0,0735%.
 2. **Ciclo Ativo MIN**: Definir o ciclo ativo inicial do módulo PWM para 500µs (microssegundos) – Ciclo de Trabalho (Duty Cycle) de 0,0025%.
 3. **Rotina movimentação Periódica**: Uma rotina para movimentação periódica do braço do servomotor entre os ângulos de 0 e 180 graus.
 
 ## Componentes Utilizados
 
 1. **Raspberry Pi Pico W**: Microcontrolador para controle do sistema.
 2. **LED RGB (na placa BitDogLab) ou 3 LEDs de cores diferentes (no Simulador)**: Interface para visualização do pwm.
 3. **Motor Servo (no simulador Wokwi)**: Interface para visualização do pwm.
 4. **VS Code**: Ambiente de desenvolvimento para código em linguagem C.
 5. **Simulador Wokwi**: Para simulação do circuito.
   <div align="center">
       <img width="800px" src="https://github.com/danrleiaraujo/BitDogLab_Pwm/blob/main/src/image.png" />
       <p>Fig 1. Projeto no simulador .</p>
    </div>
    
 ## Estrutura do Projeto
 
 - **pwm.c**: Código responsável pela configuração.
 
 ## Como Executar
 
 ### Pré-requisitos
 
 1. **Git**: Certifique-se de ter o Git instalado no seu sistema. 
 2. **VS Code**: Instale o Visual Studio Code, um editor de código recomendado para desenvolvimento com o Raspberry Pi Pico.
 3. **Pico SDK**: Baixe e configure o SDK do Raspberry Pi Pico, conforme as instruções da documentação oficial.
 4. **Simulador Wokwi**: Utilize o simulador de eletrônica Wokwi para simular o projeto, caso não tenha acesso à placa física.
 5. **Conexão USB**: Certifique-se de que o Raspberry Pi Pico W esteja conectado via USB quando for testar o código.
 
 ### Passos para Execução
 
 1. **Clonar o repositório**: Clone o repositório utilizando o comando Git no terminal:
    
    ```bash
    git clone https://github.com/danrleiaraujo/Clock-e-Temporizadores.git
    ```
 2. Abrir no VS Code: Abra a pasta clonada no VS Code e no terminal do VS Code, vá até a pasta do projeto.
 3. Caso esteja usando a placa BitDogLab, acessar o arquivo "pwm.c" e mudar o valor da constante BITDOGLAB para 1.
 4. Compilar o código.
 
 ## Vídeo demonstração


 ## Autor
 
 <table>
   <tr>
     <td align="center">
       <a href="https://github.com/danrleiaraujo" target="_blank">
         <img src="https://avatars.githubusercontent.com/u/44043273?v=4" width="100px;" alt=""/>
       </a>
       <br /><sub><b> Danrlei Araujo</b></sub>
     </td>
   </tr>
 </table>
 
 
