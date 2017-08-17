#include "Packet.h"
#include "MemoryPool.h"

/** For the definition of ntohl, htonl and __BYTE_ORDER */
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include <sys/endian.h>
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
#include <netinet/in.h>
#define htonq(x) __bswap_64(x)
#define ntohq(x) __bswap_64(x)
#endif




Packet::Packet()
{
	m_nLen = 0;
	m_nCursor = 0;

	m_body = new char[51200];
	m_poolIndex = -1;
}

Packet::Packet(uint32 packetType)
{
	m_nLen = 0;//预留数据包头
	m_nCursor = 0;

	m_type = packetType;

	m_body = NULL;
	m_poolIndex = MemoryPool::getInstance()->getOnePacketBuffer(&m_body);
}

Packet::~Packet()
{
	if (m_poolIndex != -1)
	{
		MemoryPool::getInstance()->returnMemory(m_poolIndex);
	}else
	{
		delete[] m_body;
	}

}

void Packet::skipHead()
{
	m_nLen = PACKET_HEAD_LEN;//预留数据包头
}

void Packet::writeHead()
{
	int n = m_nLen;
	m_nLen = 0;
	writeUint16(n - PACKET_HEAD_LEN);
	//writeUint16(m_type);
	m_nLen = n;

}
//==================================================================

void Packet::writeBytes( const char * ba, uint32 nlen)
{
	if (m_nLen + nlen >= PACKET_MAX)
		return;

	memcpy(m_body+m_nLen, ba, nlen);
	m_nLen += nlen;
}

void Packet::writeUint8( uint8 data)
{
	memcpy(m_body+m_nLen, (const void*)(&data), 1);
	m_nLen += 1;
}

void Packet::writeUint16( uint16 data )
{
	data = htons(data);
	memcpy(m_body+m_nLen, (const void*)(&data), 2);
	m_nLen+=2;
}

void Packet::writeUint32( uint32 data )
{
	data = htonl(data);
	memcpy(m_body+m_nLen, (const void*)(&data), 4);
	m_nLen += 4;
}

void Packet::writeUint64( uint64 data)
{

#if __BYTE_ORDER == __LITTLE_ENDIAN
	//data = htonq(data);
#endif

	memcpy(m_body+m_nLen, (const void*)data, 8);
	m_nLen += 8;
}

void Packet::writeString( const char* data)
{
	uint16 hostlen = strlen(data);
	uint16 netlen = htons(hostlen);
	memcpy(m_body+m_nLen, (void*)(&netlen), 2);
	m_nLen+=2;

	memcpy(m_body+m_nLen, data, hostlen);
	m_nLen+=hostlen;
}

uint8 Packet::readUint8()/*  0 ~ 255 */
{
    if (m_nCursor + 1 > m_nLen)
        return 0;

	uint8 data;
	memcpy((void*)(&data), m_body+m_nCursor, 1);
	m_nCursor += 1;
	return data;
}

uint16 Packet::readUint16()/* 0 ~ 65536 */
{
    if (m_nCursor + 2 > m_nLen)
        return 0;

	uint16 data;
	memcpy((void*)(&data), m_body+m_nCursor, 2);
	m_nCursor += 2;
	return ntohs(data);
}

uint32 Packet::readUint32()/* 0 ~ 4294967259 */
{
    if (m_nCursor + 4 > m_nLen)
        return 0;

	uint32 data;
	memcpy((void*)(&data), m_body+m_nCursor, 4);
	m_nCursor += 4;
	return ntohl(data);
}

uint64 Packet::readUint64()
{
    if (m_nCursor + 8 > m_nLen)
        return 0;

	uint64 data;
	memcpy((void*)(&data), m_body+m_nCursor, 8);
	m_nCursor += 8;

#if __BYTE_ORDER == __LITTLE_ENDIAN
	//data = ntohq(data);
#endif

	return data;
}

std::string Packet::readString()
{
    if (m_nCursor + 2 > m_nLen)
        return std::string("");

	uint16 len = 0;
	memcpy((void*)(&len) , m_body+m_nCursor, 2);
	m_nCursor+=2;

	len = ntohs(len);

    if (m_nCursor + len > m_nLen)
        return "";

	char data[1024] = {0};
	memcpy(data, m_body+m_nCursor, len);
	m_nCursor+=len;
	return std::string(data);
}


void Packet::readBytes(int len, char* data)
{
	memcpy(data,m_body+m_nCursor,len);
	m_nCursor+=len;
}



