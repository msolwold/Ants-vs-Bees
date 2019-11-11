# Ants-vs-Bees
Lab 5; CS361

 ***Assignment 5 Polymorphism through Ants vs. Some Bees***
 
Based on the game Plants vs. Zombies and adapted from a similar assignment presented as a Nifty Assignment at SIGCSE 2014, Ants vs. Some Bees is a tower defense game. The player controls the ant colony and must defeat the bees. If the bees get to the queen, the bees win the game. If all bees are defeated from the game, then the ants win.
Game Setup
The game is played on a one-dimensional board of size 10. The queen ant resides on the left side of the board while the hive where the bees are generated resides on the right side. The ant colony will begin with a food bank of 50. Multiple insects may reside on a square of the board.

**Game Play**

Five things happen each turn:
1. A bee is generated on the right side of the board.
2. The player can generate an ant and place it anywhere on the board.
3. The ants attack the bees. (Order of ant attacks occur left to right).
4. The bees either attack an ant (order of attack is left to right) which is blocking them or pass through to the next square on the board if they are not blocked by an ant.
5. Check to see if the bees have reached the queen or if there are any bees left in play, declare a winner and end the game if either condition is true.
The game continues so long as there are bees on the board at the end of the turn and they have not reached the queen.

*Bee Details*

Bees are the insect adversaries in this game. They have an armor of 3 when they are generated. They try to move one square, right to left, on the board each turn. The bee cannot move a square if it occupies a square with an ant. The ant must be killed before the bee can move. Multiple bees may occupy a square. If multiple bees occupy a square, and the first bee kills the ant, then all other bees on the square (not including the bee who killed the ant) may proceed forward during that turn. When a bee attacks an ant, it inflicts 1 damage.

*Ant Details*

There are multiple kinds of ants. All ants have an initial food cost that is incurred when they are placed on the board. All ants have armor, but the armor value varies per ant. Once ants are placed, they are fixed to that location while they live. A new ant may be generated and placed each turn, food bank permitting. An ant may be placed on any square including those occupied by a bee. An ant may not share a square with another ant unless the other ant is a bodyguard. The following table outlines the different ants:

| Ant | Food Cost | Armor | Action |
| --- | --- | --- | --- |
| Harvester | 2 | 1 | Adds one food to the colony each turn that it lives |
| Thrower | 4 | 1 | Throws a leaf at one bee sharing its square and inflicts 1 damage to that bee. |
Fire | 4 | 1 | Upon the death of this ant (when armor is zero or less), it reduces all armor values of bees on the same square to zero. |
Long Thrower | 3 | 1 | Inflicts 1 damage on each bee which is closest to it but at least 4 squares away. |
Short Thrower | 3 | 1 | Inflicts damage on each bee which is closest to it but no more than 2 squares away. |
Wall | 4 | 4 | Occupies a space to block the bees. Cannot attack bees. |
Ninja | 6 | 1 | Cannot block bees and bees cannot attack the ninja. Bees pass by the ninja and incur 1 damage. |
Bodyguard | 4 | 2 | The only ant which may occupy another square which has an ant on it. The bodyguard will be the ant to incur the damage from any bee which also occupies the square. When the bodyguard ant dies, the next bee attack will hit the other ant on the square. There can only be one bodyguard on a square. |

**Requirements**

- The program must run to the above specified requirements in their entirety. A readable and understandable user interface must be present.
- Classes must be used.
- Inheritance must be used, demonstrating the use of base and child classes.
- Appropriate use of the Big 3. Polymorphism must be used.
- Files must be separated.
- A functioning Makefile must be provided. No memory leaks.
- No functions greater than 20 lines.
- Vectors are permitted on this assignment, the <algorithms> library is not.
