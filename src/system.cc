
#include "system.h"
#include "auth.h"
#include <vector>
using namespace std;

string InputEquip::getMsg() const{
    return msg;
}

void InputEquip::input() {
	cout << "清输入验证信息:";
	cin >> msg;
}

Computer::Computer(){
	for (int i = 0; i < 20; ++i) {
				passwds.push_back("aaa");
				cards.push_back("bbbb");
				fingers.push_back("ccc");
			}
}

bool Computer::valid(string msg){
	 string prefix = msg.substr(0, 2);
	string content = msg.substr(2);
	Validate* p = NULL;
	if ("pa" == prefix) {
		p = new PasswdVld(passwds, content);
	} else if ("ca" == prefix) {
		p = new CardVld(cards, content);
	} else if ("fi" == prefix) {
		p = new FingerVld(fingers, content);
	}
	if (p != NULL) {
		bool ret = p->check();
		delete p;
		return ret;
	}
	return false;
}

void AccessControlSystem::work() {
	string msg = inputEquip.getMsg();
	if (!msg.empty()) {
		if (computer.valid(msg)) {
			door.open();
			cout << "用户验证通过,打开电子们!" << endl;
			;
		} else {
			cout << "验证失败" << endl;
		}
	}

	if (openSign == 1) {
		door.open();
		cout << "管理员按下开门按钮,打开电子门！" << endl;
	}

	if (door.isOpened()) {
		sleep(3);
		door.close();
		cout << "电子们打开3秒钟" << endl;
	}
}

InputEquip& AccessControlSystem::getInputEquip()
{
    return inputEquip;
}

int AccessControlSystem::getOpenSign() const
{
    return openSign;
}

int AccessControlSystem::getRing() const
{
    return ring;
}

void AccessControlSystem::setOpenSign(int openSign)
{
    this->openSign = openSign;
}

void AccessControlSystem::setRing(int ring)
{
    this->ring = ring;
}
