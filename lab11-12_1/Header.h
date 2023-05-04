#pragma once

#include<string>
#include<iostream>

using namespace std;

class StateContex;

//Абстрактный класс Состояние
class State
{
private:
	string name;
public:
	State(const string& name) : name(name) {}
	string GetName(){ return name;}
	virtual void On(StateContex*) = 0;
	virtual void Off(StateContex*) = 0;
};

//Класс Context определяет внешний интерфейс для клиентов
class StateContex
{
private:
	State* state;
public:
	StateContex(State* state) : state(state) {}
	void On() 
	{ 
		cout << "On - " << state->GetName() << "...\n\n" << endl; 
		state->On(this);
	}
	void Off()
	{
		cout << "Off - " << state->GetName() << "...\n\n" << endl;
		state->Off(this);
	}

	void SetState(State* s)
	{
		cout << "Changing state from " << state->GetName()
			<< " to " << s->GetName() << "..." << endl;
		delete state;
		state = s;
	}

	State* GetState()
	{
		return state;
	}

	~StateContex()
	{
		delete state;
	}

};


class OnState : public State
{
public:
	OnState() : State("On") {}
	virtual void On(StateContex* state);
	virtual void Off(StateContex* state);
};

class OffState : public State
{
public:
	OffState() : State("Off") {}
	virtual void On(StateContex* state);
	virtual void Off(StateContex* state);
};

void OnState::On(StateContex* state)
{
	cout << "Nothing happens" << endl;
}

void OnState::Off(StateContex* state)
{
	state->SetState(new OffState());
}

void OffState::On(StateContex* state)
{
	state->SetState(new OnState());
}

void OffState::Off(StateContex* state)
{
	cout << "Nothing happens" << endl;
}

