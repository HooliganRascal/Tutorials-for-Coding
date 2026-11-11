#ifndef BRASS_H_
#define BRASS_H_
#include <cstring>

typedef std::ios_base::fmtflags form;
typedef std::streamsize prec;

form SETFORMAT(void);
void RESTORE(form f, prec p);

class BRASS
{
private:
	std::string name;
	long num;
	double bal;
public:
	BRASS
	(const std::string& m_name="Null", 
	 long m_num = -1, double m_bal = 0.0);

	virtual ~BRASS(void);

	void DEPOSIT(double money);
	virtual void WITHDRAW(double money);
	double BALANCE(void) const;
	virtual void VIEW_NUM(void) const;
};

class BRASSPLUS: public BRASS // Inheritance
{
private:
	double maxloan;
	double rate;
	double owe;
public:
	BRASSPLUS
	(const std::string& m_name="Null", 
	 long m_num = -1, double m_bal = 0.0, 
	 double m_maxloan = 500, double m_rate = 0.11125);

	BRASSPLUS
	(const BRASS& m_brass, double m_maxloan = 500, 
	 double m_rate = 0.11125);

	virtual ~BRASSPLUS(void);

	inline void RESETMAX(double m){maxloan = m;}
	inline void RESETRATE(double r){rate = r;}
	inline void RESETOWE(void){owe = 0;}
	virtual void VIEW_NUM(void) const;
	virtual void WITHDRAW(double money);
};

#endif
