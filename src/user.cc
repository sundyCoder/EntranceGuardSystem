

#include "user.h"

string Guest::getName() const
{
    return name;
}

void Guest::setName(string name)
{
    this->name = name;
}

void Guest::pressRing(AccessControlSystem& acs){
	 cout << name << "按下门铃?[y/n]";
	char ch;
	cin >> ch;
	if (ch == 'y') {
		acs.setRing(1);
	} else {
		acs.setRing(0);
	}
}

void Employee::input(AccessControlSystem& acs){
	acs.getInputEquip().input();
}

void Admin::work(AccessControlSystem& acs) {
	cout << "管理员" << getName() << "按下监控室里的开门按钮?[y/n/q]:";
	char ch;
	cin >> ch;
	if (ch == 'y') {
		acs.setOpenSign(1);
	} else if (ch == 'q') {
		exit(0);
	} else {
		acs.setOpenSign(0);
	}
}



