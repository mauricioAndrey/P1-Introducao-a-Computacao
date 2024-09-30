# Semáforo 
![Diagrama de Blocos](/assets/maquinaEstados_Semaforo.pdf)

![Diagrama de Blocos](/assets/maquinaEstados_Semaforo.png)

## Esquema do projeto

<details>
<summary>Estados</summary>
   - Inicial
     - Quando: tempo < 0 ou tempo > 25
     - Acontece: 
        - lcd limpa
        - semaforo Carro desliga
        - semaforo Pedestre desliga
   - Próximo Pedestre
     - Quando: 0 < tempo < 5
     - Acontece: 
        - lcd "Próx. Pedestre"
        - semaforo Carro amarelo
        - semaforo Pedestre vermelho
   - Vez do Pedestre
     - Quando: 5 < tempo < 12
     - Acontece: 
        - lcd "Vez do Pesdestre"
        - semaforo Carro vermelho
        - semaforo Pedestre verde
   - Próximo Carro
     - Quando: 12 < tempo < 15
     - Acontece: 
        - lcd "Próx. Carro"
        - semaforo Carro vermelho
        - semaforo Pedestre amarelo
   - Vez do Carro
     - Quando: 15 < tempo < 25
     - Acontece: 
        - lcd "Vez do Caro"
        - semaforo Carro verde
        - semaforo Pedestre vermelho
</details>

<details>
<summary>Tabela dos Estados</summary>
  | Tempo | Estado Carro | Estado Pedestre | LCD |
  |:-----------:|:-----------:|:-----------:|:-----------:|
  |      `<0`      |    `-`    |    `-`    |    `-`    |
  |    `0 - 4.9`    |    `Amarelo`    |    `Vermelho`    |    `Prox: Pedestre`    |
  |    `5 - 11.9`    |    `Vermelho`    |    `Verde`    |    `Vez do Pedestre`    |
  |    `12 - 14.9`    |    `Vermelho`    |    `Amarelo`    |    `Prox: Carro`    |
  |    `15 - 25`    |    `Verde`    |    `Vermelho`    |    `Vez do Carro`    |
  |    `-`    |    `-`    |    `-`    |    `-`    |

</details>
  
