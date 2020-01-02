#include <iostream>
#include "PlaneDatabase.h"
#include "Menu.h"

int main() {
	std::string fileName = "Planes.db";

	PlaneDatabase data(fileName);

	while (true) {
		std::string input;
		std::cin >> input;
		if (input == "create") Menu::create(data);
		else if (input == "delete") Menu::deletePlane(data);
		else if (input == "update") Menu::update(data);
		else if (input == "show") Menu::show(data);
		else if (input == "optimize") Menu::optimize(data);
		else if (input == "search") Menu::search(data);
		else if (input == "exit") {
			Menu::save(data, fileName);
			break;
		}
		else {
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<long long>::max(), '\n');
			}
			std::cout << "Invalid command. Please try \"create\", \"update\", \"show\", \"optimize\", \"search\" or \"exit\"." << std::endl;
		}
	}

	return 0;
}