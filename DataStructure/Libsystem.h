#pragma once
#include<iostream>
#include<string>
#include<list>
#include<algorithm>

using namespace std;

class Patron;

class Book {
public:
	Book() {
		patron = 0;
	}

	bool operator == (const Book& bk) const {
		return strcmp(title, bk.title) == 0;
	}

private:
	char *title;
	Patron*patron;
	ostream& printBook(ostream&) const;
	friend ostream& operator<<(ostream& out, const Book& bk) {
		return bk.printBook(out);
	}

	friend class CheckedOutBook;
	friend Patron;
	friend void includeBook();
	friend void checkOutBook();
	friend void returnBook();

};


class Author {
public:
	Author() {
	}

	bool operator== (const Author& ar) const {
		return strcmp(name, ar.name) == 0;
	}

private:
	char*name;
	list<Book>books;
	ostream& printAuthor(ostream&)const;
	friend ostream& operator<<(ostream& out, const Author& ar) {
		return ar.printAuthor(out);
	}
	friend void includeBook();
	friend void checkOutBook();
	friend void returnBook();
	friend class CheckedOutBook;
	friend Patron;

};

class CheckedOutBook {
public:
	CheckedOutBook(list<Author>::iterator ar = 0,list<Book>::iterator bk=0)
};
