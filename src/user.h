/*
 * user.h
 *
 *  Created on: 2012-9-2
 *      Author: root
 */

#ifndef USER_H_
#define USER_H_
#include <string.h>
#include "system.h"

class Guest{
private:
	string name;
public:
	Guest(string name):name(name){}
	void pressRing(AccessControlSystem& acs);
	string getName() const;
	void setName(string name);
};

class Employee:public Guest{
public:
	Employee(string name):Guest(name){}
	void input(AccessControlSystem& acs);
};

class Admin:public Employee{
public:
	Admin(string name):Employee(name){}
	void work(AccessControlSystem& acs);
};



#endif /* USER_H_ */
