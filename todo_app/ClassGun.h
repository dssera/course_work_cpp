#pragma once

class Gun
{
public:
	Gun();
	Gun(int power_val);
	~Gun();

	int getPower();
	void setPower(int power_val);
private:
	int power;
};



