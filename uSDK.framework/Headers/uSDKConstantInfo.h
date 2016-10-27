//
//  uSDKConstantInfo.h
//  uSDK_iOS_v2
//
//  Created by Zono on 14-1-7.
//  Copyright (c) 2014年 haierubic. All rights reserved.
//
//设备Mac及session均为NSString类型
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


/**
 *	设备大类分类
 */
typedef NS_ENUM(NSInteger,uSDKDeviceTypeConst)  {
    /**
     *  所有设备类型
     */
    ALL_TYPE = 0, // 所有设备类型
    /**
     *  冰箱
     */
    FRIDGE = 1,	//冰箱
    /**
     *  分体空调
     */
    SPLIT_AIRCONDITION = 2, // 分体空调
    /**
     *  柜机空调
     */
    PACKAGE_AIRCONDITION = 3, // 柜机空调
    /**
     *  波轮洗衣机
     */
    PULSATOR_WASHING_MACHINE = 4, // 波轮洗衣机
    /**
     *  滚筒洗衣机
     */
    DRUM_WASHING_MACHINE = 5, // 滚筒洗衣机
    /**
     *   热水器
     */
    WATER_HEATER = 6, // 热水器
    /**
     *  微波炉
     */
    MICRO_WAVE_OVEN = 7, // 微波炉
    /**
     *  酒柜
     */
    WINE_CABINET = 8, // 酒柜
    /**
     *  油烟机
     */
    RANGE_HOOD = 9, // 油烟机
    /**
     *  洗碗机
     */
    DISH_WASHING_MACHINE = 10, // 洗碗机
    /**
     *  消毒柜
     */
    DISINFECTION_CABINET = 11, // 消毒柜
    /**
     *  保留
     */
    RESERVE = 12, // 保留
    /**
     *  商用空调
     */
    COMMERCIAL_AIRCONDITION = 13, // 商用空调
    /**
     *  电视
     */
    TV = 14, // 电视
    /**
     *  娱乐设备：媒体中心，音响等
     */
    HOME_ENTERTAINMENT_EQUIPMENT = 15, // 娱乐设备：媒体中心，音响等
    /**
     *  灯光照明
     */
    LIGHTING = 16, // 灯光照明
    /**
     *  安全防范：安防设备
     */
    SECURITY_EQUIPMENT = 17, // 安全防范：安防设备
    /**
     *  视频监控
     */
    VIDEO_SURVEILLANCE = 18, // 视频监控
    /**
     *  传感器：各类环境传感器
     */
    SENSOR = 19, // 传感器：各类环境传感器
    /**
     *  智能家居：智能窗帘，三表等
     */
    SMART_HOME = 20, // 智能家居：智能窗帘，三表等
    /**
     *   医疗保健：各种家庭医疗监护，远程医疗等
     */
    MEDICAL_CARE = 21, // 医疗保健：各种家庭医疗监护，远程医疗等
    /**
     *  冷柜
     */
    REFRIDGERATOR = 22, // 冷柜
    /**
     *  医用柜
     */
    MEDICAL_CABINET = 23, // 医用柜
    /**
     *  燃气热水器
     */
    GAS_WATER_HEATER = 24, // 燃气热水器
    /**
     *  采暖炉
     */
    HEATING_FURNACE = 25, // 采暖炉
    /**
     *  蒸箱
     */
    STEAM_BOX = 26, // 蒸箱
    /**
     *  咖啡机
     */
    COFFEE_MAKER = 27, // 咖啡机
    /**
     *  饮水机
     */
    WATER_MACHINE = 28, // 饮水机
    /**
     *  灶具
     */
    COOKING = 29, // 灶具
    /**
     *  烤箱
     */
    OVEN = 30, // 烤箱
    /**
     *  太阳能热水器
     */
    SOLAR_WATER_HEATER = 31, // 太阳能热水器
    /**
     *  空气净化器
     */
    AIR_PURIFIER = 33, // 空气净化器
    /**
     *  净水机
     */
    WATER_PURIFIER = 34, // 净水机
    /**
     *  空气魔方
     */
    AIR_CUBE = 51, // 空气魔方
    /**
     *  路由模块
     */
    ROUTING_MODULE = 225, // 路由模块
    /**
     *  智能路由器
     */
    SMART_ROUTER = 226, // 智能路由器
    /**
     *  控制终端
     */
    CONTROL_TERMINAL = 241, // 控制终端
    
    /**
     *  新风设备
     */
    NEW_WIND_DEVICE = 0X24,     //新风设备	24
    
    /**
     *  影音娱乐
     */
    VIDEO_AUDIO = 0X0F,         //影音娱乐	0F
    /**
     *  视频监控
     */
    VIDEO_MONITOR = 0X12,       //视频监控	12
    /**
     *  小厨电
     */
    KITCHEN_APPLIANCE = 0X28,   //小厨电	28
    /**
     *  公共服务类
     */
    PUBLIC_SERVICE = 0X26,      //公共服务类	26
    /**
     *  安防报警
     */
    SECURITY_ALARM = 0X11,      //安防报警	11
    /**
     *  环境监测设备
     */
    ENV_MONITOR = 0X29,         //环境监测设备	29
    /**
     *  空气净化设备
     */
    AIR_PURIFY_DEVICE = 0X21,   //空气净化设备	21
    /**
     *  其他
     */
    OTHER_DEVICE = 0X35,        //其他	35
    /**
     *  除尘设备
     */
    DUST_PROOF = 0X27,          //除尘设备	27
    /**
     *  可穿戴设备
     */
    WEARABLE_DEVICE = 0X32,     //可穿戴设备 	32
    /**
     *  热泵
     */
    HEAT_PUMP = 0X20,
    /**
     *  水壶
     */
    KETTLE = 0X23,
    /**
     *  地暖设备
     */
    FLOOR_HEATING_DEVICE =	0X25,
    /**
     *  网关
     */
    GATEWAY = 0X30,
    /**
     *  机器人
     */
    ROBOT =	0XA1
} ;

/**
 *	uSDK错误类型
 */
typedef  NS_ENUM(NSInteger,uSDKErrorConst) {
    /**
     *  uSDK接口执行成功
     */
    RET_USDK_OK = 0, // uSDK接口执行成功
    
    //通用0
    /**
     *  uSDK无效参数错误
     */
    ERR_USDK_INVALID_PARAM = -10001, // uSDK无效参数
    /**
     *  uSDK未启动
     */
    ERR_USDK_UNSTARTED = -10002,  //uSDK未启动
    /**
     *  uSDK接口超时
     */
    ERR_USDK_TIMEOUT = -10003, // uSDK接口超时
    /**
     *  内部错误
     */
    ERR_INTERNAL = -10006, // 内部错误
    /**
     *  uSDK已经停止
     */
    ERR_USDK_ALREADY_STOPPED = -10007, //uSDK已经停止

    
    //通信1
    /**
     *  通过socket发送数据失败
     */
    ERR_USDK_SEND_DATA_TO_SERVER = -11001,
    
    //SDK管理2
    /**
     *  uSDK启动失败
     */
    ERR_USDK_START_FAILED = -12001, // uSDK启动失败
    /**
     *  uSDK正在启动
     */
    ERR_USDK_STARTING = -12002,   //uSDK正在启动

    //设备管理3
    /**
     *  远程设备重复
     */
    ERR_USDK_REMOTE_DEVICE_DUPLICATE = -13001,//远程设备重复
    /**
     *  远程设备不存在
     */
    ERR_USDK_REMOTE_DEVICE_NOT_EXIST = -13002,//远程设备不存在
    
    /**
     *   设备正在配置中
     */
    ERR_USDK_DEVICE_CONFIG_IN_PROGRESS=-13006,//设备正在配置中
    
    /**
     *   smartlink配置被取消
     */
    ERR_USDK_SMARTCONFIG_BE_CANCELED=-13007,//smartlink配置被取消
    
    /**
     *   smartlink配置完成,但未找到上线设备
     */
    ERR_USDK_RECV_ACK_BUT_NOT_FIND_DEVICE=-13008,//smartlink配置完成,但未找到上线设备
    
    //设备4
    /**
     *   设备已连接（已订阅）
     */
    ERR_USDK_DEVICE_IS_CONNECTED = -14001,//设备已连接（已订阅）
    /**
     *   读取设备属性异常,respModel.attr.name is nil
     */
    ERR_USDK_DEVICE_READ_ATTR = -14002,//读取设备属性异常,respModel.attr.name is nil
    /**
     *  设备未连接（未订阅）
     */
    ERR_USDK_DEVICE_NOT_CONNECT = -14003,//设备未连接（未订阅）
    /**
     *  设备未连接成功或未就绪
     */
    ERR_USDK_DEVICE_NOT_CONNECTED = -14004,//设备未连接成功或未就绪
    /**
     *  无效的组命令名称
     */
    ERR_USDK_INVALID_GROUP_NAME = -14005,//无效的组命令名称
    
} ;

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
 *	设备配置方式
 */
typedef NS_ENUM(NSInteger,uSDKDeviceConfigModeConst) {
    /**
     *  SOFTAP配置方式
     */
    CONFIG_MODE_SOFTAP = 0,
    /**
     *  SMARTCONFIG配置方式
     */
    CONFIG_MODE_SMARTCONFIG,
} ;




