#include "Header.h"

int main()
{
	setlocale(0, "");
	srand(time(0));
	unsigned long int a = (rand() << 16) | rand(), b = (rand() << 16) | rand(), c = (rand() << 16) | rand(), d = (rand() << 16) | rand(), e;
	char *A = word_to_mass(a), *B = word_to_mass(b), *C = word_to_mass(c), *D = word_to_mass(d), E[u + 1];
	bool *Am = mass_to_mb(A), *Bm = mass_to_mb(B), *Cm = mass_to_mb(C), *Dm = mass_to_mb(D), Em[u];
	list *Al = mass_to_list('A', A), *Bl = mass_to_list('B', B), *Cl = mass_to_list('C', C), *Dl = mass_to_list('D', D), *El = mass_to_list('E', nullptr), *temp = El, *temp_end, *del_temp;
	cl_list Acl('A', A), Bcl('B', B), Ccl('C', C), Dcl('D', D), Ecl('E', nullptr);
	cl_mass Acm(A), Bcm(B), Ccm(C), Dcm(D), Ecm;
	out_word('A', a);
	out_word('B', b);
	out_word('C', c);
	out_word('D', d);
	//-------------------------------������ � ��������---------------------------------------------
	{
		short count = 0;
		for (short i = 0; B[i]; ++i)
			for (short j = 0; C[j]; ++j)
				if (B[i] == C[j])
				{
					short k = 0;
					for (; D[k] && B[i] != D[k]; ++k);
					if (D[k] == '\0')
						E[count++] = B[i];
				}
		for (short i = 0; A[i]; ++i)
		{
			bool flag = true;
			for (short j = 0; j < count&&flag; ++j)
				if (A[i] == E[j])
					flag = false;
			if (flag)
				E[count++] = A[i];
		}
		E[count] = '\0';
		cout << "\nE (������) = {" << E << "}\n";
		delete A;
		delete B;
		delete C;
		delete D;
	}
	//-------------------------------������ �� �������---------------------------------------------
	{
		for (list *temp1 = Bl->next; temp1;)
		{
			list *temp3 = Dl->next;
			for (list *temp2 = Cl->next; temp2; )
				if (temp1->letter == temp2->letter)
				{
					for (; temp3 && temp3->letter != temp2->letter; temp3 = temp3->next);
					if (temp3 == nullptr)
					{
						temp->next = temp1;
						temp = temp->next;
					}
					temp2 = nullptr;
				}
				else
					temp2 = temp2->next;
			if (temp3 != nullptr)
			{
				del_temp = temp1;
				temp1 = temp1->next;
				delete del_temp;
			}
			else
				temp1 = temp1->next;
		}
		delete Bl;
		temp_end = temp;
		for (list *temp1 = Al->next; temp1;)
		{
			list *temp2 = El->next;
			for (; temp2 != temp_end->next && temp2->letter != temp1->letter; temp2 = temp2->next);
			if (temp2 == temp_end->next)
			{
				temp->next = temp1;
				temp = temp->next;
				temp1 = temp1->next;
			}
			else
			{
				del_temp = temp1;
				temp1 = temp1->next;
				delete del_temp;
			}
		}
		delete Al;
		temp->next = nullptr;
		cout << El->letter << " (������): {";
		del_temp = El;
		El = El->next;
		delete del_temp;
		for (; El;)
		{
			cout << El->letter;
			del_temp = El;
			El = El->next;
			delete del_temp;
		}
		cout << "}\n";
		clear(Cl);
		clear(Dl);
	}
	//-------------------------------������ � �������� ������--------------------------------------
	{
		e = ((b&c)&~d) | a;
		out_word('E', e);
	}
	//-------------------------------������ � �������� �����---------------------------------------
	{
		for (int count = 0; count < u; Em[count] = ((Bm[count] && Cm[count]) && !Dm[count]) || Am[count], count++);
		cout << "E (������ �����): {";
		for (int count = 0; count < u; count++)
			if (Em[count])
				cout << char(count+'�'); 
		cout << "}\n";
		delete Am;
		delete Bm;
		delete Cm;
		delete Dm;
	}
	//-------------------------------������ � ������� ��������-------------------------------------
	{
		Ecl.add((Bcl.same(&Ccl)->remove(&Dcl))->remove(&Acl));
		Ecl.add(&Acl);
		Ecl.out();
	}
	//-------------------------------������ � ���������-���������----------------------------------
	{
		Ecm.add(Acm.remove(Dcm.remove(Bcm.same(&Ccm))));
		Ecm.add(&Acm);
		Ecm.out();
	}
	system("pause");
	return 0;
}

char *word_to_mass(unsigned long int word)
{
	char *result = new char[u];
	int number = 0;
	for (int count = 0; count < 32; count++)
		if (word&(0x80000000 >> count))
			result[number++] = char(count + '�');
	result[number] = '\0';
	return result;
}

list *mass_to_list(char name, char *mass)
{
	list *result, *temp = nullptr;
	if (mass)
		for (int i = 0; mass[i]; i++)
		{
			result = new list;
			result->next = temp;
			result->letter = mass[i];
			temp = result;
		}
	result = new list;
	result->next = temp;
	result->letter = name;
	return result;
}

bool *mass_to_mb(char *mass)
{
	bool *result=new bool[u];
	for (int count = 0; count < u; result[count++] = 0);
	for (int count = 0; mass[count]; result[mass[count++] - '�'] = 1);
	return result;
}

void out_word(char name, unsigned long int word)
{
	cout << name<< " (�������� �����): {";
	for (int count = 0; count < 32; count++)
		if (word&(0x80000000 >> count))
			cout << char(count + '�');
	cout << "}\n";
}

cl_list::cl_list(char cur_letter, char *mass)
{
	letter = cur_letter;
	if (mass)
	{
		cl_list *next_el = new cl_list(mass, 0);
		next = next_el;
	}
	else
		next = nullptr;
}

cl_list::cl_list(char *mass, int count)
{
	letter = mass[count];
	if (mass[++count])
	{
		cl_list *next_el = new cl_list(mass, count);
		next = next_el;
	}
	else
		next = nullptr;
}

void cl_list::add(cl_list *add_list)
{
	cl_list *temp = this;
	for (; temp->next; temp = temp->next);
	if (add_list->letter > 0)
	{
		temp->next = add_list->next;
		add_list->next = nullptr;
	}
	else
		temp->next = add_list;
}

cl_list *cl_list::same(cl_list *another)
{
	cl_list *result = nullptr, *temp = nullptr, *temp_del = nullptr;
	for (cl_list *temp1 = next; temp1;)
		for (cl_list *temp2 = another->next; temp2; )
			if (temp1->letter == temp2->letter)
			{
				if (!result)
				{
					result = temp1;
					temp = result;
				}
				else
				{
					temp->next = temp1;
					temp = temp1;
				}
				temp2 = nullptr;
				temp1 = temp1->next;
			}
			else
			{
				temp2 = temp2->next;
				if (!temp2)
				{
					temp_del = temp1;
					temp1 = temp1->next;
					delete temp_del;
				}
			}
	temp->next = next = nullptr;
	return result;
}

cl_list *cl_list::remove(cl_list *another)
{
	cl_list *result = this, *prev = nullptr, *temp_del = nullptr;
	for (cl_list *temp1 = this; temp1; )
		for (cl_list *temp2 = another->next; temp2;)
			if (temp1->letter == temp2->letter)
			{
				if (temp1 == result)
				{
					result = result->next;
					prev = result;
				}
				else
					prev->next = temp1->next;
				temp2 = nullptr;
				temp_del = temp1;
				temp1 = temp1->next;
				delete temp_del;
			}
			else
			{
				if (!temp2->next)
				{
					prev = temp1;
					temp1 = temp1->next;
				}
				temp2 = temp2->next;
			}
	return result;
}

void cl_list::out()
{
	cout << letter<<" (������ ��������): {";
	for (cl_list *temp = next; temp; temp = temp->next)
		cout << temp->letter;
	cout << "}\n";
}

cl_list::~cl_list()
{
	if (letter > 0)
		if (next)
		{
			next->letter = 1;
			delete next;
		}
}

void clear(list *cl_list)
{
	list *del_temp;
	for (list *temp = cl_list; temp;)
	{
		del_temp = temp;
		temp = temp->next;
		delete del_temp;
	}
}

cl_mass::cl_mass(char *mass)
{
	this->mass = new char[strlen(mass)+1];
	for (int count = 0; mass[count]; this->mass[count] = mass[count], count++);
	this->mass[strlen(mass)] = '\0';
}

cl_mass::cl_mass()
{
	mass = nullptr;
}

void cl_mass::add(char *mass)
{
	this->mass = mass;
}

void cl_mass::add(cl_mass *another)
{
	int temp2 = strlen(mass);
	for (int temp1 = 0; another->mass[temp1]; mass[temp2++] = another->mass[temp1++]);
	mass[temp2] = '\0';
}

char *cl_mass::remove(char *result)
{
	for (int temp1 = 0; mass[temp1]; temp1++)
		for (int temp2 = 0; result[temp2]; temp2++)
			if (mass[temp1] == result[temp2])
			{
				do
				{
					result[temp2] = result[temp2 + 1];
				} while (result[++temp2]);
			}
	return result;
}

char *cl_mass::same(cl_mass *another)
{
	char *result = new char[u];
	int count = 0;
	for (int temp1 = 0; mass[temp1]; temp1++)
		for (int temp2 = 0; another->mass[temp2]; temp2++)
			if (mass[temp1] == another->mass[temp2])
			{
				result[count] = mass[temp1];
				count++;
			}
	result[count] = '\0';
	return result;
}

void cl_mass::out()
{
	cout << "E (������-������): {" << mass << "}\n";
}

cl_mass::~cl_mass()
{
	delete mass;
}