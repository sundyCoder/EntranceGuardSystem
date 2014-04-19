/*
 * main.cc
 *
 *  Created on: 2012-9-2
 *      Author: root
 */

#include <iostream>
using namespace std;
#include "user.h"
#include "system.h"

int main() {

	Admin admin("wang");
	AccessControlSystem acs;

	while (1) {
		acs.work();
		admin.work(acs);
	}

	/*Admin admin("wang");
	Guest guest("chen");
	AccessControlSystem acs;

	while (1) {
		acs.work();
		guest.pressRing(acs);
		admin.work(acs);
	}

	AccessControlSystem acs;
	Employee emp("hong");
	while (1) {
		acs.work();
		emp.input(acs);
	}*/
	return 0;
}
