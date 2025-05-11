import pygame
import sys
import time

def tower_of_hanoi(n, source, auxiliary, target):
    if n == 1:
        moves.append((source, target))
        return
    tower_of_hanoi(n - 1, source, target, auxiliary)
    moves.append((source, target))
    tower_of_hanoi(n - 1, auxiliary, source, target)

def draw_towers():
    screen.fill(BACKGROUND_COLOR)
    for tower in towers:
        pygame.draw.rect(screen, (200, 200, 200), (tower - 5, 100, 10, 350))
    pygame.draw.rect(screen, (150, 75, 0), (50, 450, 700, 20))  # Chân đế
    step_text = font.render(f"Buoc: {steps}", True, (255, 255, 255))
    screen.blit(step_text, (10, 10))
    disk_text = font.render(f"So dia: {num_disks}", True, (255, 255, 255))
    screen.blit(disk_text, (10, 40))
    delay_text = font.render(f"Toc do: {move_delay:.1f}s", True, (255, 255, 255))
    screen.blit(delay_text, (10, 70))
    pygame.draw.rect(screen, (0, 255, 0), start_button)
    pygame.draw.rect(screen, (255, 0, 0), reset_button)
    pygame.draw.rect(screen, (0, 0, 255), increase_disk_button)
    pygame.draw.rect(screen, (0, 0, 255), decrease_disk_button)
    pygame.draw.rect(screen, (0, 0, 255), increase_speed_button)
    pygame.draw.rect(screen, (0, 0, 255), decrease_speed_button)
    start_text = font.render("Start", True, (0, 0, 0))
    reset_text = font.render("Reset", True, (0, 0, 0))
    inc_disk_text = font.render("+D", True, (255, 255, 255))
    dec_disk_text = font.render("-D", True, (255, 255, 255))
    inc_speed_text = font.render("+S", True, (255, 255, 255))
    dec_speed_text = font.render("-S", True, (255, 255, 255))
    screen.blit(start_text, (start_button.x + 10, start_button.y + 5))
    screen.blit(reset_text, (reset_button.x + 10, reset_button.y + 5))
    screen.blit(inc_disk_text, (increase_disk_button.x + 10, increase_disk_button.y + 5))
    screen.blit(dec_disk_text, (decrease_disk_button.x + 10, decrease_disk_button.y + 5))
    screen.blit(inc_speed_text, (increase_speed_button.x + 10, increase_speed_button.y + 5))
    screen.blit(dec_speed_text, (decrease_speed_button.x + 10, decrease_speed_button.y + 5))
    for i, stack in enumerate(stacks):
        for j, disk in enumerate(stack):
            disk.draw(towers[i], HEIGHT - (j + 1) * 25 - 50)
    pygame.display.flip()

def move_disk(source, target):
    global steps
    if stacks[source]:
        disk = stacks[source].pop()
        stacks[target].append(disk)
        steps += 1
        draw_towers()
        time.sleep(move_delay)

def reset_game():
    global stacks, steps, moves
    stacks.clear()
    stacks.extend([[] for _ in range(3)])
    for i in range(num_disks, 0, -1):
        stacks[0].append(Disk(i, disk_colors[i % len(disk_colors)]))
    steps = 0
    moves.clear()
    draw_towers()

def start_game():
    global moves, steps
    moves.clear()
    steps = 0
    draw_towers()
    tower_of_hanoi(num_disks, 0, 1, 2)
    for move in moves:
        move_disk(move[0], move[1])

def adjust_disks(change):
    global num_disks
    num_disks = max(1, min(7, num_disks + change))
    reset_game()

def adjust_speed(change):
    global move_delay
    move_delay = max(0.1, move_delay + change)
    draw_towers()

class Disk:
    def __init__(self, size, color):
        self.size = size
        self.color = color
    def draw(self, x, y):
        pygame.draw.rect(screen, self.color, (x - self.size * 20, y, self.size * 40, 20))

pygame.init()
WIDTH, HEIGHT = 800, 500
BACKGROUND_COLOR = (50, 50, 50)
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Tower of Hanoi")
font = pygame.font.Font(None, 36)
towers = [WIDTH // 4, WIDTH // 2, 3 * WIDTH // 4]

disk_colors = [(255, 0, 0), (0, 255, 0), (0, 0, 255), (255, 255, 0), (255, 165, 0), (128, 0, 128), (0, 255, 255)]
num_disks = 3
move_delay = 0.5
steps = 0
stacks = [[] for _ in range(3)]
for i in range(num_disks, 0, -1):
    stacks[0].append(Disk(i, disk_colors[i % len(disk_colors)]))

moves = []
start_button = pygame.Rect(600, 50, 80, 40)
reset_button = pygame.Rect(600, 100, 80, 40)
increase_disk_button = pygame.Rect(700, 50, 50, 40)
decrease_disk_button = pygame.Rect(700, 100, 50, 40)
increase_speed_button = pygame.Rect(700, 150, 50, 40)
decrease_speed_button = pygame.Rect(700, 200, 50, 40)

draw_towers()

running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        elif event.type == pygame.MOUSEBUTTONDOWN:
            if start_button.collidepoint(event.pos):
                start_game()
            elif reset_button.collidepoint(event.pos):
                reset_game()
            elif increase_disk_button.collidepoint(event.pos):
                adjust_disks(1)
            elif decrease_disk_button.collidepoint(event.pos):
                adjust_disks(-1)
            elif increase_speed_button.collidepoint(event.pos):
                adjust_speed(0.1)
            elif decrease_speed_button.collidepoint(event.pos):
                adjust_speed(-0.1)
pygame.quit()
sys.exit()
