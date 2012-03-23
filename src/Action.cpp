#include "include/Action.h"

Action::Action()
{
	this->action_name = "undefined";
	this->message = "";
	this->damage = 0;
}

Action::Action(string name, string msg, float dmg)
{
	this->action_name = name;
	this->message = msg;
	this->damage = dmg;
}