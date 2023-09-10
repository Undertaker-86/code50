import emoji

emo = input("What's your emoji: ")

print(emoji.emojize(emo))

from pyfiglet import Figlet
f = Figlet(font='slant')
print f.renderText('text to render')