#ifndef MY_CLASSES_H_
#define MY_CLASSES_H_

#include <string>

class Person
{
	private:
		std::string name_;
		std::string surname_;
	protected:
		void ShowName() const;
		void ShowSurname() const;
	public:
		Person();
		Person(std::string& name, std::string surname);
		virtual ~Person();
		virtual void Show() const;
};

class Gunslinger : virtual public Person
{
	private:
		double prepare_time_;
		int quantity_of_rifle_notches_;
	protected:
		void ShowPrepareTime() const;
		void ShowNotches() const;
	public:
		Gunslinger();
		Gunslinger(const Person& p, double t, int q);
		Gunslinger(std::string& name, std::string surname, double t, int q);
		virtual ~Gunslinger();
		virtual void Show() const;
		double Draw() const;
};

class PockerPlayer : virtual public Person
{
	public:
		PockerPlayer();
		PockerPlayer(std::string& name, std::string surname);
		PockerPlayer(const Person& p);
		virtual ~PockerPlayer();
		virtual void Show() const;// Show от Person
		int Draw() const;// случайное число от 1 до 52. это карта
};

class BadDude : public Gunslinger, public PockerPlayer
{
	protected:

	public:
		BadDude();
		BadDude(const Person& p, double prepare_time, int notches);
		BadDude(std::string& name, std::string surname, double prepare_time, int notches);
		BadDude(const PockerPlayer& p, double prepare_time, int notches);
		BadDude(const  Gunslinger& g);
		double Gdraw() const;// время вынимания оружия
		int Cdraw() const;// возвращает следующую вытянутую карту
		virtual void Show() const;
};

#endif
