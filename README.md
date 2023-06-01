# Trabalho-CG
Autores: Rayan Victor e Renato Vasconcelos

//main.cpp
1. Incluições de bibliotecas:
   - `#include <GL/freeglut.h>`: Inclui a biblioteca FreeGLUT, que fornece funções para criar janelas, lidar com eventos e renderizar gráficos em OpenGL.
   - `#include "player.h"`, `#include "enemy.h"`, `#include "powerUp.h"`, `#include "score.h"`: Inclui os arquivos de cabeçalho das classes relacionadas ao jogo.

2. Declaração de objetos:
   - `Player player;`, `Enemy enemy;`, `PowerUp powerUp;`, `Score score;`: Declara objetos das classes Player, Enemy, PowerUp e Score, que representam os elementos do jogo.

3. Função `drawObjects()`:
   - Chama o método `draw()` de cada objeto para desenhá-los na tela.

4. Função `updateObjects()`:
   - Chama os métodos `update()` de cada objeto para atualizá-los.

5. Função `display()`:
   - Limpa o buffer de cor.
   - Chama a função `drawObjects()` para desenhar os objetos.
   - Troca os buffers para exibir o desenho na janela.

6. Função `reshape()`:
   - Define a viewport de acordo com as dimensões da janela.

7. Função `keyboard()`:
   - Trata os eventos de teclado, movendo o jogador com base na tecla pressionada.

8. Função `idle()`:
   - Obtém as dimensões da janela.
   - Chama a função `updateObjects()` para atualizar os objetos.
   - Solicita uma nova renderização.

9. Função `main()`:
   - Inicializa o FreeGLUT.
   - Configura o modo de exibição, tamanho da janela e título da janela.
   - Registra as funções de callback para os eventos de exibição, redimensionamento, teclado e ociosidade.
   - Define a cor de fundo.
   - Inicia o loop principal do FreeGLUT.

//powerUp.cpp

1. Incluições de bibliotecas:
   - `#include "powerUp.h"`: Inclui o arquivo de cabeçalho da classe PowerUp.
   - `#include <GL/gl.h>`: Inclui a biblioteca OpenGL, que fornece funções e estruturas para renderização gráfica em 2D e 3D.
   - `#include <cmath>`: Inclui a biblioteca cmath, que fornece funções matemáticas, como cos e sin.

2. Construtor `PowerUp::PowerUp()`:
   - Inicializa as variáveis ​​de posição, velocidade, raio e atividade do Power-Up.

3. Função `PowerUp::update()`:
   - Atualiza a posição do Power-Up adicionando a velocidade atual à posição atual nas coordenadas X e Y.
   - Essa função é responsável pela lógica de movimento ou comportamento do Power-Up. Você pode adicionar a lógica específica desejada aqui.

4. Função `PowerUp::draw()`:
   - Verifica se o Power-Up está ativo. Se não estiver, retorna imediatamente.
   - Salva a matriz de transformação atual com `glPushMatrix()` e a restaura com `glPopMatrix()` no final da função. Isso garante que as transformações não afetem outros objetos desenhados.
   - Usa `glTranslatef()` para mover o Power-Up para a posição correta antes de desenhá-lo.
   - Desenha o Power-Up como um círculo preenchido usando `glBegin(GL_TRIANGLE_FAN)` e `glEnd()`.
   - O círculo é desenhado com a cor amarela (1.0, 1.0, 0.0).

//player.cpp

1. Inclusões de bibliotecas:
   - `#include "player.h"`: Inclui o arquivo de cabeçalho da classe Player.
   - `#include "input.h"`: Inclui o arquivo de cabeçalho da classe Input.
   - `#include <GLFW/glfw3.h>`: Inclui a biblioteca GLFW, que fornece funções para criar janelas e capturar entradas do teclado.

2. Construtor `Player::Player()`:
   - Inicializa as variáveis `positionX`, `positionY`, `speed`, `width` e `height` com valores padrão.

3. Função `Player::update(int windowWidth, int windowHeight)`:
   - Verifica se as teclas 'a', 'd', 'w' e 's' estão pressionadas usando a função `Input::KeyIsPressed()`.
   - Atualiza as posições `positionX` e `positionY` com base nas teclas pressionadas e na velocidade do jogador.
   - Limita o movimento do jogador dentro dos limites da janela.

4. Função `Player::draw()`:
   - Salva a matriz de transformação atual com `glPushMatrix()` e a restaura com `glPopMatrix()` no final da função. Isso garante que as transformações não afetem outros objetos desenhados.
   - Usa `glTranslatef()` para mover o jogador para a posição correta antes de desenhá-lo.
   - Desenha o jogador como um quadrado preenchido usando `glBegin(GL_QUADS)` e `glEnd()`.

5. Funções `Player::moveLeft()`, `Player::moveRight()`, `Player::moveUp()`, `Player::moveDown()`:
   - Atualizam a posição do jogador ao mover o jogador para a esquerda, direita, cima ou baixo com base na velocidade do jogador.

6. Função `Input::KeyIsPressed(int key)`:
   - Essa função deve ser implementada no arquivo `input.cpp`.
   - É responsável por verificar se uma tecla específica está pressionada. Você precisa adicionar seu código nessa função para retornar verdadeiro ou falso com base na entrada da tecla.

//score.cpp

1. Inclusões de bibliotecas:
   - `#include <GL/glut.h>`: Inclui a biblioteca GLUT, que fornece funções para criar janelas e lidar com eventos de entrada.
   - `#include <string>`: Inclui a biblioteca string, necessária para manipulação de strings.

2. Construtor `Score::Score()`:
   - Inicializa as variáveis `scoreValue`, `positionX`, `positionY` e `fontSize` com valores padrão.

3. Função `Score::increaseScore(int points)`:
   - Aumenta o valor do score (`scoreValue`) com base nos pontos fornecidos.

4. Função `Score::draw()`:
   - Define a matriz de projeção com `glMatrixMode(GL_PROJECTION)` e `glLoadIdentity()`. Isso define a projeção ortogonal para desenhar o texto na tela.
   - Define a matriz de visualização com `glMatrixMode(GL_MODELVIEW)` e `glLoadIdentity()`. Isso restaura a matriz de visualização para seu estado original.
   - Salva a matriz de transformação atual com `glPushMatrix()` e a restaura com `glPopMatrix()` no final da função. Isso garante que as transformações não afetem outros objetos desenhados.
   - Usa `glTranslatef()` para mover o texto para a posição correta antes de desenhá-lo.
   - Usa `glRasterPos2i()` para definir a posição inicial do texto.
   - Cria uma string `scoreText` contendo o texto "Score: " seguido do valor atual do score convertido para string.
   - Itera sobre cada caractere da string `scoreText` e usa `glutBitmapCharacter()` para desenhar cada caractere na tela usando a fonte `GLUT_BITMAP_HELVETICA_18`.

//enemy.cpp
1. Inclusões de bibliotecas:
   - `"enemy.h"`: Inclui o arquivo de cabeçalho `enemy.h`, que contém a declaração da classe Enemy.
   - `<GL/gl.h>`: Inclui a biblioteca `GL/gl.h`, que fornece os cabeçalhos e definições necessárias para a programação com OpenGL.

2. Construtor `Enemy::Enemy()`:
   - Inicializa as variáveis `positionX`, `positionY`, `speed`, `width` e `height` com valores padrão.

3. Função `Enemy::update()`:
   - Atualiza a posição do inimigo adicionando a velocidade atual às coordenadas X e Y.
   - Inclui a lógica de movimento ou comportamento específico do inimigo. Você pode adicionar a lógica personalizada aqui.
   - Verifica colisões ou outras interações com o jogador ou obstáculos. Essa parte também pode ser personalizada conforme necessário.

4. Função `Enemy::draw()`:
   - Salva a matriz de transformação atual com `glPushMatrix()` e a restaura com `glPopMatrix()` no final da função. Isso garante que as transformações não afetem outros objetos desenhados.
   - Usa `glTranslatef()` para mover o objeto inimigo para a posição correta antes de desenhá-lo.
   - Desenha o inimigo como um quadrado usando `glBegin(GL_QUADS)` e especifica os vértices do quadrado com `glVertex2f()`.
   - Encerra o desenho do quadrado com `glEnd()`.

//input.cpp

"input.h" e a biblioteca GLFW/glfw3.h para as definições e funções relacionadas à entrada de teclado.

1. A função bool Input::KeyIsPressed(int key) implementa a lógica para verificar se uma tecla está pressionada. Ela utiliza a função glfwGetKey() para obter o estado da tecla especificada pelo parâmetro "key" em relação ao contexto GLFW atual.

2. A função retorna true se o estado da tecla for GLFW_PRESS (pressionada) ou GLFW_REPEAT (mantida pressionada), indicando que a tecla está atualmente sendo pressionada. Caso contrário, retorna false.

No entanto, é importante garantir que a biblioteca GLFW esteja instalada corretamente e que você esteja utilizando a versão correta das funções e definições relacionadas à entrada de teclado.


#Classes

//powerUp.h

1. A classe `PowerUp` possui membros públicos para as funções `update()` e `draw()`, que atualizam e desenham o Power-Up, respectivamente.

2. Os membros privados da classe incluem variáveis ​​para armazenar a posição (`positionX` e `positionY`), velocidade (`speed`), raio (`radius`) e estado ativo (`isActive`) do Power-Up.

//player.h

1. A classe `Player` possui membros públicos para as funções `update()`, `draw()`, `moveLeft()`, `moveRight()`, `moveUp()` e `moveDown()`, que são responsáveis por atualizar, desenhar e mover o jogador, respectivamente.

2. Os membros privados da classe incluem variáveis para armazenar a posição (`positionX` e `positionY`), velocidade (`speed`), largura (`width`) e altura (`height`) do jogador.

//score.h

1.A classe `Score` possui membros públicos para as funções `increaseScore()` e `draw()`, que são responsáveis por aumentar a pontuação e desenhar a pontuação na tela, respectivamente.

2. Os membros privados da classe incluem variáveis para armazenar o valor da pontuação (`scoreValue`), a posição X e Y para o desenho da pontuação (`positionX` e `positionY`) e o tamanho da fonte (`fontSize`). 
Além disso, há uma indicação de que pode haver outras variáveis e métodos relacionados à pontuação, mas eles não estão explicitamente definidos no código compartilhado.

//enemy.h

1. A classe `Enemy` possui membros públicos para as funções `draw()` e `update()`, responsáveis por desenhar o inimigo na tela e atualizar sua posição e comportamento, respectivamente.

2. Os membros privados da classe incluem variáveis para armazenar a posição X e Y do inimigo (`positionX` e `positionY`), sua velocidade (`speed`), largura e altura (`width` e `height`). 
 Essas variáveis são usadas para controlar o desenho e o movimento do inimigo.

//input.h

1. A função `KeyIsPressed` utiliza a função `glfwGetKey` da biblioteca GLFW para obter o estado da tecla especificada pelo parâmetro `key`. 
2. Se o estado da tecla for `GLFW_PRESS` ou `GLFW_REPEAT`, a função retorna `true`, indicando que a tecla está pressionada. Caso contrário, ela retorna `false`.



#Copilando e rodando no linux

g++ -o programa main.cpp enemy.cpp player.cpp powerUp.cpp score.cpp -lGL -lGLU -lglut

./programa
