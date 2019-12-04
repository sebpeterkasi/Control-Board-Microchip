#ifndef __CONDITION_H

#include "event.h"

typedef volatile struct sCondition tCondition;

void conditionRegisterChangeEvent(tCondition *, eventCallbackFunc);

inline void conditionCheck(tCondition *, unsigned long);
void conditionChange(tCondition *, unsigned long);
void conditionOverride(tCondition *, unsigned long);

struct sCondition
{
	tEvent changeEvent;				// event to trigger on change
	
	unsigned long value;			// value to store
	unsigned long last_value;		// value prior to change
	unsigned long lastUpdate;		// last update timestamp
	unsigned long lastChange;		// last change timestamp

#ifdef __DEBUG
	unsigned long counter;			// number of changes since boot
#endif
};

#define __CONDITION_H
#endif