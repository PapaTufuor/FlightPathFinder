#include <iostream>
#include <string>
using namespace std;

class Airlines {
protected:
	string airlineID;
	string airlineName;
	string IATACode;
	string ICAOCode;
	string country;
public:
	string getAirlineID() {
		return airlineID;
	}
	void setAirlineID(string airlineID) {
		this->airlineID = airlineID;
	}
	string getAirlineName() {
		return airlineName;
	}
	void setAirlineName(string airlineName) {
		this->airlineName = airlineName;
	}
	string getIATACode() {
		return IATACode;
	}

	void setIATACode(string IATACode) {
		this->IATACode = IATACode;
	}
	string getICAOCode() {
		return ICAOCode;
	}

	void setICAOCode(string ICAOCode) {
		this->ICAOCode = ICAOCode;
	}

	string getCountry() {
		return country;
	}

	void setCountry(string country) {
		this->country = country;
	}
		
};