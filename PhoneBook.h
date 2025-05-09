#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include <iostream>
#include <string>
#include <vector>

class Contact
{
	char* m_name;
	char* m_surname;
	char* m_patronymic;
	size_t m_homenumber;
	size_t m_worknumber;
	size_t m_phonenumber;
	char* m_contactinfo;
public:
	Contact() : m_name(new char[5])
		, m_surname(new char[5])
		, m_patronymic(new char[5]),
		m_homenumber(0)
		, m_worknumber(0)
		, m_phonenumber(0)
		, m_contactinfo(new char[5])
	{
		strcpy_s(m_name, 5, "Null");
		strcpy_s(m_surname, 5, "Null");
		strcpy_s(m_patronymic, 5, "Null");
		strcpy_s(m_contactinfo, 5, "Null");
	}

	Contact(const char* name, const char* surname, const char* patronymic, size_t homenum, size_t worknum, size_t phonenum, const char* cinfo)
		: m_homenumber(homenum)
		, m_worknumber(worknum)
		, m_phonenumber(phonenum)
	{
		m_name = new char[strlen(name) + 1];
		strcpy_s(m_name, strlen(name) + 1, name);
		m_surname = new char[strlen(surname) + 1];
		strcpy_s(m_surname, strlen(surname) + 1, surname);
		m_patronymic = new char[strlen(patronymic) + 1];
		strcpy_s(m_patronymic, strlen(patronymic) + 1, patronymic);
		m_contactinfo = new char[strlen(cinfo) + 1];
		strcpy_s(m_contactinfo, strlen(cinfo) + 1, cinfo);
	}


	~Contact()
	{
		delete[] m_name;
		delete[] m_surname;
		delete[] m_patronymic;
		delete[] m_contactinfo;
	}

	void setName(const char* name) {
		delete[] m_name;
		m_name = new char[strlen(name) + 1];
		strcpy_s(m_name, strlen(name) + 1, name);
	}

	const char* getName() {
		return m_name;
	}

	void setSurname(const char* surname) {
		delete[] m_surname;
		m_surname = new char[strlen(surname) + 1];
		strcpy_s(m_surname, strlen(surname) + 1, surname);
	}

	const char* getSurname() {
		return m_surname;
	}

	void setPatronymic(const char* patronymic) {
		delete[] m_patronymic;
		m_patronymic = new char[strlen(patronymic) + 1];
		strcpy_s(m_patronymic, strlen(patronymic) + 1, patronymic);
	}

	const char* getPatronymic() {
		return m_patronymic;
	}

	void setHomenumber(size_t homenum) {
		m_homenumber = homenum;
	}

	size_t getHomenumber() {
		return m_homenumber;
	}

	void setWorknumber(size_t worknum) {
		m_worknumber = worknum;
	}

	size_t getWorknumber() {
		return m_worknumber;
	}


	void setPhonenumber(size_t phonenum) {
		m_phonenumber = phonenum;
	}

	size_t getPhonenumber() {
		return m_phonenumber;
	}

	void setContactinfo(const char* cinfo) {
		delete[] m_contactinfo;
		m_contactinfo = new char[strlen(cinfo) + 1];
		strcpy_s(m_contactinfo, strlen(cinfo) + 1, cinfo);
	}

	const char* getContactinfo() {
		return m_contactinfo;
	}

};

class PhoneBook
{
	std::vector<Contact> contacts;

public: 
	
	void addContact();

	void printContacts(); 

	void deleteContact(); 

	void findContact();

	const Contact& operator[](size_t index) const {
		return contacts[index]; 
	}

	void saveContacts(const char* filename); 

	void loadContacts(const char* filename); 
};





#endif
