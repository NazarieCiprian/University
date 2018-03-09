#include "Ui.h"
#include <string>
#include <iostream>
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  
using namespace std;

int main()
{
	{
		//testDynamicVector();
		//testRepository();
		//testController();
		Repository repo{};
		TrenchCoat c1{ 120, "red",45.5,1,"https://www.google.ro/search?q=trenchcoat&client=opera&hs=IDP&source=lnms&tbm=isch&sa=X&ved=0ahUKEwjS65_s0ZHTAhXJKMAKHV_zC14Q_AUICCgB&biw=1366&bih=660#tbm=isch&q=trench+coat+red&imgrc=bgywTjsRyiAucM:" ,80};
		TrenchCoat c2{ 150,"blue",60.0,100,"https://www.google.ro/search?q=trenchcoat&client=opera&hs=IDP&source=lnms&tbm=isch&sa=X&ved=0ahUKEwjS65_s0ZHTAhXJKMAKHV_zC14Q_AUICCgB&biw=1366&bih=660#tbm=isch&q=trench+coat+blue&imgrc=qz9hQAcvQlmOCM:", 100};
		TrenchCoat c3{ 100, "kaki",150,35,"https://www.google.ro/search?q=trenchcoat&client=opera&hs=IDP&source=lnms&tbm=isch&sa=X&ved=0ahUKEwjS65_s0ZHTAhXJKMAKHV_zC14Q_AUICCgB&biw=1366&bih=660#tbm=isch&q=trench+coat+kaki&imgrc=xBpbeiD3tcELVM:",70 };
		TrenchCoat c4{ 200,"yellow",25.5,120,"https://www.google.ro/search?q=trenchcoat&client=opera&hs=IDP&source=lnms&tbm=isch&sa=X&ved=0ahUKEwjS65_s0ZHTAhXJKMAKHV_zC14Q_AUICCgB&biw=1366&bih=660#tbm=isch&q=trench+coat+yellow&imgrc=TJoy1a3ufCquiM:",120 };
		TrenchCoat c5{ 120, "pink",62,80,"https://www.google.ro/search?q=trenchcoat&client=opera&hs=IDP&source=lnms&tbm=isch&sa=X&ved=0ahUKEwjS65_s0ZHTAhXJKMAKHV_zC14Q_AUICCgB&biw=1366&bih=660#tbm=isch&q=trenchcoat+pink&imgrc=NpGE14pD72nWbM:",59 };
		TrenchCoat c6{ 120,"black",120,1,"https://www.google.ro/search?q=trenchcoat&client=opera&hs=IDP&source=lnms&tbm=isch&sa=X&ved=0ahUKEwjS65_s0ZHTAhXJKMAKHV_zC14Q_AUICCgB&biw=1366&bih=660#tbm=isch&q=trench+coat+black&imgrc=z2Cce4P7ENTBNM:",60 };
		repo.addCoat(c1);
		repo.addCoat(c2);
		repo.addCoat(c3);
		repo.addCoat(c4);
		repo.addCoat(c5);
		repo.addCoat(c6);
		Controller ctrl{ repo };
		Ui ui{ ctrl };
		ui.run();
	}
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();
	system("pause");
}