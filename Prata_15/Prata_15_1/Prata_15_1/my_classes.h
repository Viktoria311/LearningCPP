#ifndef  MY_CLASSES_H_
#define  MY_CLASSES_H_

class Remote;
class Tv
{
	friend class Remote;
	private:
		int state;
		int volume;
		int maxchannel;
		int channel;
		int mode;
		int input;
	public:
		enum State{On, Off};
		enum { MinVal, MaxVal = 20 };
		enum {Antenna, Cabel};
		enum {TV, DVD};
		Tv(int s = Off, int mc = 25) : state(s), volume(5), maxchannel(mc), channel(2), mode(Cabel), input(TV) { }
		void onoff() { state = (state == On) ? Off : On; }
		bool ison() const { return state == On; }
		bool volup();
		bool voldown();
		void chanup();
		void chandown();
		void set_mode() { mode = (mode == Antenna) ? Cabel : Antenna; }
		void set_input() { input = (input == TV) ? DVD : TV; }
		void settings() const;
		void set_remote(Remote & r);
};

class Remote
{
	friend class Tv;
	private:
		int mode_tv;
		int mode_remote;
	public:
		enum State { On, Off };
		enum { MinVal, MaxVal = 20 };
		enum { Antenna, Cabel };
		enum { TV, DVD };
		enum { normal, interactive };
		Remote(int m = TV, int n = normal) : mode_tv(m), mode_remote(n) { }
		void onoff_tv(Tv& t);
		bool volup(Tv& t);
		bool voldown(Tv& t);
		void chanup(Tv& t);
		void chandown(Tv& t);
		void set_mode_tv() { mode_tv = (mode_tv == Antenna) ? Cabel : Antenna; }
		void set_mode_remote() { mode_remote = (mode_remote == normal) ? interactive : normal; }
		void set_input(Tv& t) { t.set_input(); }
		void set_chan(Tv& t, int c) { t.channel = c; }
		void show_mode_remote() const
		{ 
			if (mode_remote == 0)
			std::cout << "normal" << std::endl;
			else 
				std::cout << "interactive" << std::endl;
		}
};

inline bool Tv::volup()
{
	if (volume == MaxVal)
		return false;
	++volume;
	return true;
}

inline bool Tv::voldown()
{
	if (volume == MinVal)
		return false;
	--volume;
	return true;
}

inline void Tv::chanup()
{
	if (channel == maxchannel) channel = 1;
	else ++channel;
}

inline void Tv::chandown()
{
	if (channel == 1) channel = maxchannel;
	else --channel;
}

inline void Tv::settings() const
{
	if (state == On)
	{
		std::cout << "Channel = " << channel << std::endl;
		std::cout << "Volume = " << volume << std::endl;
		std::cout << "Mode = " << (mode == Antenna ? "Antenna" : "Cabel" ) << std::endl;
		std::cout << "Input = " << (input == TV ? "TV" : "DVD") << std::endl;
	}
}
        
inline void Tv::set_remote(Remote & r)
{
	if (ison())
		r.set_mode_remote();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
inline void Remote::onoff_tv(Tv& t)
{
	t.onoff();
}

inline bool Remote::volup(Tv& t)
{
	return t.volup();
}

inline bool Remote::voldown(Tv& t)
{
	return t.voldown();
}

inline void Remote::chanup(Tv& t)
{
	t.chanup();
}

inline void Remote::chandown(Tv& t)
{
	t.chandown();
}

#endif