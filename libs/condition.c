#include "condition.h"

#include "../device.h"

void conditionRegisterChangeEvent(tCondition * condition, eventCallbackFunc event)
{
	if(condition != NULL)														// check for valid condition
	{
		eventApendCB((tEvent *)&(condition->changeEvent), event);				// register event function
	}
}

inline void conditionCheck(tCondition * condition, unsigned long value)
{
	/* wrapper for condition change
	 */
	conditionChange(condition, value);
}

void conditionChange(tCondition * condition, unsigned long value)
{
	if(condition != NULL)														// check for valid condition
	{
		if(value != condition->value)											// value changed?
		{
			condition->last_value = condition->value;							// store last value
			condition->value = value;											// store new value
			condition->lastChange = deviceGetMilliSec();						// store changed timestamp

#ifdef __DEBUG
			condition->counter++;												// increment transition counter
#endif
			eventQueueEnqueue((tEvent *)&condition->changeEvent);				// enqueue the event
		}

		condition->lastUpdate = deviceGetMilliSec();
	}
}

void conditionOverride(tCondition * condition, unsigned long value)
{
	/* raise event, even if there is no change in the current value
	 */
	if(condition != NULL)														// check for valid condition
	{
		condition->last_value = condition->value;								// store last value
		condition->value = value;												// store new value
		condition->lastChange = deviceGetMilliSec();							// store changed timestamp
		condition->lastUpdate = deviceGetMilliSec();
		
#ifdef __DEBUG
		condition->counter++;													// increment transition counter
#endif

		eventQueueEnqueue((tEvent *)&condition->changeEvent);					// enqueue the event
	}
}
