#ifndef __MEMORY_POOL_H
#define __MEMORY_POOL_H

#include <cstring>

class MemoryNode
{
public:
	char *m_buffer;
	MemoryNode *next;
	MemoryNode *prev;
	bool m_isEmpty;
	int m_index;
public:
	MemoryNode(){}
	MemoryNode(int index);
	~MemoryNode();
	void setEmpty(bool flag);
	char* getBuffer();
	void resetBuffer();
};

class MemoryPool
{
private:
	static MemoryPool *g_memoryPool;

	MemoryNode* headNode;
	MemoryNode* otherNode;
public:
	static MemoryPool* getInstance();

	MemoryPool();
	~MemoryPool();
	void initMemory();
	void releaseMemory();
	int getOnePacketBuffer(char **buffer);
	void returnMemory(int index);
	
};



#endif
