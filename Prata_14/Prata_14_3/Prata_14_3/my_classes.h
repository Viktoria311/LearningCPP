#ifndef MY_CLASSES_H_
#define MY_CLASSES_H_

#include <string>

class  Worker
{
	private:
		std::string name_;
		long id_;
	protected:
		void EnterName();
		void EnterID();
	public:
		Worker(std::string name, long id);
		Worker();
		virtual ~Worker() = 0;
		virtual void Show() const = 0;
		virtual void Enter() = 0;
};


class Waiter : virtual public Worker
{
	private:
		int panache;
	protected:
		void ShowPanache() const;
		void EnterPanache();
	public:
		Waiter();
		Waiter(std::string n, long id, int p);
		Waiter(const Worker& w, int p = 0);
		virtual ~Waiter();
		void Show() const;
		void Enter();
};

class Singer : virtual public Worker
{
	protected:
		enum { other, alto, contralto, soprano, bass, baritone, tenor };
		void ShowVoice() const;
		void enter_voice();
		void EnterVoice();
	public:
		enum { Vtypes = 7 };
		Singer();
		Singer(std::string n, long id, int v);
		Singer(const Worker& s, int v = 0);
		virtual ~Singer();
		void Show() const;
		void Enter();
		static void show_all_types_of_voices();
	private:
		static std::string v[Vtypes];
		int voice;
};

class SingingWaiter : public Waiter, public Singer
{
	private:
		double luck;
	public:
		SingingWaiter();
		SingingWaiter(std::string n, long id, int p, int v, double l);
		SingingWaiter(const Worker& wor, int p, int v, double l);
		SingingWaiter(const Waiter& wait, int v = other, double l = 0.0);
		SingingWaiter(const Singer& sin, int p = 0, double l = 0.0);
		~SingingWaiter();
		void Show() const;
		void Enter();
};

#endif