#include <iostream>
#include <string>
#include "my_classes.h"


Worker::Worker(std::string name, long id) : name_(name), id_(id)
{

}

Worker::Worker() : name_("some"), id_(0L)
{

}

Worker::~Worker() { }

void Worker::EnterName()
{
	std::cout << "Enter a name: ";
	getline(std::cin, name_);
}

void Worker::EnterID()
{
	std::cout << "Enter ID: ";
	while (!(std::cin >> id_))
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Uncorrect enter. Try again to enter ID: ";
	}
}

void Worker::Show() const
{
	std::cout << "Name: " << name_ << std::endl;
	std::cout << "ID: " << id_ << std::endl;
}

void Worker::Enter()
{
	EnterName();
	EnterID();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//WAITER

Waiter::Waiter() : Worker(), panache(0)
{

}

Waiter::Waiter(std::string n, long id, int p) : Worker(n, id), panache(p)
{

}

Waiter::Waiter(const Worker& w, int p) : Worker(w), panache(p)
{

}

Waiter::~Waiter() { }

void Waiter::ShowPanache() const
{
	std::cout << "Panache: " << panache << std::endl;
}

void Waiter::Show() const
{
	Worker::Show();
	ShowPanache();
}

void Waiter::EnterPanache()
{
	std::cout << "Enter panache: ";
	while (!(std::cin >> panache))
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Try again to enter panache: ";
	}
}

void Waiter::Enter()
{
	Worker::Enter();
	EnterPanache();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//SINGER

std::string Singer::v[Singer::Vtypes] = { "other", "alto", "contralto", "soprano", "bass", "baritone", "tenor" };

Singer::Singer() : Worker(), voice(0)
{

}

Singer::Singer(std::string n, long id, int v) : Worker(n, id), voice(v)
{

}

Singer::Singer(const Worker& s, int v) : Worker(s), voice(v)
{

}

Singer::~Singer() { }

void Singer::ShowVoice() const
{
	std::cout << "Voice: " << v[voice - 1] << std::endl;
}

void Singer::show_all_types_of_voices()
{
	for (int i = 0; i < Vtypes; ++i)
		std::cout << v[i] << " - " << i + 1 << "  ";
	std::cout << std::endl;
}

void Singer::enter_voice()
{
	while (!(std::cin >> voice))
	{

		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Try again to enter panache: ";
	}
}

void Singer::EnterVoice()
{
	bool right;
	
	do
	{
		std::cout << "Enter a numper of singer`s voise range." << std::endl;
		show_all_types_of_voices();
		enter_voice();

		if (voice != 1 && voice != 2 && voice != 3 && voice != 4 && voice != 5 && voice != 6 && voice != 7)
			right = false;
		else right = true;

	} while(right);
	
}

void Singer::Show() const
{
	Worker::Show();
	ShowVoice();
}

void Singer::Enter()
{
	Worker::Enter();
	EnterVoice();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//SINGINGWAITER

SingingWaiter::SingingWaiter() : Worker(), Waiter(), Singer(), luck(0.0)
{

}

SingingWaiter::SingingWaiter(std::string n, long id, int p, int v, double l) : Worker(n, id), Waiter(n, id, p), Singer(n, id, v), luck(l)
{

}

SingingWaiter::SingingWaiter(const Worker& wor, int p, int v, double l) : Worker(wor), Waiter(wor, p), Singer(wor, v), luck(l)
{

}

SingingWaiter::SingingWaiter(const Waiter& wait, int v, double l) : Worker(wait), Waiter(wait), Singer(wait, v), luck(l)
{

}

SingingWaiter::SingingWaiter(const Singer& sin, int p, double l) : Worker(sin), Waiter(sin, p), Singer(sin), luck(l)
{

}

SingingWaiter::~SingingWaiter() { }

void SingingWaiter::Show() const
{
	Worker::Show();
	ShowPanache();
	ShowVoice();
}

void SingingWaiter::Enter()
{
	Worker::Enter();
	EnterPanache();
	EnterVoice();
}