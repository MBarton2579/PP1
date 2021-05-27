#include <string>
#include <random>
#include <vector>
#include <iostream>

struct Object {
	std::string name;
	int strength{ 0 };
	int health{ 0 };

};

int main() {

	Object Player{ "Billy Wild", 0, 0 };

	std::random_device seed;
	std::default_random_engine engine(seed());
	std::normal_distribution<double> strength(30.0, 5.0);
	std::normal_distribution<double> health(5.0, 1.0);

	Player.strength = std::max(1, (int)strength(engine));
	Player.health = std::max(1, (int)health(engine));

	std::vector<Object> Monsters;

	std::uniform_real_distribution<double> createMonsters(1.0, 3.0);

	for (int i = 0; i < std::max(1, (int)createMonsters(engine)); i++) {

		Monsters.push_back({ "Monster" + i, std::max(1, (int)strength(engine)), std::max(1, (int)health(engine)) });

	}

	while (Player.health > 0 || Monsters.size() != 0) {

		std::cout << Player.name << std::endl;
		std::cout << "Health: " << Player.health << std::endl;

	}

	if (Player.health <= 0) {
		std::cout << "Game Over. YOU DIED!";
	}
	else {
		std::cout << "You have fended off the monsters! YOU WIN!";
	}

}



}
