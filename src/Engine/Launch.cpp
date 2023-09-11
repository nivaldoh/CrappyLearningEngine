#include "Engine.h"

// TODO: setup basic cross-platform support
int main()
{
	Engine EngineInst = Engine();
	EngineInst.PreInit();
	EngineInst.Init();
	EngineInst.Tick();

	return 0;
}