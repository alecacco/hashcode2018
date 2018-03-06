#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

struct Node{
	int row;
	int column;
};

struct Vehicle{
	vector<int> rides;
	Node position;
	int sleep;
};

struct Ride{
	Node start;
	Node end; 
	int distance;
	int beststart;
	int bestend;
	int whichride;
	bool done;
};

struct Scenario{
	int rows;
	int columns;
	vector<Vehicle> cars;
	vector<Ride> rides;
	int bonus;
	int time;
	int step;
};

int nodeDistance(Node node1, Node node2){
	return abs(node1.column-node2.column)+abs(node1.row-node2.row);
}

int main(int argc, char** argv){
	if (argc==1) {
		cerr << "ERROR, missing input file" << endl;
		return(-1);
	}

	ifstream in;
	in.open(argv[1],ios::in);

	Scenario scenario;
	in >> scenario.rows;
	in >> scenario.columns;
	
	int vehicleno;
	in >> vehicleno;

	for (;vehicleno>0;vehicleno--){
		Vehicle newcar;

		vector<int> carrides;
		newcar.rides = carrides;

		Node startingpoint;
		startingpoint.column = 0;
		startingpoint.row = 0;
		newcar.position = startingpoint;

		newcar.sleep = 0;

		scenario.cars.push_back(newcar);
	}

	int ridesno;
	in >> ridesno;

	in >> scenario.bonus;
	in >> scenario.time;
	scenario.step = 0;

	for (int currentride = 0; currentride<ridesno; currentride++){

		Ride newride;
		newride.whichride = currentride;

		int newstartr;
		in >> newstartr;
		int newstartc;
		in >> newstartc;
		Node newNode1;
		newNode1.row = newstartr;	
		newNode1.column = newstartc;		
		newride.start = newNode1;

		int newendr;
		in >> newendr;
		int newendc;
		in >> newendc;
		Node newNode2;
		newNode2.row = newendr;
		newNode2.column = newendc;		
		newride.end = newNode2;

		in >> newride.beststart;
		in >> newride.bestend;

		newride.distance = nodeDistance(newride.start,newride.end);
		//cout<<newride.distance<<endl;

		scenario.rides.push_back(newride);
	}

	in.close();

}