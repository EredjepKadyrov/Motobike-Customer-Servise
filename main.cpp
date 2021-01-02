#include <iostream>
#include <cstdlib>
#include <fstream>
#include<ctime>

using namespace std;



class Date{  //this will be used for additional ideas with age of allowed to drive a bike
    private:
        short day;
        short month;
        int age;
        int yearOfBirth;
	public:
        void enterDate();
        void showData();
        void incrementByOneMonth();
        void showAge();

};

void Date::enterDate()
{

    cout << "||| Day ||| Month ||| Year ||| ";
    cin >> day >> month >> yearOfBirth;

}

void Date::showData()
{

    cout << " |||Date Of Bith:  ";
    cout << day << "." << month << "." << yearOfBirth << endl;
}


class Motobike    //to import motobikes from product.txt file
{
private:
    int motonum;
    string mname;
    int mcost;
    int mquantity;
public:
    Motobike() {};
    void setMotonum(int m) { motonum = m; }
    void setMotoName(string mn) { mname = mn; }
    string get_mname () { return mname; }
    void setMCost(int mc) { mcost = mc; }
    void setQuantity(int q) { mquantity = q; }
    void displayData();
};

void Motobike:: displayData()
{
    cout << motonum << "\t" << mname << "\t" << mcost << "\t" << mquantity << endl;

}




class Item
{
// friend Declaration
friend class Reservlist;

private:
	string name;
	string surname;
    string dateOfBirth;
    string street;
    int houseNumber;
    string city;
    int postalCode;
    int id;
    string selectMoto;

	Item *successor;
public:

	Item(string n, string s,  string d, string ad, int hn, string c, int pc, int i, string sm) : name(n),surname(s),  dateOfBirth(d), street(ad),houseNumber(hn),city(c), postalCode(pc), id(i), selectMoto(sm)
	{
		successor = 0;
	}
	string get_name () { return name; }
	string get_surname () { return surname; }
	string get_dateOfBirth () { return dateOfBirth; }
	string get_street () { return street; }
	int get_houseNumber () { return houseNumber; }
	string get_city () { return city; }
	int get_postal () { return postalCode; }
	int get_id () { return id; }
	string get_selectMoto () { return selectMoto; }

	void set_name (string n) { name = n; }
	void set_surname (string s) { surname = s; }
	void set_dateOfbith(string d) { dateOfBirth = d; }
    void set_street (string ad) { street = ad; }
    void set_hNumber (int hn) { houseNumber = hn;}
    void set_city (string c) { city = c; }
    void set_selectMoto (string sm) { selectMoto = sm; }
    void set_postal (int pc) { postalCode = pc; }
    void set_id(int i) { id = i; }
	void displayData()
	{

		cout << get_name() << "\t" << get_surname() << "\t"  << get_dateOfBirth() << "\t" << get_street() << "\t" << get_houseNumber() << "\t" << get_city() << "\t" << get_postal() << "\t" << get_id() << "\t" << get_selectMoto()<< endl;
	};
	Item *next () { return successor; }
};

class Reservlist
{
private:
	Item *beginning;
public:
	Reservlist ()
	{
		beginning = 0;
	}
	Item *begin () { return beginning; }

	insert(Item *k)
	{
		k->successor = beginning;
		beginning = k;
	}
	Item* find(string dataset)
	{
		Item *kp;
		for (kp = begin(); kp != 0; kp = kp->next())
			if (kp->get_name() == dataset)
				break;
		return kp;
	}
	void remove(string dataset)
	{
		if(beginning!=NULL)
		{
			if(beginning->get_name() == dataset) //check if the beginning is our dataset, as we may not have a successor

			{
				beginning = beginning->next(); //falls ja, dann ist unser neuer Anfang der Nachfolger
			}
			else if(beginning->get_name() != dataset && beginning->next() == NULL) //check if start is not equal to dataset and if next dataset is NULL
			{
				return;
			}
			else
			{
				Item *kp;
				for (kp = begin(); kp != 0; kp = kp->next())
				{
					if(kp->next()->get_name() != dataset && kp->next()->next() == NULL) //check if the successor dataset is not equal to my dataset and if the successor of the successor is equal to NUL
						break;														  //is needed if we are at the second to last dataset & last data is not equal, because last does not provide any data
					else if (kp->next()->get_name() == dataset) //check if successor is our dataset
					{
						kp->successor = kp->next()->next(); //If yes, then our new successor is the successor of the successor of the current object.
						break;
					}
				}
			}
		}
	}

	bool empty() { return beginning == 0; }
	Item *clear()
	{
    // Remove a node from the beginning of the list
        Item * kp = beginning;
        if (kp != 0)
        {
        	cout << kp->get_name() << " deleted." << endl;
            beginning = kp->successor;
            kp->successor = 0;
        }
        return kp;
	}
};

Reservlist list;

void list_initialize(); // Fills the list with the values from the file
void add(); // Add item
void modify(); // Modify item
void display(); // Displays all items and price
void remove(); // Delete item
void empty(); // Empty shopping list

int main()
{
	string insert;
	int selection = 1;
	Item *tmpObject = NULL;   //initialization
	ofstream fileWriter;
    string input;
	list_initialize();

	Motobike motolist[4];   //motobikes array
    int i = 0;
    int m,q,mc;
    string mn;

    ifstream fileMReader("products.txt");
    if(fileMReader.good())
    {
     while(fileMReader >> m >> mn >> mc >> q)
     {
         motolist[i].setMotonum(m);
         motolist[i].setMotoName(mn);
         motolist[i].setMCost(mc);
         motolist[i].setQuantity(q);
         i++;
     }
    }
    else
    {
        cout << "File could not be opened.";
        return 0;
    }



	do
    {
    	system("cls");
    	time_t timetoday;
        time (&timetoday);

        cout << " Welcome to the MOTOBIKE RENTAL" << endl << endl;
        cout << " -- Todays is : "<< asctime(localtime(&timetoday));
        cout << " Please select from the menu..." << endl << endl << endl;

        cout << "---- Reservationlist ----" << endl;
        cout << "1. Add reservation" << endl;
        cout << "2. Modify reservation" << endl;
        cout << "3. Delete reservation/hand over the motorbike" << endl;
        cout << "4. Display reservation list" << endl;
        cout << "5. Empty reservation list." << endl;
        cout << "6. Display motobikes list." << endl;
        cout << "0. Exit program" << endl;
        cout << "Your selection: ";
        cin >> selection;
        cout << endl;

        try
        {
	        switch (selection)
	        {
	            case 0: // End
	            	fileWriter.open("reservationlist.txt");
	            	if(fileWriter.good())
	            	{
						for (tmpObject=list.begin(); tmpObject != 0; tmpObject = tmpObject->next())
						{

							fileWriter << tmpObject->get_name() << "\t" << tmpObject->get_surname() << "\t" << tmpObject->get_dateOfBirth() << "\t" << tmpObject->get_street() << "\t" << tmpObject->get_houseNumber() << "\t" << tmpObject->get_city() << "\t" << tmpObject->get_postal() << "\t" << tmpObject->get_id() << "\t" << tmpObject->get_selectMoto()<< endl;
						}
						if(list.begin()!=0)
							cout << "List saved to file reservationlist.txt!" << endl;
					}
					else
						cout << "Datei reservationlist.txt cannot be opened. Old list remains." << endl;

	            	cout << "Goodbye!" << endl;
	                break;
	            case 1: // Add customer to reservation list

	            	system("cls");
					cout << " Have you an A driving license ? Please answer yes if you have license or no if you have not " << endl;
	            	cin >> input;
	            	if(input == "yes") {
                        add();
					    system("pause");
	                    break;
	            	}
	            	else
						cout << "You have not rights to drive a bike, please try again" << endl;
					system("pause");
					break;
	            case 2: // Modify reservation
	            	if(list.begin()!=0)
	            	{
	            		system("cls");
	            		modify();
					}
					else
						cout << "List is empty." << endl;
	        		system("pause");
	                break;
	            case 3: // Delete selected reservation
                    if(list.begin()!=0)
	            	{
	            		system("cls");
	            		remove();
					}
					else
						cout << "List is empty." << endl;
					    system("pause");
					break;
				case 4: // Display reservation details
	            	if(list.begin()!=0)
	            	{
	            		display();
					}
					else
						cout << "List is empty." << endl;
					system("pause");
					break;
                case 5: // Empty reservation list
	            	if(list.begin()!=0)
	            	{
	            		system("cls");
	            		empty();
					}
					else
						cout << "List is empty." << endl;
					system("pause");
					break;
                case 6: // Display motobikes with name, price, quantity
                    cout << "MotoNo\tMotoName\tCost\tQuantity" << endl;
                    for(int i=0;i<4;i++)
                    motolist[i].displayData();
                    system("pause");


					break;
	            default: // Incorrect input
	            	cerr << "Incorrect input" << endl;
	            	system("pause");
	                break;
	        }
    	}
        catch(string msg)
		{
			cout << msg << " cannot be negative or null!" << endl << "Transaction canceled." << endl;
			system("pause");
		}
    } while (selection != 0);

	system("pause");
	return 0;
}

void list_initialize()
{
	string name;
	string surname;
    string dateOfBirth;
    string street;
    int houseNumber;
    string city;
    int postalCode;
    int id;
    string selectMoto;
	Item *it;

	ifstream fileReader("reservationlist.txt", ios::out);

	if(fileReader.good())
    {


		while(fileReader >> name >> surname >>  dateOfBirth >> street >> houseNumber >> city >> postalCode >> id >> selectMoto)
    	{


			it = new Item(name,surname, dateOfBirth, street, houseNumber,city, postalCode, id, selectMoto);
        	list.insert(it);
     	}
    }

    fileReader.close();
}

void add()   //Add reservation
{
	string name;
	string surname;
    string dateOfBirth;
    string street;
    int houseNumber;
    string city;
    int postalCode;
    int id,selection;
    string selectMoto;

    Date *data;           //for the future development will be used
    Motobike *mobject;  //for the future development will be used

	cout << "Name: ";
	cin >> name;
	cout << "Surname: ";
	cin >> surname;

	Item *tmpItem = NULL;

	tmpItem = list.find(name);

	if (tmpItem == 0)
	{
        cout << "Date Of Birth(dd.mm.year): ";
		cin >> dateOfBirth;
		cout << "Street: ";
		cin >> street;
		cout << "House Number: ";
		cin >> houseNumber;
		cout << "City: ";
		cin >> city;
		cout << "Postal Code: ";
		cin >> postalCode;
		cout << "ID Nummer: ";
		cin >> id;
		cout << "Which Motobike should be selected?"  << endl << "Please insert number ||| 1 ||| 2 ||| 3 ||| 4 ||| : ";
        do
	    {
		    cin >> selection;
	    }while(selection <= 0 || selection >= 4);

	    if(selection==1) {
            if (selectMoto == "")
	        {
		    cout << "Was reserved Suzuki_Bandit"<< endl;
            selectMoto = "Suzuki";
            system("pause");
	        } else {
            cout << "You already have reservation, please first hand over and make new reservation"<< endl;
            }
	    }
        else if(selection ==2)  {
            if (selectMoto == "")
	        {
            cout << "Was reserved Honda_TransAlp"<< endl;
            selectMoto = "Honda";
            system("pause");
            } else {
            cout << "You already have reservation, please first hand over and make new reservation"<< endl;
            }
        }
        else if(selection ==3) {
            if (selectMoto == "")
	        {
            cout << "Was reserved BMW"<< endl;
            selectMoto = "BMW_650_GS";
            system("pause");
	        } else {
            cout << "You already have reservation, please first hand over and make new reservation"<< endl;
            }
        }
        else if(selection ==4) {
            if (selectMoto == "")
	        {

            cout << "Was reserved Kawasaki_ZZR1400"<< endl;
            selectMoto = "Kawasaki";
            system("pause");
	        } else {
            cout << "You already have reservation, please first hand over and make new reservation"<< endl;
            }
        }
	    else
	    cout << "Reservation has been declined." << endl;

        }

	    system("cls");
		Item *object = new Item(name,surname, dateOfBirth, street, houseNumber,city, postalCode, id, selectMoto); //Create new object with newly assigned address
		list.insert(object);
		cout << "Item added." << endl;
	}



void modify()
{
	string name;
	string surname;
	int  no = 1, selection;
	Item *object;

	cout << "Number\tName.\tSurname" << endl;
	for (object=list.begin(); object != 0; object = object->next())
	{
		cout << "[" << no << "]\t";
		object-> displayData();
		cout << endl;
		no++;
	}

	cout << "Which reservation should be altered?" << endl << "Please insert number : ";
	do
	{
		cin >> selection;
	}while(selection <= 0 || selection >= no);

	no = 1;
	for (object=list.begin(); object != 0; object = object->next())
	{
		if(selection==no)
			break;
		no++;
	}

	system("cls");

	cout << "Which item should be altered?" << endl << "[1] Name: " << object->get_name() << "[2] Surname: " << object->get_surname()<< endl << "Please insert number : ";
	do
	{
		cin >> selection;
	}while(selection <= 0 || selection >= 4);

	if(selection==1)
	{
		cout << "New name: ";
		cin >> name;
		object->set_name(name);
	}
    else if(selection ==2)
	{
		cout << "New surname: ";
		cin >> surname;
        if(surname == "")
			throw (string)"Surname";
		object->set_surname(surname);
	}
	cout << "Reservation has been changed." << endl;
}

void display()
{
	float totalprice = 0;
	Item *object;
	int listentries = 0;
	cout << "Name\tSurname\tDateOfBirth\tStreet\tHouseNumber\tCity\tPostalCode\tId\tMotobike" << endl;
	for (object=list.begin(); object != 0; object = object->next())
	{
		object->displayData();

	}

}

void remove()
{
	string name;
	string surname;
	int no=1, selection;
	Item *object;

	cout << "Number\tName\tSurname" << endl;
	for (object=list.begin(); object != 0; object = object->next())
	{
		cout << "[" << no << "]\t";
		object->displayData();
		cout << endl;
		no++;
	}

	cout << "Which reservation should be deleted?" << endl << "Please insert number : ";
	do
	{
		cin >> selection;
	}while(selection <= 0 || selection >= no);

	no = 1;
	for (object=list.begin(); object != 0; object = object->next())
	{
		if(selection==no)
			break;
		no++;
	}
	list.remove(object->get_name());
	cout << "Rservation has been deleted." << endl;
}

void empty()
{
	while(!list.empty())
		list.clear();
	cout << endl << "Reservation list is empty!" << endl;
}



