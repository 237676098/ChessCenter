#pragma once

#define SINGLETON(_CLASS_)					\
public:										\
	inline static _CLASS_& getInstance()	\
	{										\
	static _CLASS_ s_instance;				\
	return s_instance;						\
	}										\
private:									\
	_CLASS_(){}								\
	_CLASS_(_CLASS_ const&){}				\
	_CLASS_& operator= (_CLASS_ const&){return *this;}	\
	~_CLASS_(){}								\

//����ģʽĬ�Ϲ��캯����������������ϵ���ģʽ��ʹ�ã�
#define SINGLETON_C_D(_CLASS_)		\
	_CLASS_::_CLASS_(){}			\
	_CLASS_::~_CLASS_(){}			