#pragma once
#include <iostream>
#include "time.h"
using namespace std;
const int u = 32; 

struct list
{
	char letter;
	list* next;
};

class cl_list
{
private:
	char letter;
	cl_list *next;
public:
	cl_list(char, char*);
	cl_list(char*, int);
	void add(cl_list*);
	cl_list *same(cl_list*);
	cl_list *remove(cl_list*);
	~cl_list();
	void out();
};

class cl_mass
{
private:
	char *mass;
public:
	cl_mass(char*);
	cl_mass();
	void add(char*);
	void add(cl_mass*);
	char *same(cl_mass*);
	char *remove(char*);
	void out();
	~cl_mass();
};

list *mass_to_list(char, char*);
char *word_to_mass(unsigned long int);
bool *mass_to_mb(char*);
void clear(list*);
void out_word(char, unsigned long int);