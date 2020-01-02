#pragma once
#include<iostream>
#include<string>

class Plane {
	unsigned long long id;
	std::string name;
	std::string type;
	unsigned long long flights;
	
public:
	Plane(unsigned long long id, std::string Plane, std::string Type, unsigned long long Flights);
	
	unsigned long long getID() const;
	
	void setID(unsigned long long id);
	void setFlights(long long flights);
	void setName(const std::string& name);
	void setType(const std::string& type);

	void printPlane();
	friend std::ostream& operator<< (std::ostream& os, const Plane& plane);
};


