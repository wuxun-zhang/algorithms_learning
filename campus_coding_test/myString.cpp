#include<iostream>
#include<cstring>
using namespace std;

class myString
{
	friend ostream& operator <<(ostream& os, const myString& str);
	friend istrean& operator >>(istrean& is, const myString& str);
public:
	myString(const char *str=nullptr);
	myString(const myString& other);
	~myString(void);
	myString& operator =(const myString& other);
	myString operator +(const myString& other);
	bool operator ==(const myString& other);
	int getLength(void) const;
private:
	char *m_data;	
};


myString::myString(const char* str){
	if(str == nullptr)
		this->m_data = nullptr;
	else
	{
		this->m_data = new char [strlen(str)+1];
		strcpy(this->m_data, str);
	}
}

// copy construction function
myString::myString(const myString& other){
	if(other.m_data == nullptr)
		this->m_data = nullptr;
	else{
		this->m_data = new char[strlen(other.m_data)+1];
		strcpy(this->m_data, other.m_data);
	}
}

// deconstruction function
myString::~myString(void){
	if(this->m_data != nullptr){
		delete[] m_data;
		this->m_data = nullptr;
	}
}

myString& myString::operator =(const myString& other){
	//// low
	// if(this == &other)
	// 	return *this;
	// delete [] m_data;
	// m_data = nullptr;
	// m_data = new char [strlen(other.m_data)+1];
	// strcpy(m_data, other.m_data);
	// return *this;

	// high
	if(this != &other){
		myString temp(other);
		char *pTemp = temp.m_data;
		temp.m_data = m_data;
		m_data = pTemp;
	}
	return *this;
}


myString myString::operator +(const myString& other){
	myString newString;
	if(other.m_data == nullptr)
		return *this;
	else if(this->m_data){
		newString = other;
	}else{
		newString.m_data = new char[strlen(other.m_data)+strlen(this->m_data)+1];
		strcpy(newString.m_data, this->m_data);
		strcpy(newString.m_data, other.m_data);		
	}
	return newString;
}

bool myString::operator ==(const myString& other){
	if(this == &other)
		return true;

	if(strlen(this->m_data) != strlen(other.m_data))
		return false;
	else
		return strcmp(this->m_data, other.m_data)?false:true;
}

int myString::getLength(void) const {
	return strlen(this->m_data);
}


friend ostream& operator <<(ostream& os, const myString& str){
	os<<str->m_data;
	return os;
}

friend istrean& operator >>(istrean& is, const myString& str){
	in>>str->m_data;
	return is;
}