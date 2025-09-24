#pragma once
#include "Gamelib/RaceData.h"

typedef uint8_t TPacketHeader;

enum
{
	/////////////////////////////////////////////////
	// To Server
	// HEADER_BLANK is the not use(for future use)
	HEADER_CG_LOGIN								= 1,
	HEADER_CG_ATTACK							= 2,
	HEADER_CG_CHAT								= 3,
	HEADER_CG_PLAYER_CREATE						= 4,		// 새로운 플래이어를 생성
	HEADER_CG_PLAYER_DESTROY					= 5,		// 플래이어를 삭제.
	HEADER_CG_PLAYER_SELECT						= 6,
	HEADER_CG_CHARACTER_MOVE					= 7,
	HEADER_CG_SYNC_POSITION  					= 8,
	HEADER_CG_DIRECT_ENTER						= 9,
	HEADER_CG_ENTERGAME							= 10,
	HEADER_CG_ITEM_USE							= 11,
	HEADER_CG_ITEM_DROP							= 12,
	HEADER_CG_ITEM_MOVE							= 13,
	HEADER_CG_ITEM_PICKUP						= 15,
	HEADER_CG_QUICKSLOT_ADD                     = 16,
	HEADER_CG_QUICKSLOT_DEL                     = 17,
	HEADER_CG_QUICKSLOT_SWAP                    = 18,
	HEADER_CG_WHISPER							= 19,
	HEADER_CG_ITEM_DROP2                        = 20,	
	//HEADER_BLANK21								= 21,
	//HEADER_BLANK22								= 22,
	//HEADER_BLANK22								= 23,
	//HEADER_BLANK24								= 24,
	//HEADER_BLANK25								= 25,
	HEADER_CG_ON_CLICK							= 26,
	HEADER_CG_EXCHANGE							= 27,
    HEADER_CG_CHARACTER_POSITION                = 28,
    HEADER_CG_SCRIPT_ANSWER						= 29,
	HEADER_CG_QUEST_INPUT_STRING				= 30,
    HEADER_CG_QUEST_CONFIRM                     = 31,
	//HEADER_BLANK32								= 32,
	//HEADER_BLANK33								= 33,
	//HEADER_BLANK34								= 34,
	//HEADER_BLANK35								= 35,
	//HEADER_BLANK36								= 36,
	//HEADER_BLANK37								= 37,
	//HEADER_BLANK38								= 38,
	//HEADER_BLANK39								= 39,
	//HEADER_BLANK40								= 40,
	HEADER_CG_PVP								= 41,
	//HEADER_BLANK42								= 42,
	//HEADER_BLANK43								= 43,
	//HEADER_BLANK44								= 44,
	//HEADER_BLANK45								= 45,
	//HEADER_BLANK46								= 46,
	//HEADER_BLANK47								= 47,
	//HEADER_BLANK48								= 48,
	//HEADER_BLANK49								= 49,
    HEADER_CG_SHOP								= 50,
	HEADER_CG_FLY_TARGETING						= 51,
	HEADER_CG_USE_SKILL							= 52,
    HEADER_CG_ADD_FLY_TARGETING                 = 53,
	HEADER_CG_SHOOT								= 54,
	HEADER_CG_MYSHOP                            = 55,    
	//HEADER_BLANK56								= 56,
	//HEADER_BLANK57								= 57,
	//HEADER_BLANK58								= 58,
	//HEADER_BLANK59								= 59,
	HEADER_CG_ITEM_USE_TO_ITEM					= 60,
    HEADER_CG_TARGET                            = 61,
	//HEADER_BLANK62								= 62,
	//HEADER_BLANK63								= 63,
	//HEADER_BLANK64								= 64,
	HEADER_CG_WARP								= 65, 
    HEADER_CG_SCRIPT_BUTTON						= 66,
    HEADER_CG_MESSENGER                         = 67,
	//HEADER_BLANK68								= 68,
    HEADER_CG_MALL_CHECKOUT                     = 69,
    HEADER_CG_SAFEBOX_CHECKIN                   = 70,   // 아이템을 창고에 넣는다.
    HEADER_CG_SAFEBOX_CHECKOUT                  = 71,   // 아이템을 창고로 부터 빼온다.
    HEADER_CG_PARTY_INVITE                      = 72,
    HEADER_CG_PARTY_INVITE_ANSWER               = 73,
    HEADER_CG_PARTY_REMOVE                      = 74,
    HEADER_CG_PARTY_SET_STATE                   = 75,
    HEADER_CG_PARTY_USE_SKILL                   = 76,
    HEADER_CG_SAFEBOX_ITEM_MOVE                 = 77,
	HEADER_CG_PARTY_PARAMETER                   = 78,
	//HEADER_BLANK68								= 79,
	HEADER_CG_GUILD								= 80,
	HEADER_CG_ANSWER_MAKE_GUILD					= 81,
    HEADER_CG_FISHING                           = 82,
    HEADER_CG_GIVE_ITEM                         = 83,
	//HEADER_BLANK84								= 84,
	//HEADER_BLANK85								= 85,
	//HEADER_BLANK86								= 86,
	//HEADER_BLANK87								= 87,
	//HEADER_BLANK88								= 88,
	//HEADER_BLANK89								= 89,
    HEADER_CG_EMPIRE                            = 90,
	//HEADER_BLANK91								= 91,
	//HEADER_BLANK92								= 92,
	//HEADER_BLANK93								= 93,
	//HEADER_BLANK94								= 94,
	//HEADER_BLANK95								= 95,
    HEADER_CG_REFINE                            = 96,
	//HEADER_BLANK97								= 97,
	//HEADER_BLANK98								= 98,
	//HEADER_BLANK99								= 99,

	HEADER_CG_MARK_LOGIN						= 100,
	HEADER_CG_MARK_CRCLIST						= 101,
	HEADER_CG_MARK_UPLOAD						= 102,
	HEADER_CG_MARK_IDXLIST						= 104,

	HEADER_CG_GUILD_MARK_UPLOAD_NEW			= 160,
	HEADER_CG_GUILD_MARK_REQUEST				= 161,
	HEADER_CG_GUILD_MARK_DELETE				= 162,

	HEADER_CG_CRC_REPORT						= 103,
	
	HEADER_CG_HACK								= 105,
    HEADER_CG_CHANGE_NAME                       = 106,
    HEADER_CG_SMS                               = 107,
    HEADER_CG_CHINA_MATRIX_CARD                 = 108,
    HEADER_CG_LOGIN2                            = 109,
	HEADER_CG_DUNGEON							= 110,
	HEADER_CG_LOGIN3							= 111,
	HEADER_CG_GUILD_SYMBOL_UPLOAD				= 112,
	HEADER_CG_GUILD_SYMBOL_CRC					= 113,
	HEADER_CG_SCRIPT_SELECT_ITEM				= 114,
	HEADER_CG_LOGIN4							= 115,

	HEADER_CG_RUNUP_MATRIX_ANSWER               = 201,

	HEADER_CG_DRAGON_SOUL_REFINE			= 205,
	HEADER_CG_STATE_CHECKER					= 206,

	HEADER_CG_KEY_AGREEMENT						= 0xfb, // _IMPROVED_PACKET_ENCRYPTION_
	HEADER_CG_TIME_SYNC							= 0xfc,
	HEADER_CG_CLIENT_VERSION					= 0xfd,
	HEADER_CG_CLIENT_VERSION2					= 0xf1,
	HEADER_CG_PONG								= 0xfe,
    HEADER_CG_HANDSHAKE                         = 0xff,
	/////////////////////////////////////////////////
	// From Server

	HEADER_GC_CHARACTER_ADD						= 1,
	HEADER_GC_CHARACTER_DEL						= 2,
	HEADER_GC_CHARACTER_MOVE					= 3,
	HEADER_GC_CHAT								= 4,
	HEADER_GC_SYNC_POSITION 					= 5,
	HEADER_GC_LOGIN_SUCCESS3					= 6,
	HEADER_GC_LOGIN_FAILURE						= 7,
	HEADER_GC_PLAYER_CREATE_SUCCESS				= 8,
	HEADER_GC_PLAYER_CREATE_FAILURE				= 9,
	HEADER_GC_PLAYER_DELETE_SUCCESS				= 10,
	HEADER_GC_PLAYER_DELETE_WRONG_SOCIAL_ID		= 11,
	// 12
	HEADER_GC_STUN								= 13,
	HEADER_GC_DEAD								= 14,

	HEADER_GC_MAIN_CHARACTER					= 15,
	HEADER_GC_PLAYER_POINTS						= 16,
	HEADER_GC_PLAYER_POINT_CHANGE				= 17,
	HEADER_GC_CHANGE_SPEED						= 18,
	HEADER_GC_CHARACTER_UPDATE                  = 19,

	HEADER_GC_ITEM_DEL							= 20, // 아이템 창에 추가
	HEADER_GC_ITEM_SET							= 21, // 아이템 창에 추가
	HEADER_GC_ITEM_USE							= 22, // 아이템 사용 (주위 사람들에게 보여주기 위해)
	HEADER_GC_ITEM_DROP							= 23, // 아이템 버리기
	HEADER_GC_ITEM_UPDATE						= 25, // 아이템 수치 업데이트

	HEADER_GC_ITEM_GROUND_ADD					= 26, // 바닥에 아이템 추가
	HEADER_GC_ITEM_GROUND_DEL					= 27, // 바닥에서 아이템 삭제
    HEADER_GC_QUICKSLOT_ADD                     = 28,
    HEADER_GC_QUICKSLOT_DEL                     = 29,
    HEADER_GC_QUICKSLOT_SWAP                    = 30,
	HEADER_GC_ITEM_OWNERSHIP					= 31,
	HEADER_GC_LOGIN_SUCCESS4					= 32,
	HEADER_GC_ITEM_UNBIND_TIME					= 33,
	HEADER_GC_WHISPER							= 34,
	HEADER_GC_ALERT								= 35,

	HEADER_GC_MOTION							= 36,

	HEADER_GC_SHOP							    = 38,
	HEADER_GC_SHOP_SIGN							= 39,

	// 39 ~ 41 Balnk
	HEADER_GC_DUEL_START						= 40,
	HEADER_GC_PVP								= 41,
	HEADER_GC_EXCHANGE							= 42,
    HEADER_GC_CHARACTER_POSITION                = 43,

	HEADER_GC_PING								= 44,

	HEADER_GC_SCRIPT							= 45,
    HEADER_GC_QUEST_CONFIRM                     = 46,

	HEADER_GC_MOUNT								= 61,
	HEADER_GC_OWNERSHIP                         = 62, 
    HEADER_GC_TARGET                            = 63,
	HEADER_GC_WARP								= 65, 
	HEADER_GC_ADD_FLY_TARGETING                 = 69,

	HEADER_GC_CREATE_FLY						= 70,
	HEADER_GC_FLY_TARGETING						= 71,
	HEADER_GC_SKILL_LEVEL						= 72,
	HEADER_GC_SKILL_COOLTIME_END				= 73,
    HEADER_GC_MESSENGER                         = 74,
	HEADER_GC_GUILD								= 75,
	HEADER_GC_SKILL_LEVEL_NEW					= 76,

    HEADER_GC_PARTY_INVITE                      = 77,
    HEADER_GC_PARTY_ADD                         = 78,
    HEADER_GC_PARTY_UPDATE                      = 79,
    HEADER_GC_PARTY_REMOVE                      = 80,

    HEADER_GC_QUEST_INFO                        = 81,
    HEADER_GC_REQUEST_MAKE_GUILD                = 82,
	HEADER_GC_PARTY_PARAMETER                   = 83,

    HEADER_GC_SAFEBOX_MONEY_CHANGE              = 84,
    HEADER_GC_SAFEBOX_SET                       = 85,
    HEADER_GC_SAFEBOX_DEL                       = 86,
    HEADER_GC_SAFEBOX_WRONG_PASSWORD            = 87,
    HEADER_GC_SAFEBOX_SIZE                      = 88,

    HEADER_GC_FISHING                           = 89,

    HEADER_GC_EMPIRE                            = 90,

    HEADER_GC_PARTY_LINK                        = 91,
    HEADER_GC_PARTY_UNLINK                      = 92,

    HEADER_GC_REFINE_INFORMATION                = 95,

	HEADER_GC_OBSERVER_ADD						= 96,
	HEADER_GC_OBSERVER_REMOVE					= 97,
	HEADER_GC_OBSERVER_MOVE						= 98,
	HEADER_GC_VIEW_EQUIP                        = 99,

	HEADER_GC_MARK_BLOCK						= 100,
	HEADER_GC_MARK_DIFF_DATA                    = 101,
	HEADER_GC_MARK_IDXLIST						= 102,

	HEADER_GC_GUILD_MARK_UPLOAD_RESULT		= 160,
	HEADER_GC_GUILD_MARK_DATA					= 161,
	HEADER_GC_GUILD_MARK_UPDATE				= 162,

	//HEADER_GC_SLOW_TIMER						= 105,
    HEADER_GC_TIME                              = 106,
    HEADER_GC_CHANGE_NAME                       = 107,

	HEADER_GC_DUNGEON							= 110,
	HEADER_GC_WALK_MODE							= 111, 
	HEADER_GC_CHANGE_SKILL_GROUP				= 112,

	// SUPPORT_BGM
	HEADER_GC_MAIN_CHARACTER2_EMPIRE			= 113,
	// END_OF_SUPPORT_BGM

    HEADER_GC_SEPCIAL_EFFECT                    = 114,
	HEADER_GC_NPC_POSITION						= 115,

    HEADER_GC_CHINA_MATRIX_CARD                 = 116,
    HEADER_GC_CHARACTER_UPDATE2                 = 117,
    HEADER_GC_LOGIN_KEY                         = 118,
    HEADER_GC_REFINE_INFORMATION_NEW            = 119,
    HEADER_GC_CHARACTER_ADD2                    = 120,
    HEADER_GC_CHANNEL                           = 121,

    HEADER_GC_MALL_OPEN                         = 122,
	HEADER_GC_TARGET_UPDATE                     = 123,
	HEADER_GC_TARGET_DELETE                     = 124,
	HEADER_GC_TARGET_CREATE_NEW                 = 125,

	HEADER_GC_AFFECT_ADD                        = 126,
	HEADER_GC_AFFECT_REMOVE                     = 127,

    HEADER_GC_MALL_SET                          = 128,
    HEADER_GC_MALL_DEL                          = 129,
	HEADER_GC_LAND_LIST                         = 130,
	HEADER_GC_LOVER_INFO						= 131,
	HEADER_GC_LOVE_POINT_UPDATE					= 132,
	HEADER_GC_GUILD_SYMBOL_DATA					= 133,
    HEADER_GC_DIG_MOTION                        = 134,

	HEADER_GC_DAMAGE_INFO						= 135,
	HEADER_GC_CHAR_ADDITIONAL_INFO				= 136,

	// SUPPORT_BGM
	HEADER_GC_MAIN_CHARACTER3_BGM				= 137,
	HEADER_GC_MAIN_CHARACTER4_BGM_VOL			= 138,
	// END_OF_SUPPORT_BGM

    HEADER_GC_AUTH_SUCCESS                      = 150,
    HEADER_GC_PANAMA_PACK						= 151,

	//HYBRID CRYPT
	HEADER_GC_HYBRIDCRYPT_KEYS					= 152,
	HEADER_GC_HYBRIDCRYPT_SDB					= 153, // SDB means Supplmentary Data Blocks
	//HYBRID CRYPT

	HEADER_GC_RUNUP_MATRIX_QUIZ                 = 201,

	HEADER_GC_SPECIFIC_EFFECT					= 208,
	HEADER_GC_DRAGON_SOUL_REFINE						= 209,
	HEADER_GC_RESPOND_CHANNELSTATUS				= 210,

	HEADER_GC_KEY_AGREEMENT_COMPLETED			= 0xfa, // _IMPROVED_PACKET_ENCRYPTION_
	HEADER_GC_KEY_AGREEMENT						= 0xfb, // _IMPROVED_PACKET_ENCRYPTION_
	HEADER_GC_HANDSHAKE_OK						= 0xfc, // 252
	HEADER_GC_PHASE								= 0xfd,	// 253
    HEADER_GC_BINDUDP                           = 0xfe, // 254
    HEADER_GC_HANDSHAKE                         = 0xff, // 255

	/////////////////////////////////////////////////
	// Client To Client for UDP
	/*
	HEADER_CC_STATE_WAITING						= 1,
	HEADER_CC_STATE_WALKING						= 2,
	HEADER_CC_STATE_GOING						= 3,
	HEADER_CC_EVENT_NORMAL_ATTACKING			= 4,
	HEADER_CC_EVENT_COMBO_ATTACKING				= 5,
	HEADER_CC_EVENT_HIT							= 6,
	*/
};

enum
{
	ID_MAX_NUM = 30,
	PASS_MAX_NUM = 16,
	CHAT_MAX_NUM = 128,
	PATH_NODE_MAX_NUM = 64,
	SHOP_SIGN_MAX_LEN = 32,

	PLAYER_PER_ACCOUNT3 = 3,
	PLAYER_PER_ACCOUNT4 = 4,

	PLAYER_ITEM_SLOT_MAX_NUM = 20,		// 플래이어의 슬롯당 들어가는 갯수.

	QUICKSLOT_MAX_LINE = 4,
	QUICKSLOT_MAX_COUNT_PER_LINE = 8, // 클라이언트 임의 결정값
	QUICKSLOT_MAX_COUNT = QUICKSLOT_MAX_LINE * QUICKSLOT_MAX_COUNT_PER_LINE,

	QUICKSLOT_MAX_NUM = 36, // 서버와 맞춰져 있는 값

	SHOP_HOST_ITEM_MAX_NUM = 40,

	METIN_SOCKET_COUNT = 6,

	PARTY_AFFECT_SLOT_MAX_NUM = 7,

	GUILD_GRADE_NAME_MAX_LEN = 8,
	GUILD_NAME_MAX_LEN = 12,
	GUILD_GRADE_COUNT = 15,
	GULID_COMMENT_MAX_LEN = 50,

	MARK_CRC_NUM = 8*8,
	MARK_DATA_SIZE = 16*12,
	SYMBOL_DATA_SIZE = 128*256,
	QUEST_INPUT_STRING_MAX_NUM = 64,

	PRIVATE_CODE_LENGTH = 8,

	REFINE_MATERIAL_MAX_NUM = 5,

	CHINA_MATRIX_ANSWER_MAX_LEN	= 8,

	RUNUP_MATRIX_QUIZ_MAX_LEN	= 8,
	RUNUP_MATRIX_ANSWER_MAX_LEN = 4,

	WEAR_MAX_NUM = 11,

	SHOP_TAB_NAME_MAX = 32,
	SHOP_TAB_COUNT_MAX = 3,
};

#pragma pack(push)
#pragma pack(1)

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Mark
typedef struct command_mark_login
{
    uint8_t    header;
    uint32_t   handle;
    uint32_t   random_key;
} TPacketCGMarkLogin;

typedef struct command_mark_upload
{
    uint8_t    header;
    uint32_t   gid;
    uint8_t    image[16*12*4];
} TPacketCGMarkUpload;

typedef struct command_mark_idxlist
{
    uint8_t    header;
} TPacketCGMarkIDXList;

typedef struct command_mark_crclist
{
    uint8_t    header;
    uint8_t    imgIdx;
    uint32_t   crclist[80];
} TPacketCGMarkCRCList;

typedef struct packet_mark_idxlist
{
    uint8_t    header;
	uint32_t	bufSize;
    uint16_t    count;
    //뒤에 size * (uint16_t + uint16_t)만큼 데이터 붙음
} TPacketGCMarkIDXList;

typedef struct packet_mark_block
{
    uint8_t    header;
    uint32_t   bufSize;
	uint8_t	imgIdx;
    uint32_t   count;
    // 뒤에 64 x 48 x 픽셀크기(4바이트) = 12288만큼 데이터 붙음
} TPacketGCMarkBlock;

typedef struct command_symbol_upload
{
	uint8_t	header;
	uint16_t	size;
	uint32_t	handle;
} TPacketCGSymbolUpload;

typedef struct command_symbol_crc
{
	uint8_t	header;
	uint32_t	dwGuildID;
	uint32_t	dwCRC;
	uint32_t	dwSize;
} TPacketCGSymbolCRC;

typedef struct packet_symbol_data
{
    uint8_t header;
    uint16_t size;
    uint32_t guild_id;
} TPacketGCGuildSymbolData;

//
//
//
typedef struct packet_observer_add
{
	uint8_t	header;
	uint32_t	vid;
	uint16_t	x;
	uint16_t	y;
} TPacketGCObserverAdd;

typedef struct packet_observer_move
{
	uint8_t	header;
	uint32_t	vid;
	uint16_t	x;
	uint16_t	y;
} TPacketGCObserverMove;


typedef struct packet_observer_remove
{
	uint8_t	header;
	uint32_t	vid;	
} TPacketGCObserverRemove;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// To Server

typedef struct command_checkin
{
	uint8_t header;
	char name[ID_MAX_NUM+1];
	char pwd[PASS_MAX_NUM+1];
} TPacketCGCheckin;

typedef struct command_login
{
    uint8_t header;
    char name[ID_MAX_NUM + 1];
    char pwd[PASS_MAX_NUM + 1];
} TPacketCGLogin;

// start - 권한 서버 접속을 위한 패킷들
typedef struct command_login2
{
	uint8_t	header;
	char	name[ID_MAX_NUM + 1];
	uint32_t	login_key;
    uint32_t	adwClientKey[4];
} TPacketCGLogin2;

typedef struct command_login3
{
    uint8_t	header;
    char	name[ID_MAX_NUM + 1];
    char	pwd[PASS_MAX_NUM + 1];
    uint32_t	adwClientKey[4];
} TPacketCGLogin3;

typedef struct command_direct_enter
{
    uint8_t        bHeader;
    char        login[ID_MAX_NUM + 1];
    char        passwd[PASS_MAX_NUM + 1];
    uint8_t        index;
} TPacketCGDirectEnter;

typedef struct command_player_select
{
	uint8_t	header;
	uint8_t	player_index;
} TPacketCGSelectCharacter;

typedef struct command_attack
{
	uint8_t	header;
	uint8_t	bType;			// 공격 유형
	uint32_t	dwVictimVID;	// 적 VID
	uint8_t	bCRCMagicCubeProcPiece;
	uint8_t	bCRCMagicCubeFilePiece;
} TPacketCGAttack;

typedef struct command_chat
{
	uint8_t	header;
	uint16_t	length;
	uint8_t	type;
} TPacketCGChat;

typedef struct command_whisper
{
    uint8_t        bHeader;
    uint16_t        wSize;
    char        szNameTo[CHARACTER_NAME_MAX_LEN + 1];
} TPacketCGWhisper;

typedef struct command_sms
{
    uint8_t        bHeader;
    uint16_t        wSize;
    char        szNameTo[CHARACTER_NAME_MAX_LEN + 1];
} TPacketCGSMS;

enum EBattleMode
{
	BATTLEMODE_ATTACK = 0,
	BATTLEMODE_DEFENSE = 1,
};

typedef struct command_EnterFrontGame
{
	uint8_t header;
} TPacketCGEnterFrontGame;

typedef struct command_item_use
{
	uint8_t header;
	TItemPos pos;
} TPacketCGItemUse;

typedef struct command_item_use_to_item
{
	uint8_t header;
	TItemPos source_pos;
	TItemPos target_pos;
} TPacketCGItemUseToItem;

typedef struct command_item_drop
{
	uint8_t  header;
	TItemPos pos;
	uint32_t elk;
} TPacketCGItemDrop;

typedef struct command_item_drop2
{
    uint8_t        header;
    TItemPos pos;
    uint32_t       gold;
    uint8_t        count;
} TPacketCGItemDrop2;

typedef struct command_item_move
{
	uint8_t header;
	TItemPos pos;
	TItemPos change_pos;
	uint8_t num;
} TPacketCGItemMove;

typedef struct command_item_pickup
{
	uint8_t header;
	uint32_t vid;
} TPacketCGItemPickUp;

typedef struct command_quickslot_add
{
    uint8_t        header;
    uint8_t        pos;
	TQuickSlot	slot;
}TPacketCGQuickSlotAdd;

typedef struct command_quickslot_del
{
    uint8_t        header;
    uint8_t        pos;
}TPacketCGQuickSlotDel;

typedef struct command_quickslot_swap
{
    uint8_t        header;
    uint8_t        pos;
    uint8_t        change_pos;
}TPacketCGQuickSlotSwap;

typedef struct command_on_click
{
	uint8_t		header;
	uint32_t		vid;
} TPacketCGOnClick;


enum
{
    SHOP_SUBHEADER_CG_END,
	SHOP_SUBHEADER_CG_BUY,
	SHOP_SUBHEADER_CG_SELL,
	SHOP_SUBHEADER_CG_SELL2,
};

typedef struct command_shop
{
	uint8_t        header;
	uint8_t		subheader;
} TPacketCGShop;

enum
{
	EXCHANGE_SUBHEADER_CG_START,			// arg1 == vid of target character
	EXCHANGE_SUBHEADER_CG_ITEM_ADD,		// arg1 == position of item
	EXCHANGE_SUBHEADER_CG_ITEM_DEL,		// arg1 == position of item
	EXCHANGE_SUBHEADER_CG_ELK_ADD,			// arg1 == amount of elk
	EXCHANGE_SUBHEADER_CG_ACCEPT,			// arg1 == not used
	EXCHANGE_SUBHEADER_CG_CANCEL,			// arg1 == not used
};

typedef struct command_exchange
{
	uint8_t		header;
	uint8_t		subheader;
	uint32_t		arg1;
	uint8_t		arg2;
	TItemPos	Pos;
} TPacketCGExchange;

typedef struct command_position
{   
    uint8_t        header;
    uint8_t        position;
} TPacketCGPosition;

typedef struct command_script_answer
{
    uint8_t        header;
	uint8_t		answer;
} TPacketCGScriptAnswer;

typedef struct command_script_button
{
    uint8_t        header;
	uint32_t		idx;
} TPacketCGScriptButton;

typedef struct command_target
{
    uint8_t        header;
    uint32_t       dwVID;
} TPacketCGTarget;

typedef struct command_move
{
	uint8_t		bHeader;
	uint8_t		bFunc;
	uint8_t		bArg;
	uint8_t		bRot;
	uint32_t		lX;
	uint32_t		lY;
	uint32_t		dwTime;	
} TPacketCGMove;

typedef struct command_sync_position_element 
{ 
    uint32_t       dwVID; 
    int32_t        lX; 
    int32_t        lY; 
} TPacketCGSyncPositionElement; 

typedef struct command_sync_position
{ 
    uint8_t        bHeader;
	uint16_t		wSize;
} TPacketCGSyncPosition; 

typedef struct command_fly_targeting
{
	uint8_t		bHeader;
	uint32_t		dwTargetVID;
	int32_t		lX;
	int32_t		lY;
} TPacketCGFlyTargeting;

typedef struct packet_fly_targeting
{
    uint8_t        bHeader;
	uint32_t		dwShooterVID;
	uint32_t		dwTargetVID;
	int32_t		lX;
	int32_t		lY;
} TPacketGCFlyTargeting;

typedef struct packet_shoot
{   
    uint8_t		bHeader;                
    uint8_t		bType;
} TPacketCGShoot;

typedef struct command_warp
{
	uint8_t			bHeader;
} TPacketCGWarp;

enum
{
	MESSENGER_SUBHEADER_GC_LIST,
	MESSENGER_SUBHEADER_GC_LOGIN,
	MESSENGER_SUBHEADER_GC_LOGOUT,
	MESSENGER_SUBHEADER_GC_INVITE,
	MESSENGER_SUBHEADER_GC_MOBILE,
};

typedef struct packet_messenger
{
    uint8_t header;
    uint16_t size;
    uint8_t subheader;
} TPacketGCMessenger;

typedef struct packet_messenger_list_offline
{
    uint8_t connected; // always 0
	uint8_t length;
} TPacketGCMessengerListOffline;

enum
{
	MESSENGER_CONNECTED_STATE_OFFLINE,
	MESSENGER_CONNECTED_STATE_ONLINE,
	MESSENGER_CONNECTED_STATE_MOBILE,
};

typedef struct packet_messenger_list_online
{
    uint8_t connected;
	uint8_t length;
	//uint8_t length_char_name;
} TPacketGCMessengerListOnline;

typedef struct packet_messenger_login
{
	//uint8_t length_login;
	//uint8_t length_char_name;
	uint8_t length;
} TPacketGCMessengerLogin;

typedef struct packet_messenger_logout
{
	uint8_t length;
} TPacketGCMessengerLogout;

enum
{
    MESSENGER_SUBHEADER_CG_ADD_BY_VID,
    MESSENGER_SUBHEADER_CG_ADD_BY_NAME,
    MESSENGER_SUBHEADER_CG_REMOVE,
};

typedef struct command_messenger
{
    uint8_t header;
    uint8_t subheader;
} TPacketCGMessenger;

typedef struct command_messenger_remove
{
	uint8_t length;
} TPacketCGMessengerRemove;

enum
{
	SAFEBOX_MONEY_STATE_SAVE,
	SAFEBOX_MONEY_STATE_WITHDRAW,
};

typedef struct command_safebox_money
{
    uint8_t        bHeader;
    uint8_t        bState;
    uint32_t       dwMoney;
} TPacketCGSafeboxMoney;

typedef struct command_safebox_checkout
{
    uint8_t        bHeader;
    uint8_t        bSafePos;
    TItemPos	ItemPos;
} TPacketCGSafeboxCheckout;

typedef struct command_safebox_checkin
{
    uint8_t        bHeader;
    uint8_t        bSafePos;
    TItemPos	ItemPos;
} TPacketCGSafeboxCheckin;

typedef struct command_mall_checkout
{
    uint8_t        bHeader;
    uint8_t        bMallPos;
    TItemPos	ItemPos;
} TPacketCGMallCheckout;

///////////////////////////////////////////////////////////////////////////////////
// Party

typedef struct command_use_skill
{
    uint8_t                bHeader;
    uint32_t               dwVnum;
	uint32_t				dwTargetVID;
} TPacketCGUseSkill;

typedef struct command_party_invite
{
    uint8_t header;
    uint32_t vid;
} TPacketCGPartyInvite;

typedef struct command_party_invite_answer
{
    uint8_t header;
    uint32_t leader_pid;
    uint8_t accept;
} TPacketCGPartyInviteAnswer;

typedef struct command_party_remove
{
    uint8_t header;
    uint32_t pid;
} TPacketCGPartyRemove;

typedef struct command_party_set_state
{
    uint8_t byHeader;
    uint32_t dwVID;
	uint8_t byState;
    uint8_t byFlag;
} TPacketCGPartySetState;

typedef struct packet_party_link
{
    uint8_t header;
    uint32_t pid;
    uint32_t vid;
} TPacketGCPartyLink;

typedef struct packet_party_unlink
{
    uint8_t header;
    uint32_t pid;
	uint32_t vid;
} TPacketGCPartyUnlink;

typedef struct command_party_use_skill
{
    uint8_t byHeader;
	uint8_t bySkillIndex;
    uint32_t dwTargetVID;
} TPacketCGPartyUseSkill;

enum
{
	GUILD_SUBHEADER_CG_ADD_MEMBER,
	GUILD_SUBHEADER_CG_REMOVE_MEMBER,
	GUILD_SUBHEADER_CG_CHANGE_GRADE_NAME,
	GUILD_SUBHEADER_CG_CHANGE_GRADE_AUTHORITY,
	GUILD_SUBHEADER_CG_OFFER,
	GUILD_SUBHEADER_CG_POST_COMMENT,
	GUILD_SUBHEADER_CG_DELETE_COMMENT,
	GUILD_SUBHEADER_CG_REFRESH_COMMENT,
	GUILD_SUBHEADER_CG_CHANGE_MEMBER_GRADE,
	GUILD_SUBHEADER_CG_USE_SKILL,
	GUILD_SUBHEADER_CG_CHANGE_MEMBER_GENERAL,
	GUILD_SUBHEADER_CG_GUILD_INVITE_ANSWER,
	GUILD_SUBHEADER_CG_CHARGE_GSP,
	GUILD_SUBHEADER_CG_DEPOSIT_MONEY,
	GUILD_SUBHEADER_CG_WITHDRAW_MONEY,
};

typedef struct command_guild
{
    uint8_t byHeader;
	uint8_t bySubHeader;
} TPacketCGGuild;

typedef struct command_guild_answer_make_guild
{
	uint8_t header;
	char guild_name[GUILD_NAME_MAX_LEN+1];
} TPacketCGAnswerMakeGuild; 

typedef struct command_give_item
{
	uint8_t byHeader;
	uint32_t dwTargetVID;
	TItemPos ItemPos;
	uint8_t byItemCount;
} TPacketCGGiveItem;

typedef struct SPacketCGHack
{
    uint8_t        bHeader;
    char        szBuf[255 + 1];
} TPacketCGHack;

typedef struct command_dungeon
{
	uint8_t		bHeader;
	uint16_t		size;
} TPacketCGDungeon;

// Private Shop
typedef struct SShopItemTable
{
    uint32_t		vnum;
    uint8_t		count;

    TItemPos	pos;			// PC 상점에만 이용
    uint32_t		price;			// PC 상점에만 이용
    uint8_t		display_pos;	//	PC 상점에만 이용, 보일 위치.
} TShopItemTable;

typedef struct SPacketCGMyShop
{
    uint8_t        bHeader;
    char        szSign[SHOP_SIGN_MAX_LEN + 1];
    uint8_t        bCount;	// count of TShopItemTable, max 39
} TPacketCGMyShop;

typedef struct SPacketCGRefine
{
	uint8_t		header;
	uint8_t		pos;
	uint8_t		type;
} TPacketCGRefine;

typedef struct SPacketCGChangeName
{
    uint8_t header;
    uint8_t index;
    char name[CHARACTER_NAME_MAX_LEN+1];
} TPacketCGChangeName;

typedef struct command_client_version
{
	uint8_t header;
	char filename[32+1];
	char timestamp[32+1];
} TPacketCGClientVersion;

typedef struct command_client_version2
{
	uint8_t header;
	char filename[32+1];
	char timestamp[32+1];
} TPacketCGClientVersion2;

typedef struct command_crc_report
{
	uint8_t header;
	uint8_t byPackMode;
	uint32_t dwBinaryCRC32;
	uint32_t dwProcessCRC32;
	uint32_t dwRootPackCRC32;
} TPacketCGCRCReport;

typedef struct command_china_matrix_card
{
	uint8_t	bHeader;
	char	szAnswer[CHINA_MATRIX_ANSWER_MAX_LEN + 1];
} TPacketCGChinaMatrixCard;

typedef struct command_runup_matrix_answer
{
	uint8_t	bHeader;
	char	szAnswer[RUNUP_MATRIX_ANSWER_MAX_LEN + 1];
} TPacketCGRunupMatrixAnswer;

enum EPartyExpDistributionType
{
    PARTY_EXP_DISTRIBUTION_NON_PARITY,
    PARTY_EXP_DISTRIBUTION_PARITY,
};

typedef struct command_party_parameter
{
    uint8_t        bHeader;
    uint8_t        bDistributeMode;
} TPacketCGPartyParameter;

typedef struct command_quest_input_string
{
    uint8_t        bHeader;
    char		szString[QUEST_INPUT_STRING_MAX_NUM+1];
} TPacketCGQuestInputString;

typedef struct command_quest_confirm
{
    uint8_t header;
    uint8_t answer;
    uint32_t requestPID;
} TPacketCGQuestConfirm;

typedef struct command_script_select_item
{
    uint8_t header;
    uint32_t selection;
} TPacketCGScriptSelectItem;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// From Server
enum EPhase
{
    PHASE_CLOSE,				// 끊기는 상태 (또는 끊기 전 상태)
    PHASE_HANDSHAKE,			// 악수..;;
    PHASE_LOGIN,				// 로그인 중
    PHASE_SELECT,				// 캐릭터 선택 화면
    PHASE_LOADING,				// 선택 후 로딩 화면
    PHASE_GAME,					// 게임 화면
    PHASE_DEAD,					// 죽었을 때.. (게임 안에 있는 것일 수도..)

	PHASE_DBCLIENT_CONNECTING,	// 서버용
    PHASE_DBCLIENT,				// 서버용
    PHASE_P2P,					// 서버용
    PHASE_AUTH,					// 로그인 인증 용
};

typedef struct packet_phase
{
    uint8_t        header;
    uint8_t        phase;
} TPacketGCPhase;

typedef struct packet_blank		// 공백패킷.
{
	uint8_t		header;
} TPacketGCBlank;

typedef struct packet_blank_dynamic
{
	uint8_t		header;
	uint16_t		size;
} TPacketGCBlankDynamic;

typedef struct packet_header_handshake
{
	uint8_t		header;
	uint32_t		dwHandshake;
	uint32_t		dwTime;
	int32_t		lDelta;
} TPacketGCHandshake;

typedef struct packet_header_bindudp
{
	uint8_t		header;
	uint32_t		addr;
	uint16_t		port;
} TPacketGCBindUDP;

typedef struct packet_header_dynamic_size
{
	uint8_t		header;
	uint16_t		size;
} TDynamicSizePacketHeader;

typedef struct SSimplePlayerInformation
{
    uint32_t               dwID;
    char                szName[CHARACTER_NAME_MAX_LEN + 1];
    uint8_t                byJob;
    uint8_t                byLevel;
    uint32_t               dwPlayMinutes;
    uint8_t                byST, byHT, byDX, byIQ;
//	uint16_t				wParts[CRaceData::PART_MAX_NUM];
    uint16_t                wMainPart;
    uint8_t                bChangeName;
	uint16_t				wHairPart;
    uint8_t                bDummy[4];
	int32_t				x, y;
	uint32_t				lAddr;
	uint16_t				wPort;
	uint8_t				bySkillGroup;
} TSimplePlayerInformation;

typedef struct packet_login_success3
{
	uint8_t						header;
	TSimplePlayerInformation	akSimplePlayerInformation[PLAYER_PER_ACCOUNT3];
    uint32_t						guild_id[PLAYER_PER_ACCOUNT3];
    char						guild_name[PLAYER_PER_ACCOUNT3][GUILD_NAME_MAX_LEN+1];
	uint32_t handle;
	uint32_t random_key;
} TPacketGCLoginSuccess3;

typedef struct packet_login_success4
{
	uint8_t						header;
	TSimplePlayerInformation	akSimplePlayerInformation[PLAYER_PER_ACCOUNT4];
    uint32_t						guild_id[PLAYER_PER_ACCOUNT4];
    char						guild_name[PLAYER_PER_ACCOUNT4][GUILD_NAME_MAX_LEN+1];
	uint32_t handle;
	uint32_t random_key;
} TPacketGCLoginSuccess4;


enum { LOGIN_STATUS_MAX_LEN = 8 };
typedef struct packet_login_failure
{
	uint8_t	header;
	char	szStatus[LOGIN_STATUS_MAX_LEN + 1];
} TPacketGCLoginFailure;

typedef struct command_player_create
{
	uint8_t        header;
	uint8_t        index;
	char        name[CHARACTER_NAME_MAX_LEN + 1];
	uint16_t        job;
	uint8_t		shape;
	uint8_t		CON;
	uint8_t		INT;
	uint8_t		STR;
	uint8_t		DEX;
} TPacketCGCreateCharacter;

typedef struct command_player_create_success
{
    uint8_t						header;
    uint8_t						bAccountCharacterSlot;
    TSimplePlayerInformation	kSimplePlayerInfomation;
} TPacketGCPlayerCreateSuccess;

typedef struct command_create_failure
{
	uint8_t	header;
	uint8_t	bType;
} TPacketGCCreateFailure;

typedef struct command_player_delete
{
	uint8_t        header;
	uint8_t        index;
	char		szPrivateCode[PRIVATE_CODE_LENGTH];
} TPacketCGDestroyCharacter;

typedef struct packet_player_delete_success
{
	uint8_t        header;
	uint8_t        account_index;
} TPacketGCDestroyCharacterSuccess;

enum
{
	ADD_CHARACTER_STATE_DEAD   = (1 << 0),
	ADD_CHARACTER_STATE_SPAWN  = (1 << 1),
	ADD_CHARACTER_STATE_GUNGON = (1 << 2),
	ADD_CHARACTER_STATE_KILLER = (1 << 3),
	ADD_CHARACTER_STATE_PARTY  = (1 << 4),
};

enum EPKModes
{
	PK_MODE_PEACE,
	PK_MODE_REVENGE,
	PK_MODE_FREE,
	PK_MODE_PROTECT,
	PK_MODE_GUILD,
	PK_MODE_MAX_NUM,
};

// 2004.11.20.myevan.CRaceData::PART_MAX_NUM 사용안하게 수정 - 서버에서 사용하는것과 일치하지 않음
enum ECharacterEquipmentPart
{
	CHR_EQUIPPART_ARMOR,
	CHR_EQUIPPART_WEAPON,
	CHR_EQUIPPART_HEAD,
	CHR_EQUIPPART_HAIR,

	CHR_EQUIPPART_NUM,		
};

typedef struct packet_char_additional_info
{
	uint8_t    header;
	uint32_t   dwVID;
	char    name[CHARACTER_NAME_MAX_LEN + 1];
	uint16_t    awPart[CHR_EQUIPPART_NUM];
	uint8_t	bEmpire;
	uint32_t   dwGuildID;
	uint32_t   dwLevel;
	int16_t   sAlignment; //선악치
	uint8_t    bPKMode;
	uint32_t   dwMountVnum;
} TPacketGCCharacterAdditionalInfo;

typedef struct packet_add_char
{
    uint8_t        header;

    uint32_t       dwVID;

    //char        name[CHARACTER_NAME_MAX_LEN + 1];

    float       angle;
    int32_t        x;
    int32_t        y;
    int32_t        z;

	uint8_t		bType;
    uint16_t        wRaceNum;
    //uint16_t        awPart[CHR_EQUIPPART_NUM];
    uint8_t        bMovingSpeed;
    uint8_t        bAttackSpeed;

    uint8_t        bStateFlag;
    uint32_t       dwAffectFlag[2];        // ??
    //uint8_t      bEmpire;
    //uint32_t     dwGuild;
    //int16_t     sAlignment;	
	//uint8_t		bPKMode;
	//uint32_t		dwMountVnum;
} TPacketGCCharacterAdd;

typedef struct packet_add_char2
{
    uint8_t        header;

    uint32_t       dwVID;

    char        name[CHARACTER_NAME_MAX_LEN + 1];

    float       angle;
    int32_t        x;
    int32_t        y;
    int32_t        z;

	uint8_t		bType;
    uint16_t        wRaceNum;
    uint16_t        awPart[CHR_EQUIPPART_NUM];
    uint8_t        bMovingSpeed;
    uint8_t        bAttackSpeed;

    uint8_t        bStateFlag;
    uint32_t       dwAffectFlag[2];        // ??
    uint8_t        bEmpire;

    uint32_t       dwGuild;
    int16_t       sAlignment;
	uint8_t		bPKMode;
	uint32_t		dwMountVnum;
} TPacketGCCharacterAdd2;

typedef struct packet_update_char
{
    uint8_t        header;
    uint32_t       dwVID;

    uint16_t        awPart[CHR_EQUIPPART_NUM];
    uint8_t        bMovingSpeed;
	uint8_t		bAttackSpeed;

    uint8_t        bStateFlag;
    uint32_t       dwAffectFlag[2];

	uint32_t		dwGuildID;
    int16_t       sAlignment;
	uint8_t		bPKMode;
	uint32_t		dwMountVnum;
} TPacketGCCharacterUpdate;

typedef struct packet_update_char2
{
    uint8_t        header;
    uint32_t       dwVID;

    uint16_t        awPart[CHR_EQUIPPART_NUM];
    uint8_t        bMovingSpeed;
	uint8_t		bAttackSpeed;

    uint8_t        bStateFlag;
    uint32_t       dwAffectFlag[2];

	uint32_t		dwGuildID;
    int16_t       sAlignment;
	uint8_t		bPKMode;
	uint32_t		dwMountVnum;
} TPacketGCCharacterUpdate2;

typedef struct packet_del_char
{
	uint8_t	header;
    uint32_t	dwVID;
} TPacketGCCharacterDelete;

typedef struct packet_GlobalTime
{
	uint8_t	header;
	float	GlobalTime;
} TPacketGCGlobalTime;

enum EChatType
{
	CHAT_TYPE_TALKING,  /* 그냥 채팅 */
	CHAT_TYPE_INFO,     /* 정보 (아이템을 집었다, 경험치를 얻었다. 등) */
	CHAT_TYPE_NOTICE,   /* 공지사항 */
	CHAT_TYPE_PARTY,    /* 파티말 */
	CHAT_TYPE_GUILD,    /* 길드말 */
	CHAT_TYPE_COMMAND,	/* 명령 */
	CHAT_TYPE_SHOUT,	/* 외치기 */
	CHAT_TYPE_WHISPER,	// 서버와는 연동되지 않는 Only Client Enum
	CHAT_TYPE_BIG_NOTICE,
	CHAT_TYPE_MAX_NUM,
};

typedef struct packet_chatting
{
	uint8_t	header;
	uint16_t	size;
	uint8_t	type;
	uint32_t	dwVID;
	uint8_t	bEmpire;
} TPacketGCChat;

typedef struct packet_whisper   // 가변 패킷    
{   
    uint8_t        bHeader;                        
    uint16_t        wSize;
    uint8_t        bType;
    char        szNameFrom[CHARACTER_NAME_MAX_LEN + 1];
} TPacketGCWhisper;

typedef struct packet_stun
{
	uint8_t		header;
	uint32_t		vid;
} TPacketGCStun;

typedef struct packet_dead
{
	uint8_t		header;
	uint32_t		vid;
} TPacketGCDead;

typedef struct packet_main_character
{
    uint8_t        header;
    uint32_t       dwVID;
	uint16_t		wRaceNum;
    char        szName[CHARACTER_NAME_MAX_LEN + 1];
    int32_t        lX, lY, lZ;
	uint8_t		bySkillGroup;
} TPacketGCMainCharacter;

// SUPPORT_BGM
typedef struct packet_main_character2_empire
{
    uint8_t        header;
    uint32_t       dwVID;
	uint16_t		wRaceNum;
    char        szName[CHARACTER_NAME_MAX_LEN + 1];
    int32_t        lX, lY, lZ;
	uint8_t		byEmpire;
	uint8_t		bySkillGroup;
} TPacketGCMainCharacter2_EMPIRE;

typedef struct packet_main_character3_bgm
{
	enum
	{
		MUSIC_NAME_MAX_LEN = 24,
	};
    uint8_t        header;
    uint32_t       dwVID;
	uint16_t		wRaceNum;
    char        szUserName[CHARACTER_NAME_MAX_LEN + 1];
	char        szBGMName[MUSIC_NAME_MAX_LEN + 1];
    int32_t        lX, lY, lZ;
	uint8_t		byEmpire;
	uint8_t		bySkillGroup;
} TPacketGCMainCharacter3_BGM;

typedef struct packet_main_character4_bgm_vol
{
	enum
	{
		MUSIC_NAME_MAX_LEN = 24,
	};
    uint8_t        header;
    uint32_t       dwVID;
	uint16_t		wRaceNum;
    char        szUserName[CHARACTER_NAME_MAX_LEN + 1];
	char        szBGMName[MUSIC_NAME_MAX_LEN + 1];
	float		fBGMVol;
    int32_t        lX, lY, lZ;
	uint8_t		byEmpire;
	uint8_t		bySkillGroup;
} TPacketGCMainCharacter4_BGM_VOL;
// END_OF_SUPPORT_BGM

enum EPointTypes
{
    POINT_NONE,                 // 0
    POINT_LEVEL,                // 1
    POINT_VOICE,                // 2
    POINT_EXP,                  // 3
    POINT_NEXT_EXP,             // 4
    POINT_HP,                   // 5
    POINT_MAX_HP,               // 6
    POINT_SP,                   // 7
    POINT_MAX_SP,               // 8  
    POINT_STAMINA,              // 9  스테미너
    POINT_MAX_STAMINA,          // 10 최대 스테미너
    
    POINT_GOLD,                 // 11
    POINT_ST,                   // 12 근력
    POINT_HT,                   // 13 체력
    POINT_DX,                   // 14 민첩성
    POINT_IQ,                   // 15 정신력
    POINT_ATT_POWER,            // 16 공격력
    POINT_ATT_SPEED,            // 17 공격속도
    POINT_EVADE_RATE,           // 18 회피율
    POINT_MOV_SPEED,            // 19 이동속도
    POINT_DEF_GRADE,            // 20 방어등급
	POINT_CASTING_SPEED,        // 21 주문속도 (쿨다운타임*100) / (100 + 이값) = 최종 쿨다운 타임
	POINT_MAGIC_ATT_GRADE,      // 22 마법공격력
    POINT_MAGIC_DEF_GRADE,      // 23 마법방어력
    POINT_EMPIRE_POINT,         // 24 제국점수
    POINT_LEVEL_STEP,           // 25 한 레벨에서의 단계.. (1 2 3 될 때 보상, 4 되면 레벨 업)
    POINT_STAT,                 // 26 능력치 올릴 수 있는 개수
	POINT_SUB_SKILL,            // 27 보조 스킬 포인트
	POINT_SKILL,                // 28 액티브 스킬 포인트
//    POINT_SKILL_PASV,           // 27 패시브 기술 올릴 수 있는 개수
//    POINT_SKILL_ACTIVE,         // 28 액티브 스킬 포인트
	POINT_MIN_ATK,				// 29 최소 파괴력
	POINT_MAX_ATK,				// 30 최대 파괴력
    POINT_PLAYTIME,             // 31 플레이시간
    POINT_HP_REGEN,             // 32 HP 회복률
    POINT_SP_REGEN,             // 33 SP 회복률
    
    POINT_BOW_DISTANCE,         // 34 활 사정거리 증가치 (meter)
    
    POINT_HP_RECOVERY,          // 35 체력 회복 증가량
    POINT_SP_RECOVERY,          // 36 정신력 회복 증가량
    
    POINT_POISON_PCT,           // 37 독 확률
    POINT_STUN_PCT,             // 38 기절 확률
    POINT_SLOW_PCT,             // 39 슬로우 확률
    POINT_CRITICAL_PCT,         // 40 크리티컬 확률
    POINT_PENETRATE_PCT,        // 41 관통타격 확률
    POINT_CURSE_PCT,            // 42 저주 확률
    
    POINT_ATTBONUS_HUMAN,       // 43 인간에게 강함
    POINT_ATTBONUS_ANIMAL,      // 44 동물에게 데미지 % 증가
    POINT_ATTBONUS_ORC,         // 45 웅귀에게 데미지 % 증가
    POINT_ATTBONUS_MILGYO,      // 46 밀교에게 데미지 % 증가
    POINT_ATTBONUS_UNDEAD,      // 47 시체에게 데미지 % 증가
    POINT_ATTBONUS_DEVIL,       // 48 마귀(악마)에게 데미지 % 증가
    POINT_ATTBONUS_INSECT,      // 49 벌레족
    POINT_ATTBONUS_FIRE,        // 50 화염족
    POINT_ATTBONUS_ICE,         // 51 빙설족
    POINT_ATTBONUS_DESERT,      // 52 사막족
    POINT_ATTBONUS_UNUSED0,     // 53 UNUSED0
    POINT_ATTBONUS_UNUSED1,     // 54 UNUSED1
    POINT_ATTBONUS_UNUSED2,     // 55 UNUSED2
    POINT_ATTBONUS_UNUSED3,     // 56 UNUSED3
    POINT_ATTBONUS_UNUSED4,     // 57 UNUSED4
    POINT_ATTBONUS_UNUSED5,     // 58 UNUSED5
    POINT_ATTBONUS_UNUSED6,     // 59 UNUSED6
    POINT_ATTBONUS_UNUSED7,     // 60 UNUSED7
    POINT_ATTBONUS_UNUSED8,     // 61 UNUSED8
    POINT_ATTBONUS_UNUSED9,     // 62 UNUSED9

    POINT_STEAL_HP,             // 63 생명력 흡수
    POINT_STEAL_SP,             // 64 정신력 흡수

    POINT_MANA_BURN_PCT,        // 65 마나 번

    /// 피해시 보너스 ///

    POINT_DAMAGE_SP_RECOVER,    // 66 공격당할 시 정신력 회복 확률

    POINT_BLOCK,                // 67 블럭율
    POINT_DODGE,                // 68 회피율

    POINT_RESIST_SWORD,         // 69
    POINT_RESIST_TWOHAND,       // 70
    POINT_RESIST_DAGGER,        // 71
    POINT_RESIST_BELL,          // 72
    POINT_RESIST_FAN,           // 73
    POINT_RESIST_BOW,           // 74  화살   저항   : 대미지 감소
    POINT_RESIST_FIRE,          // 75  화염   저항   : 화염공격에 대한 대미지 감소
    POINT_RESIST_ELEC,          // 76  전기   저항   : 전기공격에 대한 대미지 감소
    POINT_RESIST_MAGIC,         // 77  술법   저항   : 모든술법에 대한 대미지 감소
    POINT_RESIST_WIND,          // 78  바람   저항   : 바람공격에 대한 대미지 감소

    POINT_REFLECT_MELEE,        // 79 공격 반사

    /// 특수 피해시 ///
    POINT_REFLECT_CURSE,        // 80 저주 반사
    POINT_POISON_REDUCE,        // 81 독데미지 감소

    /// 적 소멸시 ///
    POINT_KILL_SP_RECOVER,      // 82 적 소멸시 MP 회복
    POINT_EXP_DOUBLE_BONUS,     // 83
    POINT_GOLD_DOUBLE_BONUS,    // 84
    POINT_ITEM_DROP_BONUS,      // 85

    /// 회복 관련 ///
    POINT_POTION_BONUS,         // 86
    POINT_KILL_HP_RECOVER,      // 87

    POINT_IMMUNE_STUN,          // 88
    POINT_IMMUNE_SLOW,          // 89
    POINT_IMMUNE_FALL,          // 90
    //////////////////

    POINT_PARTY_ATT_GRADE,      // 91
    POINT_PARTY_DEF_GRADE,      // 92

    POINT_ATT_BONUS,            // 93
    POINT_DEF_BONUS,            // 94

    POINT_ATT_GRADE_BONUS,			// 95
    POINT_DEF_GRADE_BONUS,			// 96
    POINT_MAGIC_ATT_GRADE_BONUS,	// 97
    POINT_MAGIC_DEF_GRADE_BONUS,	// 98

    POINT_RESIST_NORMAL_DAMAGE,		// 99

	POINT_STAT_RESET_COUNT = 112,
    POINT_HORSE_SKILL = 113,

	POINT_MALL_ATTBONUS,		// 114 공격력 +x%
	POINT_MALL_DEFBONUS,		// 115 방어력 +x%
	POINT_MALL_EXPBONUS,		// 116 경험치 +x%
	POINT_MALL_ITEMBONUS,		// 117 아이템 드롭율 x/10배
	POINT_MALL_GOLDBONUS,		// 118 돈 드롭율 x/10배
    POINT_MAX_HP_PCT,			// 119 최대생명력 +x%
    POINT_MAX_SP_PCT,			// 120 최대정신력 +x%

	POINT_SKILL_DAMAGE_BONUS,       // 121 스킬 데미지 *(100+x)%
	POINT_NORMAL_HIT_DAMAGE_BONUS,  // 122 평타 데미지 *(100+x)%
   
    POINT_SKILL_DEFEND_BONUS,       // 123 스킬 방어 데미지
    POINT_NORMAL_HIT_DEFEND_BONUS,  // 124 평타 방어 데미지
    POINT_PC_BANG_EXP_BONUS,        // 125
	POINT_PC_BANG_DROP_BONUS,       // 126 PC방 전용 드롭률 보너스

	POINT_ENERGY = 128,				// 128 기력

	// 기력 ui 용.
	// 이렇게 하고 싶지 않았지만, 
	// uiTaskBar에서는 affect에 접근할 수 없고,
	// 더구나 클라리언트에서는 blend_affect는 관리하지 않아,
	// 임시로 이렇게 둔다.
	POINT_ENERGY_END_TIME = 129,	// 129 기력 종료 시간

	// 클라이언트 포인트
	POINT_MIN_WEP = 200,
	POINT_MAX_WEP,
	POINT_MIN_MAGIC_WEP,
	POINT_MAX_MAGIC_WEP,
	POINT_HIT_RATE,


    //POINT_MAX_NUM = 255,=>stdafx.h 로/
};

typedef struct packet_points
{
    uint8_t        header;
    int32_t        points[POINT_MAX_NUM];
} TPacketGCPoints;

typedef struct packet_point_change
{
    int32_t         header;

	uint32_t		dwVID;
	uint8_t		Type;

	int32_t        amount; // 바뀐 값
    int32_t        value;  // 현재 값
} TPacketGCPointChange;

typedef struct packet_motion
{
	uint8_t		header;
	uint32_t		vid;
	uint32_t		victim_vid;
	uint16_t		motion;
} TPacketGCMotion;

typedef struct packet_del_item
{
	uint8_t		header;
	TItemPos	pos;
} TPacketGCItemDel;

typedef struct packet_set_item
{
	uint8_t					header;
	TItemPos				pos;
	uint32_t				vnum;
	uint8_t					count;
	uint32_t				flags;	// 플래그 추가
	uint32_t				anti_flags;	// 플래그 추가
	uint8_t					highlight;
	int32_t					alSockets[ITEM_SOCKET_SLOT_MAX_NUM];
    TPlayerItemAttribute	aAttr[ITEM_ATTRIBUTE_SLOT_MAX_NUM];
} TPacketGCItemSet;

typedef struct packet_use_item
{
	uint8_t		header;
	TItemPos	Cell;
	uint32_t		ch_vid;
	uint32_t		victim_vid;

	uint32_t		vnum;
} TPacketGCItemUse;

typedef struct packet_update_item
{
	uint8_t		header;
	TItemPos	Cell;
	uint8_t		count;
	int32_t		alSockets[ITEM_SOCKET_SLOT_MAX_NUM];
    TPlayerItemAttribute aAttr[ITEM_ATTRIBUTE_SLOT_MAX_NUM];
} TPacketGCItemUpdate;

typedef struct packet_ground_add_item
{
    uint8_t        bHeader;
    int32_t        lX;
	int32_t		lY;
	int32_t		lZ;

    uint32_t       dwVID;
    uint32_t       dwVnum;
} TPacketGCItemGroundAdd;

typedef struct packet_ground_del_item
{
	uint8_t		header;
	uint32_t		vid;
} TPacketGCItemGroundDel;

typedef struct packet_item_ownership
{
    uint8_t        bHeader;
    uint32_t       dwVID;
    char        szName[CHARACTER_NAME_MAX_LEN + 1];
} TPacketGCItemOwnership;

typedef struct packet_quickslot_add
{
    uint8_t        header;
    uint8_t        pos;
	TQuickSlot	slot;
} TPacketGCQuickSlotAdd;

typedef struct packet_quickslot_del
{
    uint8_t        header;
    uint8_t        pos;
} TPacketGCQuickSlotDel;

typedef struct packet_quickslot_swap
{
    uint8_t        header;
    uint8_t        pos;
    uint8_t        change_pos;
} TPacketGCQuickSlotSwap;

typedef struct packet_shop_start
{
	struct packet_shop_item		items[SHOP_HOST_ITEM_MAX_NUM];
} TPacketGCShopStart;

typedef struct packet_shop_start_ex // 다음에 TSubPacketShopTab* shop_tabs 이 따라옴.
{
	typedef struct sub_packet_shop_tab 
	{
		char name[SHOP_TAB_NAME_MAX];
		uint8_t coin_type;
		packet_shop_item items[SHOP_HOST_ITEM_MAX_NUM];
	} TSubPacketShopTab;
	uint32_t owner_vid;
	uint8_t shop_tab_count;
} TPacketGCShopStartEx;


typedef struct packet_shop_update_item
{
	uint8_t						pos;
	struct packet_shop_item		item;
} TPacketGCShopUpdateItem;

typedef struct packet_shop_update_price
{
	int32_t iElkAmount;
} TPacketGCShopUpdatePrice;

enum EPacketShopSubHeaders
{
	SHOP_SUBHEADER_GC_START,
    SHOP_SUBHEADER_GC_END,
	SHOP_SUBHEADER_GC_UPDATE_ITEM,
	SHOP_SUBHEADER_GC_UPDATE_PRICE,
    SHOP_SUBHEADER_GC_OK,
    SHOP_SUBHEADER_GC_NOT_ENOUGH_MONEY,
    SHOP_SUBHEADER_GC_SOLDOUT,
    SHOP_SUBHEADER_GC_INVENTORY_FULL,
    SHOP_SUBHEADER_GC_INVALID_POS,
	SHOP_SUBHEADER_GC_SOLD_OUT,
	SHOP_SUBHEADER_GC_START_EX,
	SHOP_SUBHEADER_GC_NOT_ENOUGH_MONEY_EX,
};

typedef struct packet_shop
{
	uint8_t        header;
	uint16_t		size;
	uint8_t        subheader;
} TPacketGCShop;

typedef struct packet_exchange
{
    uint8_t        header;
    uint8_t        subheader;
    uint8_t        is_me;
    uint32_t       arg1;
    TItemPos       arg2;
    uint32_t       arg3;
	int32_t		alValues[ITEM_SOCKET_SLOT_MAX_NUM];
    TPlayerItemAttribute aAttr[ITEM_ATTRIBUTE_SLOT_MAX_NUM];
} TPacketGCExchange;

enum
{
    EXCHANGE_SUBHEADER_GC_START,			// arg1 == vid
    EXCHANGE_SUBHEADER_GC_ITEM_ADD,		// arg1 == vnum  arg2 == pos  arg3 == count
	EXCHANGE_SUBHEADER_GC_ITEM_DEL,		// arg1 == pos
    EXCHANGE_SUBHEADER_GC_ELK_ADD,			// arg1 == elk
    EXCHANGE_SUBHEADER_GC_ACCEPT,			// arg1 == accept
    EXCHANGE_SUBHEADER_GC_END,				// arg1 == not used
    EXCHANGE_SUBHEADER_GC_ALREADY,			// arg1 == not used
    EXCHANGE_SUBHEADER_GC_LESS_ELK,		// arg1 == not used
};

typedef struct packet_position
{
    uint8_t        header;
	uint32_t		vid;
    uint8_t        position;
} TPacketGCPosition;

typedef struct packet_ping
{
	uint8_t		header;
} TPacketGCPing;

typedef struct packet_pong
{
	uint8_t		bHeader;
} TPacketCGPong;

typedef struct packet_script
{
    uint8_t		header;
    uint16_t        size;
	uint8_t		skin;
    uint16_t        src_size;
} TPacketGCScript;

typedef struct packet_target
{
    uint8_t        header;
    uint32_t       dwVID;
    uint8_t        bHPPercent;
} TPacketGCTarget;

typedef struct packet_damage_info
{
	uint8_t header;
	uint32_t dwVID;
	uint8_t flag;
	int32_t  damage;
} TPacketGCDamageInfo;

typedef struct packet_mount
{
    uint8_t        header;
    uint32_t       vid;
    uint32_t       mount_vid;
    uint8_t        pos;
	uint32_t		_x, _y;
} TPacketGCMount;

typedef struct packet_change_speed
{
	uint8_t		header;
	uint32_t		vid;
	uint16_t		moving_speed;
} TPacketGCChangeSpeed;

typedef struct packet_move
{	
	uint8_t		bHeader;
	uint8_t		bFunc;
	uint8_t		bArg;
	uint8_t		bRot;
	uint32_t		dwVID;
	int32_t		lX;
	int32_t		lY;
	uint32_t		dwTime;
	uint32_t		dwDuration;
} TPacketGCMove;

enum
{
	QUEST_SEND_IS_BEGIN         = 1 << 0,
    QUEST_SEND_TITLE            = 1 << 1,  // 28자 까지
    QUEST_SEND_CLOCK_NAME       = 1 << 2,  // 16자 까지
    QUEST_SEND_CLOCK_VALUE      = 1 << 3,
    QUEST_SEND_COUNTER_NAME     = 1 << 4,  // 16자 까지
    QUEST_SEND_COUNTER_VALUE    = 1 << 5,
	QUEST_SEND_ICON_FILE		= 1 << 6,  // 24자 까지 
};

typedef struct packet_quest_info
{
	uint8_t header;
	uint16_t size;
	uint16_t index;
	uint8_t flag;
} TPacketGCQuestInfo;

typedef struct packet_quest_confirm
{
    uint8_t header;
    char msg[64+1];
    int32_t timeout;
    uint32_t requestPID;
} TPacketGCQuestConfirm;

typedef struct packet_attack
{
    uint8_t        header;
    uint32_t       dwVID;
    uint32_t       dwVictimVID;    // 적 VID
    uint8_t        bType;          // 공격 유형
} TPacketGCAttack;

typedef struct packet_c2c
{
	uint8_t		header;
	uint16_t		wSize;
} TPacketGCC2C;

typedef struct packetd_sync_position_element 
{ 
    uint32_t       dwVID; 
    int32_t        lX; 
    int32_t        lY; 
} TPacketGCSyncPositionElement; 

typedef struct packetd_sync_position
{ 
    uint8_t        bHeader; 
    uint16_t		wSize;
} TPacketGCSyncPosition; 

typedef struct packet_ownership 
{ 
    uint8_t                bHeader; 
    uint32_t               dwOwnerVID; 
    uint32_t               dwVictimVID; 
} TPacketGCOwnership; 

#define	SKILL_MAX_NUM 255

typedef struct packet_skill_level
{
    uint8_t        bHeader;
    uint8_t        abSkillLevels[SKILL_MAX_NUM];
} TPacketGCSkillLevel;

typedef struct SPlayerSkill
{
	uint8_t bMasterType;
	uint8_t bLevel;
	time_t tNextRead;
} TPlayerSkill;

typedef struct packet_skill_level_new
{
	uint8_t bHeader;
	TPlayerSkill skills[SKILL_MAX_NUM];
} TPacketGCSkillLevelNew;

// fly
typedef struct packet_fly
{
    uint8_t        bHeader;
    uint8_t        bType;
    uint32_t       dwStartVID;
    uint32_t       dwEndVID;
} TPacketGCCreateFly;

enum EPVPModes
{
	PVP_MODE_NONE,
    PVP_MODE_AGREE,
    PVP_MODE_FIGHT,
    PVP_MODE_REVENGE,
};

typedef struct packet_duel_start
{
    uint8_t	header ;
    uint16_t	wSize ;	// uint32_t가 몇개? 개수 = (wSize - sizeof(TPacketGCPVPList)) / 4
} TPacketGCDuelStart ;

typedef struct packet_pvp
{
	uint8_t		header;
	uint32_t		dwVIDSrc;
	uint32_t		dwVIDDst;
	uint8_t		bMode;
} TPacketGCPVP;

typedef struct packet_skill_cooltime_end
{
	uint8_t		header;
	uint8_t		bSkill;
} TPacketGCSkillCoolTimeEnd;

typedef struct packet_warp
{
	uint8_t			bHeader;
	int32_t			lX;
	int32_t			lY;
	int32_t			lAddr;
	uint16_t			wPort;
} TPacketGCWarp;

typedef struct packet_party_invite
{
    uint8_t header;
    uint32_t leader_pid;
} TPacketGCPartyInvite;

typedef struct packet_party_add
{
    uint8_t header;
    uint32_t pid;
    char name[CHARACTER_NAME_MAX_LEN+1];
} TPacketGCPartyAdd;

typedef struct packet_party_update
{
    uint8_t header;
    uint32_t pid;
    uint8_t state;
    uint8_t percent_hp;
    int16_t affects[PARTY_AFFECT_SLOT_MAX_NUM];
} TPacketGCPartyUpdate;

typedef struct packet_party_remove
{
    uint8_t header;
    uint32_t pid;
} TPacketGCPartyRemove;

typedef TPacketCGSafeboxCheckout TPacketGCSafeboxCheckout;
typedef TPacketCGSafeboxCheckin TPacketGCSafeboxCheckin;

typedef struct packet_safebox_wrong_password
{
    uint8_t        bHeader;
} TPacketGCSafeboxWrongPassword;

typedef struct packet_safebox_size
{
	uint8_t bHeader;
	uint8_t bSize;
} TPacketGCSafeboxSize; 

typedef struct packet_safebox_money_change
{
    uint8_t bHeader;
    uint32_t dwMoney;
} TPacketGCSafeboxMoneyChange;

typedef struct command_empire
{
    uint8_t        bHeader;
    uint8_t        bEmpire;
} TPacketCGEmpire;

typedef struct packet_empire
{
    uint8_t        bHeader;
    uint8_t        bEmpire;
} TPacketGCEmpire;

enum
{
	FISHING_SUBHEADER_GC_START,
	FISHING_SUBHEADER_GC_STOP,
	FISHING_SUBHEADER_GC_REACT,
	FISHING_SUBHEADER_GC_SUCCESS,
	FISHING_SUBHEADER_GC_FAIL,
    FISHING_SUBHEADER_GC_FISH,
};

typedef struct packet_fishing
{
    uint8_t header;
    uint8_t subheader;
    uint32_t info;
    uint8_t dir;
} TPacketGCFishing;

typedef struct paryt_parameter
{
    uint8_t        bHeader;
    uint8_t        bDistributeMode;
} TPacketGCPartyParameter;

//////////////////////////////////////////////////////////////////////////
// Guild

enum
{
    GUILD_SUBHEADER_GC_LOGIN,
	GUILD_SUBHEADER_GC_LOGOUT,
	GUILD_SUBHEADER_GC_LIST,
	GUILD_SUBHEADER_GC_GRADE,
	GUILD_SUBHEADER_GC_ADD,
	GUILD_SUBHEADER_GC_REMOVE,
	GUILD_SUBHEADER_GC_GRADE_NAME,
	GUILD_SUBHEADER_GC_GRADE_AUTH, 
	GUILD_SUBHEADER_GC_INFO,
	GUILD_SUBHEADER_GC_COMMENTS,
    GUILD_SUBHEADER_GC_CHANGE_EXP,
    GUILD_SUBHEADER_GC_CHANGE_MEMBER_GRADE,
	GUILD_SUBHEADER_GC_SKILL_INFO,
	GUILD_SUBHEADER_GC_CHANGE_MEMBER_GENERAL,
	GUILD_SUBHEADER_GC_GUILD_INVITE,
    GUILD_SUBHEADER_GC_WAR,
    GUILD_SUBHEADER_GC_GUILD_NAME,
    GUILD_SUBHEADER_GC_GUILD_WAR_LIST,
    GUILD_SUBHEADER_GC_GUILD_WAR_END_LIST,
    GUILD_SUBHEADER_GC_WAR_POINT,
	GUILD_SUBHEADER_GC_MONEY_CHANGE,
};

typedef struct packet_guild
{
    uint8_t header;
    uint16_t size;
    uint8_t subheader;
} TPacketGCGuild;

// SubHeader - Grade
enum
{
    GUILD_AUTH_ADD_MEMBER       = (1 << 0),
    GUILD_AUTH_REMOVE_MEMBER    = (1 << 1),
    GUILD_AUTH_NOTICE           = (1 << 2),
    GUILD_AUTH_SKILL            = (1 << 3),
};

typedef struct packet_guild_sub_grade
{
	char grade_name[GUILD_GRADE_NAME_MAX_LEN+1]; // 8+1 길드장, 길드원 등의 이름
	uint8_t auth_flag;
} TPacketGCGuildSubGrade;

typedef struct packet_guild_sub_member
{
	uint32_t pid;
	uint8_t byGrade;
	uint8_t byIsGeneral;
	uint8_t byJob;
	uint8_t byLevel;
	uint32_t dwOffer;
	uint8_t byNameFlag;
// if NameFlag is TRUE, name is sent from server.
//	char szName[CHARACTER_ME_MAX_LEN+1];
} TPacketGCGuildSubMember;

typedef struct packet_guild_sub_info
{
    uint16_t member_count;
    uint16_t max_member_count;
	uint32_t guild_id;
    uint32_t master_pid;
    uint32_t exp;
    uint8_t level;
    char name[GUILD_NAME_MAX_LEN+1];
	uint32_t gold;
	uint8_t hasLand;
} TPacketGCGuildInfo;

enum EGuildWarState
{
    GUILD_WAR_NONE,
    GUILD_WAR_SEND_DECLARE,
    GUILD_WAR_REFUSE,
    GUILD_WAR_RECV_DECLARE,
    GUILD_WAR_WAIT_START,
    GUILD_WAR_CANCEL,
    GUILD_WAR_ON_WAR,
    GUILD_WAR_END,

    GUILD_WAR_DURATION = 2*60*60, // 2시간
};

typedef struct packet_guild_war
{
    uint32_t       dwGuildSelf;
    uint32_t       dwGuildOpp;
    uint8_t        bType;
    uint8_t        bWarState;
} TPacketGCGuildWar;

typedef struct SPacketGuildWarPoint
{
    uint32_t dwGainGuildID;
    uint32_t dwOpponentGuildID;
    int32_t lPoint;
} TPacketGuildWarPoint;

// SubHeader - Dungeon
enum
{
	DUNGEON_SUBHEADER_GC_TIME_ATTACK_START = 0,
	DUNGEON_SUBHEADER_GC_DESTINATION_POSITION = 1,
};

typedef struct packet_dungeon
{
	uint8_t		bHeader;
    uint16_t		size;
    uint8_t		subheader;
} TPacketGCDungeon;

// Private Shop
typedef struct SPacketGCShopSign
{
    uint8_t        bHeader;
    uint32_t       dwVID;
    char        szSign[SHOP_SIGN_MAX_LEN + 1];
} TPacketGCShopSign;

typedef struct SPacketGCTime
{
    uint8_t        bHeader;
    time_t      time;
} TPacketGCTime;

enum
{
    WALKMODE_RUN,
    WALKMODE_WALK,
};

typedef struct SPacketGCWalkMode
{
    uint8_t        header;
    uint32_t       vid;
    uint8_t        mode;
} TPacketGCWalkMode;

typedef struct SPacketGCChangeSkillGroup
{
    uint8_t        header;
    uint8_t        skill_group;
} TPacketGCChangeSkillGroup;

struct TMaterial
{
    uint32_t vnum;
    uint32_t count;
};

typedef struct SRefineTable
{
    uint32_t src_vnum;
    uint32_t result_vnum;
    uint8_t material_count;
    int32_t cost; // 소요 비용
    int32_t prob; // 확률
    TMaterial materials[REFINE_MATERIAL_MAX_NUM];
} TRefineTable;

typedef struct SPacketGCRefineInformation
{
	uint8_t			header;
	uint8_t			pos;
	TRefineTable	refine_table;
} TPacketGCRefineInformation;

typedef struct SPacketGCRefineInformationNew
{
	uint8_t			header;
	uint8_t			type;
	uint8_t			pos;
	TRefineTable	refine_table;
} TPacketGCRefineInformationNew;

enum SPECIAL_EFFECT
{
	SE_NONE,
	SE_HPUP_RED,
	SE_SPUP_BLUE,
	SE_SPEEDUP_GREEN,
	SE_DXUP_PURPLE,
	SE_CRITICAL,
	SE_PENETRATE,
	SE_BLOCK,
	SE_DODGE,
	SE_CHINA_FIREWORK,
	SE_SPIN_TOP,
	SE_SUCCESS,
	SE_FAIL,
	SE_FR_SUCCESS,    
    SE_LEVELUP_ON_14_FOR_GERMANY,	//레벨업 14일때 ( 독일전용 )
    SE_LEVELUP_UNDER_15_FOR_GERMANY,//레벨업 15일때 ( 독일전용 )
    SE_PERCENT_DAMAGE1,
    SE_PERCENT_DAMAGE2,
    SE_PERCENT_DAMAGE3,    
	SE_AUTO_HPUP,
	SE_AUTO_SPUP,
	SE_EQUIP_RAMADAN_RING,			// 초승달의 반지를 착용하는 순간에 발동하는 이펙트
	SE_EQUIP_HALLOWEEN_CANDY,		// 할로윈 사탕을 착용(-_-;)한 순간에 발동하는 이펙트
	SE_EQUIP_HAPPINESS_RING,		// 크리스마스 행복의 반지를 착용하는 순간에 발동하는 이펙트
	SE_EQUIP_LOVE_PENDANT,		// 발렌타인 사랑의 팬던트(71145) 착용할 때 이펙트 (발동이펙트임, 지속이펙트 아님)
};

typedef struct SPacketGCSpecialEffect
{
    uint8_t header;
    uint8_t type;
    uint32_t vid;
} TPacketGCSpecialEffect;

typedef struct SPacketGCNPCPosition
{
    uint8_t header;
	uint16_t size;
    uint16_t count;
} TPacketGCNPCPosition;

struct TNPCPosition
{
    uint8_t bType;
    char name[CHARACTER_NAME_MAX_LEN+1];
    int32_t x;
    int32_t y;
};

typedef struct SPacketGCChangeName
{
    uint8_t header;
    uint32_t pid;
    char name[CHARACTER_NAME_MAX_LEN+1];
} TPacketGCChangeName;

enum EBlockAction
{
    BLOCK_EXCHANGE              = (1 << 0),
    BLOCK_PARTY_INVITE          = (1 << 1),
    BLOCK_GUILD_INVITE          = (1 << 2),
    BLOCK_WHISPER               = (1 << 3),
    BLOCK_MESSENGER_INVITE      = (1 << 4),
    BLOCK_PARTY_REQUEST         = (1 << 5),
};

typedef struct packet_china_matrixd_card
{
	uint8_t	bHeader;
	uint32_t	dwRows;
	uint32_t	dwCols;
} TPacketGCChinaMatrixCard;

typedef struct packet_runup_matrixd_quiz
{
	uint8_t	bHeader;
	char	szQuiz[RUNUP_MATRIX_QUIZ_MAX_LEN + 1];	
} TPacketGCRunupMatrixQuiz;

typedef struct packet_login_key
{
	uint8_t	bHeader;
	uint32_t	dwLoginKey;
} TPacketGCLoginKey;

typedef struct packet_auth_success
{
    uint8_t        bHeader;
    uint32_t       dwLoginKey;
    uint8_t        bResult;
} TPacketGCAuthSuccess;

typedef struct packet_channel
{
    uint8_t header;
    uint8_t channel;
} TPacketGCChannel;

typedef struct SEquipmentItemSet
{
	uint32_t   vnum;
	uint8_t    count;
	int32_t    alSockets[ITEM_SOCKET_SLOT_MAX_NUM];
	TPlayerItemAttribute aAttr[ITEM_ATTRIBUTE_SLOT_MAX_NUM];
} TEquipmentItemSet;

typedef struct pakcet_view_equip
{
    uint8_t header;
	uint32_t dwVID;
	TEquipmentItemSet equips[WEAR_MAX_NUM];
} TPacketGCViewEquip;

typedef struct
{
    uint32_t       dwID;
    int32_t        x, y;
    int32_t        width, height;
    uint32_t       dwGuildID;
} TLandPacketElement;

typedef struct packet_land_list
{
    uint8_t        header;
    uint16_t        size;
} TPacketGCLandList;

typedef struct
{
    uint8_t        bHeader;
    int32_t        lID;
    char        szTargetName[32+1];
} TPacketGCTargetCreate;

enum
{
	CREATE_TARGET_TYPE_NONE,
	CREATE_TARGET_TYPE_LOCATION,
	CREATE_TARGET_TYPE_CHARACTER,
};

typedef struct
{
	uint8_t		bHeader;
	int32_t		lID;
	char		szTargetName[32+1];
	uint32_t		dwVID;
	uint8_t		byType;
} TPacketGCTargetCreateNew;

typedef struct
{
    uint8_t        bHeader;
    int32_t        lID;
    int32_t        lX, lY;
} TPacketGCTargetUpdate;

typedef struct
{
    uint8_t        bHeader;
    int32_t        lID;
} TPacketGCTargetDelete;

typedef struct
{
    uint32_t       dwType;
    uint8_t        bPointIdxApplyOn;
    int32_t        lApplyValue;
    uint32_t       dwFlag;
    int32_t        lDuration;
    int32_t        lSPCost;
} TPacketAffectElement;

typedef struct 
{
    uint8_t bHeader;
    TPacketAffectElement elem;
} TPacketGCAffectAdd;

typedef struct
{
    uint8_t bHeader;
    uint32_t dwType;
    uint8_t bApplyOn;
} TPacketGCAffectRemove;

typedef struct packet_mall_open
{
	uint8_t bHeader;
	uint8_t bSize;
} TPacketGCMallOpen;

typedef struct packet_lover_info
{
	uint8_t bHeader;
	char szName[CHARACTER_NAME_MAX_LEN + 1];
	uint8_t byLovePoint;
} TPacketGCLoverInfo;

typedef struct packet_love_point_update
{
	uint8_t bHeader;
	uint8_t byLovePoint;
} TPacketGCLovePointUpdate;

typedef struct packet_dig_motion
{
    uint8_t header;
    uint32_t vid;
    uint32_t target_vid;
	uint8_t count;
} TPacketGCDigMotion;

typedef struct SPacketGCOnTime
{
    uint8_t header;
    int32_t ontime;     // sec
} TPacketGCOnTime;

typedef struct SPacketGCResetOnTime
{
    uint8_t header;
} TPacketGCResetOnTime;

typedef struct SPacketGCPanamaPack
{
    uint8_t    bHeader;
    char    szPackName[256];
    uint8_t    abIV[32];
} TPacketGCPanamaPack;

typedef struct SPacketGCHybridCryptKeys
{
private:
	SPacketGCHybridCryptKeys() : m_pStream(NULL) {}

public:
	SPacketGCHybridCryptKeys(int32_t iStreamSize) : iKeyStreamLen(iStreamSize)
	{
		m_pStream = new uint8_t[iStreamSize];
	}
	~SPacketGCHybridCryptKeys()
	{
		if( m_pStream )
		{
			delete[] m_pStream;
			m_pStream = NULL;
		}
	}
	static int32_t GetFixedHeaderSize() 
	{
		return sizeof(uint8_t)+sizeof(uint16_t)+sizeof(int32_t);
	}

	uint8_t	bHeader;
	uint16_t    wDynamicPacketSize;
	int32_t		iKeyStreamLen;
	uint8_t*	m_pStream;

} TPacketGCHybridCryptKeys;


typedef struct SPacketGCHybridSDB
{
private:
	SPacketGCHybridSDB() : m_pStream(NULL) {}

public:
	SPacketGCHybridSDB(int32_t iStreamSize) : iSDBStreamLen(iStreamSize)
	{
		m_pStream = new uint8_t[iStreamSize];
	}
	~SPacketGCHybridSDB()
	{
		delete[] m_pStream;
		m_pStream = NULL;
	}
	static int32_t GetFixedHeaderSize()
	{
		return sizeof(uint8_t)+sizeof(uint16_t)+sizeof(int32_t);
	}

	uint8_t	bHeader;
	uint16_t    wDynamicPacketSize;
	int32_t		iSDBStreamLen;
	uint8_t*	m_pStream;

} TPacketGCHybridSDB;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Client To Client

typedef struct packet_state
{
	uint8_t			bHeader;
	uint8_t			bFunc;
	uint8_t			bArg;
	uint8_t			bRot;
	uint32_t			dwVID;
	uint32_t			dwTime;
	TPixelPosition	kPPos;
} TPacketCCState;

// AUTOBAN
typedef struct packet_autoban_quiz
{
    uint8_t bHeader;
	uint8_t bDuration;
    uint8_t bCaptcha[64*32];
    char szQuiz[256];
} TPacketGCAutoBanQuiz;
// END_OF_AUTOBAN

// Guild Mark Packets
typedef struct packet_cg_guild_mark_upload {
    uint8_t header;
    uint32_t guild_id;
    uint32_t data_size;
    uint8_t format[8];
    uint32_t crc32;
} TPacketCGGuildMarkUpload;

typedef struct packet_cg_guild_mark_request {
    uint8_t header;
    uint32_t guild_id;
} TPacketCGGuildMarkRequest;

typedef struct packet_cg_guild_mark_delete {
    uint8_t header;
    uint32_t guild_id;
} TPacketCGGuildMarkDelete;

typedef struct packet_gc_guild_mark_upload_result {
    uint8_t header;
    uint32_t guild_id;
    uint8_t result;
    uint32_t mark_id;
} TPacketGCGuildMarkUploadResult;

typedef struct packet_gc_guild_mark_data {
    uint8_t header;
    uint32_t guild_id;
    uint32_t mark_id;
    uint32_t compressed_size;
    uint32_t original_size;
    uint8_t format[8];
    uint32_t crc32;
    uint64_t timestamp;
} TPacketGCGuildMarkData;

typedef struct packet_gc_guild_mark_update {
    uint8_t header;
    uint32_t guild_id;
    uint32_t mark_id;
    uint8_t update_type;
} TPacketGCGuildMarkUpdate;

#ifdef _IMPROVED_PACKET_ENCRYPTION_
struct TPacketKeyAgreement
{
	static const int32_t MAX_DATA_LEN = 256;
	uint8_t bHeader;
	uint16_t wAgreedLength;
	uint16_t wDataLength;
	uint8_t data[MAX_DATA_LEN];
};

struct TPacketKeyAgreementCompleted
{
	uint8_t bHeader;
	uint8_t data[3]; // dummy (not used)
};
#endif // _IMPROVED_PACKET_ENCRYPTION_

typedef struct SPacketGCSpecificEffect
{
	uint8_t header;
	uint32_t vid;
	char effect_file[128];
} TPacketGCSpecificEffect;

// 용혼석
enum EDragonSoulRefineWindowRefineType
{
	DragonSoulRefineWindow_UPGRADE,
	DragonSoulRefineWindow_IMPROVEMENT,
	DragonSoulRefineWindow_REFINE,
};

enum EPacketCGDragonSoulSubHeaderType
{
	DS_SUB_HEADER_OPEN,
	DS_SUB_HEADER_CLOSE,
	DS_SUB_HEADER_DO_UPGRADE,
	DS_SUB_HEADER_DO_IMPROVEMENT,
	DS_SUB_HEADER_DO_REFINE,
	DS_SUB_HEADER_REFINE_FAIL,
	DS_SUB_HEADER_REFINE_FAIL_MAX_REFINE,
	DS_SUB_HEADER_REFINE_FAIL_INVALID_MATERIAL,
	DS_SUB_HEADER_REFINE_FAIL_NOT_ENOUGH_MONEY,
	DS_SUB_HEADER_REFINE_FAIL_NOT_ENOUGH_MATERIAL,
	DS_SUB_HEADER_REFINE_FAIL_TOO_MUCH_MATERIAL,
	DS_SUB_HEADER_REFINE_SUCCEED,
};

typedef struct SPacketCGDragonSoulRefine
{
	SPacketCGDragonSoulRefine() : header (HEADER_CG_DRAGON_SOUL_REFINE)
	{}
	uint8_t header;
	uint8_t bSubType;
	TItemPos ItemGrid[DS_REFINE_WINDOW_MAX_NUM];
} TPacketCGDragonSoulRefine;

typedef struct SPacketGCDragonSoulRefine
{
	SPacketGCDragonSoulRefine() : header(HEADER_GC_DRAGON_SOUL_REFINE)
	{}
	uint8_t header;
	uint8_t bSubType;
	TItemPos Pos;
} TPacketGCDragonSoulRefine;

typedef struct SChannelStatus
{
	int16_t nPort;
	uint8_t bStatus;
} TChannelStatus;

#pragma pack(pop)
