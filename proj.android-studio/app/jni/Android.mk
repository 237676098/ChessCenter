LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../../cocos2d/cocos)
$(call import-add-path,$(LOCAL_PATH)/../../../Classes)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
				../../../Classes\AppDelegate.cpp \
				../../../Classes\HelloWorldScene.cpp \
				../../../Classes\core\fsm\GameStateMachine.cpp \
				../../../Classes\core\fsm\IGameState.cpp \
				../../../Classes\core\fsm\LobbyState.cpp \
				../../../Classes\core\fsm\LoginState.cpp \
				../../../Classes\core\fsm\TableState.cpp \
				../../../Classes\core\network\http\HttpManager.cpp \
				../../../Classes\core\network\protocol\common.pb.cc \
				../../../Classes\core\network\protocol\game.pb.cc \
				../../../Classes\core\network\protocol\paigow.pb.cc \
				../../../Classes\core\network\socket\MemoryPool.cpp \
				../../../Classes\core\network\socket\Packet.cpp \
				../../../Classes\core\network\socket\PacketBuffer.cpp \
				../../../Classes\core\network\socket\protocol.cpp \
				../../../Classes\core\network\socket\SocketManager.cpp \
				../../../Classes\core\scene\BaseUI.cpp \
				../../../Classes\core\scene\BaseWindow.cpp \
				../../../Classes\core\scene\CommonMessageView.cpp \
				../../../Classes\core\scene\scene.cpp \
				../../../Classes\core\scene\SceneManager.cpp \
				../../../Classes\core\scene\WindowManager.cpp \
				../../../Classes\games\game.cpp \
				../../../Classes\games\GameManager.cpp \
				../../../Classes\games\MatchSnapshot.cpp \
				../../../Classes\games\PlayerInfo.cpp \
				../../../Classes\games\paigow\PaiGowData.cpp \
				../../../Classes\games\paigow\PaiGowLogic.cpp \
				../../../Classes\games\paigow\PaigowManager.cpp \
				../../../Classes\games\paigow\PaiGowPlayer.cpp \
				../../../Classes\games\paigow\PaiGowProxy.cpp \
				../../../Classes\games\paigow\PaiGowResult.cpp \
				../../../Classes\games\paigow\PaiGowSnapshot.cpp \
				../../../Classes\games\paigow\PaiGowViewController.cpp \
				../../../Classes\games\paigow\views\PaigowBetOperateView.cpp \
				../../../Classes\games\paigow\views\PaiGowCardGroupView.cpp \
				../../../Classes\games\paigow\views\PaiGowCardView.cpp \
				../../../Classes\games\paigow\views\PaigowCollocationOperateView.cpp \
				../../../Classes\games\paigow\views\PaigowGrabOperateView.cpp \
				../../../Classes\games\paigow\views\PaIGowHandCardsPanel.cpp \
				../../../Classes\games\paigow\views\PaiGowPublicCardsView.cpp \
				../../../Classes\games\paigow\views\PaiGowResultWindow.cpp \
				../../../Classes\games\paigow\views\PaiGowSeatView.cpp \
				../../../Classes\games\paigow\views\PaigowTableView.cpp \
				../../../Classes\games\paigow\views\PaigowWaitOperateView.cpp \
				../../../Classes\lobby\LobbyManager.cpp \
				../../../Classes\lobby\LobbyView.cpp \
				../../../Classes\lobby\modules\room\RoomCreateWindow.cpp \
				../../../Classes\lobby\modules\room\RoomJoinWindow.cpp \
				../../../Classes\login\AgreementTipsWindow.cpp \
				../../../Classes\login\LoginManager.cpp \
				../../../Classes\login\LoginView.cpp \
				../../../Classes\user\UserManager.cpp \
				../../../Classes\utils\LanguageManager.cpp \



LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../../Classes
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../Classes/core/network/protobuf/include


# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END


LOCAL_STATIC_LIBRARIES := cocos2dx_static
LOCAL_STATIC_LIBRARIES += protobuf_static

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)
$(call import-module,core/network/protobuf/prebuilt/android)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END

