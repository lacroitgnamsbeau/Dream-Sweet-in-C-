# Dream-Sweet-in-C++
# TASK-TRACK RPG

Members: Calvin Pugay, Mai Thao, Louise Santos

This will be our github repository for the project in CSCE A201.

DUE DATES: 
  October 28 - Group Name and Project Idea
  December 1 - Final Day to Submit

I divided the flow of the project into 5 weeks.

Concept: Task-Track RPG

Basically the user will name their task, assign a level of difficulty on it (Maybe 1-3 or 1-5?), and add a timer on it.
Should we give the player a choice to pause and unpause the timer? Need some input on this.
After that, we can input some base values on different difficulties of stages, bosses, etc.
The task priority will serve as an additional multiplier for the player's base damage.

Some weapon items could be:
  1. Pencil
  2. Sharpener
  3. Eraser
  4. Some stationery stuff or whatever
We can add some skills to those weapons too like
  1. Pencil - Skill: Stab
  2. Sharpener - Skill: Enhances attack and crit chance for a limited amount of time
  3. Eraser - Skill: Nullify incoming damage for a limited amount of time

Execution (subject to change, just rough ideas):
  1. Task name - string user input
  2. Difficulty - integer user input
  3. Timer - find out how to make a timer (pause/unpause function is optional)
  4. Fail/Succeed task - probably a bool value, user says if task was failed or succeeded, failed if time runs out
  5. Skill points - Gained if task success, lost/no gain if task failed (amount based on difficulty?)
  6. Attributes - multiple int variables (attack, defense, agility, or even weapon stats)
  7. Weapons/armor/special - Weapons can increase/multiply attack, armor increases/multiplies defense, special abilities do other things to skills
  8. Stages/Bosses: Checks if certain attributes are met. User passes if attributes are met, user fails if attributes are not met.
