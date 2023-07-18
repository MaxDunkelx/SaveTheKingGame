OOP1 – project – Save the King
Max Dunkel:

Game description:
The mission of the game is to guide the king through the levels to the throne.
The user controls 4 characters: King, Mage, Warrior and Thief.
Each character has unique skills:
King – only the king can sit on the throne and finish the level or the game.
Mage – can extinguish fire permanently.
Warrior – kills Orcs and Dragons (the dragon once killed drops key). 
Thief – pick up key (can store 1 key at a time) and open gates to pass through the level.
Design:
The basic class is GameObj, which gives to all static and movable objects. 
The Controller is the game manager, start the game and managing all the Continuity/progress of the game. The game loads the levels from generic files names (making it easy to add levels) and insert them to the Board members.  The Board, held in the Controller, holds the game objects and responsible for most of the game actions, such as movement, adding new objects, collisions etc.

List of class:
Board – class to store and manage board of the game, holds all the entities of the game.
Controller – class that run and manage the game.
Gate – opened when collides with thief that holds key.
Fire – plain fire.
GameObject – all entities come from here & sprite members.
macros (no cpp) – holds all the game consts.
Menu - Class of the game menu, loads button:start, help, exit.
Movable - all mobile objects come from here.
King – character of the game and his movements.
Mage – character of the game and his movements.
Warrior – character of the game and his movements.
Thief – character of the game and his movements.
StaticObjects – all immobile objects come from here.
Gamestats – to display the game stats.
Textures - textures singleton resource.
Text – setting in game text.
Wall - still wall object.
Dragon – static enemy.
Dwarf – enemy that chases the king character (using dynamic cast).
Orc – randomly moving enemy.
Enemy – draws all kinds of enemies.
Gifts - gives bonuses like adding time to game level time or making the all dwarfs disappear or give fine by reducing time from game level time.
Key – key object appears in the same spot dragon was killed.
Level – loading level from file and storing vectors of all game objects.
Music - sound singleton resource.
Teleport – holds collision of teleports with moving objects. 
Throne – object that ends the level.
 
Main data structures:
Vectors of unique_ptr – to store all entities.
Maps – for the Textures & Sounds.

Notable algorithms:
Basic physics-based Movement algorithm for the moveable.
Enemy change direction (up/down/left/right).
Enemy moving towards the king character.
The game collision method is Double Dispatch collision.
Finding and sending character between the closest 2 teleports 
Known bugs:
Unknown.
Other comments:
We created a dragon object for spawning a key after warrior character collides with it because it’s a static object and not movable object like the orc.

