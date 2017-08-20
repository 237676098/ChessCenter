#pragma once

//�����ռ�궨��
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


//�����궨��
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

//����ģʽĬ�Ϲ��캯����������������ϵ���ģʽ��ʹ�ã�
#define SINGLETON_C_D(_CLASS_)		\
	_CLASS_::_CLASS_(){}			\
	_CLASS_::~_CLASS_(){}			


