#pragma once

//命名空间宏定义
#ifdef __cplusplus
#define NS_CORE_BEGIN                     namespace chess { namespace core {
#define NS_CORE_END                       }}
#define NS_LOGIN_BEGIN                     namespace chess { namespace login {
#define NS_LOGIN_END                       }}
#define NS_USER_BEGIN                     namespace chess { namespace user {
#define NS_USER_END                       }}
#define NS_LOBBY_BEGIN                     namespace chess { namespace lobby {
#define NS_LOBBY_END                       }}
#define USING_NS_CHESS					   using namespace chess
#else
#define NS_CORE_BEGIN 
#define NS_CORE_END 
#define NS_LOGIN_BEGIN 
#define NS_LOGIN_END 
#define NS_USER_BEGIN
#define NS_USER_END
#define NS_LOBBY_BEGIN
#define NS_LOBBY_END
#endif


//单例宏定义
#define SINGLETON(_CLASS_)					\
public:										\
	inline static _CLASS_* getInstance()	\
	{										\
	static _CLASS_* s_instance = new _CLASS_();				\
	return s_instance;						\
	}										\
private:									\
	_CLASS_();								\
	_CLASS_(_CLASS_ const&){};				\
	_CLASS_& operator= (_CLASS_ const&){return *this;}	\
	~_CLASS_();								\

//单例模式默认构造函数与析构函数（配合单例模式宏使用）
#define SINGLETON_C_D(_CLASS_)		\
	_CLASS_::_CLASS_(){}			\
	_CLASS_::~_CLASS_(){}			


