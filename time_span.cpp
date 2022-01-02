#include "time_span.h"
const int kTimeInMinute = 60;
const int kTimeInHour = 60;
int TimeSpan::hours() const
{
	return hours_;
}
int TimeSpan::minutes() const
{
	return minutes_;
}
int TimeSpan::seconds() const
{
	return seconds_;
}
void TimeSpan::set_time(int hours, int minutes, int seconds)
{
	hours_ = hours;
	minutes_ = minutes;
	seconds_ = seconds;
	FixOverflow();
}

TimeSpan::TimeSpan()
{
	hours_ = 0;
	minutes_ = 0;
	seconds_ = 0;
}

TimeSpan::TimeSpan(double seconds)
{
	double extra = seconds - (int)seconds;				
	if (extra > 0.5) {
		seconds++;
	}
	hours_ = 0;
	minutes_ = 0;
	seconds_ = seconds;
	FixOverflow();
}

TimeSpan::TimeSpan(double minutes, double seconds)
{
	double extra = minutes - (int)minutes;
	extra = extra * kTimeInMinute;
	if ((extra - (int)extra) > 0.5) {					
		extra -= (extra - (int)extra);
		extra++;
	}
	seconds = seconds + (int)extra;

	hours_ = 0;
	minutes_ = minutes;
	seconds_ = seconds;
	FixOverflow();
}

TimeSpan::TimeSpan(double hours, double minutes, double seconds)
{
	double extra = hours - (int) hours;
	extra = (extra * kTimeInHour) + minutes;
	minutes = (int)extra;
	extra -= (int)extra;
	extra = (extra * kTimeInMinute) + seconds;				
	if ((extra - (int)extra) > 0.5) {
		extra -= (extra - (int)extra);
		extra++;
	}
	seconds =  (int)extra; 

	hours_ = hours;
	minutes_ = minutes;
	seconds_ = seconds;
	FixOverflow();
}



void TimeSpan::FixOverflow()
{
	int add_minutes = seconds_ / kTimeInMinute;				
	int add_hours = minutes_ / kTimeInHour;

	if (abs(seconds_) > kTimeInMinute) {
		minutes_ += add_minutes;
		seconds_ -= add_minutes * kTimeInMinute;
	}
	if (abs(minutes_) > kTimeInHour) {
		hours_ += add_hours;
		minutes_ -= add_hours * kTimeInHour;
	}

	add_minutes = seconds_ / kTimeInMinute;
	add_hours = minutes_ / kTimeInHour;

	if (seconds_ < 0) {
		minutes_ += add_minutes - 1;
		seconds_ += ((abs(add_minutes) + 1) * kTimeInMinute);
	}
	if (minutes_ < 0) {
		hours_ += add_hours -1;
		minutes_ += ((abs(add_hours) + 1) * kTimeInHour);
	}

	if (hours_ < 0 && minutes_ > 0) { 
		hours_++;
		minutes_-= kTimeInHour;
	}
	if (minutes_ < 0 && seconds_ > 0) {
		minutes_++;
		seconds_-= kTimeInMinute;
	}								   
}

ostream& operator<<(ostream& stream, const TimeSpan& ts)
{
	cout << "Hours: " << ts.hours_ << ", Minutes: " << ts.minutes_ << ", Seconds: " << ts.seconds_;

	return stream;
}

istream& operator>>(istream& stream, TimeSpan& ts)
{
	cout << "Enter the amount of hours: " << endl;
	stream >> ts.hours_;
	cout << "Enter the amount of minutes: " << endl;
	stream >> ts.minutes_;
	cout << "Enter the amount of seconds: " << endl;
	stream >> ts.seconds_;
	ts.FixOverflow();
	return stream;
}

TimeSpan TimeSpan::operator+(const TimeSpan& rhs) const
{
	TimeSpan result = *this;
	result += rhs;
	return result;
}

TimeSpan TimeSpan::operator-(const TimeSpan& rhs) const
{
	TimeSpan result = *this;
	result -= rhs;
	return result;
}

TimeSpan& TimeSpan::operator-=(const TimeSpan& rhs)
{
	hours_ = hours() - rhs.hours();
	minutes_ = minutes() - rhs.minutes();
	seconds_ = seconds() - rhs.seconds();
	FixOverflow();
	return *this;
}

TimeSpan& TimeSpan::operator+=(const TimeSpan& rhs)
{
	
	hours_ = this->hours_ + rhs.hours_;
	minutes_ = this->minutes_ + rhs.minutes_;
	seconds_ = this->seconds_ + rhs.seconds_;
	FixOverflow();
	return *this;
}

bool TimeSpan::operator==(const TimeSpan& rhs) const
{
	bool equal = true;
	if (hours() != rhs.hours()) {
		equal = false;
	}
	if (minutes() != rhs.minutes()) {
		equal = false;
	}
	if (seconds() != rhs.seconds()) {
		equal = false;
	}

	return equal;
}

bool TimeSpan::operator!=(const TimeSpan& rhs)const
{
	return !(*this == rhs);
}

bool TimeSpan::operator<=(const TimeSpan& rhs) const
{
	float total_time = 0;
	float rhs_total_time = 0;

	total_time = (float)hours() + ((float)minutes() / kTimeInHour) + ((float)seconds() / (kTimeInHour * kTimeInMinute));
	rhs_total_time = (float)rhs.hours() + ((float)rhs.minutes() / kTimeInHour) + ((float)rhs.seconds() / (kTimeInHour * kTimeInMinute));

	return total_time <= rhs_total_time;
}

bool TimeSpan::operator>=(const TimeSpan& rhs) const
{
	float total_time = 0;
	float rhs_total_time = 0;

	total_time = (float)hours() + ((float)minutes() / kTimeInHour) + ((float)seconds() / (kTimeInHour * kTimeInMinute));
	rhs_total_time = (float)rhs.hours() + ((float)rhs.minutes() / kTimeInHour) + ((float)rhs.seconds() / (kTimeInHour * kTimeInMinute));

	return total_time >= rhs_total_time;
}

bool TimeSpan::operator<(const TimeSpan& rhs) const
{
	float total_time = 0;
	float rhs_total_time = 0;

	total_time = (float)hours() + ((float)minutes() / kTimeInHour) + ((float)seconds() / (kTimeInHour * kTimeInMinute));
	rhs_total_time = (float)rhs.hours() + ((float)rhs.minutes() / kTimeInHour) + ((float)rhs.seconds() / (kTimeInHour * kTimeInMinute));

	return total_time < rhs_total_time;
}

bool TimeSpan::operator>(const TimeSpan& rhs) const
{
	float total_time = 0;
	float rhs_total_time = 0;

	total_time = (float)hours() + ((float)minutes() / kTimeInHour) + ((float)seconds() / (kTimeInHour * kTimeInMinute));
	rhs_total_time = (float)rhs.hours() + ((float)rhs.minutes() / kTimeInHour) + ((float)rhs.seconds() / (kTimeInHour * kTimeInMinute));

	return total_time > rhs_total_time;
}

TimeSpan TimeSpan::operator-() const
{
	TimeSpan temp;
	temp.hours_ = -hours_;
	temp.minutes_ = -minutes_;
	temp.seconds_ = -seconds_;
	return temp;
}

TimeSpan& TimeSpan::operator=(const TimeSpan& rhs) 
{
	this->hours_ = rhs.hours();
	this->minutes_ = rhs.minutes();
	this->seconds_ = rhs.seconds();
	return *this;
}
