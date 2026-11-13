#ifndef ABSTRACT_H_
#define ABSTRACT_H_
#include <iostream>
#include <cstring>

class ABSTRACT
{
private:
	std::string name;
	long num_account;
	double balance;

protected:
	struct FORM
	{
		std::ios_base::fmtflags flag;
		std::streamsize prec;
	};
	inline const std::string& NAME(void) const{return name;}
	inline long NUM_ACCOUNT(void) const{return num_account;}
	FORM SET_FORMAT(void) const;
	void RESTORE(FORM& f) const;

public:
	ABSTRACT
	(const std::string& s="Nullbody", 
	 long an=-1, double bal = 0.0);
	void DEPOSIT(double money);
	inline double BALANCE(void) const{return balance;}
	virtual void WITHDRAW(double money)=0; // pure virtual 
	virtual void VIEW_ACCOUNT(void) const=0; // pure virtual no def
	virtual ~ABSTRACT(void){}; // it is necessary!
};

class BRASS : public ABSTRACT
{
public:
	inline BRASS
	(const std::string& s="Nullbody", 
	 long an=-1, double bal=0.0) : 
	ABSTRACT(s,an,bal){} // member initializer list
	inline virtual ~BRASS(void){};

	virtual void WITHDRAW(double money); // override
	virtual void VIEW_ACCOUNT(void) const;	
}; // no need the private

class BRASSPLUS : public ABSTRACT
{
private: // new features added as private members
	double max_loan;
	double rate;
	double owe_bank;

public:
	BRASSPLUS
	(const std::string& s="Nullbody",
	 long an=-1, double bal=0.0, double ml=500, double r=0.1);
	BRASSPLUS
	(const ABSTRACT& ba, double ml=500, double r=0.1);
	inline virtual ~BRASSPLUS(void){};

	virtual void WITHDRAW(double money); // pure virtual
	virtual void VIEW_ACCOUNT(void) const; 
	inline void RESER_MAX(double m){max_loan = m;}
	inline void RESER_RATE(double r){rate = r;}
	inline void RESER_OWE(void){owe_bank = 0;}
};

#endif
