#ifndef __PACKET_BUFFER_H__
#define __PACKET_BUFFER_H__

#include "Packet.h"


typedef std::vector<Packet*> packets;

class PacketBuffer
{
private :
	Packet buf;
public:
	PacketBuffer();

	void push(const char * ba, uint32 nlen);
	void clear();

	packets getPackets();

};

#endif
