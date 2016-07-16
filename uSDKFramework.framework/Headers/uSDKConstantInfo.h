//
//  uSDKConstantInfo.h
//  uSDK_iOS_v2
//
//  Created by Zono on 14-1-7.
//  Copyright (c) 2014年 haierubic. All rights reserved.
//

// 设备Mac及session均为NSString类型
#define DEVICE_LIST_CHANGED_NOTIFICATION     @"deviceListChangedNotify"	     //(NSArray*)发生变化的设备列表，元素为uSDKDevice对象
#define DEVICE_ONLINE_CHANGED_NOTIFICATION   @"deviceOnlineChangedNotify"	 //(NSDictionary*)发生变化的设备Mac:此设备的在线状态（uSDKDeviceStatusConst类型）
#define DEVICE_STATUS_CHANGED_NOTIFICATION   @"deviceStatusChangedNotify"	 //(NSDictionary*)发生变化的设备Mac:此设备当前发生的属性变化字典（NSDictionary类型）
#define DEVICE_ALARM_NOTIFICATION            @"deviceAlarmNotify"            //(NSDictionary*)发生变化的设备Mac:此设备当前上报的报警列表（NSArray类型）
#define DEVICE_INFRAREDINFO_NOTIFICATION     @"deviceInfraredInfoNotify"	 //(uSDKTransparentMessage*)当前上报的红外消息
#define BIGDATA_NOTIFICATION                 @"bigDataNotify"                //(uSDKTransparentMessage*)当前上报的大数据消息
#define DEVICE_BINDMESSAGE_NOTIFICATION      @"deviceBindMessageNotify"      //(NSDictionary*)远程session:设备mac
#define DEVICE_UNBINDMESSAGE_NOTIFICATION    @"deviceUnbindMessageNotify"    //(NSDictionary*)远程session:设备mac
#define BUSINESS_MESSAGE_NOTIFICATION        @"businessMessageNofify"        //(uSDKBusinessMessage*)当前推送的业务消息
#define SESSION_EXCEPTION_NOTIFICATION       @"sessionExceptionNotify"       //(NSString*)当前失效的远程session
#define DEVICE_OPERATION_ACK_NOTIFICATION    @"deviceOperationACKNotify"     //(NSDictionary*)命令sn:本次操作引起的属性变化字典

#define SUBDEVICE_LIST_CHANGED_NOTIFICATION  @"subDeviceListChangedNotify"   //(NSDictionary*)发生变化的复杂设备主机设备Mac:对应的发生变化的子机设备列表（NSDictionary类型）

#define INNER_ERROR_NOTIFICATION  @"innerErrorNotification"                         //上报server内部处理时产生的错误

//#define SMART_CONFIG_RESULT_NOTIFICATION   @"smartConfigResultNotification"              //smartConfig配置结果上报

/**
 *	@brief	日志级别
 */
typedef enum
 {
    USDK_LOG_NONE = 0,
    USDK_LOG_DEBUG = 9,
    USDK_LOG_ERROR = 1,
} uSDKLogLevelConst;

/**
 *	@brief	设备网络类型
 */
typedef enum{
    NET_TYPE_REMOTE = 0,
    NET_TYPE_LOCAL,
} uSDKDeviceNetTypeConst;

typedef enum {
	PHONE_NUM = 1,
	MAILBOX = 2,
	USERNAME = 3,
} uSDKLoginTypeConst;

/**
 *	@brief	设备配置方式
 */
typedef enum {
    CONFIG_MODE_SOFTAP = 0,
    CONFIG_MODE_SMARTCONFIG,
} uSDKDeviceConfigModeConst;

/**
 *	@brief	设备网络状态
 */
typedef enum {
    STATUS_OFFLINE = 0,
    STATUS_ONLINE,
    STATUS_READY,
    STATUS_UNAVAILABLE,
} uSDKDeviceStatusConst;

/**
 *	@brief	wifi热点的加密方式：<br>
 *      AP_ENCRYPTION_UNKNOWN：未知<br>
 *      AP_ENCRYPTION_NONE：无加密<br>
 *      AP_ENCRYPTION_WEP：WEP加密<br>
 *      AP_ENCRYPTION_WPA_WPA2：WPA/WPA2加密<br>
 */
typedef enum {
    AP_ENCRYPTION_UNKNOWN = 0,	// 未知
    AP_ENCRYPTION_NONE,         // 无加密
    AP_ENCRYPTION_WEP,          // WEP加密
    AP_ENCRYPTION_WPA_WPA2,     // WPA/WPA2加密
} uSDKApEncryptionTypeConst;

/**
 *	@brief	设备大类分类
 */
typedef enum {
    ALL_TYPE = 0, // 所有设备类型
    FRIDGE = 1,	//冰箱
    SPLIT_AIRCONDITION = 2, // 分体空调
    PACKAGE_AIRCONDITION = 3, // 柜机空调
    PULSATOR_WASHING_MACHINE = 4, // 波轮洗衣机
    DRUM_WASHING_MACHINE = 5, // 滚筒洗衣机
    WATER_HEATER = 6, // 热水器
    MICRO_WAVE_OVEN = 7, // 微波炉
    WINE_CABINET = 8, // 酒柜
    RANGE_HOOD = 9, // 油烟机
    DISH_WASHING_MACHINE = 10, // 洗碗机
    DISINFECTION_CABINET = 11, // 消毒柜
    RESERVE = 12, // 保留
    COMMERCIAL_AIRCONDITION = 13, // 商用空调
    TV = 14, // 电视
    HOME_ENTERTAINMENT_EQUIPMENT = 15, // 娱乐设备：媒体中心，音响等
    LIGHTING = 16, // 灯光照明
    SECURITY_EQUIPMENT = 17, // 安全防范：安防设备
    VIDEO_SURVEILLANCE = 18, // 视频监控
    SENSOR = 19, // 传感器：各类环境传感器
    SMART_HOME = 20, // 智能家居：智能窗帘，三表等
    MEDICAL_CARE = 21, // 医疗保健：各种家庭医疗监护，远程医疗等
    REFRIDGERATOR = 22, // 冷柜
    MEDICAL_CABINET = 23, // 医用柜
    GAS_WATER_HEATER = 24, // 燃气热水器
    HEATING_FURNACE = 25, // 采暖炉
    STEAM_BOX = 26, // 蒸箱
    COFFEE_MAKER = 27, // 咖啡机
    WATER_MACHINE = 28, // 饮水机
    COOKING = 29, // 灶具
    OVEN = 30, // 烤箱
    SOLAR_WATER_HEATER = 31, // 太阳能热水器
    AIR_PURIFIER = 33, // 空气净化器
    WATER_PURIFIER = 34, // 净水机
    AIR_CUBE = 51, // 空气魔方
    ROUTING_MODULE = 225, // 路由模块
    SMART_ROUTER = 226, // 智能路由器
    CONTROL_TERMINAL = 241, // 控制终端
} uSDKDeviceTypeConst;

/**
 *	@brief	uSDK错误类型
 */
typedef  enum
{
    RET_USDK_OK = 0, // uSDK接口执行成功
    RET_USDK_OTHER = 40001, // uSDK其他错误
    RET_USDK_PARA_ERR = 40002, // uSDK参数指定错误
    RET_USDK_MALLOC_ERR = 40003, // uSDK分配内存失败
    RET_USDK_TIMEOUT_ERR = 40004, // uSDK接口执行超时错误
    RET_USDK_CON_DEV_ERR = 40005, // uSDK连接设备错误
    RET_USDK_GET_DEV_INFO_ERR = 40006, // uSDK获取设备信息失败
    RET_USDK_SET_DEV_INFO_ERR = 40007, // uSDK设置设备信息失败
    RET_USDK_FREE_DEV_ERR = 40008, // uSDK释放设备资源失败
    RET_USDK_SEARCH_DEV_ERR = 40009, // uSDK未搜索到任何设备
    RET_USDK_FREE_DEVLIST_ERR = 40010, // uSDK释放设备链表失败
    RET_USDK_REG_ERR = 40011, // uSDK向设备认证失败
    RET_USDK_GET_SESSION_ERR = 40012, // uSDK获取session失败
    RET_USDK_DEL_SESSION_ERR = 40013, // uSDK删除session失败
    RET_USDK_EXE_ERR = 40014, // uSDK执行设备操作失败
    RET_USDK_GET_ALARM_ERR = 40015, // uSDK查询报警信息失败
    RET_USDK_PARSE_DATA_ERR = 40016, // uSDK解析数据失败
    RET_USDK_INVALID_CMD_ERR = 40017, // uSDK解析到无效命令
    RET_USDK_KEEPALIVE_SERVER_ERR = 40018, // uSDK保持远程心跳错误
    RET_USDK_INVALID_SESSION = 40019, // uSDK监测到无效的session
    RET_USDK_INVALID_CONNECTION = 40020, // uSDK监测到无效的网络连接
    RET_BIND_SEARCH_PORT_ERROR = 40021, // uSDK绑定搜索端口失败
    RET_USDK_STOP_ALARM_ERR = 40022, // uSDK停止报警失败
    RET_USDK_GET_DEVSTATUS_ERR = 40023, // uSDK查询设备状态失败
    RET_USDK_PARSE_ALARM_ERR = 40024, // uSDK解析报警上报出错
    RET_USDK_PARSE_STATUS_ERR = 40025, // uSDK解析状态上报出错
    RET_USDK_KEEPALIVE_WIFI_ERR = 40026, // uSDK保持与wifi设备之间的心跳错误
    RET_USDK_SET_CONFIGFILE_ERR = 40027, // uSDK设置配置文件失败
    RET_USDK_LOGIN_REPEAT_ERR = 40028, // uSDK重复登陆设备错误
    RET_USDK_DEVICE_NOREPLY_ERR = 40029, // 底板无响应
    RET_USDK_PARSE_SESSION_INVALID_ERR = 40030, // uSDK解析session失效上报出错
    RET_USDK_TRANS_MODE_SWITCH_ERR = 40031, // uSDK请求模式切失败
    RET_USDK_REG_SERVER_ERR = 40032, // uSDK远程认证失败
    RET_USDK_RECV_SERVER_ERR = 40033, // 远程反馈错误
    RET_USDK_DEV_OFFLINE_ERR = 40034, // 当前设备不在线
    RET_USDK_DEV_UNLOGIN_ERR = 40035, // 当前设备未登陆
    REPORT_DEV_SUCCESS_ALARM = 41000, // uSDK解析报警成功
    REPORT_DEV_SUCCESS_STATUS = 41001, // uSDK解析状态成功
    REPORT_DEV_SUCCESS_PUSH_MESSAGE = 41002, // uSDK解析主动推送消息成功
    REPORT_DEV_SUCCESS_ERR_DATA = 41003, // uSDK收到干扰的无关数据（不做处理）
    REPORT_DEV_SUCCESS_SESSION_INVALID = 41004, // uSDK解析session失效成功
    RET_USDK_START_FAILED = 42001, // uSDK启动失败
    RET_USDK_LOGINIT_FAILED = 42002, // uSDK日志初始化失败
    RET_USDK_LOCAL_LOGIN_FAILED = 42003, // uSDK本地登录失败
    RET_USDK_STOP_FAILED = 42004, // uSDK停止失败
    RET_USDK_SO_LOAD_ERR = 42005, // uSDK的SO文件没有加载
    
    RET_USDK_CERTIFICATION_LOAD_FAIL = 42996,
    RET_USDK_ILLEGAL_APP = 42997,
    
    //add return value from inner protocal ducument//2014 12 26 fansq
        RET_USDK_SOCKET_SENDTO_ERR=40044,//	发送配置失败
    	RET_USDK_CREATE_SOCKET_ERR=40036,//	uSDK创建socket错误
    	RET_USDK_CREATE_THREAD_ERR=40037,//	uSDK创建线程错误
    	RET_USDK_CONFIG_DEV_BUSY_ERR=40038,//	配置设备正在工作中
    	RET_USDK_JSON_FORMAT_ERR=40039,//	收到的数据json格式错误
    	RET_USDK_UNRECV_SMART_ACK_ERR=40046,//	smartconfig没有收到smartlink的确认包
    	RET_USDK_DEV_NOT_EXIST_ERR=40047,//	操作的设备不存在
    	RET_USDK_JSON_TO_EPLUSPLUS_ERR=40048,// 	json转e++失败
    	RET_USDK_SOCKET_BROADCAST_ERR=40049,//	设置socket广播属性失败
    	RET_USDK_TYPEID_INVALID=40050,//	typeid非法，或不存在这个typeid的设备
    	RET_USDK_CONFIG_FILE_NOT_EXIST_ERR=40051,//	配置文件不存在
    	RET_USDK_CONFIG_FILE_ERR=40052,//	读取配置文件异常
    	RET_USDK_CLIEN_NOT_AUTH_ERR=40205,//	客户端没有发送握手协议
    	ERR_UNKNOW_PROTOCOL=40207,//	未知协议（分解包）
    	ERR_MALLOC_ERR=40208,//	malloc失败（分解包）
    	ERR_GET_CONFIGFILE=40209,//	获取配置文件失败
    	RET_USDK_DNS_ERR=40210,//	域名解析失败(远程登录时主动推送)
    	RET_USDK_REMOTE_CONNECT_ERR=40211,//	远程连接失败(远程登录时主动推送)
        RET_USDK_RECV_ACK_BUT_NOT_FIND_DEVICE = 40212, // smartconfig时，收到模块的确认，但模块没有入网
     	ERR_EPP_PARSE_BASE=42000,//	e++解析器错误号基值
    	//ERR_OPENFILE=42001,//	打开配置文件失败（解析器）
    	//ERR_BADFORMAT=42002,//	配置文件格式错误（解析器）
    	//ERR_NOMATCHTYPE=42003,//	ID码错误（解析器）
    	//ERR_SMALLBUFFER=42004,//	E++解析器缓存不够（解析器）
    	//ERR_NOATTRNAME=42005,//  	没有操作的属性名（解析器）
    	ERR_NOATTRVALUE=42006,//	没有操作的属性值（解析器）
    	ERR_NOEPPWORD=42007,//	没有E++控制字（解析器）
    	ERR_NOEPPVALUE=42008,//	没有E++状态值（解析器）
    	ERR_PARAMETERNULL=42009,//	传入解析器参数为空（解析器）
    	ERR_MALLOCFAULT=42010,//	Malloc失败（解析器）
    	ERR_CALLBACK_TYPE=42011,//	没有对应回调类型（解析器）
    	ERR_INVALID_FRAME=42012,//	设备底板返无效帧错误
    	ERR_NOT_SUPPORT=42014,//	该命令不支持 如支持组命令的操作，发送了单命令
    
    
        ERR_REMOTE_BASE=50000,//  	远程错误号基值
    	ERR_USER_NOT_AVAILABLE=50100,//	用户不可用（远程）
    	ERR_USER_NOT_ASSOCIATED_DEVICE=50104,//	设备与用户未关联（远程）
    	ERR_INVALID_SESSION=50105,//	无效会话（远程）
    	ERR_DEVICE_OFFLINE=50103,//	远程设备离线（远程）
    	ERR_DEVICE_NOT_AVAILABLE=50102,//	远程设备不存在（远程）
    	ERR_ACCESS_DENIED=50101,//	用户访问拒绝（远程）
    	ERR_INCOMPELET_CONTENT=50106,//	不完整的内容（如OTA升级包md5校验失败）（远程）
    	ERR_ILLEGAL_CONTENT=50107,//	非法的内容（如OTA升级包与目标平台、硬件不匹配；如更改远程域名时，域名或IP格式不合法，对设备进行无效操作等）（远程）
    	ERR_ENTITY_TOO_LARGE=50108,//	请求实体过大（如OTA升级包大小）（远程）
    	ERR_VERIFY_DECRYPT=50109,//	解密失败
    	ERR_VERIFY_MAC_NOT_EXIST=50110,//	手机mac地址不存在
    	ERR_VERIFY_MAC_INVALID=50111,//	手机mac地址错误
    	ERR_VERIFY_APPID_INVALID=50112,//	appid错误
    	ERR_VERIFY_PACKAGE_NAME_INVALID=50113,//	包名错误
    	ERR_VERIFY_UUID_INVALID=50114,//	uuid错误
    	ERR_VERIFY_MD5_INVALID=50115,//	md5错误
    	ERR_VERIFY_CERT_FILE_NOT_EXIST=50116,//	证书文件不存在
    	ERR_VERIFY_CERT_EXPIRATION=50117,//	证书文件过期
        ERR_VERIFY_BUNDLE_ID_INVALID=50118,//app的bundle id错误(ipone)
        ERR_VERIFY_VERSION_INVALID=50119,//app的version错误(iphone)
    	RET_DEV_EXE_ERR=30002,//	无效命令（底板）
    	ERR_INTERNAL_ERROR=50200,//	云平台内部错误（远程）
    	ERR_OUT_OF_SERVICE=50201,//	云平台不可用（远程）
    RET_USDK_CANCEL_SMARTCONFIG_NOT_AUTH_ERR=40213,//没有权限停止当前正在进行的smart配置。只会出现在类似android这类多客户端的情况，就是客户端只能停止自己触发的配置。
    RET_USDK_CANCEL_SMARTCONFIG_NOT_DOING_ERR=40214, //当前已经没有正在进行的smart配置。
    RET_USDK_SMARTCONFIG_BE_CANCEL_ERR=40212 //配置过程中，被取消配置了
    
} uSDKErrorConst;

typedef  enum
{
    USDK_STATUS_STOPPED = 0,
    USDK_STATUS_STARTED,
}uSDKStatus;

/**
 *	@brief	透传消息类型
 */
typedef enum
{
    MESSAGE_INFRARED_DATA = 0,  //红外数据
    MESSAGE_CHECKING_RESULT,    //生产检测数据
    MESSAGE_BIGDATA,            //大数据
    MESSAGE_OTHER,              //其他数据
}uSDKMessageTypeConst;
