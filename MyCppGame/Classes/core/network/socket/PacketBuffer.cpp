#include "PacketBuffer.h"

PacketBuffer::PacketBuffer()
{
	
}

void PacketBuffer::push(const char * ba, uint32 nlen)
{
	buf.writeBytes(ba, nlen);
}

packets PacketBuffer::getPackets()
{
	packets ps;
	uint16 packetLen = 0;
	uint16 dataLen = 0;

	while( buf.m_nLen - buf.m_nCursor >= PACKET_HEAD_LEN)
	{
		packetLen = buf.readUint16();

		if(packetLen > buf.m_nLen - buf.m_nCursor)
		{
			buf.m_nCursor -= PACKET_HEAD_LEN;
			return ps;
		}

		buf.m_nCursor-=PACKET_HEAD_LEN;
		dataLen = packetLen + PACKET_HEAD_LEN;

		Packet* packet = new Packet();
		packet->writeBytes(buf.m_body+buf.m_nCursor, dataLen);

		buf.m_nCursor += dataLen;

		ps.push_back(packet);
	}
	return ps;
}

void PacketBuffer::clear()
{
	buf.m_nCursor = 0;
	buf.m_nLen = 0;
}
