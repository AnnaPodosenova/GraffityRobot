#include <iostream>
#include <cmath>
using namespace std;

class Server
{
public:
	void Robo();
	void Graff();
	void Route();
};

class Regulation
{
public:

	int rotate(float angle)
	{
		return 0;
	}
	int driving(float distance)
	{
		return 0;
	}
	int cleaning()
	{
		return 0;
	}
};


class Camera
{
public:

	bool graffity()
	{
		return 0;
	}
	bool detectAngle(float angle)
	{
		return 0;
	}
	bool detectWay(float distance)
	{
		return 0;
	}
	bool graffityFinds()
	{
		return 0;
	}

};

class Graffity
{
private:
	int x1;
	int x2;
};

enum Status
{
	Status_Waiting, Status_Moving,
	Status_Rotate, Status_MoveForward,
	Status_Clean
};

class Robot
{
private:
	int x;
	int y;
	Status status;
	Camera* det;
	Regulation* command;

public:
	void start();
	void stop();
	void clean();

	Robot()
	{
		status = Status_Waiting;
	}
	void processEvents()
	{
		switch (status)
		{
		case Status_Waiting:
			if (det->graffityFinds())
			{
				status = Status_Moving;//движение
			}
			break;

		case Status_Moving:
			if (det->detectAngle(5))//проверяем угол
			{
				status = Status_Rotate;// поворот
			}
			else if (det->detectWay(5))//проверяем расстояние
			{
				status = Status_MoveForward;
			}
			else if (det->graffityFinds())// чистка пола                              ->
			{
				status = Status_Clean;
			}

			break;

		case Status_Rotate:
			command->rotate(5);
			status = Status_Moving;
			break;

		case Status_MoveForward:
			command->driving(10);
			status = Status_Moving;
			break;

		case Status_Clean:
			command->cleaning();
			status = Status_Waiting;
			break;
		}
	}
	void run()
	{
		while (1)
		{
			processEvents();
		}
	}

};

int main()
{
	setlocale(LC_ALL, "Russian");
	Robot bip;
	bip.run();
	return 0;
}
