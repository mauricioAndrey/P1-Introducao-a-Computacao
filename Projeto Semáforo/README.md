# Semáforo 

## Esquema do projeto
 - Estados do Carro
   - Neutro
     - tempo < 0 ou tempo > 25
     - lcd limpa
     - semaforo desliga
     - muda para o amarelo depois do tempo = 0
   - Amarelo
     - tempo > 0 e tempo < 5
     - lcd mostra um timer e que os carros tenham atenção
     - semaforo amarelo liga (e os outros desligam)
     - muda para o vermelho depois do tempo = 5
   - Vermelho
     - tempo > 5 e tempo < 15
     - lcd mostra um timer e que é a vez dos pedestres
     - semaforo vermelho liga (e os outros desligam)
     - muda para o verde depois do tempo = 15
   - Verde
     - tempo > 15 e tempo < 25
     - lcd mostra um timer e que é a vez dos carros
     - semaforo verde liga (e os outros desligam)
     - muda para o neutro depois do tempo = 25
 - Estados do Pedestre
   - Neutro
     - tempo < 0 ou tempo > 25
     - lcd limpa
     - semaforo desliga
     - muda para o vermelho depois do tempo = 0 
   - Verde
     - tempo > 0 e tempo < 5
     - lcd mostra um timer e que é a vez dos pedestres
     - semaforo verde liga (e os outros desligam)
     - muda para o amarelo depois do tempo = 12
   - Amarelo
     - tempo > 15 e tempo < 25
     - lcd mostra um timer e que os pedestres tenham atenção
     - semaforo amarelo liga (e os outros desligam)
     - muda para o vermelho depois do tempo = 15
   - Vermelho
     - tempo > 5 e tempo < 15
     - lcd mostra um timer e que é a vez dos carros
     - semaforo vermelho liga (e os outros desligam)
     - muda para o neutro depois do tempo = 25

  | Tempo | Estado Carro | Estado Pedestre | LCD |
  |:-----------:|:-----------:|:-----------:|:-----------:|
  |      `<0`      |    `-`    |    `-`    |    `-`    |
  |    `0 - 4.9`    |    `Amarelo`    |    `Vermelho`    |    `Prox: Pedestre`    |
  |    `5 - 11.9`    |    `Vermelho`    |    `Verde`    |    `Vez do Pedestre`    |
  |    `12 - 14.9`    |    `Vermelho`    |    `Amarelo`    |    `Prox: Carro`    |
  |    `15 - 25`    |    `Verde`    |    `Vermelho`    |    `Vez do Carro`    |
  |    `-`    |    `-`    |    `-`    |    `-`    |
  
  
