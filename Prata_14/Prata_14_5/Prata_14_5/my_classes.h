#ifndef MY_CLASSES_H_
#define MY_CLASSES_H_

#include <string>

class AbstractEmploee
{
	private:
		std::string name_;
		std::string surname_;
		std::string job_;
	protected:
		void SetName();
		void SetSurname();
		void SetJob();
		void ShowName() const;
		void ShowSurname() const;
		void ShowJob() const;
	public:
		AbstractEmploee();
		AbstractEmploee(const std::string& name, const std::string& surname, const std::string& job);
		virtual ~AbstractEmploee() = 0;
		virtual void Show() const;
		virtual void Set();
		friend std::ostream& operator<<(std::ostream& os, const AbstractEmploee& emp);
};

class Emploee : public AbstractEmploee
{
	public:
		Emploee();
		Emploee(const std::string& name, const std::string& surname, const std::string& job);
		~Emploee();
		virtual void Show() const;
		virtual void Set();
};

class Manager : virtual public AbstractEmploee
{
	private:
		int subordinates_;
	protected:
		void SetSubordinates();
		int subordinates() const;
		void ShowSubordinates() const;
	public:
		Manager();
		Manager(const std::string& name, const std::string& surname, const std::string& job, int subordinates = 0);
		Manager(const AbstractEmploee& emp, int subordinates);
		Manager(const Manager& m);
		virtual ~Manager();
		virtual void Show() const;
		virtual void Set();
};

class Fink : virtual public AbstractEmploee
{
	private:
		std::string reports_to_;
	protected:
		void SetReportsTo();
		const std::string& reports_to() const;
		void ShowReportsTo() const;
	public:
		Fink();
		Fink(const std::string& name, const std::string& surname, const std::string& job, const std::string& reports_to);
		Fink(const AbstractEmploee& emp, const std::string& reports_to);
		Fink(const Fink& f);
		virtual ~Fink();
		virtual void Show() const;
		virtual void Set();

};

class HighFink : public Manager, public Fink
{
	public:
		HighFink();
		HighFink(const std::string& name, const std::string& surname, const std::string& job, std::string& reports_to, int subordinates);
		HighFink(const AbstractEmploee& emp, const std::string& reports_to, int subordinates);
		HighFink(const Fink& f, int subordinates);
		HighFink(const Manager& m, const  std::string& reports_to);
		HighFink(const HighFink& h);
		virtual ~HighFink();
		virtual void Show() const;
		virtual void Set();
};

#endif