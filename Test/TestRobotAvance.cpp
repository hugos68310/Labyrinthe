#include "doctest.h"
#include "RobotAvance.h"
#include <fstream>
#include <iostream>
#include <Maps.h>

TEST_CASE("Les mouvements du robotAvance fonctionnent"){
	maps* m = new maps("map1.txt", new game{"map1.txt"});
    SUBCASE("Verifier a gauche fonctionne s'il y a un mur"){
    	robotAvance r{0, 1, m};
    	REQUIRE_EQ(false, r.wallLeft());
	}
	SUBCASE("Verifier a gauche fonctionne s'il ny a pas de mur"){
    	robotAvance r{0,2,m};
    	REQUIRE_EQ(true, r.wallLeft());
	}
	SUBCASE("Verifier a droite fonctionne s'il y a un mur"){
    	robotAvance r{0,13,m};
    	REQUIRE_EQ(false, r.wallRight());
	}
	SUBCASE("Verifier a droite fonctionne s'il ny a pas de mur"){
    	robotAvance r{0,14,m};
    	REQUIRE_EQ(true, r.wallRight());
	}
}
