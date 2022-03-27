#ifndef CD_H_
#define CD_H_


class CD
{
	protected:
		char* performers_;
		char* label_;
		int selections_;
		double playtime_;
	public:
		CD(const char* s1, const char* s2, int n, double x);
		CD(const CD& d);
		CD();
		virtual ~CD();
		virtual void Report() const;
		virtual CD& operator=(const CD& d);
		friend std::ostream& operator<<(std::ostream& os, const CD& cd);
};

class Classic : public CD
{
	private:
		char* main_song_;
	public:
		Classic(const char* song, const  char* s1, const char* s2, int n, double x);
		Classic();
		~Classic();
		void Report() const;
		Classic& operator=(const Classic& d);
		friend std::ostream& operator<<(std::ostream& os, const Classic& classic);
};

#endif