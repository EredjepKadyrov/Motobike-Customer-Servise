# Motobike Customer Servise(Project created by EK)
##  - Reservation application


I created a motorcycle management program for the bike reservation.
The employee shall be able to manage the customers and make reservations of the motorbikes: Operate with reservationlist.txt(save,edit,delete) 
The customer can only reserve one motorcycle at a time. There are 4 motorbikes to choose from: "Suzuki Bandit", "Honda TransAlp", "BMW F 650 GS" and "Kawasaki ZZR1400"
(taking data from products.txt). The motorbike is not reserved twice. When making the reservation, the customer has to enter his/her name, first name, address (street, postal code, city), 
year of birth, telephone number and whether he/she has a Class A driving license. If he/she does not hold an A driving licence, no motorcycle can be reserved. 
Once the motorcycle has been handed over, the reservation for this customer will be cancelled. The data record is removed from the linked list.

For reservation following info schould be entered:
#### Name
#### Surname
#### Date of birth(as string for future developmet could be used class Date)
#### Street
#### House nummer
#### City
#### Postal Code
#### ID

Additional class Motobike to import and show file with motobikes, contains:
#### Motobike number(first, second and so on)
#### Model name
#### Cost(for future use)
#### Quantity





##  - Process Description
This program covers the following situation:

#### Customer management:

• Enter data(method Add reservation then if "yes" we have drive license enter name and so on). The data has to be collected via istream (>>) operator overloading.
(for the future development we can add age and date with more detailes, special class for this purpose was created)

• Output all customer data. The output has to be done via ostream (<<) operator overloading. File saved to reservationlist.txt, at the start file initialized.

#### Management of the reservations:

• Make a reservation

• Hand over the motorbike (with the customer's first and last name). Remove reservation from the reservationlist.txt 

#### File management:

• The data records should be saved in a linked list.

• The current status of the reservations should be written to the "reservationlist.txt" file. If the file does not yet exist, it should be created. Otherwise the data should be overwritten.

• When the program is started, the file has to be read and the linked list (if there are data records) has to be filled with the data.


The management of customers has to be dynamic. If necessary, respective (error) Messages are to be displayed.


##  - For the submission task a maximum of 30 points can be achieved:
#### • 60% Syntax and semantics (correctness)

       20% Documentation (comprehensibility)

       10% Structuring (readability of the source code, OO principles)

       10% Creativity and your own ideas!


