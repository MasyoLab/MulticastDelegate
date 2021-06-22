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
		// 関数ポインタ破棄の例
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

		// マクロ関数の使用例
		world->eveSetParam.AddDynamic1(&DataClass::SetData, this);
		world->eveDrawParam.AddDynamic0(&DataClass::Draw, this);

		// ラムダ式
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
		// 関数ポインタ破棄の例
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

		// マクロ関数の使用例
		world->eveUpdate.AddDynamic1(&Control::Update, this);

		// ラムダ式
		world->eveUpdate.AddDynamic(
			[&](int value) {
				Update(value);
			}, this);
	}
	~Control() {
		// 関数ポインタ破棄の例
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
