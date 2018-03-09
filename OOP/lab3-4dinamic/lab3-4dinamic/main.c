#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Ui.h"

int main()
{
	testRepo();
	testArray();
	testController();
	MedsRepo* repo = createRepo();
	OperationStack* undo = createStack();
	OperationStack* redo = createStack();
	Controller* ctrl = createController(repo,undo,redo);
	addMedicationCont(ctrl, "Nurofen", 10, 50, 2);
	addMedicationCont(ctrl, "No-spa", 60, 100, 4);
	addMedicationCont(ctrl, "Algocalmin", 10, 40, 3.5);
	addMedicationCont(ctrl, "Loperamid", 30, 200, 4.6);
	addMedicationCont(ctrl, "Kreon", 15, 30, 3.2);
	addMedicationCont(ctrl, "Dicarbocalm", 50, 10, 1.2);
	addMedicationCont(ctrl, "Coldrex", 10, 52, 7.5);
	addMedicationCont(ctrl, "Aspacardin", 100, 43, 10);
	addMedicationCont(ctrl, "Vicodin", 50, 24, 20);
	addMedicationCont(ctrl, "Ospamox", 20, 100, 5.5);
	addMedicationCont(ctrl, "Vicodin", 25, 24, 20);
	addMedicationCont(ctrl, "Vicodin", 130, 100, 5.5);
	Ui* ui = createUi(ctrl);
	startUi(ui);
	destroyUi(ui);

	//_CrtDumpMemoryLeaks();
	return 0;

}