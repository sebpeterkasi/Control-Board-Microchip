#include "event.h"

#include <stdlib.h>
#include <stdio.h>

tEventQueue event_queue;

void eventQueueInit(void)
{
	
}

/*
char eventRemoveCB(tEvent * event, eventCallbackFunc cb)
{
	if(event->cb == cb)															// is this the callback we are looking for?
	{
		event->cb = NULL;														// delete callback

		if(event->next != NULL)													// has child events?
		{
			event->cb = event->next.cb;											// copy callback

			if(event->next.next != NULL)										// the child has a child?
				event->next = event->next.next;									// copy event pointer

			free(event->next);

			event->next = NULL;													// clear pointer to next
		}

		return 1;
	}
	else
	{
		if(event->next != NULL)													// event has children?
		{
			return eventRemoveCB(event->next, cb);
		}
		else
		{
			return -1;
		}
	}
}
*/

char eventApendCB(tEvent * event, eventCallbackFunc cb)
{
	tEvent * new_event;
	tEvent * last_event;

	if(event->cb == NULL)
	{
		event->cb = cb;
		return 1;
	}
	else
	{
		if(eventSearchCB(event, cb) != 1)										// prevent double callback to the same function
		{
			new_event = malloc(sizeof(tEvent));									// reserve memory for new element
			last_event = eventLast(event);										// find last event;

			last_event->next = new_event;										// assign next event
			new_event->next = NULL;												// be sure the next-pointer is not pointing somewhere
			new_event->cb = cb;													// assign callback

			return 1;
		}
		else
		{
			return -1;
		}
	}
}

tEvent * eventLast(tEvent * event)
{
	if(event->next == NULL)
	{
		return event;
	}
	else
	{
		return eventLast(event->next);
	}
}

char eventSearchCB(tEvent * event, eventCallbackFunc cb)
{
	if(event->cb == cb)															// is this the callback we are looking for?
	{
		return 1;																// yes
	}
	else																		// no
	{
		if(event->next != NULL)													// is there a child?
		{
			return eventSearchCB(event->next, cb);								// yes
		}
		else
		{
			return -1;															// no
		}
	}
}

char eventAdd(tEvent * event_add, tEvent * event_old)
{
	if(event_old != NULL)														// valid event?
	{
		if(event_old->next == NULL)												// slot free?
		{
			event_old->next = event_add;

			return 1;
		}
		else
		{
			return eventAdd(event_add, event_old->next);						// try next slot
		}
	}
	else
		return -1;
}

char eventQueueEnqueueCB(eventCallbackFunc event, void * _data)
{
	if(event != NULL)		// only add event if address is valid
	{
		__builtin_disi(0x3FFF);                                                 // disable interrupts
			if(event_queue.len < CONF_EVENT_QUEUE_SIZE)
			{
				event_queue.elements[event_queue.wr] = event;
				event_queue._data[event_queue.wr] = _data;
				event_queue.wr = (event_queue.wr + 1)&(CONF_EVENT_QUEUE_SIZE-1);
				event_queue.len++;
			}
			else
			{
				__builtin_disi(0);                                              // enable interrupts
				return -1;
			}
		__builtin_disi(0);                                                      // enable interrupts
	}

	return 1;
}

char eventQueueEnqueue(tEvent * event)
{
	if(event->cb != NULL)														// only add event if address is valid
	{
		__builtin_disi(0x3FFF);                                                 // disable interrupts
			if(event_queue.len < CONF_EVENT_QUEUE_SIZE)
			{
				event_queue.elements[event_queue.wr] = event->cb;
				event_queue._data[event_queue.wr] = event->_data;
				event_queue.wr = (event_queue.wr + 1)&(CONF_EVENT_QUEUE_SIZE-1);
				event_queue.len++;
			}
			else
			{
				__builtin_disi(0);                                              // enable interrupts
				return -1;
			}
		__builtin_disi(0);                                                      // enable interrupts
	}

	if(event->next != NULL)														// is there another event registered?
	{
		return eventQueueEnqueue(event->next);									// enqueue
	}
	
	return 1;
}

void eventQueueService(void)
{
	while(event_queue.len > 0)
	{
		if(event_queue.elements[event_queue.rd] != NULL)						// check for valid address
			event_queue.elements[event_queue.rd](event_queue._data[event_queue.rd]);
			
		__builtin_disi(0x3FFF);                                                 // disable interrupts
			event_queue.rd = (event_queue.rd + 1)&(CONF_EVENT_QUEUE_SIZE-1);
			event_queue.len--;
		__builtin_disi(0);                                                      // enable interrupts
	}
}
