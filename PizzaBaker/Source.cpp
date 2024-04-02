#include <iostream>
#include <string>

using namespace std;

/* ������� ��������� �������� ��������������� �������� ������� �� ��� �������������, ��� ���
	   � ���������� ������ � ���� �� �������� ��������������� ����� ���������� ������ �������������.
	������������
	   - �������� �������� �������� ������� �� ������ �������� �� ����, �� ����� ������ ������� ������ � ��� ��� ��������� ����� �����;
	   - ������� ��������������� ������ ������������ ��������� ������������� ��������������� �������.
   ����������� �������� ��������� � ��� ����������:
	- ��������� �������� ���������� ������������� ��������
	- ��������� ���, ����������� ��������������� � �������������
	- ���� ����� ������ �������� ��� ��������� ���������������
   */

   /*
		* Pizza (�������) ������������ ������� �������������� ������.
		* ConcreteBuilder ������ ���������� ������������� �������� � ���������� ������� ��� ������.
		* */
class Car
{
	string name;
	string frame;
	int engine;
	int wheels;
	string transmission;
public:
	void SetName(string name)
	{
		this->name = name;
	}
	string GetName()
	{
		return this->name;
	}
	void SetFrame(string frame)
	{
		this->frame = frame;
	}
	string GetFrame()
	{
		return this->frame;
	}
	void SetTransmission(string transmission)
	{
		this->transmission = transmission;
	}
	string GetTransmission()
	{
		return this->transmission;
	}
	void SetEngine(int engine)
	{
		this->engine = engine;
	}
	int GetEngine()
	{
		return this->engine;
	}
	void SetWheels(int wheels)
	{
		this->wheels = wheels;
	}
	int GetWheels()
	{
		return this->wheels;
	}
	void ShowCar()
	{
		cout << "Name: "<<name << ", Frame: " << frame << ", Engine: " << engine << ", Wheels: " << wheels << ", Transmission: " << transmission << endl;
	}
};

   // Abstract Builder ������ ����������� ��������� (�����) ��� �������� ������ ������� Product (� ����� ������, Pizza);
   /** "Abstract Builder" */
class CarBuilder abstract
{
protected:
	Car car;
public:
	Car GetCar()
	{
		return car;
	}
	virtual void BuildName() abstract;
	virtual void BuildFrame() abstract;
	virtual void BuildTransmisson() abstract;
	virtual void BuildEngine() abstract;
	virtual void BuildWheels() abstract;
};

// ConcreteBuilder ��������� ��������� ��������:
// - ������������ � �������� ������ ����� �������� ����������� ���������� ���������� Builder;
// - ���������� ����������� ������������� � ������ �� ���;
// - ������������� ��������� ��� ������� � ��������

class LanosBuilder: public CarBuilder
{
public:
	void BuildName() override
	{
		car.SetName("Daewoo Lanos");
	}
	void BuildFrame() override
	{
		car.SetFrame("Sedan");
	}
	void BuildTransmisson() override
	{
		car.SetTransmission("5 Manual");
	}
	void BuildEngine() override
	{
		car.SetEngine(98);
	}
	void BuildWheels() override
	{
		car.SetWheels(13);
	}
};

class PatriotBuilder : public CarBuilder
{
public:
	void BuildName() override
	{
		car.SetName("UAZ Patriot");
	}
	void BuildFrame() override
	{
		car.SetFrame("Universal");
	}
	void BuildTransmisson() override
	{
		car.SetTransmission("4 Manual");
	}
	void BuildEngine() override
	{
		car.SetEngine(120);
	}
	void BuildWheels() override
	{
		car.SetWheels(16);
	}
};

class ProbeBuilder : public CarBuilder
{
public:
	void BuildName() override
	{
		car.SetName("Ford Probe");
	}
	void BuildFrame() override
	{
		car.SetFrame("Cupe");
	}
	void BuildTransmisson() override
	{
		car.SetTransmission("4 Auto");
	}
	void BuildEngine() override
	{
		car.SetEngine(160);
	}
	void BuildWheels() override
	{
		car.SetWheels(14);
	}
};
class GetzBuilder : public CarBuilder
{
public:
	void BuildName() override
	{
		car.SetName("Hyundai Getz");
	}
	void BuildFrame() override
	{
		car.SetFrame("Hatchback");
	}
	void BuildTransmisson() override
	{
		car.SetTransmission("4 Auto");
	}
	void BuildEngine() override
	{
		car.SetEngine(66);
	}
	void BuildWheels() override
	{
		car.SetWheels(13);
	}
};

// Director(�������������) - ������������ ������ (Pizza), ��������� ����������� Builder
class Shop
{
	CarBuilder *carBuilder;
public:
	void SetCarBuilder(CarBuilder* cb)
	{
		carBuilder = cb;
	}
	Car GetCar()
	{
		return carBuilder->GetCar();
	}
	void ConstructCar()
	{
		carBuilder->BuildName();
		carBuilder->BuildFrame();
		carBuilder->BuildTransmisson();
		carBuilder->BuildEngine();
		carBuilder->BuildWheels();
	}
};

// ������ ������� ������-������������� Director � ������������� ��� ������ ��������-���������� Builder
void client(CarBuilder* builder)
{
	Shop shop;
	shop.SetCarBuilder(builder);
	shop.ConstructCar();
	Car car = shop.GetCar();
	car.ShowCar();
}

void main()
{
	CarBuilder* builder = new LanosBuilder();
	client(builder);
	delete builder;
	builder = new ProbeBuilder();
	client(builder);
	delete builder;
	builder = new PatriotBuilder();
	client(builder);
	delete builder;
	builder = new GetzBuilder();
	client(builder);
	delete builder;
	system("pause");
}