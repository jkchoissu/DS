
#include "CreditCard.h"				// provides CreditCard

using namespace std;				// make std:: accessible
									// standard constructor
CreditCard::CreditCard(const string& no, const string& nm, int lim, double bal, double rate) {
  number = no;
  name = nm;
  balance = bal;
  limit = lim;
  interestRate = rate;
}
									// make a charge
bool CreditCard::chargeIt(double price) {
  if (price <= 0) {
	  cerr << " price is not positive : " << price << endl;
	  return false;
  }
  if (price + balance > double(limit)) {
	  cerr << " over limit : " << limit << endl;
    return false;					// over limit
  }
  balance += price;
  return true;						// the charge goes through
}

void CreditCard::makePayment(double payment) {	// make a payment
  if (payment <= 0) {
	  cerr << " Payment is not positive : " << payment << endl;
	  return;
  }
  balance -= payment*(1 - interestRate);
}
  									// print card information
ostream& operator<<(ostream& out, const CreditCard& c) {
  out << "Number = "        << c.getNumber()      << "\n"
      << "Name = "          << c.getName()        << "\n"
      << "Balance = "       << c.getBalance()     << "\n"
      << "Limit = "         << c.getLimit()       << "\n";
  return out;
}



