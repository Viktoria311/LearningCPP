#ifndef GOLF_H_
#define GOLF_H_


class Golf
{
	private:
		static const int LEN = 40;
		char fullname_[LEN];
		int handicap_;
	public:
		Golf();
		Golf(const char* fullname, int handicap = 0);
		Golf(int handicap, const char* fullname = "New user");
	   ~Golf(){}
	    static const int ReturnLEN();
	    const char* Fullname() const;
		int Handicap() const;
		void ChangeHandicap(int handicap);
		void ShowGolf() const;
};

#endif