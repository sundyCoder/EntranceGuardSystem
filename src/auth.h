/*
 * auth.h
 *
 *  Created on: 2012-9-2
 *      Author: root
 */

#ifndef AUTH_H_
#define AUTH_H_

#include <vector>
using namespace std;

class Validate{
public:
        virtual ~Validate(){}
        virtual bool check() = 0;
};

class GenericVal:public Validate{
private:
  vector<string> infos;
	string msg;
public:
 GenericVal(vector<string>infos,string msg):infos(infos),msg(msg){}
 bool check(){
   for (unsigned int i = 0; i < infos.size(); ++i) {
   if(msg == infos[i]) return true;
        }
   return false;
        }
};

class PasswdVld:public GenericVal{
public:
        PasswdVld(vector<string> infos,string msg):GenericVal(infos,msg){}
};

class CardVld:public GenericVal{
public:
        CardVld(vector<string> infos,string msg):GenericVal(infos,msg){}
};

class FingerVld:public GenericVal{
public:
        FingerVld(vector<string> infos,string msg):GenericVal(infos,msg){}
};


#endif /* AUTH_H_ */
