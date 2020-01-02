#pragma once
#include "Plane.h"
#include <fstream>
#include <vector>

class PlaneDatabase {
	std::vector<Plane> db;
	bool isOptimized;

	void heapify(unsigned long long n, unsigned long long i);
	long long binSearch(unsigned long long left, unsigned long long right, unsigned long long id);
public:
	PlaneDatabase();
	PlaneDatabase(std::string& fileName);

	unsigned long long search(unsigned long long id);
	void cratePlane(unsigned long long id, std::string name, std::string Type, long long Flights);
	void deletePlane(unsigned long long id);
	void updatePlane(unsigned long long id, std::string attribute, std::string newValue);
	void optimize();
	void show(unsigned long long offset, unsigned long long limit);

	unsigned long long getSize() const;
	void saveToFile(std::string& fileName);
	void printElement(unsigned long long index);
};

