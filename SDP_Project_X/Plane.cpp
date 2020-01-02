#include "Plane.h"

Plane::Plane(unsigned long long id, std::string Plane, std::string Type, unsigned long long Flights) {
	setID(id);
	setName(Plane);
	setType(Type);
	setFlights(Flights);
}

unsigned long long Plane::getID() const
{
	return id;
}

void Plane::setID(unsigned long long id) {
	if (id < 0) id = id * (-1);
	this->id = id;
}

void Plane::setFlights(long long flights) {
	if (flights < 0) flights = 0;
	this->flights = flights;
}

void Plane::setName(const std::string& name) {
	if (name.size() > 256) {
		this->name = name.substr(0, 255);
		return;
	}
	this->name = name;
}

void Plane::setType(const std::string& type) {
	if (type.size() > 256) {
		this->type = type.substr(0, 255);
		return;
	}
	this->type = type;
}

void Plane::printPlane() {
	std::cout << id << ' ' << name << ' ' << type << ' ' << flights << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Plane& plane) {
	os << plane.id << ' ' << plane.name << ' ' << plane.type << ' ' << plane.flights;
	return os;
}
