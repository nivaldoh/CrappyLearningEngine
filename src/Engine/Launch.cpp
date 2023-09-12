#include "Engine.h"

// TODO: setup basic cross-platform support
// TODO: organize build files, cmd args, etc
int main()
{
	Engine EngineInst = Engine();
	EngineInst.PreInit();
	EngineInst.Init();
	EngineInst.Tick();

	return 0;
}