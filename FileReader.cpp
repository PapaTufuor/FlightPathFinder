#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <set>
#include "Routes.cpp"
#include "Node.cpp"
#include "BFS.cpp"

using namespace std;

template <typename K, typename V>

void print_map(std::unordered_map<K, V> const &m)
{
	for (auto const &pair : m) {
		std::cout << "{" << pair.first << ":" << pair.second << "}\n";

	}
}

int main() {
	static unordered_map<string, vector<Routes>> routesMap;
	static unordered_map<string, string> airportsToPlaces;
	static unordered_map<string, vector<string>> locationToAirportsMap;

	try {
		ifstream airportFile("airports.csv");
		string row = "";
		int count = 0;
		string ignore;
		string key;
		string values;
		string city;
		string country;
		string code;
		char delim = ",";


		while (getline(airportFile, row)) {
			if (count == 0) {
				count++;
				continue;
			}

			stringstream input(row);

			getline(input, ignore, delim);
			getline(input, ignore, delim);
			getline(input, city, delim);
			getline(input, country, delim);
			getline(input, key, delim);
			getline(input, code, delim);

			values = city + "," + country;

			airportsToPlaces.insert({ key,values });

			vector<string>airportValues;
			for (const auto& [k, v] : airportsToPlaces) {
				if (v == values) {
					airportValues.push_back(k);
				}
			}


			if (airportValues.empty()) {
				vector<string> newAirportValues;
				string codeforAirport = key;
				string nullValue = "\\N";
				if (codeforAirport == nullValue) {
					newAirportValues.push_back(code);
				}
				else {
					newAirportValues.push_back(key);

				}
				locationToAirportsMap.insert({ values,newAirportValues });
			}
			else {
				static string codeForAirport;
				if (!std::count(airportValues.begin(), airportValues.end(), key)) {
					if (key == "\\N") {
						string codeForAirport = code;
					}
					else {
						string codeForAiport = key;
					}
					airportValues.push_back(codeForAirport);
					locationToAirportMap.insert({ values,airportValues });
				}
			}
		}

		for (auto &itr : locationToAirportsMap) {
			for (string i : itr.second) {
				cout << itr.first << ":" << i << endl;
			}
		}
		cout << "" << endl;
		print_map(airportsToPlaces);

		airportFile.close();
	}
	catch (const exception& e) {
		cout << "Unable to open file" << e.what() << endl;
	}


	try {
		ifstream routesFile("routes.csv");
		string row = "";
		int count = 0;
		string ignore;
		string key;
		string airlinecode;
		string airlineid;
		string destairportcode;
		int stops;
		char delim = ",";
		static vector<Routes> values;

		while (getline(routesFile, row)) {
			if (count == 0) {
				count++;
				continue;
			}
			
			stringstream input(row);

			getline(input, airlinecode, delim);
			getline(input, airlineid, delim);
			getline(input, key, delim);
			getline(input, ignore, delim);
			getline(input, destairportcode, delim);
			getline(input, ignore, delim);

			Routes route(airlinecode, airlineid, destairportcode, stops);

			values.push_back(route);
			cout << route.toString() << endl;

			routesMap.insert({ key,values });


		}
		for (Routes i : values) { cout << i.toString() << endl; }
		routesFile.close();
	}
	catch (const exception& e) {
		cout << "Unable to open file" << e.what() << endl;
	}

	ifstream inputFile("input.txt");
	string initialLoc;
	string destinationLoc;

	getline(inputFile, initialLoc);
	getline(inputFile, destinationLoc);

	BFS newBFSOBj(airportsToPlaces, locationToAirportsMap,routesMap);
	queue<Node> frontier;
	set<string> exploredSet;

	vector<string> airports = locationToAirportsMatp.at(initialLoc);

	ofstream outputFile("output.txt");
	vector<string>path = newBFSOBj.algSearch(initialLoc, destinationLoc);

	int numFlights = 0;
	if (!path.empty())
	{
		for (string flight : path)
		{
			outputFile << flight << endl;
			numFlights++;
		}
		outputFile << "Total Flights:" + numFlights;
	}
	else {
		outputFile << "Yentumi nfa ha, sorry";
	}
	outputFile.close();

	return 0;


}