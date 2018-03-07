#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <stdlib.h>

const int DEFAULT_CAPACITY = 10; /* This is the holding capacity for resources. DEFAULT CAPACITY of 10 can be interpreted as 
"only 10 cups/spoons/etc. can be stored." */

using namespace std;

/* Class Description: Creation of data type CoffeeMachine. Each instance of CoffeeMachine represents a real world coffee machine.
 * Each Coffee Machine holds its own resources and makes coffee depending on what resources it has.
   Constructors: 
    * Default Constructor: creates a nameless coffee machine with empty resources and default capacity.
	* Constructor coffeeMachine(string) User can name the coffee machine with empty resources and default capacity.
	* Constructor coffeeMachine(string, int int) User names the coffee machine with empty resources and decides the capacity.
   Public Functions: 
    * string name: Stores the name of the CoffeeMachine. Tell the difference between each CoffeeMachine and describe the type 
	* of CoffeeMachine. For example, the name "DECAF" means that this coffee machine produces decaf coffee.
	* 
	* int makeCups(int): Takes the number of coffees ordered as a parameter. Checks if enough resources are available.
	* If not enough resources are available it will print that not enough is available and return 0. If they are available then
	* it will return 1 and invoke void makeSingleCup(int) every time it needs to make a cup. makeSingleCup decrements the 
	* resources each time it is executed. The significance of the return value is that a return value of 1 will confirm that coffee
	* cups have been made. This will be useful for when this function is inherited and overridden in milkCoffeeMachine. The call to
	* return also allows for the function to abort once it has finished its purpose.
	* 
	* void addWater(int): Inserts defined amount of water into the current active coffeeMachine. If more water than the capacity
	* is requested, then it displays error prompt and fills coffeeMachine to max capacity water.
	* 
	* void addCoffee(int): Inserts defined amount of coffee into current active coffeeMachine. If more coffee than the capacity
	* is requested, then it displays error prompt and fills coffeeMachine to max capacity coffee.
	* 
	* void displayCM(): Displays current status of coffeeMachine. It tells which machine is being displayed and the current 
	* resources and resource capacity. 
	* 
	* void makeSingleCup(): decrements the right amount of resources so that the Machine can know the remaining resources. it decrements
	* water by 1 and coffee by 1 * coffee_spoons_per_cup each time it is called. It is called for every cup of coffee that is ordered.
	* 
	* */
	
class coffeeMachine { //creation of class coffeeMachine
	public: // Public members of class coffeeMachine
		~coffeeMachine(); //Destructor and constructors
		coffeeMachine(); 
		coffeeMachine(string);
		coffeeMachine(string, int, int);
		string name; // Public Member Variables
		void addCoffee(int); // Public Member functions
		void addWater(int);
		void displayCM();
		int makeCups(int);
	protected: // Protected Members
		int coffee_spoons_per_cup; // Protected Member Variable
	private: // Private Members
		int water_capacity; // Private Member Variables
		int coffee_capacity;
		int curr_water;
		int curr_coffee;
	void makeSingleCup(); // Private Member Functions
};

coffeeMachine::coffeeMachine(){ // Default Constructor
	name = "UNTITLED";
	cout << "Created Coffee Machine " << name << " with empty resources." << endl;
	water_capacity = DEFAULT_CAPACITY;
	coffee_capacity = DEFAULT_CAPACITY;
	curr_water = 0;
	curr_coffee = 0;
	coffee_spoons_per_cup = 2;
}

coffeeMachine::coffeeMachine(string name){ // Constructor coffeeMachine(string)
	this-> name = name;
	cout << "Starting up Coffee Machine " << name << " with empty resources." << endl;
	water_capacity = DEFAULT_CAPACITY;
	coffee_capacity = DEFAULT_CAPACITY;
	curr_water = 0;
	curr_coffee = 0;
	coffee_spoons_per_cup = 1;
}

coffeeMachine::coffeeMachine(string name, int water_capacity, int coffee_capacity){ // Constructor (string, int, int)
	this-> name = name;
	this-> water_capacity = water_capacity;
	this-> coffee_capacity = coffee_capacity;
	cout << "Starting up Coffee Machine " << name << " with empty resources and capacities: " << endl;
	cout << setw(20) << "Water Capacity= \t" << water_capacity << " cups" << endl;
	cout << setw(20) << "Coffee Capacity= \t" << water_capacity << " spoons" << endl;
	curr_water = 0;
	curr_coffee = 0;
	coffee_spoons_per_cup = 1;
}

coffeeMachine::~coffeeMachine(){ // destructor
	cout << "Shutting down Coffee Machine " << name << " with the following resources left:" << endl;
	cout << setw(20) << "Water: " << curr_water << " cups" << endl;
	cout << setw(20) << "Coffee: " << curr_coffee << " spoons" << endl;
}

void coffeeMachine::displayCM(){ // PUBLIC MEMBER FUNCTION CLASS COFFEEMACHINE: DISPLAY MACHINE STATUS.
	cout << "CURRENT STATUS OF COFFEE MACHINE: " << name << endl;
	cout << setw(20) << "WATER:\t" << curr_water << "/" << water_capacity << " Cups" << endl;
	cout << setw(20) << "COFFEE:\t" << curr_coffee << "/" << coffee_capacity << " Spoons" << endl;
	cout << setw(20) << "COFFEE STRENGTH:\t" << coffee_spoons_per_cup << " spoons per cup" << endl;
}

void coffeeMachine::addWater(int cupsOfWater){ // PUBLIC MEMBER FUNCTION CLASS COFFEEMACHINE: ADD WATER TO MACHINE
	if (cupsOfWater > water_capacity){ // Check for overflow.
		cout << name << " cannot contain " << cupsOfWater << " cups. Filling to Capacity instead." << endl;
		curr_water = water_capacity; // The user input is set to the max capacity when overflow detected.
	} else {
		curr_water = curr_water + cupsOfWater; // No overflow detected. curr_water initialized to itself plus the input.
		cout << setw(20) << "\tAdded " << cupsOfWater << " cups of water to " << name << endl;
	}
}
void coffeeMachine::addCoffee(int spoonsOfCoffee){ // PUBLIC MEMBER FUNCTION CLASS COFFEEMACHINE: ADD COFFEE TO MACHINE
	if (spoonsOfCoffee > coffee_capacity){ // Check for overfill
		cout << name << " cannot contain " << spoonsOfCoffee << " spoons. Filling to Capacity instead." << endl;
		curr_coffee = coffee_capacity; // Input is set to max capacity if overfill detected.
	} else {
		curr_coffee = curr_coffee + spoonsOfCoffee; // If no overfill, then initialize to curr_coffee to itself plus the input.
		cout << setw(20) << "\tAdded " << spoonsOfCoffee << " spoons of coffee to " << name << endl;
	}
}

int coffeeMachine::makeCups(int cupsOrdered){ // PUBLIC MEMBER FUNCTION CLASS COFFEEMACHINE: MAKE COFFEES
	cout << "Ordered " << cupsOrdered << " cups of coffee of strength " << coffee_spoons_per_cup << endl;
	if(cupsOrdered > curr_water){ // Check if enough water to fulfill order.
		cout << setw(20) << "\tNOT " << "ENOUGH RESOURCES!" << endl;
		return 0; // The order exceeds resources.
	}
	if(cupsOrdered * coffee_spoons_per_cup > curr_coffee){ // Check if enough coffee to fulfill order.
		cout << setw(20) << "\tNOT " << "ENOUGH RESOURCES!" << endl;
		return 0; // The order exceeds resources.
	}
	for(int i = 0; i < cupsOrdered; i++){ // For loop that will increment x times for each cup of coffee ordered.
		makeSingleCup(); // Execute the at each iteration.
	}
	return 1; // Lets machine know that cups were made, and that the order did not exceed resources
}

void coffeeMachine::makeSingleCup(){ // PRIVATE MEMBER FUNCTION CLASS COFFEEMACHINE: KEEP TRACK OF RESOURCES.
	cout << setw(20) << "... Making a cup of coffee ..." << name << endl;
	curr_coffee = curr_coffee - coffee_spoons_per_cup;
	curr_water--;
}

int main(){ // MAIN FUNCTION
	int cupsOrdered = 0; //store the number of coffees ordered. Command line variable
	int cupsOfWater = 0; //store the number of cups of water added to machine. Command line variable
	int spoonsOfCoffee = 0; //store the number of spoons of coffee added to machine. Command line variable.
	coffeeMachine cm1;
	cm1.displayCM();
	cout << "How many cups of water should be put in " << cm1.name << "?: "; // Command Line Prompt
	cin >> cupsOfWater;
	cout << "How many spoons of coffee should be put in " << cm1.name << "?: "; // Command Line Prompt
	cin >> spoonsOfCoffee;
	cm1.addWater(cupsOfWater);
	cm1.addCoffee(spoonsOfCoffee);
	cm1.displayCM();
	cout << "How many cups of coffee do you want?: "; // Command Line Prompt
	cin >> cupsOrdered;
	cm1.makeCups(cupsOrdered);
	cm1.displayCM();
	
	coffeeMachine cm2("DECAF");
	cm2.displayCM();
	cout << "How many cups of water should be put in " << cm2.name << "?: ";
	cin >> cupsOfWater;
	cout << "How many spoons of coffee should be put in " << cm2.name << "?: ";
	cin >> spoonsOfCoffee;
	cm2.addWater(cupsOfWater);
	cm2.addCoffee(spoonsOfCoffee);
	cm2.displayCM();
	cout << "How many cups of coffee do you want?: ";
	cin >> cupsOrdered;
	cm2.makeCups(cupsOrdered);
	cm2.displayCM();
	
	coffeeMachine cm3("StarBucks", 7, 7);
	cm3.displayCM();
	cout << "How many cups of water should be put in " << cm3.name << "?: ";
	cin >> cupsOfWater;
	cout << "How many spoons of coffee should be put in " << cm3.name << "?: ";
	cin >> spoonsOfCoffee;
	cm3.addWater(cupsOfWater);
	cm3.addCoffee(spoonsOfCoffee);
	cm3.displayCM();
	cout << "How many cups of coffee do you want?: ";
	cin >> cupsOrdered;
	cm3.makeCups(cupsOrdered);
	cm3.displayCM(); // Destructors execute after this function.
	return 0; // end program.
}


