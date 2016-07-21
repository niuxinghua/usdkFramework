/*!
 @header uAnalytics
 @abstract uAnalytics
 @author Haier ubic
 @version 1.00 2015/03/13 Creation
 */
#import <UIKit/UIKit.h>

/** @brief 发送策略 */
typedef NS_ENUM(NSInteger, uAnalyticsReportPolicy) {
    /** 实时发送 */
    UANALYTICS_REALTIME,
    /** 下次启动时发送 */
    UANALYTICS_BATCH
};


/** 预定义 event id */
extern NSString* const DEVICE_BIND_EVENT;    //设备绑定事件ID
extern NSString* const DEVICE_UNBIND_EVENT;  //设备解绑事件ID
extern NSString* const USER_LOGIN_DURATION;  //用户登录耗时事件ID
extern NSString* const APP_LOAD_DURATION;    //APP加载耗时事件ID
extern NSString* const PAGE_LOAD_DURATION;   //页面加载耗时事件ID
extern NSString* const APP_USE_DURATION;     //APP使用时长事件ID
extern NSString* const DEVICE_COMMAND_EVENT;     //设备控制事件ID
extern NSString* const USER_CLICK_EVENT;  //打点事件ID




/** **数据统计SDK核心类**
 
 uAnalytics类的所有方法以类方法的形式提供。使用SDK时，要求首先设置AppId和AppKey等相关信息。其他缺省设置为实时发送策略，AppStore渠道。
 
 数据统计以事件作为统计标准，分为时长类事件和非时长类事件。
 时长类事件需要成对调用`eventStart:label:`和`eventEnd:label:`来完成一次数据的统计；
 非时长类事件需要调用`event:`或`event:acc:`或`event:attributes:`或`event:attributes:acc:`方法来完成一次数据的统计。
 
 SDK本身提供8种预定义事件以方便用户使用，如果不能满足需求，可以与云平台协商，自己定义事件名称：
 
 - DEVICE_BIND_EVENT    设备绑定事件，附加属性见帮助文档
 - DEVICE_UNBIND_EVENT  设备解绑事件，附加属性见帮助文档
 - DEVICE_COMMAND_EVENT 设备控制事件，附加属性见帮助文档
 - USER_CLICK_EVENT     打点事件，附加属性见帮助文档
 
 - USER_LOGIN_DURATION  用户登录耗时事件，无附加属性
 - APP_LOAD_DURATION    APP加载耗时事件，无附加属性
 - PAGE_LOAD_DURATION   页面加载耗时事件，无附加属性
 - APP_USE_DURATION     APP使用时长事件，无附加属性
 */
@interface uAnalytics : NSObject
#pragma mark basics
///---------------------------------------------------------------------------------------
/// @initialize & basic settings
///---------------------------------------------------------------------------------------


/** 设置SDK启动信息
 
 缺省设置为实时发送策略，渠道为App Store，idfa为空。如果要自己设置这些信息，请使用`startWithAppId:appKey:reportPolicy:channel:idfa:`

 @param appId  云平台分配的appid，不能为空
 @param appKey 云平台分配的appkey，不能为空
 @see   startWithAppId:appKey:reportPolicy:channel:idfa:
*/
+ (void)startWithAppId:(NSString *)appId appKey:(NSString *)appKey;

/** 设置SDK启动信息
 
 @param appId   云平台分配的appid，不能为空
 @param appKey  云平台分配的appkey，不能为空
 @param policy  发送策略，分为实时发送和下次启动时发送，详见`uAnalyticsReportPolicy`定义
 @param channel 渠道名称,为nil或@""时,SDK自动作为@"App Store"渠道处理
 @param idfa    广告标识符，可以为nil或@""
 @see   startWithAppId:appKey:
 */
+ (void)startWithAppId:(NSString *)appId appKey:(NSString *)appKey reportPolicy:(uAnalyticsReportPolicy)policy channel:(NSString *)channel idfa:(NSString*)idfa;

/** 设置uSDK版本号
 
 在可以获得uSDK版本的位置调用该接口记录下uSDK版本信息,用在设备绑定或发生异常时上报app正在使用的uSDK版本。
 如果APP没有嵌入uSDK，不需要使用此接口
 
 @param uSDKVersion uSDK版本号
 */
+ (void)setUSDKVersion:(NSString *)uSDKVersion;

/** 设置用户id
 
 在App登录成功后调用，设置用户的id， 绑定userId后所有的消息都会带有userId信息。
 
 @param userId 用户id
 */
+ (void)setUserId:(NSString *)userId;

/** 设置是否由SDK捕获APP崩溃异常
 
 设置是否由SDK自动捕获未知的崩溃信息并在下次启动时上传服务器,可以不调用.
 默认为YES，设置为NO可以关闭自动崩溃异常收集功能
 
 @param value 是否由SDK自动捕获未知的崩溃信息
 */
+ (void)setExceptionCatchEnabled:(BOOL)value;


#pragma mark event
///---------------------------------------------------------------------------------------
/// @event methods
///---------------------------------------------------------------------------------------


/** 上传地理位置信息
 
 设置当前的经纬度值,SDK会将此经纬度信息上传至服务器
 
 @param latitude  纬度
 @param longitude 经度
 */
+ (void)setLatitude:(double)latitude longitude:(double)longitude;

/** 无附加属性事件的数据统计
 
 适用于非时长类事件
 
 @warning "e_app_start"为SDK保留字，App开发者主动调用无效。
 @param eventId 事件名称
 @see event:attributes:
 @see event:acc:
 @see event:attributes:acc:
 */
+ (void)event:(NSString *)eventId;

/** 有附加属性事件的数据统计
 
 适用于非时长类事件，具体的附加属性要求详见帮助文档。
 
 @warning "e_app_start"为SDK保留字，App开发者主动调用无效。
 @param eventId    事件名称
 @param attributes 附加属性字典, 用于对事件的属性及信息等进行描述。如USER_CLICK_EVENT事件，要求携带属性信息：@{actioncode:value}，详见帮助文档
 @see event:
 @see event:acc:
 @see event:attributes:acc:
 */
+ (void)event:(NSString *)eventId attributes:(NSDictionary *)attributes;

/** 无附加属性事件的数据统计
 
 适用于非时长类事件，当需要标识事件发生的次数时调用此接口
 
 @warning "e_app_start"为SDK保留字，App开发者主动调用无效。
 @param eventId      事件名称
 @param accumulation 累加值。为减少网络交互，可以自行对某一事件进行累加，再传入次数作为参数。
 @see event:
 @see event:attributes:
 @see event:attributes:acc:
 */
+ (void)event:(NSString *)eventId acc:(NSInteger)accumulation;

/** 有附加属性事件的数据统计
 
 适用于非时长类事件
 
 @warning "e_app_start"为SDK保留字，App开发者主动调用无效。
 @param eventId      事件名称
 @param attributes   事件属性字典, 用于对事件的属性及信息等进行描述。如USER_CLICK_EVENT事件，要求携带属性信息：@{actioncode:value}，详见帮助文档
 @param accumulation 累加值。为减少网络交互，可以自行对某一事件进行累加，再传入次数作为参数。
 @see event:
 @see event:attributes:
 @see event:acc:
 */
+ (void)event:(NSString *)eventId attributes:(NSDictionary *)attributes acc:(NSInteger)accumulation;

///---------------------------------------------------------------------------------------
/// @duration event methods
///---------------------------------------------------------------------------------------

/** 时长类事件的开始统计接口
 
 调用该接口，会对传入的事件开始计时，并在调用`eventEnd:label:`后完成该时长类事件的统计
 
 @warning 该接口必须与`eventEnd:label:`成对出现时才会正确统计。对于APP_USE_DURATION事件，APP进入后台时会由SDK自动统计一次，恢复到前台时该事件重新开始。
 如果调用`onKill`接口，则会自动结束当前开始的所有时长类事件
 @param eventId 事件名称
 @param label   事件标签
 @see eventEnd:label:
 */
+ (void)eventStart:(NSString *)eventId label:(NSString *)label;

/** 时长类事件的结束统计接口
 
 调用该接口，会匹配通过`eventStart:label:`接口传入的eventId和label，完成该时长类事件的统计
 
 @warning 该接口必须与`eventStart:label:`成对出现时才会正确统计。对于APP_USE_DURATION事件，APP进入后台会由SDK自动统计一次，恢复到前台时该事件重新开始
 @param eventId 事件名称
 @param label   分类标签
 @see eventStart:label:
 */
+ (void)eventEnd:(NSString *)eventId label:(NSString *)label;

///---------------------------------------------------------------------------------------
/// @exception methods
///---------------------------------------------------------------------------------------

/** 上报异常
 
 当APP捕获到异常或APP想记录一次异常事件，可以调用该接口记录异常信息
 
 @param exception 需要上报的异常
 @see postExceptionString:
 */
+ (void)postException:(NSException*)exception;

/** 上报异常
 
 当APP捕获到异常或APP想记录一次异常事件，可以调用该接口记录异常信息
 
 @param exception 需要上报的异常字符串
 @see postException:
 */
+ (void)postExceptionString:(NSString*)exception;

@end