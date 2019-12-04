#ifndef __EVENT_H

#include "../config.h"

typedef void (*eventCallbackFunc)(void *);
typedef struct sEventQueue tEventQueue;
typedef struct sEvent tEvent;

void eventQueueInit(void);
void eventQueueService(void);
char eventQueueEnqueue(tEvent *);
char eventQueueEnqueueCB(eventCallbackFunc, void *);
char eventAdd(tEvent *, tEvent *);

char eventRemoveCB(tEvent *, eventCallbackFunc);
char eventApendCB(tEvent *, eventCallbackFunc);
tEvent * eventLast(tEvent *);
char eventSearchCB(tEvent *, eventCallbackFunc);

struct sEvent
{
	eventCallbackFunc cb;
	void *_data;
	tEvent * next;
};

struct sEventQueue
{
	eventCallbackFunc elements[CONF_EVENT_QUEUE_SIZE];
	void *_data[CONF_EVENT_QUEUE_SIZE];
	
	unsigned short len;
	unsigned short rd;
	unsigned short wr;
};

#define __EVENT_H
#endif
