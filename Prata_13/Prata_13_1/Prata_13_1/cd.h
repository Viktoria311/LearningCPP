#ifndef CD_H_
#define CD_H_

#include <string>

class CD
{
	protected:
		std::string performers_;
		std::string label_;
		int selections_;
		double playtime_;
	public:
		 CD(const std::string& s1, const std::string& s2, int n, double x);
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
		std::string main_song_;
	public:
		Classic(const std::string& song, const std::string& s1, const std::string& s2, int n, double x);
		Classic();
	   ~Classic();
	   void Report() const;
		Classic& operator=(const Classic& d);
		friend std::ostream& operator<<(std::ostream& os, const Classic& classic);
};

#endif
