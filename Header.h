#pragma once
#include <iostream>
using namespace std;
const int u = 32; 

#ifdef _DEBUG//Это для отслеживания утечек памяти
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC
#endif
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)

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
	//~cl_list();//вернуть перед отчетом, работает
	void out();
	void clear();
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
unsigned long int mass_to_byte(char*);
bool *mass_to_mb(char*);
void out_word(unsigned long int);
void memory_leaks();
void clear(list*);