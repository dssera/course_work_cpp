#include "ClassGun.h"

class Gun
{
public:
	Gun() {}
	Gun(int power_val)
	{
		power = power_val;
	}

	~Gun()
	{

	}

	int getPower()
	{
		return this->power;
	}
	void setPower(int power_val)
	{
		this->power = power_val;
	}
private:
	int power;
};



