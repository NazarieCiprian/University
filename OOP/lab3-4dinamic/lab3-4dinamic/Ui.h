#pragma once
#include "Controller.h"

typedef struct {
	Controller* ctrl;
}Ui;

Ui* createUi(Controller* c);
void destroyUi(Ui* ui);
void startUi(Ui* ui);