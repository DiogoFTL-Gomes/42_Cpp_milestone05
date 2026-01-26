#include "Data.hpp"
#include <iostream>

Data::Data() : id(42), value(0.33) {
}

Data::Data(const Data &other) : id(other.id), value(other.value) {
}

Data	&Data::operator=(const Data &other){
	if (this != &other){
		this->id = other.id;
		this->value = other.value;
	}
	return (*this);
}

Data::~Data(){
}
