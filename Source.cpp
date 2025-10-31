//// Hospital Management System

//header files
#include<iostream>
#include<string>
#include<queue>

/////////////////patient Structure//////////////
struct patient {
	int ID = 0;
	std::string NAME;
	std::string DISEASE;
};
//////////////////////////////////////////////////////////////////////////////////////////////////////
void interface(const std::string* ARRAY, const int& SIZE) {
	std::cout << "\n\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;

	//////////////////////// displaying available wards/////////////////////////
	std::cout << "\t\t\t\tAvailable Wards\t\t\t\t\t" << std::endl;
	for (int i = 0; i < SIZE; ++i) {
		std::cout << "\t\t\t\t" << i << " " << ARRAY[i] << std::endl;
	}
	///////////////////////////////////////////////////////////////////////////
	//c) The user interface should enable the user to add and remove patients from any queue. 
	//add remove and view a specific queue
	std::cout << "================================================================================" << std::endl;
	std::cout << "\t\t\t\tEDIT DATA IN WARDS" << std::endl;
	std::cout << "(A)\tAdd Patient Details " << std::endl;
	std::cout << "(B)\tRemove Patient Details " << std::endl;
	std::cout << "(C)\tQuit" << std::endl;
	std::cout << "================================================================================" << std::endl;

}

////////////add patient ////////////////////////////////////////////////////////////////////////////////
void add_patient(const std::string* ARRAY, const int& SIZE, std::queue<patient>* QUEUES) {
	int WARD;
	std::cout << "In which ward you want to enter patient data? (ward number starts with 0: ";
	std::cin >> WARD;
	if (WARD > SIZE) {
		std::cout << "This ward is not present ";
	}
	else {
		std::cout << "Data entering in ward: " << ARRAY[WARD] << std::endl;
		// making obj of patient and pushing it 
		patient p;
		std::cin.ignore();
		std::cout << "\nNAME: ";
		std::getline(std::cin, p.NAME);
		std::cout << "ID:(integers only) ";
		std::cin >> p.ID;
		std::cin.ignore();
		std::cout << "DISEASE: ";
		std::getline(std::cin, p.DISEASE);
		QUEUES[WARD].push(p);

		std::cout << "Data added of " << p.NAME << " in ward " << ARRAY[WARD];
	}

}///////////END OF ADD PATIENT FUNCTION////////////////////////////////////////////////////////

///////////////REMOVE PATIENT///////////////////////////////
void remove_patient(const std::string* ARRAY, int& SIZE, std::queue<patient>* QUEUES) {
	int WARD;
	std::cout << "From which ward you want to remove patient data? (ward number starts with 0: ";
	std::cin >> WARD;
	if (WARD > SIZE || WARD < 0) {
		std::cout << "This ward is not present ";
	}
	if (QUEUES[WARD].empty()) {
		std::cout << " This ward is empty";
	}
	else {
		/// actual game starts here
		patient removed_patient = QUEUES[WARD].front();
		std::cout << "Patient Served: " << removed_patient.NAME << " from ward " << ARRAY[WARD] << std::endl;
		QUEUES[WARD].pop();
		patient current = QUEUES[WARD].front();
		std::cout << "Now we are serving " << current.NAME << " in ward " << ARRAY[WARD] << std::endl;
	}
}//////////////////////end of remove function//////////////////////////////////////////////


///////////////DISPLAY HELP/////////////
void display_help() {
	//////////user manual///////////////
	std::cout << "User help is not yet mentioned" << std::endl;
	std::cout << "\t\t\t==============================================" << std::endl;
	std::cout << "\t\t\tWelcome To ehhsen's Hospital MAnagement system" << std::endl;
	std::cout << "How to use this program:" << std::endl;
	std::cout << "Add wards: " << std::endl;
	std::cout << " so in this program you can add as many queues as you want \n"
		<< " which will serve as wards in this hospital management system\n"
		<< " to do this simpel type, source.exe *    in cmd prompt: where * \n"
		<< "represent number of queues / wards you want. it must be an integer. \n";
	std::cout << "this program stores the folloing information of a patient: \nName (type string) \nID(type integer\nDisease(type string)\n";
	std::cout << "\t\t=========================================" << std::endl;
	std::cout << "\t\tHow to add a patient's record in Ward: " << std::endl;
	std::cout << "Enter A >> then type the number corresponding to that Ward\n"
		<< " after that enter the name, id and disease of patient. " << std::endl;

	std::cout << "\t\t============================================" << std::endl;
	std::cout << "\t\tHow to remove a patient's record from a Ward " << std::endl;
	std::cout << "Enter B >> then type the number corresponding to the Ward\n"
		<< " from which U want to remove patient. press enter and the record will be removed." << std::endl;

	std::cout << "\t\t============================================" << std::endl;
	std::cout << "\nYou should follow these rules or else this program may show unexpected behaviour";
	std::cout << "\n Enter exact an integer as second command line argument";
	std::cout << "\n Number of wards you want to create must be greater than 0";
	std::cout << "\n by default the first ward will be 0 , second will be 1 and so on";
	std::cout << "\nThe ward in which you want to enter data must be present:  " << std::endl;

	std::cout << "To Exit: press C";
}

///////////////MAIN //////////////////////////
int main(int argc, char* argv[]) {

	///////////check for correct number of arguments////////////
	if (argc != 2) {
		std::cout << "invalid arguments, Correct arguments should be:  filename.exe <int> where int is number of queue you want to create" << std::endl;
		return 1;
	}
	///////////////// check help///////////////////
	if (std::string(argv[1]) == "--help") {
		display_help();
		return 0;
	}
	///////////////////////////////////////////////////////
	 // number of queue check
	if (atoi(argv[1]) < 1) {
		std::cout << "Entered queue size is invalid size should be greater than 0 ";
		return 1;
	}

	// initialize number of que from CLI 
	int NUMBER_OF_QUEUES = atoi(argv[1]);
	//std::cout << NUMBER_OF_QUEUES;   for debugging

	/////////////////////////////////////////////////////
	//creating a dynamic array to store names of queues
	std::string* NAMES_OF_QUEUES;
	NAMES_OF_QUEUES = new std::string[NUMBER_OF_QUEUES];// todo delete[] memory at last 

	////Input names for queue
	for (int i = 0; i < NUMBER_OF_QUEUES; ++i) {
		std::cout << "Enter name of Queue/Ward ";
		std::getline(std::cin, NAMES_OF_QUEUES[i]);
		//std::cout << NAMES_OF_QUEUES[i];  debugging
	}
	//creating dynamic array to make queues
	std::queue<patient>* ACTUAL_QUEUES;
	ACTUAL_QUEUES = new std::queue<patient>[NUMBER_OF_QUEUES];   //TODO: delete it 


	bool while_it = true;
	while (while_it) {
		interface(NAMES_OF_QUEUES, NUMBER_OF_QUEUES);
		std::cout << "Enter your choice: A/B/C? ";
		char choice;
		std::cin >> choice;
		choice = std::toupper(choice);

		switch (choice) {
		case 'A':
			std::cout << "Adding data of patient" << std::endl;
			add_patient(NAMES_OF_QUEUES, NUMBER_OF_QUEUES, ACTUAL_QUEUES);
			/// ask user for which queue to enter record in // call add function
			break;
		case 'B':
			std::cout << "Removing data of patient" << std::endl;
			remove_patient(NAMES_OF_QUEUES, NUMBER_OF_QUEUES, ACTUAL_QUEUES);
			/// call remove function
			break;
		case 'C':
			/////////// call end function
			while_it = false;
			break;
		default:
			std::cout << "Invalid input " << std::endl;
			break;
		}

	}
	delete[] NAMES_OF_QUEUES;
	delete[] ACTUAL_QUEUES;
	return 0;
}

