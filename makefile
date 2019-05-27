###############################################################
# Program:
#     Project 09, Skeet
#     Brother Alvey, CS165
# Author:
#     Adam Tipton
# Summary:
#     This is the Skeet project. It similates skeet shooting. 
# Above and Beyond
#     1. I added a console prompt that allows the user to verify
#	  a bird was launched and what type.
#     2. I added the words "PULL" to the top of the screen
#     that display everytime a bird is drawn.
#     3. I created a SpecialBird (LunarLander) that is faster,
#     has thrusters(FAST) activated, and gives more points for 
#     killing it.
#     4. I changed the probability of which bird gets created.
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: driver.o game.o uiInteract.o uiDraw.o point.o rifle.o birds.o flyingObject.o  velocity.o bullet.o
	g++ driver.o game.o uiInteract.o uiDraw.o point.o rifle.o birds.o flyingObject.o  velocity.o bullet.o $(LFLAGS)

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h point.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

game.o: game.cpp uiDraw.h uiInteract.h point.h velocity.h rifle.h bullet.h birds.h
	g++ -c game.cpp

driver.o: game.h uiInteract.h driver.cpp
	g++ -c driver.cpp

rifle.o: rifle.h point.h uiDraw.h rifle.cpp
	g++ -c rifle.cpp

#######################################################################
# ADD YOUR ADDITIONAL RULES HERE!
#
# Then, don't forget to add them to the dependecy list for a.out above.
#######################################################################
birds.o: birds.h birds.cpp flyingObject.h uiDraw.h
	g++ -c birds.cpp

flyingObject.o: flyingObject.h flyingObject.cpp point.h velocity.h
	g++ -c flyingObject.cpp

velocity.o: velocity.h velocity.cpp point.h
	g++ -c velocity.cpp

bullet.o: bullet.h bullet.cpp flyingObject.h point.h velocity.h uiDraw.h
	g++ -c bullet.cpp

###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o
