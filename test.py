import pygame
import threading
import time
import random

# Definiciones de colores
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
RED = (255, 0, 0)
GREEN = (0, 255, 0)

# Dimensiones de la pantalla
SCREEN_WIDTH = 800
SCREEN_HEIGHT = 600

# Tamaño de la cuadrícula del laberinto
GRID_SIZE = 20

# Tamaño del laberinto
MAZE_WIDTH = SCREEN_WIDTH // GRID_SIZE
MAZE_HEIGHT = SCREEN_HEIGHT // GRID_SIZE

# Clase para representar al personaje
class Player:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def move(self, dx, dy):
        if 0 <= self.x + dx < MAZE_WIDTH and 0 <= self.y + dy < MAZE_HEIGHT:
            self.x += dx
            self.y += dy

# Clase para representar al monstruo
class Monster:
    def __init__(self):
        self.x = random.randint(0, MAZE_WIDTH - 1)
        self.y = random.randint(0, MAZE_HEIGHT - 1)

    def move(self):
        dx = random.choice([-1, 0, 1])
        dy = random.choice([-1, 0, 1])

        if 0 <= self.x + dx < MAZE_WIDTH and 0 <= self.y + dy < MAZE_HEIGHT:
            self.x += dx
            self.y += dy

# Función para dibujar el laberinto
def draw_maze(screen):
    screen.fill(WHITE)
    for x in range(0, SCREEN_WIDTH, GRID_SIZE):
        pygame.draw.line(screen, BLACK, (x, 0), (x, SCREEN_HEIGHT))
    for y in range(0, SCREEN_HEIGHT, GRID_SIZE):
        pygame.draw.line(screen, BLACK, (0, y), (SCREEN_WIDTH, y))

# Función para dibujar el jugador
def draw_player(screen, player):
    pygame.draw.rect(screen, GREEN, (player.x * GRID_SIZE, player.y * GRID_SIZE, GRID_SIZE, GRID_SIZE))

# Función para dibujar el monstruo
def draw_monster(screen, monster):
    pygame.draw.rect(screen, RED, (monster.x * GRID_SIZE, monster.y * GRID_SIZE, GRID_SIZE, GRID_SIZE))

# Hebra para controlar el movimiento del monstruo
def monster_thread(monster, maze_lock):
    while True:
        # Bloquear el laberinto para evitar colisiones
        maze_lock.acquire()
        monster.move()
        maze_lock.release()
        time.sleep(0.5)

def main():
    pygame.init()
    screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
    pygame.display.set_caption("Laberinto con hebras y semáforos")

    player = Player(1, 1)
    monster = Monster()

    maze_lock = threading.Lock()

    monster_t = threading.Thread(target=monster_thread, args=(monster, maze_lock))
    monster_t.start()

    clock = pygame.time.Clock()

    running = True
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_UP:
                    player.move(0, -1)
                elif event.key == pygame.K_DOWN:
                    player.move(0, 1)
                elif event.key == pygame.K_LEFT:
                    player.move(-1, 0)
                elif event.key == pygame.K_RIGHT:
                    player.move(1, 0)

        # Bloquear el laberinto para evitar colisiones
        maze_lock.acquire()
        screen.fill(WHITE)
        draw_maze(screen)
        draw_player(screen, player)
        draw_monster(screen, monster)
        maze_lock.release()

        pygame.display.flip()
        clock.tick(60)

    pygame.quit()

if __name__ == "__main__":
    main()
3