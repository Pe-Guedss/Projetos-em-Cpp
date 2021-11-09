Neste exercício você deverá fazer dois TADs para um jogo de batalha espacial. Utilizando **Structs**, você deve criar os seguintes TADs: **Ponto2D** e **Nave**. Cada TAD deve seguir as especificações abaixo:

- **Ponto2D** deve possuir pelo menos um construtor que recebe dois parâmetros (x, y) do tipo double, que devem ser armazenados internamente. Ele também deve possuir o seguinte método:





1. double calcular_distancia(Ponto2D* ponto): calcula a distância euclidiana para outro ponto no plano.

   



- **Nave** deve possuir pelo menos um construtor que recebe dois parâmetros: (i) 'posicao' do tipo Ponto2D (atenção, não deve ser usado ponteiro!), e (ii) 'forca' do tipo double, que representa a força de ataque da nave. Caso o parâmetro forca não seja informado ele deve ter um valor padrão 1. Além da posição e da força, o TAD também deve ter um atributo 'energia', do tipo double, que é sempre inicializado com valor 100. Você deve implementar os seguintes métodos nesse TAD:





1. void mover(double dx, double dy): atualiza a posição da nave nos eixos x e y somando valores dx e dy, respectivamente.

   

2. double calcular_distancia(Nave* nave): calcula e retorna a distância euclidiana para outra nave qualquer passada como parâmetro (ponteiro).

   

3. Nave* determinar_nave_mais_proxima(Nave** naves, int n): recebe um array de ponteiros para naves e um parâmetro que informa a quantidade de elementos nesse array. Determina qual a nave mais próxima e retorna um ponteiro para essa nave.

   

4. void atacar(Nave** naves, int n): ataca a nave mais próxima. A nave que sofre um ataque tem o seu valor de energia reduzido, onde a quantidade de dano é dada pela equação: dano = (100/d)*forca, onde d é a distância para a nave, e a força é o parâmetro informado no construtor. O máximo de dano (limite) que uma nave pode fazer em outra é **30**. Se após um ataque a nave atacada tiver energia menor/igual a **50** deve ser impressa a mensagem "**Energia baixa!**".

   

5. void imprimir_status(): imprime a situação atual da nave no seguinte formato "**x y energia**".

Como entrada serão fornecidos a posição (x, y) e a força de ataque de cada nave que participará da batalha. Em seguida, o jogo é executado considerando os comandos informados e algumas informações são impressas na tela.

**OBS:** Nesse exercício você **não precisa implementar a função main**! O objetivo é simular o caso em que você está implementando um TAD que será utilizado por outra pessoa (que conhece apenas o contrato). Dessa forma, a leitura dos dados de entrada e jogadas já estão implementadas, e **você deve apenas implementar os TADs** (Ponto2D e Nave). Você é livre para implementar quaisquer outros métodos auxiliares nos TADs que julgar necessário.

---

Para ilustrar, abaixo é apresentado um exemplo de entrada/saída:

input=
3
-1.0 0.0 1.0
0.0 0.0 1.0
1.0 0.0 1.0
s
a 0
s

---

output =
-1.00 0.00 100.00
0.00 0.00 100.00
1.00 0.00 100.00
-1.00 0.00 100.00
0.00 0.00 70.00
1.00 0.00 100.00

---

Nesse caso, o comando 's' é usado para imprimir o status atual de todas as naves, e o comando 'a' faz um ataque considerando a nave informada.
