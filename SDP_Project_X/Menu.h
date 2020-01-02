#pragma once
#include "PlaneDatabase.h"

class Menu {
	Menu();
public:
	static void create(PlaneDatabase& db) {
		long long id, flights;
		std::string name, type;
		std::cin >> id >> name >> type >> flights;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(1024, '\n');
			std::cout << "Not a number." << std::endl;
			return;
		}
		db.cratePlane(id, name, type, flights);
	}
	static void deletePlane(PlaneDatabase& db) {
		long long id;
		std::cin >> id;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(1024, '\n');
			std::cout << "Not a number." << std::endl;
			return;
		}
		db.deletePlane(id);
	}
	static void update(PlaneDatabase& db) {
		long long id;
		std::string attribute, value;
		std::cin >> id >> attribute >> value;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(1024, '\n');
			std::cout << "Not a number." << std::endl;
			return;
		}
		db.updatePlane(id, attribute, value);
	}
	static void show(PlaneDatabase& db) {
		long long offset, limit;
		std::cin >> offset >> limit;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(1024, '\n');
			std::cout << "Not a number." << std::endl;
			return;
		}
		db.show(offset, limit);
	}
	static void optimize(PlaneDatabase& db) {
		db.optimize();
	}
	static void search(PlaneDatabase& db) {
		long long id;
		std::cin >> id;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(1024, '\n');
			std::cout << "Not a number." << std::endl;
			return;
		}
		if (db.search(id) == -1) std::cerr << "This plane does not exist." << std::endl;
		else db.printElement(db.search(id));
	}
	static void save(PlaneDatabase& db, std::string fileName) {
		db.saveToFile(fileName);		
	}
};

