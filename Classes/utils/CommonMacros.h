#ifndef __COMMON_MACROS_H__
#define __COMMON_MACROS_H__

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
#define NS_GAME_BEGIN                     namespace chess { namespace game {
#define NS_GAME_END                       }}
#define NS_PAIGOW_BEGIN                     namespace chess { namespace game {namespace paigow {
#define NS_PAIGOW_END                       }}}
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
#define NS_GAME_BEGIN
#define NS_GAME_END
#define NS_PAIGOW_BEGIN
#define NS_PAIGOW_END
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


#endif


//��Ϣ�����������궨��
#define MSG_FUNCTION_DEFINE(_MSG_)									\
void onRev##_MSG_(google::protobuf::Message* messgae);

//��Ϣע��궨��
#define MSG_FUNCTION_REGISTER(_MSG_,_CLS_)			\
core::SocketManager::getInstance()->registerHandler(core::ID_##_MSG_, std::bind(&##_CLS_::onRev##_MSG_, this, std::placeholders::_1));