#include "StdAfx.h"
#include "NProtectGameGuard.h"

#ifdef USE_NPROTECT_GAMEGUARD

static struct GameGuard
{
	bool	 isInitError;
	bool	 isProcError;
	unsigned msg;
	unsigned arg;
} gs_gameGuard = {
	false, 0, 0,
};

#ifdef LOCALE_SERVICE_HONGKONG
#include "NProtect/NPGameLibHK.h"
#pragma comment(lib, "NPGameLibHK_MT.lib")
CNPGameLib npgl("Metin2HK");
#endif

#ifdef LOCALE_SERVICE_TAIWAN
#include "NProtect/NPGameLibTW.h"
#pragma comment(lib, "NPGameLibTW_MT.lib")
CNPGameLib npgl("Metin2TW");
#endif

#ifdef LOCALE_SERVICE_EUROPE
#include "NProtect/NPGameLibEU.h"
#pragma comment(lib, "NPGameLibEU_MT.lib")
CNPGameLib npgl("Metin2EU");
#endif

BOOL CALLBACK NPGameMonCallback(DWORD msg, DWORD arg)
{
	switch (msg)
    {
	case NPGAMEMON_COMM_ERROR:
	case NPGAMEMON_COMM_CLOSE:
	case NPGAMEMON_INIT_ERROR:
	case NPGAMEMON_SPEEDHACK:
	case NPGAMEMON_GAMEHACK_KILLED:
	case NPGAMEMON_GAMEHACK_DETECT:
	case NPGAMEMON_GAMEHACK_DOUBT:		
		gs_gameGuard.msg = msg;
		gs_gameGuard.arg = arg;
		gs_gameGuard.isProcError = true;
		return false;		
		break;
	}	
	return true;
}

bool LocaleService_IsGameGuardError()
{
	return gs_gameGuard.isProcError;
}

bool LocaleService_InitGameGuard()
{
	unsigned result = npgl.Init();
	if (NPGAMEMON_SUCCESS != result)
	{
		gs_gameGuard.isInitError = true;
		gs_gameGuard.msg = result;
		return false;
	}
	return true;
}

bool LocaleService_RunGameGuard(HWND hWnd)
{
	npgl.SetHwnd(hWnd);
	return true;
}

void LocaleService_NoticeGameGuardInitError_HongKong()
{
	char msg[256];
	switch (gs_gameGuard.msg)
	{
		case NPGAMEMON_ERROR_EXIST:
			sprintf(msg, "GameGuard곰?ㄴ좧탙데??⒝촑?톝귑걺ㄷメ쪨곰?좧 ");
			break;
		case NPGAMEMON_ERROR_GAME_EXIST:
			sprintf(msg, "툮으?싣곰?⒝GameGuard쨢쫇곰?ㄴ좧뎡?툮으メ싻?톝곰?좧 ");
			break;
		case NPGAMEMON_ERROR_INIT:
			sprintf(msg, "GameGuardれ늑ㅖ월?좧?톝귑걺メ쪨곰?⒝촑츙낚쩳??탊Ν식юず?─ㄷメ쪨곰?좧 ");
			break;
		case NPGAMEMON_ERROR_AUTH_GAMEGUARD:
		case NPGAMEMON_ERROR_NFOUND_GG:
		case NPGAMEMON_ERROR_AUTH_INI:
		case NPGAMEMON_ERROR_NFOUND_INI:
			sprintf(msg, "킠GameGuard읠?⒝깼Ν꺌텝좧싻쫤맷GameGuard ず쫤맷읠좧 ");
			break;
		case NPGAMEMON_ERROR_CRYPTOAPI:
			sprintf(msg, "Windowず촟끝ψ쮝꽝읠?⅜톖좧싻?톝쫤맷IE좧 ");
			break;
		case NPGAMEMON_ERROR_EXECUTE:
			sprintf(msg, "GameGuard곰?ⅱ귐좧싻?톝곰?GameGuard쫤맷읠좧 ");
			break;
		case NPGAMEMON_ERROR_ILLEGAL_PRG:
			sprintf(msg, "탊?첗챞?─좧싻뎡?ㄳ쁨춏ず?─ㄷメ?톝곰?좧 ");
			break;
		case NPGMUP_ERROR_ABORT:
			sprintf(msg, "GameGuardㅙ?¾?좧쫜찱?そ킠챞퀂퐑좥싻?쌌얇빌몰⒝?짩ず㉭ㆅ쟈?쯹좧 ");
			break;
		case NPGMUP_ERROR_CONNECT:
		case NPGMUP_ERROR_DOWNCFG:
			sprintf(msg, "GameGuard㏆ぉ(ㅙ?)?찥퀂퐑ⅱ귐좧탙데ㄷメ쪨?톝곰?⒝촑쫜찱┳?짩㉭ㆅ쟈ず멎싻쌌얇?짩㉭ㆅ쟈?쯹ㄷメ쪨먼좧 ");
			break;
		case NPGMUP_ERROR_AUTH:
			sprintf(msg, "GameGuard㏆ぉ쮁?㏏┬좧싻?갚ㅾ곰?㉭촵?─メ쪨?톝곰?⒝촑ⓒΞPC붸쾩?─쌌얇?쯹メ쪨곰?좧 ");
			break;
		case NPGAMEMON_ERROR_NPSCAN:
			sprintf(msg, "칏촵ㅞ탇짫픟ト짫첟쨠ⓦ읫촥소꾐ⅱ귐좧쩳?촑캯압톱ㄳº⒝촑텾촚짦칏촵좧 ");
			break;
		default:
			sprintf(msg, "GameGuard곰??탊?월?좧싻켔툮으멸?㎤맸ずGameGuard멸?㎤ㄴず*.erl읠?픆퉞쨖턫τ??켋⑥game2@inca.co.kr첞폺좧 ");
			break;
	}

	MessageBox(NULL, msg, "GameGuard 월?", MB_OK);	
}

void LocaleService_NoticeGameGuardInitError_International()
{
	char msg[256];
	switch (gs_gameGuard.msg)
	{
	case NPGAMEMON_ERROR_EXIST:
		sprintf(msg, "GameGuard is already running.\nPlease reboot and restart the game.");
		break;
	case NPGAMEMON_ERROR_GAME_EXIST:
		sprintf(msg, "GameGuard is already running.\nPlease restart the game.");
		break;
	case NPGAMEMON_ERROR_INIT:
		sprintf(msg, "GameGuard has initial error.\nPlease kill other conflict programs and restart game.");
		break;
	case NPGAMEMON_ERROR_AUTH_GAMEGUARD:
	case NPGAMEMON_ERROR_NFOUND_GG:
	case NPGAMEMON_ERROR_AUTH_INI:
	case NPGAMEMON_ERROR_NFOUND_INI:
		sprintf(msg, "GameGuard files are modified or deleted.\nPlease reinstall GameGuard.");
		break;
	case NPGAMEMON_ERROR_CRYPTOAPI:
		sprintf(msg, "GameGuard detects Windows system file error.\nPlease reinstall Internet Explorer(IE)");
		break;
	case NPGAMEMON_ERROR_EXECUTE:
		sprintf(msg, "GameGuard running is failed.\nPlease reinstall GameGuard.");
		break;
	case NPGAMEMON_ERROR_ILLEGAL_PRG:
		sprintf(msg, "GameGuard detects Illegal Program.\nPlease kill other programs not needs and restart game");
		break;
	case NPGMUP_ERROR_ABORT:
		sprintf(msg, "GameGuard update was canceled.\nWhen not connect, change the internal or private firewall settings");
		break;
	case NPGMUP_ERROR_CONNECT:
		sprintf(msg, "GameGuard hooking is failed.\nPlease download newer anti-virus and check all system.");
		break;
	case NPGAMEMON_ERROR_GAMEGUARD:
		sprintf(msg, "GameGuard has initial error or old game guard.\nPlease reinstall GameGuard");
		break;
	case NPGMUP_ERROR_PARAM:
		sprintf(msg, "GameGuard detects .ini file is modified.\nPlease reinstall GameGuard");		
		break;
	case NPGMUP_ERROR_INIT:
		sprintf(msg, "GameGuard detects npgmup.des initial error.\nPlease delete GameGuard Folder and reinstall GameGuard");
		break;
	case NPGMUP_ERROR_DOWNCFG:
		sprintf(msg, "GameGuard update server connection is failed.\nPlease restart or check private firewall settings.");
		break;
	case NPGMUP_ERROR_AUTH:
		sprintf(msg, "GameGuard update is not completed.\nPlease pause anti-virus and restart game.");
		break;
	case NPGAMEMON_ERROR_NPSCAN:
		sprintf(msg, "GameGuard virus-hacking checker loading is failed\nPlease check memory lack or virus.");
		break;
	default:
		sprintf(msg, "UnknownErrorCode: %d\nPlease send a letter that has *.erl in game folder to Game1@inca.co.kr", gs_gameGuard.msg);
		break;
	}
	
	MessageBox(NULL, msg, "GameGuard Initiail Error", MB_OK);	
}

void LocaleService_NoticeGameGuardProcError_HongKong()
{
	char msg[256];
	switch (gs_gameGuard.msg)
	{
		case NPGAMEMON_COMM_ERROR:
		case NPGAMEMON_COMM_CLOSE:
			return;
		case NPGAMEMON_INIT_ERROR:
			sprintf(msg, "GameGuardれ늑ㅖ월? : %lu", gs_gameGuard.arg);
			break;
		case NPGAMEMON_SPEEDHACK:
			sprintf(msg,  "탊?speed hack좧 ");
			break;
		case NPGAMEMON_GAMEHACK_KILLED:
			sprintf(msg,  "탊?툮으hack좧 ");
			break;
		case NPGAMEMON_GAMEHACK_DETECT:
			sprintf(msg,  "탊?툮으hack좧 ");
			break;
		case NPGAMEMON_GAMEHACK_DOUBT:
			sprintf(msg,  "툮으⒝GameGuard쨢텝?좧 ");
			break;
	}
	MessageBox(NULL, msg, "GameGuard Error", MB_OK);
}

void LocaleService_NoticeGameGuardProcError_International()
{
	char msg[256];
	switch (gs_gameGuard.msg)
	{
	case NPGAMEMON_COMM_ERROR:
	case NPGAMEMON_COMM_CLOSE:
		break;
	case NPGAMEMON_INIT_ERROR:
		wsprintf(msg, "GameGuard has initial error : %lu", gs_gameGuard.arg);			
		break;
	case NPGAMEMON_SPEEDHACK:
		wsprintf(msg, "GameGuard detects SpeedHack");			
		break;
	case NPGAMEMON_GAMEHACK_KILLED:
		wsprintf(msg, "GameGuard detects GameHack\r\n%s", npgl.GetInfo());			
		break;
	case NPGAMEMON_GAMEHACK_DETECT:
		wsprintf(msg, "GameGuard detects GameHack\r\n%s", npgl.GetInfo());			
		break;
	case NPGAMEMON_GAMEHACK_DOUBT:
		wsprintf(msg, "Game or Gamguard was modified.");			
		break;
	}
	MessageBox(NULL, msg, "GameGuard Error", MB_OK);
}

void LocaleService_NoticeGameGuardMessasge()
{
	if (gs_gameGuard.isInitError)
	{		
		if (LocaleService_IsHONGKONG())
			LocaleService_NoticeGameGuardInitError_HongKong();
		else
			LocaleService_NoticeGameGuardInitError_International();		
	
	}
	else if (gs_gameGuard.isProcError)
	{
		if (LocaleService_IsHONGKONG())
			LocaleService_NoticeGameGuardProcError_HongKong();
		else
			LocaleService_NoticeGameGuardProcError_International();		
	}
}

#endif /* USE_NPROTECT_GAMEGUARD */
