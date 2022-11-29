#include <iostream>
#include <string>
using namespace std;

class Airport {
protected:
	string airportID;
	string airportName;
	string city;
	string country;
	string ICAOCode;

public:
	Airport(string airportID, string airportName, string city, string country, string ICAOCode)
	{
		this->airportID = airportID;
		this->airportName = airportName;
		this->city = city;
		this->country = country;
		this->ICAOCode = ICAOCode;
	}


		string getAirportID() 
		{
			return airportID;
		}
		void setAirportID(string airportID) 
		{
			this->airportID = airportID;
		}
		string getAirportName() 
		{
			return airportName;
		}
		void setAirportName(string airportName) {
			this->airportName = airportName;
		}
		string getCity() {
			return city;
		}

		void setCity(string city) {
			this->city = city;
		}
		string getCountry() {
			return country;
		}

		void setCountry(string country) {
			this->country = country;
		}

		string getICAOCode() {
			return ICAOCode;
		}

		void setICAOCode(string ICAOCode) {
			this->ICAOCode = ICAOCode;
		}

		string toString() {
			return "Airport{airportID=" + airportID +
				", airportName=" + airportName +
				", city=" + city +
				", country=" + country +
				",ICAOCode=" + ICAOCode + "}";

		}

	

};