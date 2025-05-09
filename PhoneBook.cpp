#include "PhoneBook.h"
#include <iostream>
#include <string>
#include <fstream>


void PhoneBook::addContact()
{
	char name[50], surname[50], patronymic[50], contactinfo[100];
	size_t homenum, worknum, phonenum;
	std::cout << "Enter Name: ";
	std::cin >> name;
	std::cout << "Enter Surname: ";
	std::cin >> surname;
	std::cout << "Enter Patronymic: ";
	std::cin >> patronymic;
	std::cout << "Enter Home Number: ";
	std::cin >> homenum;
	std::cout << "Enter Work Number: ";
	std::cin >> worknum;
	std::cout << "Enter Phone Number: ";
	std::cin >> phonenum;
	std::cout << "Enter Contact Info: ";
	std::cin.ignore();  // Игнорируем символ новой строки
	std::cin.getline(contactinfo, 100);
	Contact contact(name, surname, patronymic, homenum, worknum, phonenum, contactinfo);
	contacts.push_back(contact);
}

void PhoneBook::printContacts()
{
	if (contacts.empty())
	{
		std::cout << "Phonebook is empty" << std::endl;
		return;
	}
	for (size_t i = 0; i < contacts.size(); ++i)
	{
		std::cout << "Name: " << contacts[i].getName();
		std::cout << "\nSurname: " << contacts[i].getSurname();
		std::cout << "\nPatronymic: " << contacts[i].getPatronymic();
		std::cout << "\nHomenumber: " << contacts[i].getHomenumber();
		std::cout << "\nWorknumber: " << contacts[i].getWorknumber();
		std::cout << "\nPhonenumber: " << contacts[i].getPhonenumber();
		std::cout << "\nContact info: " << contacts[i].getContactinfo() << std::endl;
	}
}

void PhoneBook::deleteContact()
{
	size_t index; 
	std::cout << "Input number of contact: "; 
	std::cin >> index; 
	index -= 1; 
	if (index < 0 || index >= contacts.size())
	{
		std::cout << "Invalid index" << std::endl; 
		return; 
	}
	contacts.erase(contacts.begin() + index); 
}

void PhoneBook::findContact()
{
	char name[50], surname[50], patronymic[50], contactinfo[100];
	bool key = false; 
	std::cout << "Enter Name: ";
	std::cin >> name;
	std::cout << "Enter Surname: ";
	std::cin >> surname;
	std::cout << "Enter Patronymic: ";
	std::cin >> patronymic;
	for (size_t i = 0; i < contacts.size(); ++i)
	{
		if (strcmp(contacts[i].getName(), name) == 0 && strcmp(contacts[i].getSurname(), surname) == 0 && strcmp(contacts[i].getPatronymic(), patronymic) == 0)
		{
			std::cout << "Name: " << contacts[i].getName();
			std::cout << "\nSurname: " << contacts[i].getSurname();
			std::cout << "\nPatronymic: " << contacts[i].getPatronymic();
			std::cout << "\nHomenumber: " << contacts[i].getHomenumber();
			std::cout << "\nWorknumber: " << contacts[i].getWorknumber();
			std::cout << "\nPhonenumber: " << contacts[i].getPhonenumber();
			std::cout << "\nContact info: " << contacts[i].getContactinfo() << std::endl;
			key = true; 
			break; 
		}
	}
	if (!key)
		std::cout << "Contact is not found" << std::endl; 
}

void PhoneBook::saveContacts(const char* filename)
{
	setlocale(LC_ALL, "");
	std::ofstream outputFile(filename, std::ios::out);
	
	try
	{
		if (!outputFile) {
			throw std::runtime_error("Error while opening file");
		}

		for (Contact& contact : contacts)
		{
			outputFile << contact.getName() << '\n'
				<< contact.getSurname() << '\n'
				<< contact.getPatronymic() << '\n'
				<< contact.getHomenumber() << '\n'
				<< contact.getWorknumber() << '\n'
				<< contact.getPhonenumber() << '\n'
				<< contact.getContactinfo() << '\n';
		}
		outputFile.close();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl; 
	}

	
}

void PhoneBook::loadContacts(const char* filename)
{
	std::ifstream inputFile(filename, std::ios::in); 
	try
	{
		if (!inputFile)
			throw std::runtime_error("Error while opening file"); 
		
		while (!inputFile.eof())
		{
			char name[50], surname[50], patronymic[50], cinfo[50]; 
			size_t homenum, worknum, phonenum; 

			inputFile.getline(name, 50); 
			if (inputFile.eof())
				break; 
			
			inputFile.getline(surname, 50);
			inputFile.getline(patronymic, 50);
			inputFile >> homenum;
			inputFile >> worknum;
			inputFile >> phonenum;
			inputFile.ignore(); 
			inputFile.getline(cinfo, 100);

			Contact contact(name, surname, patronymic, homenum, worknum, phonenum, cinfo); 
			contacts.push_back(contact); 
		}
		
		inputFile.close(); 

	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}
	
	
