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


	while (true)
	{
		if (buf.m_nLen - buf.m_nCursor < PACKET_HEAD_LEN)
		{
			break;
		}
		uint32 msg_length = buf.readUint32();
		if (buf.m_nLen - buf.m_nCursor - 4 < msg_length)
		{
			buf.m_nCursor += 4;
			break;
		}


		uint16 serial_number = buf.readUint16();
		uint32 msg_id = buf.readUint32();
		Packet* packet = new Packet();
		packet->writeUint32(msg_length);
		packet->writeUint16(serial_number);
		packet->writeUint32(msg_id);
		packet->writeBytes(buf.m_body + buf.m_nCursor, msg_length);
		ps.push_back(packet);
		buf.m_nCursor += msg_length;
	}
	
	return ps;
}

void PacketBuffer::clear()
{
	buf.m_nCursor = 0;
	buf.m_nLen = 0;
}
