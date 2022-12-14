#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <unordered_map>
#include<iterator>
#include "Routes.cpp"
#include "Node.cpp"

class BFS {
protected:
	string initialLoc;
	string destinationLoc;
	queue<Node> frontier;
	set<string> exploredSet;
	vector<string> airports;

	unordered_map<string, string> airportsToPlaces;
	unordered_map<string, vector<string>> locationToAirportsMap;
	unordered_map<string, vector<Routes>> routesMap;
	

public:
	BFS(unordered_map<string, string> airportsMap, unordered_map<string, vector<string>> locationsMap,unordered_map<string,vector<Routes>> routesMap);

	bool contains (queue<Node> anyQueue, Node anyNode);
	bool contains(set<string> anySet, string anyString);
	bool equals(Node node1, Node node2);
	bool equals(string firstString, string secondString);
	bool equals(vector<Routes> firstList, any secondItem);
	vector<string> algSearch(string initialLoc, string destinationLoc);

};

BFS::BFS(unordered_map<string, string> airportsMap, unordered_map<string, vector<string>> locationsMap,unordered_map<string,vector<Routes>> routesMap)
{
	this->airportsToPlaces = airportsMap;
	this->locationToAirportsMap = locationsMap;
	this->routesMap = routesMap;
}

bool BFS::contains(queue<Node> anyQueue, Node anyNode)
{
	bool check;
	queue<Node> newQueueCopy = anyQueue;
	while (!newQueueCopy.empty())
	{
		Node item = newQueueCopy.front();
		check = equals(item, anyNode);
	}

	return check;
}

bool BFS::contains(set<string> anySet, string anyString)
{
	bool check;
	for (auto item : anySet)
	{
		check = (item == anyString);
		if (check == true)
			break;
	}
	return check;
	
}

bool BFS::equals(Node firstNode, Node secNode)
{
	return (typeid(firstNode) == typeid(secNode));
}

bool BFS::equals(string firstString, string secondString)
{
	return(firstString == secondString);
}

bool BFS::equals(list<Routes> firstList, any secondItem)
{
	return(typeid(firstList) == typeid(secondItem));

}

vector<string> BFS::algSearch(string initialloc, string destinationLoc) 
{
	airports = locationToAirportsMap.at(initialLoc);
	for (string airport : airports)
	{
		Node airportNode(NULL, airport, NULL, 0, NULL);
		frontier.push(airportNode);
	}

	while (frontier.size() != 0)
	{
		Node currentNode = frontier.pop();

		exploredSet.insert(currentNode.getAirportCode());
		vector<Routes> successorStates = routesMap.at(currentNode.getAirportCode());

		if (equals(successorStates, NULL) == false)
		{
			for (Routes successorState : successorStates)
			{
				Node child(currentNode, successorState.getDestinationAirpotCode(), successorState.getAirlineCode(), successorState.getStops(), NULL);

				if (!(contains(frontier, child) && !(contains(exploredSet, child.getAirportCode()))) {
					string destinationName = airportsToPlaces.at(child.getAirportCode());
					if ((equals(destinationName, NULL) == false) && (equals(destinationName, destinationLoc) == true))
					{
						return child.solutionPath();
					}
				}
				frontier.push(child);
			}
		}
	}
}