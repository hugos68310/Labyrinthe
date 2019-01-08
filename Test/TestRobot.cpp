#include "doctest.h"
#include "Robot.h"
#include <fstream>
#include <iostream>
#include <Maps.h>


TEST_CASE("Les mouvements du robot fonctionnent"){
	maps* m = new maps("map1.txt", new game{"map1.txt"});
	robot r{1,1,m};
    SUBCASE("Avancer fonctionne"){
    	r.d_direction = 2;
    	r.move();
    	REQUIRE_EQ(r.d_posX,1);
    	REQUIRE_EQ(r.d_posY,2);
	}
	SUBCASE("Tourner à gauche fonctionne"){
    	r.turnLeft();
    	REQUIRE_EQ(r.d_direction,3);
    	r.move();
    	REQUIRE_EQ(r.d_posX,0);
    	REQUIRE_EQ(r.d_posY,1);
	}
	SUBCASE("Tourner à droite fonctionne"){
    	r.turnRight();
    	REQUIRE_EQ(r.d_direction,1);
    	r.move();
    	REQUIRE_EQ(r.d_posX,2);
    	REQUIRE_EQ(r.d_posY,1);
	}
}
TEST_CASE("Les murs sont bien detectes"){
	maps m{map1.txt};
	
	robot r{1,1};
	r.wallFront;

	
	
