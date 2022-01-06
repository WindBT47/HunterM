# HunterM

## Table of Contents

- [Background](#background)
- [Usage](#usage)

## Background

This is a project for learning UE4. This project contains TPS, AI, WallRun, and random maps. But because it's a learning project, it doesn't have some UIs and features. And some code is a little bit rough. And hastily developed the WallRun feature with the Blueprint.

## Usage

Here are some introductions about the features in this project.

### WallRun
![avatar](https://github.com/WindBT47/MarkdownPhotos/blob/master/Pic_HunterM/wallRun1_s.gif)

![avatar](https://github.com/WindBT47/MarkdownPhotos/blob/master/Pic_HunterM/wallRun2_s.gif)

![avatar](https://github.com/WindBT47/MarkdownPhotos/blob/master/Pic_HunterM/wallRun3_s.gif)
### GoCartMovementComponent.cpp&h

This component is inherited from UActorComponent, and it controls the movement of the vehicle. It has a USTRUCT named FGoCartMove to generalize the state of the vehicle. This class is base on classical physics. The force of the vehicle is the sum of the air resistance, rolling resistance, and the push force from the controller. And then calculate the rotation and the offset by mathematics with the velocity.

### GoCartMovementReplicator.cpp&h

This component is inherited from UActorComponent, and it controls the synchronization of the server and the client. This one is implemented by interpolation like Hermite cubic spline.
# HunterM

MY FPS GDD - HUNTM  
Project Description :  
  This game design document describes the details for a multi-platform FPS game with cool mechanics and characters.  
  It plays like Doom but introduces the action element.  
  The game's name is HunterM.  

1. Characters :
   HunterM is the main character. HunterM is an exile who wandering between the planets. He has to be a killing machine when landing on the planets to get the energy
   Different planets are living with different races. Different races have a different bosses.

2. Theme :
   Hunt all the races.

3. Story Progression :
   The game starts with a short intro scene where HunterM's spaceship is falling. Then HunterM gets out of the spaceship to explore the planet and the first chapter begins.
   The first chapter is the Tutorial. It can't be skipped. The player will learn to hunt on this level.

4. Gameplay :  
   4.1. Goals :  
   Overall(long term): Help HunterM get the energy and stuff.  
   Gameplay(short term): Defeat enemies. Enhance equipment and weapons.  
   4.2. User Skills :  
   Move the mouse.  
   Move the main character.  
   Enhance equipment and weapons.  
   Manage resources.  
   Strategize.  
   4.3. Game Mechanics :  
   HunterM is a single-player game.  
   Killing faster is the most critical mechanics.  
   4.4. Items and Power-ups  
   With different types of equipment, HunterM has different fighting styles. Move faster, move silently, heavy armor or...  
   For example, the player can put on jet-propelled equipment and shuttle between crowds.  
   4.5. Progression and challenge  
   The difficulty will advance by making enemies harder. To mitigate difficulty, the player has to enhance equipment and weapons versus play better.  
   Each planet drops some different items for enhancing the spaceship. Then the player can get to the new planet to fight new enemies.  
   4.6. Losing  
   These are losing conditions: died, losing by running out of spaceship's energy.  

5. Art Style
   This is a 3D game, with medium quality 3D modes. The atmosphere should be darkness. Everything should be colorful and feel alive.

6. Music and Sounds
   The music should have an Electronic rock style. A lot of sound effects must praise the player when he does something good. There should be immediate and positive feedback
   When in killing the music should be crazy. When HunterM in low health, add a sound that makes the player feel nervous.

7. Technical Description
   Initially, the game will be the PC platform. Follow with XBOX series X and PS5 version.
   For project development using Unreal Engine 4. Use Git for storing code and assets.

CONTINUED......
