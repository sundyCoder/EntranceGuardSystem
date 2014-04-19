/*
 * system.h
 *
 *  Created on: 2012-9-2
 *      Author: root
 */

#ifndef SYSTEM_H_
#define SYSTEM_H_
#include <iostream>
using namespace std;
#include <vector>

class Door{
private:
	bool opened;
public:
	Door(){}
	void open(){opened = true;}
	void close(){opened = false;}
	bool isOpened(){return opened;}
};

class InputEquip{
private:
	string msg;
public:
	InputEquip(){}
	void input();
  string getMsg() const;
};

class Computer{
private:
	vector<string> passwds;
	vector<string> cards;
	vector<string> fingers;
public:
	Computer();
	bool valid(string msg);
};


class AccessControlSystem {
private:
	Door door; // 门禁系统的电子门
	Computer computer; // 门禁系统的计算机
	InputEquip inputEquip; // 门禁系统的输入设备
	int ring; // 门铃，0为安静，1为鸣响
	int openSign; // 开门信号，由管理员按下按钮时产生
public:
	AccessControlSystem(){}
	~AccessControlSystem() {
	cout << "~AccessControlSystem()" << endl;
	}

	void work();
	InputEquip& getInputEquip();
	int getOpenSign() const;
	int getRing() const;
	void setOpenSign(int openSign);
	void setRing(int ring);

};

#endif /* SYSTEM_H_ */
