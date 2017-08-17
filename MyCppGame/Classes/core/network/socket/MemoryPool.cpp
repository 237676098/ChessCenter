#include "MemoryPool.h"

#define MEMORY_NODE_LEN 40960
#define MEMORY_NODE_NUM 25


MemoryNode::MemoryNode(int index)
{
	m_buffer = new char[MEMORY_NODE_LEN];
	memset(m_buffer,0, MEMORY_NODE_LEN);
	next = NULL;
	prev = NULL;
	m_isEmpty = true;
	m_index = index;
}

MemoryNode::~MemoryNode()
{
	if (m_buffer != NULL)
		delete[] m_buffer;
	m_buffer = NULL;
}

void MemoryNode::setEmpty(bool flag)
{
	m_isEmpty = flag;
}

char* MemoryNode::getBuffer()
{
	memset(m_buffer, 0, MEMORY_NODE_LEN);
	return m_buffer;
}

void MemoryNode::resetBuffer()
{
	m_isEmpty = true;
	memset(m_buffer, 0, MEMORY_NODE_LEN);
}



MemoryPool* MemoryPool::g_memoryPool = NULL;

MemoryPool* MemoryPool::getInstance()
{
	if(!g_memoryPool)
		g_memoryPool = new MemoryPool();

	return g_memoryPool;
}

MemoryPool::MemoryPool()
{
	headNode = NULL;
	initMemory();
}

MemoryPool::~MemoryPool()
{
	releaseMemory();
}

void MemoryPool::initMemory()
{
	headNode = new MemoryNode(0);
	otherNode = new MemoryNode(MEMORY_NODE_NUM + 1);
	MemoryNode *lastNode = NULL;
	for (int i=0; i < MEMORY_NODE_NUM; i++)
	{
		MemoryNode *temp = new MemoryNode(i+1);
		
		if(i==0)
		{
			headNode->next = temp;
			temp->prev = headNode;
		}
		else 
		{
			lastNode->next = temp;
			temp->prev = lastNode;
		}

		if (i == MEMORY_NODE_NUM - 1)
		{
			temp->next = headNode;
			headNode->prev = temp;
		}

		lastNode = temp;
	}
}

void MemoryPool::releaseMemory()
{
	MemoryNode *temp = headNode->next;
	MemoryNode *temp_last = NULL;
	while(temp->next != headNode)
	{
		temp_last = temp;
		temp = temp->next;
		if (temp_last != NULL)
			delete temp_last;
		temp_last = NULL;
	}
	if (headNode != NULL)
		delete headNode;
	headNode = NULL;

	if (otherNode != NULL)
		delete otherNode;
	otherNode = NULL;
}

int MemoryPool::getOnePacketBuffer(char **buffer)
{
	MemoryNode *temp = headNode;
	while(temp->m_isEmpty != true)
	{
		if (temp->next == headNode)
		{
			MemoryNode *add_temp = otherNode;
			while (add_temp->next != NULL)
			{
				add_temp = add_temp->next;
			}
			MemoryNode *addNode = new MemoryNode(add_temp->m_index+1);
			add_temp->next = addNode;
			addNode->prev = add_temp;
			*buffer = addNode->getBuffer();
			return addNode->m_index;
		}

		temp = temp->next;
	}
	temp->setEmpty(false);
	*buffer = temp->getBuffer();
	return temp->m_index;
}

void MemoryPool::returnMemory(int index)
{
	//g_mylock->lock();
	if (index > MEMORY_NODE_NUM)
	{
		MemoryNode* add_temp = otherNode;
		while (add_temp->m_index != index)
		{
			add_temp = add_temp->next;
		}
		add_temp->prev->next = add_temp->next;
		if (add_temp->next!=NULL)
			add_temp->next->prev = add_temp->prev;
		delete add_temp;
		add_temp = NULL;
		//g_mylock->unlock();
		return;
	}

	MemoryNode *temp = headNode;
	while (temp->m_index != index)
	{
		temp = temp->next;
	}
	temp->resetBuffer();
	//g_mylock->unlock();
}
