

 
# Text RPG
 
  Authors: [Anna Jimerson](https://github.com/pinacoladakitten), 
[Madelyn Ritchie](https://github.com/madiritc0), 
[Alex Nguyen](https://github.com/AlexPNguyen414), 
[Andrew Whitfield](https://github.com/aewhitfield90) 
 
 
## Project Description
Our Text RPG will mimic original text base style Role Playing Games.  
Our choice was based on having fun while learning skills introduced in this course.  
We will be writing our Text RPG in C++ and use Github to collaborate our work as a team.  
>	* C++  

Input will involve keyboard entries from the player. Output will move the Role Playing Game in the direction of the player's choices. This output will be shown in console as a progressing text story. There will be random enemy encounters, loot to be won, and choices made by the player will change the outcome of their success.  
   

## Class Diagram (Updated Final)
![UML](https://github.com/cs100/final-project-ajime038-awhit078-mritc003-nnguy414/blob/fb4660f18568b5f19425e96618c2f444f0ad7e32/Final%20Game%20Project%20UML.png)

**The TextLog class** is what writes everything to the console as it is a text-based RPG. This will handle anything related to writing.

**The BaseCharacter class** is the base/interface for ALL characters: enemies, the player, npc's, etc; This holds everything that a character should have and 
each class inheriting from it has their own method of "CharacterTurn", so for instance the Player would select commands from what they have, while enemies would
randomly select an attack. All characters have an Inventory to work with too.

**The Inventory class** holds all possible Actions a character can do base on what they have, whether it's Attack, Magic, or using an Item, they're all actions that can be done. Each 
subclass of Action has it's own vector just so things are separated when selecting things.

**The BaseAction class** is the base/interface for all possible Actions in the game. All actions from enemies or the player derive from this class. Each action also has
an '*onUseText'* variable which displays what happens upon being used. Attack classes are basic attacks which deal physical damage, Items have ItemCounts which give limtited
uses, and the SpecialMagic class handles all magic or special attacks..

For our project we'ved decided to go with the Strategy Pattern because in our project we've ended up having multiple contexts which each needed
their own strategy. For instance, the Actions that each character can do all need their own strategy since they all do different things. For,
example Items have an Item Count, Special Attacks use the character's mana, and each specific Action basically does their own thing. Then each
character can hold these actions through their Inventory pointers. The Strategy Pattern was basically necessary to make each classes easily extendable,
and to properly follow solid principles, and we're sure that this structure will make development on actual content a lot easier and efficient.
 
 
 ## Screenshots
 ![UML](https://github.com/cs100/final-project-ajime038-awhit078-mritc003-nnguy414/blob/fb4660f18568b5f19425e96618c2f444f0ad7e32/TextRPG1.png)
 ![UML](https://github.com/cs100/final-project-ajime038-awhit078-mritc003-nnguy414/blob/fb4660f18568b5f19425e96618c2f444f0ad7e32/TextRPG1.png)
 ![UML](https://github.com/cs100/final-project-ajime038-awhit078-mritc003-nnguy414/blob/fb4660f18568b5f19425e96618c2f444f0ad7e32/TextRPG2.png)
 ![UML](https://github.com/cs100/final-project-ajime038-awhit078-mritc003-nnguy414/blob/fb4660f18568b5f19425e96618c2f444f0ad7e32/TextRPG3.png)
 ![UML](https://github.com/cs100/final-project-ajime038-awhit078-mritc003-nnguy414/blob/fb4660f18568b5f19425e96618c2f444f0ad7e32/TextRPG4.png)
 ![UML](https://github.com/cs100/final-project-ajime038-awhit078-mritc003-nnguy414/blob/fb4660f18568b5f19425e96618c2f444f0ad7e32/TextRPG5.png)
 ![UML](https://github.com/cs100/final-project-ajime038-awhit078-mritc003-nnguy414/blob/fb4660f18568b5f19425e96618c2f444f0ad7e32/TextRPG6.png)
 ## Installation/Usage
 - Instructions for Running Text RPG
 - Run the Text RPG game
 - The Text RPG will prompt you to input a number for the Hero's choice
 - Your choices will determine if the Hero defeats their enemy and stays alive
 - Defeating the boss will complete the game
 - Losing all Health Points will lose the game
 ## Testing
 - Unit testing
 - Valgrind

