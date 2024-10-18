// dllmain.cpp : Defines the entry point for the DLL application.
#include <Windows.h>
#include <BlackBone/Process/Process.h>
typedef const wchar_t* widestring;
using namespace std;
#define DLLEXPORT extern "C" __declspec(dllexport)

DLLEXPORT bool __stdcall GetDX11DLL(widestring str) {
    blackbone::Process* proc = 0;
    NTSTATUS st = proc->Attach((widestring)str, 3451UL);
    if (st) {
        return false;
    }
    blackbone::ProcessModules* mod_proc = 0;
    blackbone::ModuleDataPtr moduledata_d3d11 = (blackbone::ModuleDataPtr)mod_proc->GetModule(L"d3d11.dll");
    if (!moduledata_d3d11) {
        printf("Failed to Find D3D9 Module!!!");
        return false;
    }
    else {
        return true;
    }
}
DLLEXPORT bool __stdcall GetDX9DLL(widestring str) {
    blackbone::Process* proc = 0;
    NTSTATUS st = proc->Attach((widestring)str, 3451UL);
    if (st) {
        return false;
    }
    blackbone::ProcessModules* mod_proc = 0;
    blackbone::ModuleDataPtr moduledata_d3d11 = (blackbone::ModuleDataPtr)mod_proc->GetModule(L"d3d9.dll");
    if (!moduledata_d3d11) {
        printf("Failed to Find D3D11 Module!!!");
        return false;
    }
    else {
        return true;
    }
}
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

