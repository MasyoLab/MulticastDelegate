#include <iostream>
#include "MulticastDelegate.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(ClassDelegate0);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(ClassDelegate1, int);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(ClassDelegate2, int, int);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(ClassDelegate3, int, int, int);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(ClassDelegate4, int, int, int, int);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(ClassDelegate5, int, int, int, int, int);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_SixParams(ClassDelegate6, int, int, int, int, int, int);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_SevenParams(ClassDelegate7, int, int, int, int, int, int, int);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_EightParams(ClassDelegate8, int, int, int, int, int, int, int, int);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_NineParams(ClassDelegate9, int, int, int, int, int, int, int, int, int);

class DelegateTest
{
public:
	ClassDelegate0 eveDrawParam;
	ClassDelegate1 eveSetParam;
	ClassDelegate1 eveUpdate;

	~DelegateTest() {
		// �֐��|�C���^�j���̗�
		eveDrawParam.Delete();
		eveSetParam.Delete();
		eveUpdate.Delete();
	}
};


class DataClass
{
private:
	int value = 0;
	DelegateTest* pWorld = nullptr;
public:
	DataClass(DelegateTest* world)
	{
		pWorld = world;

		// �}�N���֐��̎g�p��
		world->eveSetParam.AddDynamic1(&DataClass::SetData, this);
		world->eveDrawParam.AddDynamic0(&DataClass::Draw, this);

		// �����_��
		world->eveSetParam.AddDynamic(
			[&](int value) {
				SetData(value);
			}, this);

		world->eveDrawParam.AddDynamic(
			[&]() {
				Draw();
			}, this);
	}
	~DataClass() {
		// �֐��|�C���^�j���̗�
		pWorld->eveSetParam.Delete(this);
		pWorld->eveDrawParam.Delete(this);
	}

private:
	void SetData(int value)
	{
		this->value = value;
	}
	void Draw()
	{
		std::cout << "Data : " << value << std::endl;
	}
};

class Control
{
private:
	DelegateTest* pWorld = nullptr;
public:
	Control(DelegateTest* world)
	{
		pWorld = world;

		// �}�N���֐��̎g�p��
		world->eveUpdate.AddDynamic1(&Control::Update, this);

		// �����_��
		world->eveUpdate.AddDynamic(
			[&](int value) {
				Update(value);
			}, this);
	}
	~Control() {
		// �֐��|�C���^�j���̗�
		pWorld->eveUpdate.Delete(this);
	}

private:
	void Update(int value)
	{
		pWorld->eveSetParam.Broadcast(value);
		pWorld->eveDrawParam.Broadcast();
	}
};

int main()
{
	DelegateTest delegateTest;
	DataClass* dataClass = new DataClass(&delegateTest);
	Control* control = new Control(&delegateTest);

	delegateTest.eveSetParam.Broadcast(50);
	delegateTest.eveDrawParam.Broadcast();
	delegateTest.eveUpdate.Broadcast(100);

	delete dataClass;
	delete control;

	delegateTest.eveSetParam.Broadcast(150);
	delegateTest.eveDrawParam.Broadcast();
	delegateTest.eveUpdate.Broadcast(200);

	std::system("PAUSE");
}
