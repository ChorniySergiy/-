#include <iostream>
#include "PhoneBook.h"
#include <fstream>
#include <string>

int main()
{
	setlocale(LC_ALL, ""); 

	PhoneBook pb; 

	size_t menu; 

	
	while (true)
	{
		system("cls"); 
		std::cout << "Menu:\n1. Add contact\n2. Print Contacts\n3. Delete contact\n4. Find Contact\n5. Write contacts\n6. Load contacts" 
			<< std::endl;
		std::cin >> menu; 
		system("cls");
		switch (menu)
		{
			case 1:
				pb.addContact(); 
				break; 
			case 2: 
				pb.printContacts(); 
				system("pause"); 
				break; 
			case 3: 
				pb.deleteContact(); 
				break; 
			case 4:
				pb.findContact(); 
				system("pause"); 
				break; 
			case 5: 
				try
				{
					pb.saveContacts("Contacts.txt");
					std::cout << "Saving successfully" << std::endl; 
					system("pause"); 
				}
				catch(std::runtime_error& e)
				{
					std::cout << "Error: " << e.what() << std::endl; 
				}
				break; 
			case 6: 
				pb.loadContacts("Contacts.txt"); 
				std::cout << "Loading successfully" << std::endl;
				system("pause");
				break; 
			default:
				return 0; 
				break;
		}
	}


	
}