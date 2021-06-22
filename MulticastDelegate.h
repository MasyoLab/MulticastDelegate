//==========================================================================
// 動的なマルチキャスト デリゲート [MulticastDelegate.h]
// author : MasyoLab
//==========================================================================
#pragma once
#include <list>
#include <unordered_map>
#include <functional>

//==========================================================================
//
// class : MulticastDelegate 
// Content : マルチキャスト デリゲート
//
//==========================================================================
template < class... _Args>
class MulticastDelegate
{
private:
	std::unordered_map<void*, std::list<std::function<void(_Args...)>>> _functions;
public:
	/**
	@brief 関数ポインタの登録
	*/
	template <class _Thisptr>
	void AddDynamic(const std::function<void(_Args...)>& func, _Thisptr* _this)
	{
		_functions[_this].push_back(func);
	}

	/**
	@brief 関数ポインタの破棄
	*/
	void Delete()
	{
		_functions.clear();
	}

	/**
	@brief 関数ポインタを指定して破棄
	*/
	template <class _Thisptr>
	void Delete(_Thisptr* _this)
	{
		_functions.erase(_this);
	}

	/**
	@brief 登録された関数ポインタの実行
	*/
	void Broadcast(const _Args&... args)
	{
		// 登録したthisptr毎に実行
		for (auto& obj : _functions)
			// 登録順に実行
			for (auto& itr : obj.second)
				itr((args)...);
	}
};

//==========================================================================
//
// マクロ関数 
//
//==========================================================================
#define AddDynamic0(Func,thisptr) AddDynamic(std::bind(Func, thisptr),thisptr)
#define DECLARE_DYNAMIC_MULTICAST_DELEGATE(DelegateName) using DelegateName = MulticastDelegate<>;
#define AddDynamic1(Func,thisptr) AddDynamic(std::bind(Func, thisptr, std::placeholders::_1),thisptr)
#define DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(DelegateName,Param1Type) using DelegateName = MulticastDelegate<Param1Type>;
#define AddDynamic2(Func,thisptr) AddDynamic(std::bind(Func, thisptr, std::placeholders::_1, std::placeholders::_2),thisptr)
#define DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(DelegateName,Param1Type,Param2Type) using DelegateName = MulticastDelegate<Param1Type,Param2Type>;
#define AddDynamic3(Func,thisptr) AddDynamic(std::bind(Func, thisptr, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3),thisptr)
#define DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(DelegateName,Param1Type,Param2Type,Param3Type) using DelegateName = MulticastDelegate<Param1Type,Param2Type,Param3Type>;
#define AddDynamic4(Func,thisptr) AddDynamic(std::bind(Func, thisptr, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4),thisptr)
#define DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(DelegateName,Param1Type,Param2Type,Param3Type,Param4Type) using DelegateName = MulticastDelegate<Param1Type,Param2Type,Param3Type,Param4Type>;
#define AddDynamic5(Func,thisptr) AddDynamic(std::bind(Func, thisptr, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5),thisptr)
#define DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(DelegateName,Param1Type,Param2Type,Param3Type,Param4Type,Param5Type) using DelegateName = MulticastDelegate<Param1Type,Param2Type,Param3Type,Param4Type,Param5Type>;
#define AddDynamic6(Func,thisptr) AddDynamic(std::bind(Func, thisptr, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6),thisptr)
#define DECLARE_DYNAMIC_MULTICAST_DELEGATE_SixParams(DelegateName,Param1Type,Param2Type,Param3Type,Param4Type,Param5Type,Param6Type) using DelegateName = MulticastDelegate<Param1Type,Param2Type,Param3Type,Param4Type,Param5Type,Param6Type>;
#define AddDynamic7(Func,thisptr) AddDynamic(std::bind(Func, thisptr, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7),thisptr)
#define DECLARE_DYNAMIC_MULTICAST_DELEGATE_SevenParams(DelegateName,Param1Type,Param2Type,Param3Type,Param4Type,Param5Type,Param6Type,Param7Type) using DelegateName = MulticastDelegate<Param1Type,Param2Type,Param3Type,Param4Type,Param5Type,Param6Type,Param7Type>;
#define AddDynamic8(Func,thisptr) AddDynamic(std::bind(Func, thisptr, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7, std::placeholders::_8),thisptr)
#define DECLARE_DYNAMIC_MULTICAST_DELEGATE_EightParams(DelegateName,Param1Type,Param2Type,Param3Type,Param4Type,Param5Type,Param6Type,Param7Type,Param8Type) using DelegateName = MulticastDelegate<Param1Type,Param2Type,Param3Type,Param4Type,Param5Type,Param6Type,Param7Type,Param8Type>;
#define AddDynamic9(Func,thisptr) AddDynamic(std::bind(Func, thisptr, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7, std::placeholders::_8, std::placeholders::_9),thisptr)
#define DECLARE_DYNAMIC_MULTICAST_DELEGATE_NineParams(DelegateName,Param1Type,Param2Type,Param3Type,Param4Type,Param5Type,Param6Type,Param7Type,Param8Type,Param9Type) using DelegateName = MulticastDelegate<Param1Type,Param2Type,Param3Type,Param4Type,Param5Type,Param6Type,Param7Type,Param8Type,Param9Type>;
#define AddDynamic10(Func,thisptr) AddDynamic(std::bind(Func, thisptr, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7, std::placeholders::_8, std::placeholders::_9, std::placeholders::_10),thisptr)
#define DECLARE_DYNAMIC_MULTICAST_DELEGATE_TenParams(DelegateName,Param1Type,Param2Type,Param3Type,Param4Type,Param5Type,Param6Type,Param7Type,Param8Type,Param9Type,Param10Type) using DelegateName = MulticastDelegate<Param1Type,Param2Type,Param3Type,Param4Type,Param5Type,Param6Type,Param7Type,Param8Type,Param9Type,Param10Type>;
#define AddDynamic11(Func,thisptr) AddDynamic(std::bind(Func, thisptr, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7, std::placeholders::_8, std::placeholders::_9, std::placeholders::_10, std::placeholders::_11),thisptr)
#define DECLARE_DYNAMIC_MULTICAST_DELEGATE_ElevenParams(DelegateName,Param1Type,Param2Type,Param3Type,Param4Type,Param5Type,Param6Type,Param7Type,Param8Type,Param9Type,Param10Type,Param11Type) using DelegateName = MulticastDelegate<Param1Type,Param2Type,Param3Type,Param4Type,Param5Type,Param6Type,Param7Type,Param8Type,Param9Type,Param10Type,Param11Type>;
#define AddDynamic12(Func,thisptr) AddDynamic(std::bind(Func, thisptr, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7, std::placeholders::_8, std::placeholders::_9, std::placeholders::_10, std::placeholders::_11, std::placeholders::_12),thisptr)
#define DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwelveParams(DelegateName,Param1Type,Param2Type,Param3Type,Param4Type,Param5Type,Param6Type,Param7Type,Param8Type,Param9Type,Param10Type,Param11Type,Param12Type) using DelegateName = MulticastDelegate<Param1Type,Param2Type,Param3Type,Param4Type,Param5Type,Param6Type,Param7Type,Param8Type,Param9Type,Param10Type,Param11Type,Param12Type>;
#define AddDynamic13(Func,thisptr) AddDynamic(std::bind(Func, thisptr, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7, std::placeholders::_8, std::placeholders::_9, std::placeholders::_10, std::placeholders::_11, std::placeholders::_12, std::placeholders::_13),thisptr)
#define DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThirteenParams(DelegateName,Param1Type,Param2Type,Param3Type,Param4Type,Param5Type,Param6Type,Param7Type,Param8Type,Param9Type,Param10Type,Param11Type,Param12Type,Param13Type) using DelegateName = MulticastDelegate<Param1Type,Param2Type,Param3Type,Param4Type,Param5Type,Param6Type,Param7Type,Param8Type,Param9Type,Param10Type,Param11Type,Param12Type,Param13Type>;
#define AddDynamic14(Func,thisptr) AddDynamic(std::bind(Func, thisptr, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7, std::placeholders::_8, std::placeholders::_9, std::placeholders::_10, std::placeholders::_11, std::placeholders::_12, std::placeholders::_13, std::placeholders::_14),thisptr)
#define DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourteenParams(DelegateName,Param1Type,Param2Type,Param3Type,Param4Type,Param5Type,Param6Type,Param7Type,Param8Type,Param9Type,Param10Type,Param11Type,Param12Type,Param13Type,Param14Type) using DelegateName = MulticastDelegate<Param1Type,Param2Type,Param3Type,Param4Type,Param5Type,Param6Type,Param7Type,Param8Type,Param9Type,Param10Type,Param11Type,Param12Type,Param13Type,Param14Type>;
#define AddDynamic15(Func,thisptr) AddDynamic(std::bind(Func, thisptr, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7, std::placeholders::_8, std::placeholders::_9, std::placeholders::_10, std::placeholders::_11, std::placeholders::_12, std::placeholders::_13, std::placeholders::_14, std::placeholders::_15),thisptr)
#define DECLARE_DYNAMIC_MULTICAST_DELEGATE_FifteenParams(DelegateName,Param1Type,Param2Type,Param3Type,Param4Type,Param5Type,Param6Type,Param7Type,Param8Type,Param9Type,Param10Type,Param11Type,Param12Type,Param13Type,Param14Type,Param15Type) using DelegateName = MulticastDelegate<Param1Type,Param2Type,Param3Type,Param4Type,Param5Type,Param6Type,Param7Type,Param8Type,Param9Type,Param10Type,Param11Type,Param12Type,Param13Type,Param14Type,Param15Type>;
#define AddDynamic16(Func,thisptr) AddDynamic(std::bind(Func, thisptr, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7, std::placeholders::_8, std::placeholders::_9, std::placeholders::_10, std::placeholders::_11, std::placeholders::_12, std::placeholders::_13, std::placeholders::_14, std::placeholders::_15, std::placeholders::_16),thisptr)
#define DECLARE_DYNAMIC_MULTICAST_DELEGATE_SixteenParams(DelegateName,Param1Type,Param2Type,Param3Type,Param4Type,Param5Type,Param6Type,Param7Type,Param8Type,Param9Type,Param10Type,Param11Type,Param12Type,Param13Type,Param14Type,Param15Type,Param16Type) using DelegateName = MulticastDelegate<Param1Type,Param2Type,Param3Type,Param4Type,Param5Type,Param6Type,Param7Type,Param8Type,Param9Type,Param10Type,Param11Type,Param12Type,Param13Type,Param14Type,Param15Type,Param16Type>;
#define AddDynamic17(Func,thisptr) AddDynamic(std::bind(Func, thisptr, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7, std::placeholders::_8, std::placeholders::_9, std::placeholders::_10, std::placeholders::_11, std::placeholders::_12, std::placeholders::_13, std::placeholders::_14, std::placeholders::_15, std::placeholders::_16, std::placeholders::_17),thisptr)
#define DECLARE_DYNAMIC_MULTICAST_DELEGATE_SeventeenParams(DelegateName,Param1Type,Param2Type,Param3Type,Param4Type,Param5Type,Param6Type,Param7Type,Param8Type,Param9Type,Param10Type,Param11Type,Param12Type,Param13Type,Param14Type,Param15Type,Param16Type,Param17Type) using DelegateName = MulticastDelegate<Param1Type,Param2Type,Param3Type,Param4Type,Param5Type,Param6Type,Param7Type,Param8Type,Param9Type,Param10Type,Param11Type,Param12Type,Param13Type,Param14Type,Param15Type,Param16Type,Param17Type>;
#define AddDynamic18(Func,thisptr) AddDynamic(std::bind(Func, thisptr, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7, std::placeholders::_8, std::placeholders::_9, std::placeholders::_10, std::placeholders::_11, std::placeholders::_12, std::placeholders::_13, std::placeholders::_14, std::placeholders::_15, std::placeholders::_16, std::placeholders::_17, std::placeholders::_18),thisptr)
#define DECLARE_DYNAMIC_MULTICAST_DELEGATE_EightteenParams(DelegateName,Param1Type,Param2Type,Param3Type,Param4Type,Param5Type,Param6Type,Param7Type,Param8Type,Param9Type,Param10Type,Param11Type,Param12Type,Param13Type,Param14Type,Param15Type,Param16Type,Param17Type,Param18Type) using DelegateName = MulticastDelegate<Param1Type,Param2Type,Param3Type,Param4Type,Param5Type,Param6Type,Param7Type,Param8Type,Param9Type,Param10Type,Param11Type,Param12Type,Param13Type,Param14Type,Param15Type,Param16Type,Param17Type,Param18Type>;
#define AddDynamic19(Func,thisptr) AddDynamic(std::bind(Func, thisptr, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7, std::placeholders::_8, std::placeholders::_9, std::placeholders::_10, std::placeholders::_11, std::placeholders::_12, std::placeholders::_13, std::placeholders::_14, std::placeholders::_15, std::placeholders::_16, std::placeholders::_17, std::placeholders::_18, std::placeholders::_19),thisptr)
#define DECLARE_DYNAMIC_MULTICAST_DELEGATE_NineteenParams(DelegateName,Param1Type,Param2Type,Param3Type,Param4Type,Param5Type,Param6Type,Param7Type,Param8Type,Param9Type,Param10Type,Param11Type,Param12Type,Param13Type,Param14Type,Param15Type,Param16Type,Param17Type,Param18Type,Param19Type) using DelegateName = MulticastDelegate<Param1Type,Param2Type,Param3Type,Param4Type,Param5Type,Param6Type,Param7Type,Param8Type,Param9Type,Param10Type,Param11Type,Param12Type,Param13Type,Param14Type,Param15Type,Param16Type,Param17Type,Param18Type,Param19Type>;
#define AddDynamic20(Func,thisptr) AddDynamic(std::bind(Func, thisptr, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7, std::placeholders::_8, std::placeholders::_9, std::placeholders::_10, std::placeholders::_11, std::placeholders::_12, std::placeholders::_13, std::placeholders::_14, std::placeholders::_15, std::placeholders::_16, std::placeholders::_17, std::placeholders::_18, std::placeholders::_19, std::placeholders::_20),thisptr)
#define DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwentyParams(DelegateName,Param1Type,Param2Type,Param3Type,Param4Type,Param5Type,Param6Type,Param7Type,Param8Type,Param9Type,Param10Type,Param11Type,Param12Type,Param13Type,Param14Type,Param15Type,Param16Type,Param17Type,Param18Type,Param19Type,Param20Type) using DelegateName = MulticastDelegate<Param1Type,Param2Type,Param3Type,Param4Type,Param5Type,Param6Type,Param7Type,Param8Type,Param9Type,Param10Type,Param11Type,Param12Type,Param13Type,Param14Type,Param15Type,Param16Type,Param17Type,Param18Type,Param19Type,Param20Type>;
