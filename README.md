# Trabalho-CG
Autores: Rayan Victor e Renato Vasconcelos

**------------ Jornada do Rei da Pradaria--------------------

**//main.cpp

1. `drawObjects()`: Essa função desenha os objetos do jogo na tela. Ela chama os métodos `draw()` de cada um dos objetos: `player`, `enemy`, `powerUp` e `score`.

2. `updateObjects(int windowWidth, int windowHeight)`: Essa função atualiza os objetos do jogo. Ela chama os métodos `update()` de cada um dos objetos: `player`, `enemy` e `powerUp`. Os parâmetros `windowWidth` e `windowHeight` são utilizados para passar as dimensões da janela do jogo para os objetos, de forma que eles possam ajustar seu comportamento com base no tamanho da janela.

3. `display()`: Essa função é responsável por limpar o buffer de cor, chamar a função `drawObjects()` e trocar os buffers, usando `glutSwapBuffers()`. Essa troca de buffers é necessária quando se usa o modo de renderização dupla, `GLUT_DOUBLE`, para evitar o efeito de flickering na tela.

4. `reshape(int width, int height)`: Essa função é chamada quando a janela do jogo é redimensionada. Ela define a nova viewport para a janela com base nas dimensões passadas como parâmetro.

5. `keyboard(unsigned char key, int x, int y)`: Essa função lida com a entrada do teclado. Ela recebe a tecla pressionada (`key`) e as coordenadas do mouse (`x` e `y`) quando a tecla foi pressionada. Neste caso, ela verifica qual tecla foi pressionada e chama os métodos apropriados do objeto `player` para mover o jogador (por exemplo, `moveLeft()` para mover para a esquerda quando a tecla 'a' é pressionada).

6. `idle()`: Essa função é chamada quando não há eventos a serem tratados. Ela obtém as dimensões da janela usando `glutGet(GLUT_WINDOW_WIDTH)` e `glutGet(GLUT_WINDOW_HEIGHT)`, e chama a função `updateObjects()` passando essas dimensões. Em seguida, chama `glutPostRedisplay()` para solicitar que a função `display()` seja chamada e a tela seja atualizada.

7. `main(int argc, char** argv)`: A função principal do programa. Ela inicializa a biblioteca GLUT, define o modo de exibição, tamanho da janela e título, registra as funções de callback (`display()`, `reshape()`, `keyboard()`, `idle()`), define a cor de fundo e inicia o loop principal do GLUT com `glutMainLoop()`.

Essas funções em conjunto implementam a lógica básica do jogo, onde o jogador (`player`) pode se mover usando as teclas 'a', 'd', 'w' e 's' para evitar os inimigos (`enemy`), coletar os power-ups (`powerUp`) e aumentar sua pontuação (`score`).

**//powerUp.cpp

1. `PowerUp::PowerUp(const Player& player)`: Este é o construtor da classe `PowerUp`. Ele recebe uma referência constante para um objeto `Player` como parâmetro. Ele inicializa as variáveis de membro da classe, como `positionX`, `positionY`, `speed`, `radius` e `isActive`. As variáveis `width` e `height` também são inicializadas, mas seus valores não foram fornecidos no código. É possível que essas variáveis sejam usadas posteriormente para definir a área de colisão do Power-Up.

2. `PowerUp::update()`: Esta função é responsável por atualizar o estado do Power-Up. Neste caso, ela incrementa as coordenadas `positionX` e `positionY` com a velocidade definida. Em seguida, ela verifica se houve colisão entre o Power-Up e o jogador usando as informações do objeto `Player` (posição e tamanho). Caso ocorra uma colisão, a função pode executar alguma ação desejada, como adicionar pontos ao jogador ou ativar um efeito especial.

3. `PowerUp::draw() const`: Esta função desenha o Power-Up na tela. Ela primeiro verifica se o Power-Up está ativo (`isActive`). Caso não esteja ativo, a função retorna sem desenhar nada. Caso contrário, ela define uma transformação de translação com base nas coordenadas `positionX` e `positionY` e, em seguida, desenha o Power-Up como um círculo usando a função `glBegin(GL_TRIANGLE_FAN)` e `glVertex2f()` para definir os vértices do círculo. O círculo é desenhado usando uma cor preta (`glColor3f(0.0f, 0.0f, 0.0f)`). Por fim, a transformação de translação é desfeita usando `glPopMatrix()`.

Essas funções em conjunto permitem criar um objeto `PowerUp` que pode ser atualizado e desenhado na tela. O objeto se move em uma determinada velocidade e verifica colisões com o jogador. Quando ocorre uma colisão, alguma ação específica pode ser executada. O desenho do Power-Up é feito como um círculo preto na posição especificada.

**//player.cpp

1. `Player::Player()`: Este é o construtor da classe `Player`. Ele inicializa as variáveis de membro da classe, como `positionX`, `positionY`, `speed`, `width` e `height`.

2. `Player::update(int windowWidth, int windowHeight)`: Esta função é responsável por atualizar o estado do jogador. Ela verifica se as teclas 'a', 'd', 'w' e 's' estão pressionadas, e, em seguida, ajusta as coordenadas `positionX` e `positionY` de acordo com a velocidade (`speed`) do jogador. Além disso, ela limita o movimento do jogador dentro dos limites da janela, verificando se ele ultrapassou as bordas. Os parâmetros `windowWidth` e `windowHeight` são usados para definir esses limites.

3. `Player::draw()`: Esta função desenha o jogador na tela. Ela define uma transformação de translação com base nas coordenadas `positionX` e `positionY`. Em seguida, ela define a cor preta (`glColor3f(0.0f, 0.0f, 0.0f)`) e desenha um quadrado usando `glBegin(GL_QUADS)` e `glVertex2f()` para definir os vértices do quadrado. Por fim, a transformação de translação é desfeita usando `glPopMatrix()`.

4. `Player::moveLeft()`: Esta função é chamada quando a tecla 'a' é pressionada. Ela decrementa a coordenada `positionX` do jogador com base na velocidade (`speed`), fazendo com que o jogador se mova para a esquerda.

5. `Player::moveRight()`: Esta função é chamada quando a tecla 'd' é pressionada. Ela incrementa a coordenada `positionX` do jogador com base na velocidade (`speed`), fazendo com que o jogador se mova para a direita.

6. `Player::moveUp()`: Esta função é chamada quando a tecla 'w' é pressionada. Ela decrementa a coordenada `positionY` do jogador com base na velocidade (`speed`), fazendo com que o jogador se mova para cima.

7. `Player::moveDown()`: Esta função é chamada quando a tecla 's' é pressionada. Ela incrementa a coordenada `positionY` do jogador com base na velocidade (`speed`), fazendo com que o jogador se mova para baixo.

8. `Player::getPositionX() const`: Esta função retorna a coordenada `positionX` atual do jogador.

9. `Player::getPositionY() const`: Esta função retorna a coordenada `positionY` atual do jogador.

10. `Input::KeyIsPressed(int key)`: Esta função verifica se uma tecla específica está pressionada. Ela recebe um código de tecla como parâmetro (`key`). Neste caso, ela usa a função `glutGet()` do GLUT para obter o estado das teclas de seta (`GLUT_KEY_UP`, `GLUT_KEY_DOWN`, `GLUT_KEY_LEFT` e `GLUT_KEY_RIGHT`). Se uma das teclas estiver pressionada, a função retorna `true`, caso contrário, retorna


**//score.cpp

1. `Score::Score()`: Este é o construtor da classe `Score`. Ele inicializa as variáveis de membro da classe, como `scoreValue` (valor do placar), `positionX` e `positionY` (posição do placar na janela) e `fontSize` (tamanho da fonte usada para exibir o placar).

2. `Score::increaseScore(int points)`: Esta função é chamada para aumentar o valor do placar. Ela recebe um parâmetro `points` que representa a quantidade de pontos a serem adicionados ao placar. Ela simplesmente adiciona esse valor ao `scoreValue`.

3. `Score::draw()`: Esta função desenha o placar na tela. Ela usa as funções do OpenGL para definir a projeção ortogonal (`glOrtho2D()`) e a matriz de modelo e visualização (`glMatrixMode()` e `glLoadIdentity()`). Em seguida, ela define uma transformação de translação com base nas coordenadas `positionX` e `positionY` do placar. A partir desse ponto, ela define a posição inicial para renderizar o texto (`glRasterPos2i(0, 0)`).

   Em seguida, ela cria uma string `scoreText` que contém o texto "Score: " seguido do valor atual do placar convertido em uma string (`std::to_string(scoreValue)`). A função então itera sobre cada caractere da string usando um loop `for`, e usa a função `glutBitmapCharacter()` para renderizar cada caractere na tela. A fonte usada é `GLUT_BITMAP_HELVETICA_18`, que é uma das fontes bitmap disponíveis no GLUT.

   

**//enemy.cpp

1. `Enemy::Enemy(Player& player)`: Este é o construtor da classe `Enemy`. Ele recebe uma referência para um objeto `Player` e inicializa as variáveis de membro da classe, como `positionX` e `positionY` (posição do inimigo na janela), `speed` (velocidade de movimento do inimigo), `width` e `height` (largura e altura do inimigo). O objetivo é armazenar a referência ao jogador para uso posterior, por exemplo, para verificar colisões com o jogador.

2. `Enemy::update()`: Esta função é responsável por atualizar o estado do inimigo. Ela atualiza a posição do inimigo adicionando a velocidade atual nas coordenadas `positionX` e `positionY`. A lógica de movimento ou comportamento do inimigo é implementada neste método. No exemplo fornecido, há um movimento aleatório implementado: em cada frame, há uma chance de 5% (5% de chance de 0 a 99) de o inimigo inverter a direção do movimento.

   Após atualizar a posição e o comportamento do inimigo, a função chama `checkCollision()` para verificar se houve uma colisão com o jogador.

3. `Enemy::checkCollision()`: Esta função verifica se houve uma colisão entre o inimigo e o jogador. Ela obtém as informações de posição, largura e altura do jogador usando os métodos apropriados fornecidos pela classe `Player`. Em seguida, ela verifica se há sobreposição entre as áreas retangulares delimitadas pelo inimigo e pelo jogador. Se houver uma colisão, é possível executar ações como diminuir a vida do jogador ou destruir o inimigo.

4. `Enemy::draw() const`: Esta função desenha o inimigo na tela. Ela usa as funções do OpenGL para definir a matriz de modelo e visualização (`glMatrixMode()` e `glLoadIdentity()`) e a transformação de translação com base nas coordenadas `positionX` e `positionY` do inimigo. A cor vermelha é definida com `glColor3f()` e, em seguida, um quadrado é desenhado usando `glBegin(GL_QUADS)` e `glVertex2f()`.

5. Funções auxiliares para obter informações do jogador: Essas funções são implementadas para obter informações específicas do jogador, como sua posição, largura e altura. Elas são usadas na função `checkCollision()` para obter as informações necessárias para verificar colisões com o jogador.


**//input.cpp

1. `Input::keyStates[256]` e `Input::specialKeyStates[256]`: Estas são duas variáveis estáticas que armazenam o estado de todas as teclas do teclado. Ambas são inicializadas com o valor `false`, indicando que nenhuma tecla está pressionada inicialmente. O tamanho de 256 é utilizado para abranger todas as teclas possíveis.

2. `Input::KeyboardKeyDown(unsigned char key, int x, int y)`: Esta função é chamada quando uma tecla comum do teclado é pressionada. Ela recebe o código da tecla pressionada, bem como as coordenadas do cursor no momento do evento. Nessa função, o estado da tecla correspondente no array `keyStates` é atualizado para `true`, indicando que a tecla está pressionada.

3. `Input::KeyboardKeyUp(unsigned char key, int x, int y)`: Esta função é chamada quando uma tecla comum do teclado é liberada (quando o usuário solta a tecla). Assim como a função anterior, ela recebe o código da tecla liberada e as coordenadas do cursor. Nessa função, o estado da tecla correspondente no array `keyStates` é atualizado para `false`, indicando que a tecla não está mais pressionada.

4. `Input::SpecialKeyDown(int key, int x, int y)`: Esta função é chamada quando uma tecla especial (como as teclas de função ou as setas direcionais) é pressionada. Ela recebe o código da tecla pressionada e as coordenadas do cursor. Nessa função, o estado da tecla especial correspondente no array `specialKeyStates` é atualizado para `true`, indicando que a tecla especial está pressionada.

5. `Input::SpecialKeyUp(int key, int x, int y)`: Esta função é chamada quando uma tecla especial é liberada. Ela recebe o código da tecla liberada e as coordenadas do cursor. Nessa função, o estado da tecla especial correspondente no array `specialKeyStates` é atualizado para `false`, indicando que a tecla especial não está mais pressionada.

6. `Input::KeyIsPressed(unsigned char key)`: Esta função verifica se uma tecla comum está pressionada. Ela recebe o código da tecla e retorna `true` se o estado da tecla correspondente em `keyStates` for `true`, indicando que a tecla está pressionada. Caso contrário, retorna `false`.

7. `Input::SpecialKeyIsPressed(int key)`: Esta função verifica se uma tecla especial está pressionada. Ela recebe o código da tecla especial e retorna `true` se o estado da tecla correspondente em `specialKeyStates` for `true`, indicando que a tecla especial está pressionada. Caso contrário, retorna `false`.

Essas funções são úteis para controlar e verificar o estado das teclas do teclado em um programa OpenGL/GLUT, permitindo que você responda aos eventos de pressionamento e liberação de teclas.

**#Classes

**//powerUp.h

1. Construtores:
   - `PowerUp()`: Construtor padrão que inicializa os membros da classe. Não recebe argumentos.
   - `PowerUp(const Player& player)`: Construtor que recebe um objeto `Player` como argumento. Inicializa os membros da classe e define o jogador associado a esse PowerUp.

2. Funções membros:
   - `void update()`: Atualiza a posição e o comportamento do PowerUp. Pode incluir lógica de movimento e interações com o jogador ou obstáculos.
   - `void draw() const`: Desenha o PowerUp na tela usando a biblioteca OpenGL. Utiliza as coordenadas de posição, o raio e outras propriedades para definir a aparência do PowerUp.

3. Membros da classe:
   - `float positionX`: A posição X do PowerUp.
   - `float positionY`: A posição Y do PowerUp.
   - `float speed`: A velocidade do PowerUp.
   - `float radius`: O raio do PowerUp.
   - `bool isActive`: Indica se o PowerUp está ativo.
   - `Player player`: O jogador associado a esse PowerUp.
   - `float width`: A largura do PowerUp.
   - `float height`: A altura do PowerUp.

**//player.h

1. Construtor:
   - `Player()`: Construtor padrão que inicializa os membros da classe. Não recebe argumentos.

2. Funções membros:
   - `void update(int windowWidth, int windowHeight)`: Atualiza a posição do jogador com base nas teclas pressionadas. Também limita o movimento do jogador dentro dos limites da janela especificada.
   - `void draw()`: Desenha o jogador na tela usando a biblioteca OpenGL. Define a aparência do jogador com base nas coordenadas de posição, largura e altura.
   - `void moveLeft()`: Move o jogador para a esquerda.
   - `void moveRight()`: Move o jogador para a direita.
   - `void moveUp()`: Move o jogador para cima.
   - `void moveDown()`: Move o jogador para baixo.
   - `bool collidesWith(const Enemy& enemy) const`: Verifica se o jogador colide com um objeto Enemy específico. Retorna `true` se houver colisão, caso contrário, retorna `false`.

3. Funções membros getter:
   - `float getX() const`: Retorna a coordenada X atual do jogador.
   - `float getY() const`: Retorna a coordenada Y atual do jogador.
   - `float getWidth() const`: Retorna a largura do jogador.
   - `float getHeight() const`: Retorna a altura do jogador.

4. Membros da classe:
   - `float positionX`: A posição X do jogador.
   - `float positionY`: A posição Y do jogador.
   - `float speed`: A velocidade de movimento do jogador.
   - `float width`: A largura do jogador.
   - `float height`: A altura do jogador.


**//score.h

1.A classe `Score` possui membros públicos para as funções `increaseScore()` e `draw()`, que são responsáveis por aumentar a pontuação e desenhar a pontuação na tela, respectivamente.

2. Os membros privados da classe incluem variáveis para armazenar o valor da pontuação (`scoreValue`), a posição X e Y para o desenho da pontuação (`positionX` e `positionY`) e o tamanho da fonte (`fontSize`). 
Além disso, há uma indicação de que pode haver outras variáveis e métodos relacionados à pontuação, mas eles não estão explicitamente definidos no código compartilhado.

**//enemy.h

1. Construtor:
   - `Enemy(Player& player)`: Construtor que recebe uma referência para um objeto `Player`. Essa referência é armazenada no membro `player` da classe `Enemy`.

2. Funções membros:
   - `void update()`: Atualiza a posição do inimigo. Pode incluir lógica de movimento ou comportamento do inimigo.
   - `void draw() const`: Desenha o inimigo na tela usando a biblioteca OpenGL. Define a aparência do inimigo com base nas coordenadas de posição, largura e altura.
   - `void checkCollision()`: Verifica se há colisão entre o inimigo e o jogador (`Player`). Pode executar uma ação específica quando ocorre colisão.

3. Funções membros getter:
   - `float getPlayerPositionX() const`: Retorna a coordenada X atual do jogador.
   - `float getPlayerPositionY() const`: Retorna a coordenada Y atual do jogador.
   - `float getPlayerWidth() const`: Retorna a largura do jogador.
   - `float getPlayerHeight() const`: Retorna a altura do jogador.

4. Membros da classe:
   - `Player& player`: Referência para um objeto `Player`.
   - `float positionX`: A posição X do inimigo.
   - `float positionY`: A posição Y do inimigo.
   - `float speed`: A velocidade de movimento do inimigo.
   - `float width`: A largura do inimigo.
   - `float height`: A altura do inimigo.

**//input.h

1. Funções membros estáticas:
   - `static bool KeyIsPressed(int key)`: Verifica se uma tecla específica está pressionada. Recebe como parâmetro o código da tecla e retorna um valor booleano indicando se a tecla está pressionada ou não.
   - `static void KeyboardKeyDown(unsigned char key, int x, int y)`: Chamada quando uma tecla do teclado é pressionada. Recebe como parâmetros o código da tecla pressionada e as coordenadas do mouse no momento do evento.
   - `static void KeyboardKeyUp(unsigned char key, int x, int y)`: Chamada quando uma tecla do teclado é liberada. Recebe como parâmetros o código da tecla liberada e as coordenadas do mouse no momento do evento.
   - `static void SpecialKeyDown(int key, int x, int y)`: Chamada quando uma tecla especial do teclado é pressionada. Recebe como parâmetros o código da tecla especial pressionada e as coordenadas do mouse no momento do evento.
   - `static void SpecialKeyUp(int key, int x, int y)`: Chamada quando uma tecla especial do teclado é liberada. Recebe como parâmetros o código da tecla especial liberada e as coordenadas do mouse no momento do evento.

**//Compilando e Rodando no Linux

Cpmpilando: **g++ -o programa main.cpp enemy.cpp player.cpp powerUp.cpp score.cpp -lGL -lGLU -lglut

Rodando: **./programa
