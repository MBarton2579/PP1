#include <string>
#include <random>
#include <vector>

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

	std::uniform_int_distribution<double> createMonsters(1.0, 3.0);


	for (int i = 0; i < std::max(1, (int)createMonsters(engine)); i++) {

		std::string monName = "Monster" + std::string(i);

		Monsters.push_back("Monster" + std::string(i), std::max(1, (int)strength(engine)), std::max(1, (int)health(engine)));
	}



}
