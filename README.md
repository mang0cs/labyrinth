# Labyrinth Game
ANSI C program to view a recorded session of labyrinth, an abstract strategy game.
# Gameplay 
- When the game starts, each player places a token, a choice between a tortoise and a hare, in the center of their base line. Each player in turn, chooses to either move their animal or to put up a fence. A total of 8 fences are available per player. The tortoise always starts first.
- The animals are moved one square at a time, horizontally or vertically, forwards or backwards, never diagonally.
- A fence must be placed between 2 sets of 2 squares either horizontally or vertically. Fences may touch one another but may not overlap or fall on top of one another nor may the fences stick off the edge of the board. The fences can be used to facilitate the player's progress or to impede that of the opponent. The animals must move around the fences.
- When placing fences, a player must always leave an access for the opponent to reach their goal line. A player may accidentally block themselves off from their goal but that is not an illegal move.
- When the two animals face each other on neighboring squares which are not separated by a fence, the player whose turn it is can jump the opponent's animal, thus advancing an extra square.
- If there is a fence behind the opponent's animal, the player can place their own animal to the left or the right of the other animal.
