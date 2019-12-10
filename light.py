import serial, pyaudio, wave, time, sys, pygame, random
from pygame.locals import*

#screen
def get_rand_color():
        color_r = random.randint(0,255)
        color_g = random.randint(0,255)
        color_b = random.randint(0,255)
        return (color_r, color_g, color_b)

def lightshow():
        pygame.init()
        pygame.mixer.init()
        
        screen = pygame.display.set_mode((400,400), pygame.FULLSCREEN)

        clock = pygame.time.Clock()
        pygame.mouse.set_visible(False)

        done = False
        counter = 0
        color = get_rand_color()
        
        # play a song
        sounda= pygame.mixer.Sound("FunkyTown.wav")
        sounda.play()
        
        # flash colors on the screen
        while not done:
                counter += 1
                if counter > 3:
                    color = get_rand_color()
                    counter = 0
                    screen.fill(color) 
                    pygame.display.flip()
                    clock.tick(10)
                for event in pygame.event.get():
                    if event.type == pygame.QUIT:
                        done = True
                    elif event.type == KEYDOWN:
                        if event.key == K_ESCAPE:
                            pygame.quit()
                            return
        return

while True:
        lightshow()   
        break
