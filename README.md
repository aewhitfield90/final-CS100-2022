

 
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
   

 > ## Phase II
 > In addition to completing the "Class Diagram" section below, you will need to:
 > * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Create smaller actionable development tasks as issues and assign them to team members. Place these in the `TODO` column.
 >   * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA
 > * Schedule two check-ins using Calendly. You need to pick both time slots during your lab on week 8. Your entire team must be present for both check-ins.
 >   * The first check-in needs to be scheduled with your lab TA. During that meeting, you will discuss your project design/class diagram from phase II.
 >   * The second check-in should be scheduled with a reader. During that meeting you will discuss:
 >     * The tasks you are planning for the first sprint
 >     * How work will be divided between the team members

## Class Diagram (Updated)
![UML](https://github.com/cs100/final-project-ajime038-awhit078-mritc003-nnguy414/blob/0359c1792bc91721122733ba8ad8419aa2e381ef/Really%20Final%20Game%20Project%20UML.png)
**The GameSystem class** simply handles which scene we are currently in which everything in the game can read from. This class also stores the main TextLog
class which everything else in the game can write to as events occur.

**The TextLog class** is what writes everything to the console as it is a text-based RPG. This will handle anything related to writing.

**The SceneHandler class** is the base class/interface for all of the scene types, e.g. Story Scenes or Combat Scenes. These classes all handle the events in
the game which take place and their specific dialogue will be read from a file which contains text for the scene to write to the TextLog. Scenes are then linked
through a pointer to the next scene. The **StoryHandler class** is mainly made for handling normal story events, which usually only involves printing text. While 
the **CombatHandler class** should have a default implementation of the *'combat loop'* since it would basically be the same for all combat scenarios, the only
thing actually changing in them is the *'characterTurnList'* which will go through each character's turn.

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
 
 > Include a **class diagram(s)** for your project and a **description** of the diagram(s). Your class diagram(s) should include all the main classes you plan for the project. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper UML notation (as discussed in the course slides).
 
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with a reader (using Calendly). Your entire team must be present. This meeting will occur on week 8 but NOT during lab time.
 > * Before the meeting you should perform a sprint plan like you did in Phase II.
 > * You should also update this README file by adding the following:
 >   * What design pattern(s) did you use? For each pattern you must explain in 4-5 sentences:
 >     * Why did you pick this pattern? And what feature did you implement with it?
 >     * How did the design pattern help you write better code?
 >   * An updated class diagram that reflects the design pattern(s) you used. You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description).
 >   * Make sure your README file (and Project board) are up-to-date reflecting the current status of your project. Previous versions of the README file should still be visible through your commit history.
> 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the TA/reader during lab time. The TA/reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
 Instructions for Running Text RPG
 Run the Text RPG game
 The Text RPG will prompt you to input a number for the Hero's choice
 Your choices will determine if the Hero defeats their enemy and stays alive
 Defeating the boss will complete the game
 Losing all Health Points will lose the game

 How Text RPG was tested:
 - Unit testing
 - Valgrind
