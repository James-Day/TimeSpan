#ifndef TIME_SPAN_H
#define TIME_SPAN_H
#include <iostream>
using namespace std;
class TimeSpan
{
public:
	int hours() const;
	int minutes() const;
	int seconds() const;

	void set_time(int hours, int minutes, int seconds);

	TimeSpan();
	TimeSpan(double seconds);
	TimeSpan(double minutes, double seconds);		
	TimeSpan(double hours, double minutes, double seconds); 

	friend ostream& operator<<(ostream& stream, const TimeSpan& ts);
	friend istream& operator>>(istream& stream, TimeSpan& ts); 
	TimeSpan operator+(const TimeSpan& rhs) const; 
	TimeSpan operator-(const TimeSpan& rhs) const; 
	TimeSpan& operator=(const TimeSpan& rhs);	
	TimeSpan& operator-=(const TimeSpan& rhs);	
	TimeSpan& operator+=(const TimeSpan& rhs);	
	bool operator==(const TimeSpan& rhs) const;	
	bool operator!=(const TimeSpan& rhs) const; 
	bool operator<=(const TimeSpan& rhs)const;
	bool operator>=(const TimeSpan& rhs)const;
	bool operator<(const TimeSpan& rhs) const;	
	bool operator>(const TimeSpan& rhs) const;	
	TimeSpan operator-() const;

private:
	int hours_;
	int minutes_;
	int seconds_;

	//Fixes inputs greater than 60 or less than 0
	void FixOverflow(); 
};
#endif
