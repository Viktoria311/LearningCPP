#ifndef CLASSES_H_
#define CLASSES_H_


class MyABC
{
	private:
		int rating;
	public:
		MyABC(int r = 0);
	    virtual ~MyABC() {}
		virtual void Show() const = 0;
};

class BaseDMA : public MyABC
{
	private:
		char* label_;
	public:
		BaseDMA(int r = 0, const char* c = "some");
		BaseDMA(const BaseDMA& b);
	   ~BaseDMA();
	    BaseDMA& operator=(const BaseDMA& b);
		void Show() const;
};

class LacksDMA : public MyABC
{
	private:
		static const int MAX = 40;
		char color[MAX];
	public:
		LacksDMA(int r = 0, const char* c = "some");
	   ~LacksDMA() {}
		void Show() const;
};

class HasDMA : public MyABC
{
	private:
		char* style_;
	public:
		HasDMA(int r = 0, const char* c = "some");
		HasDMA(const HasDMA& h);
		~HasDMA();
		HasDMA& operator=(const HasDMA& h);
		void Show() const;
};


#endif