#ifndef __PACKET_H__
#define __PACKET_H__

#include <cstring>
#include "cocos2d.h"
#include "protocol.h"

#define  PACKET_MAX  		40960
#define  PACKET_TYPE_LEN  	(0)
#define  PACKET_HEAD_LEN  	(10)
NS_CORE_BEGIN
class Packet: public cocos2d::Ref
{
public:
	uint32 m_nLen;
	uint32 m_nCursor;

	uint16 m_type;

	char* m_body;
	int m_poolIndex;

	Packet();

	Packet(uint32 packetType);
	virtual ~Packet();

	void skipHead();
	void writeHead();


	void writeBytes(const char * ba, uint32 nlen);

	void writeUint8( uint8 data);

	void writeUint16( uint16 data );

	void writeUint32( uint32 data );

	void writeUint64( uint64 data);

	void writeString( const char* data);


	uint8 readUint8();/*  0 ~ 255 */

	uint16 readUint16();/* 0 ~ 65536 */

	uint32 readUint32();/* 0 ~ 4294967259 */

	uint64 readUint64();

	void readBytes(int len, char* data);

	std::string readString();
};
NS_CORE_END
#endif