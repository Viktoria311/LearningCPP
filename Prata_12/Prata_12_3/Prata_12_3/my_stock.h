#ifndef MY_STOCK_H_
#define MY_STOCK_H_


class MyStock
{
	private:
		char* company_;
		int shares_;
		double share_val_;
		double total_val_;
		void set_tot() { total_val_ = shares_ * share_val_; }
	public:
		MyStock();
		MyStock(const char* company, long n = 0, double pr = 0.0);
	   ~MyStock();
		void buy(long num, double price);
		void sell(long num, double price);
		void update(double price);
		void show() const;
		const MyStock& topval(const MyStock& s) const;
		friend std::ostream& operator<<(std::ostream& os, const MyStock& st);
};

#endif
