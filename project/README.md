# Otherworld Runner
#### Video Demo: https://youtu.be/N5eFmhKdcYs

#### Control:
Space   : Jump (in game) or start game (only in the menu screen)\
P       : Toggle music off (only in the menu screen)

#### Description:
CS50P Project mainly utilizing the pygame library\
You control a player who can jump twice, one big and another one small jump.\
Your score will be displayed on the top.\
The higher the score, the faster enemy will move, as well as more frequent spawn. Similar to Chrome dinosaur game.\
Also similar to Chrome dinosaur, there are two enemies in the game: snail and fly.\
\
You have 3 lifes, everytime you collide with the enemy you lose one life.\
When collision happens, every enemy will be deleted (this is to ensure no immediate loss of consecutive collisions).\
As a general rule of thumb, to avoid snails, stay on the ground or double jump to avoid fly.
When all 3 lifes are lost, the game ends and your score will be displayed.




Run to the otherworld!!!.

#### Files:
You can run an executable file located at dist folder.
This was an executable of project.py that was created using pyinstaller module
The project.py file is the main bulk of the program, containing the the class of Player and Object, as well as the game logic.
The file test_project.py is the test file project.
Then the rest of the file is resources such as sprites, audio and font.
For this program to run, you need to install pygame library in your system.





#### Credits:
Most of the graphics and music can be found here:
https://opengameart.org/content/5-chiptunes-action
https://opengameart.org/content/platformer-art-pixel-edition
Additionally, huge thanks to Clear Code who provided Clear Guide for pygame.
