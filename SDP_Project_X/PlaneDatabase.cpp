#include "PlaneDatabase.h"

void PlaneDatabase::heapify(unsigned long long n, unsigned long long i) {

	unsigned long long largest = i;
	unsigned long long left = 2 * i + 1;
	unsigned long long right = 2 * i + 2;

	if (left < n && db[left].getID() > db[largest].getID())
		largest = left;

	if (right < n && db[right].getID() > db[largest].getID())
		largest = right;

	if (largest != i) {
		std::swap(db[i], db[largest]);
		heapify(n, largest);
	}
}

long long PlaneDatabase::binSearch(unsigned long long left, unsigned long long right, unsigned long long id) {
	if (right >= left) {
		unsigned long long mid = left + (right - left) / 2;
		if (db[mid].getID() == id) return mid;
		else if (db[mid].getID() > id) return binSearch(left, mid - 1, id);
		else return binSearch(mid + 1, right, id);
	}
	return -1;
}

PlaneDatabase::PlaneDatabase(){
	isOptimized = 0;
}

PlaneDatabase::PlaneDatabase(std::string& fileName){
	isOptimized = 0;
	std::ifstream file(fileName);
	if (!file) {
		std::cerr << "File not found. Create your first plane using the \"create\" command." << std::endl;
	}
	else {
		while (!file.eof()) {
			unsigned long long id, flights;
			std::string name, type;
			file >> id >> name >> type >> flights;
			if (file.eof())break;
			cratePlane(id, name, type, flights);
		}
		file.close();
	}
}

unsigned long long PlaneDatabase::search(unsigned long long id) {
	if (!isOptimized) {
		for (int i = 0; i < db.size(); i++) {
			if (id == db[i].getID()) return i;
		}
	}
	else {
		return binSearch(0, db.size(), id);
	}
	return -1;
}

void PlaneDatabase::cratePlane(unsigned long long id, std::string name, std::string Type, long long Flights){
	if (search(id) != -1) {
		std::cerr << "A record with id: " << id << " exists. Use \"update\" instead." << std::endl;
		return;
	}
	Plane temp(id, name, Type, Flights);
	db.push_back(temp);
	isOptimized = 0;
}

void PlaneDatabase::deletePlane(unsigned long long id) {
	int temp = search(id);
	if (temp == -1) {
		std::cerr << "Record not found!" << std::endl;
		return;
	}
	db.erase(db.begin() + temp);
}

void PlaneDatabase::updatePlane(unsigned long long id, std::string attribute, std::string newValue) {
	long long temp = search(id);
	if (temp == -1) {
		std::cerr << "Record not found!" << std::endl;
		return;
	}
	if (attribute == "Id") {
		if (search(stoi(newValue)) != -1) {
			std::cerr << "A record with id: " << id << " exists. Use \"update\" instead." << std::endl;
			return;
		}
		db[temp].setID(stoi(newValue));
	}
	else if (attribute == "Flights") {
		db[temp].setFlights(stoi(newValue));
	}
	else if (attribute == "Plane") {
		db[temp].setName(newValue);
	}
	else if (attribute == "Type") {
		db[temp].setType(newValue);
	}
	else std::cerr << "Invalid command. Please try \"Id\", \"Plane\", \"Type\" or \"Flights\"." << std::endl;
}

void PlaneDatabase::optimize() {
	for (long long i = db.size() / 2 - 1; i >= 0; i--)
		heapify(db.size(), i);
	for (int i = db.size() - 1; i >= 0; i--) { 
		std::swap(db[0], db[i]); 
		heapify(i, 0);
	}
}

void PlaneDatabase::show(unsigned long long offset, unsigned long long limit){
	if (offset + limit > db.size() || offset < 0) {
		std::cerr << "Out of range." << std::endl;
		return;
	}
	for (long long i = offset; i < offset+limit; i++) {
		db[i].printPlane();
	}
}

unsigned long long PlaneDatabase::getSize() const {
	return db.size();
}

void PlaneDatabase::saveToFile(std::string& fileName){
	std::ofstream file(fileName, std::ios::trunc);
	if (!file) {
		std::cerr << "File could not be saved.";
		return;
	}
	for (int i = 0; i < db.size(); i++) {
		file << db[i] << std::endl;
	}
}

void PlaneDatabase::printElement(unsigned long long index) {
	db[index].printPlane();
}
