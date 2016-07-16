//
//  uSDKDeviceManager.h
//  uSDK_iOS_v2
//
//  Created by Zono on 14-1-7.
//  Copyright (c) 2014年 haierubic. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "uSDKConstantInfo.h"
#import "uSDKDeviceConfigInfo.h"
#import "uSDKDevice.h"
/**
 *	@brief	功能描述：<br>
 *      uSDK业务错误码消息类。
 */
@interface uSDKError : NSObject

/**
 *	@brief	功能描述：<br>
 *      具体错误码
 */
@property(nonatomic) uSDKErrorConst code;

@end

/**
 *	@brief	功能描述：<br>
 *      uSDK设备管理单例类，用于管理uSDK自动发现的局域网内设备和用户关联的远程设备。
 */
@interface uSDKDeviceManager : NSObject

/**
 *	@brief	功能描述：
 *      设备列表，存储形式：[{Key: 家电设备mac1, Object: 家电设备实例1}, {}...]；此变量只读，设置无效
 */
@property (nonatomic, strong) NSMutableDictionary* deviceDict;

/**
 *	@brief	功能描述：<br>
 *      复杂类设备列表，存储形式：[{Key: 家电设备mac1, Object: 复杂类家电设备列表1}, {}...]；此变量只读，设置无效<br>
 *
 *      注意：<br>
 *      复杂类家电设备列表中的元素为 uSDKComplexDevice 复杂类设备实例。
 */
@property (nonatomic, strong) NSMutableDictionary* subDeviceDict;

/**
 *	@brief	功能描述：<br>
 *      获取uSDKDeviceManager单例，此单例用于访问自动发现的设备列表和与用户关联的设备列表。
 *
 *
 *	@return	返回uSDKDeviceManager单例
 *
 *  <p>
 *  示例代码：
 *  </p>
 *
 *  <pre>
 *      uSDKDeviceManager* uDeviceManager = [uSDKDeviceManager getSingleInstance];
 *  </pre>
 */
+ (uSDKDeviceManager*)getSingleInstance;

/**
 *	@brief	功能描述：<br>
 *      获取指定设备类型的家电设备列表。
 *
 *
 *	@return	家电设备列表，存储形式：{设备实例1, 设备实例2, ...}
 *
 *  <p>
 *  示例代码：
 *  </p>
 *
 *  <pre>
 *      // 获取分体空调设备列表
 *      NSArray* theDevices = [[uSDKDeviceManager getSingleInstance] getDeviceList:SPLIT_AIRCONDITION];
 *  </pre>
 */
- (NSArray*)getDeviceList:(uSDKDeviceTypeConst)deviceType;

/**
 *	@brief	功能描述：<br>
 *          此方法返回所有已发现的设备。这些设备包括uSDK自动发现的wifi网络设备和已与用户关联的设备。如果设备既能本地访问也能远程访问，uSDK访问设备时会优先本地访问。
 *
 *
 *	@return	家电设备列表，存储形式：{设备实例1, 设备实例2, ...}
 *
 *  <p>
 *  示例代码：
 *  </p>
 *
 *  <pre>
 *      // 获取设备列表
 *      NSArray* theDevices = [[uSDKDeviceManager getSingleInstance] getDeviceList];
 *  </pre>
 */
- (NSArray*)getDeviceList;

/**
 *	@brief	功能描述：<br>
 *          获取设备配置信息接口。此接口仅用于softap配置模式，接口超时时间为5秒。<br>
 *
 *          此接口是对softap模式配置（手机与模块的1对1连接模式下）进行配置信息获取，返回包括当前模块可连接的 ssid 列表等配置信息，详细请见类uSDKDeviceConfigInfo
 *
 *
 *	@return	返回设备配置类实例 设备配置信息，详细请见类uSDKDeviceConfigInfo
 *
 *  <p>
 *  示例代码：
 *  </p>
 *
 *  <pre>
 *      uSDKDeviceConfigInfo* configInfo = [[uSDKDeviceManager getSingleInstance] getDeviceConfigInfo];
 *  </pre>
 */
- (uSDKDeviceConfigInfo*)getDeviceConfigInfo;

/**
 *	@brief	功能描述：<br>
 *      设置设备配置信息接口。uSDK支持两种设备配置模式：smartlink和softap。<br>
 *      当设备处于softap模式下，设备以热点模式存在，热点名称以“U_”或“haier_”开头，接口超时时间为5秒。 当设备处于smartlink模式下，设备不以热点存在，但接收udp广播的配置信息，接口立即返回。<br>
 *
 *      注意：<br>
 *      每种类型的家电设备，进入配置模式的方法，需查看各设备的使用说明。 APP向设备发送配置信息之后，设备配置成功后会连接到配置的路由上。如果APP订阅了设备列表通知消息，会得知该设备上线。设备平均上线时间为20秒左右。
 *
 *
 *	@param 	deviceConfigMode 	配置模式，支持两种配置模式：smartlink和softap，请见uSDKDeviceConfigModeConst。
 *	@param 	waitingConfirm 	是否等待确认，值为false表示不等待模块配置确认立即返回；值为true表示等待模块配置确认后才返回，此时接口超时时间为1分钟。
 *	@param 	deviceConfigInfo 	配置信息，不能为null。如果是smartlink模式，只需填入要配置的路由ssid和密码
 *
 *	@return	返回配置结果信息
 *
 *  <p>
 *  示例代码：
 *  </p>
 *
 *  <pre>
 *      uSDKDeviceConfigInfo* configInfo = [[uSDKDeviceConfigInfo alloc] init];
 *      configInfo.apPassword = @"123456";
 *      configInfo.apSsid = @"testap";
 *      uSDKErrorConst err = [[uSDKDeviceManager getSingleInstance] setDeviceConfigInfo:CONFIG_MODE_SOFTAP watitingConfirm:YES deviceConfigInfo:configInfo];
 *  </pre>
 */
- (uSDKErrorConst)setDeviceConfigInfo:(uSDKDeviceConfigModeConst)deviceConfigMode watitingConfirm:(BOOL)waitingConfirm deviceConfigInfo:(uSDKDeviceConfigInfo*)deviceConfigInfo;

/**
 *	@brief	功能描述：
 *      远程用户登录接口。此接口提供远程设备的访问能力，超时时间为5S。 在Internet网络环境下（比如2G、3G、外网wifi），在有效会话期内，用户可以对设备进行远程操作，接收设备报警、状态、业务消息等推送消息。<br>
 *
 *      注意：<br>
 *      当远程连接异常时，所有远程设备都将处于离线状态。如果设备能够在局域网内被发现，该设备会被标记为本地设备，并且所有相关的消息都只通过局域网传递。 如果用户没有已关联的设备，调用此接口后，云平台推送的与设备无关的业务消息也可以送达。 如果用户在一个手机上，通过多个APP操作远程设备，session有效期相同。
 *
 *
 *	@param 	session 远程会话ID，此会话ID是指用户登录云平台时获得的session。
 *	@param 	remoteDevices   远程设备列表，指与用户关联的设备，APP需要向云平台获取。获取到的设备基本信息可以通过uSDKDevice类的newRemoteDeviceInstance接口生成设备实例传递下来，详情请见uSDKDevice类。
 *	@param 	domain  接入网关域名。此接入网关域名是由云平台分配下来，APP需要向云平台获取
 *	@param 	port    接入网关端口。此接入网关端口是由云平台分配下来，APP需要向云平台获取
 *
 *	@return	返回执行结果信息
 *
 *  <p>
 *  示例代码：
 *  </p>
 *
 *  <pre>
 *      NSString* accessToken = @"accessToken";
 *
 *      NSMutableArray* remoteDevices = [[NSMutableArray alloc] init];
 *      NSString* mac = @"mac";
 *      NSString* typeID = @"wifitype";
 *      NSString* online = @"isonline";
 *      NSString* wifiSVersion = @"versionmyself";
 *      NSString* wifiPlatm = @"platformver";
 *
 *      uSDKDevice* dev = [uSDKDevice newRemoteDeviceInstance:mac withDeviceTypeIdentifier:typeID withOnline:online withSmartLinkVersion:wifiVersion withSmartLinkPlatform:wifiPlatm];
 *      [remoteDevices addObject:dev];
 *
 *      [[uSDKDeviceManager getSingleInstance] remoteUserLogin:accessToken withRemoteDevices:remoteDevices withAccessGatewayDomain:@"103.8.220.165" withAccessGatewayPort:56701];
 *  </pre>
 */
- (uSDKErrorConst)remoteUserLogin:(NSString*)session withRemoteDevices:(NSArray*)remoteDevices withAccessGatewayDomain:(NSString*)domain withAccessGatewayPort:(NSInteger)port;

/**
 *	@brief	功能描述：
 *      注销设备的远程访问接口。注销后，所有远程设备标记为离线，所有远程消息都不会再送达APP。<br>
 *
 *      注意： <br>
 *      远程注销后再重新登录时，需要重新向云平台获取session传递进来。
 *
 *
 *	@return	返回执行结果信息
 *
 *  <p>
 *  示例代码：
 *  </p>
 *  <pre>
 *      [[uSDKDeviceManager getSingleInstance] remoteUserLogout];
 *  </pre>
 */
- (uSDKErrorConst)remoteUserLogout;

/**
 *	@brief	功能描述：<br>
 *      smartconfig设备配置信息接口。<br>
 *
 *      注意：<br>
 *      每种类型的家电设备，进入配置模式的方法，需查看各设备的使用说明。 APP向设备发送配置信息之后，设备配置成功后会连接到配置的路由上。如果APP订阅了设备列表通知消息，会得知该设备上线。设备平均上线时间为20秒左右。
 *
 *
 *	@param 	ssid        配置模块连接的路由器的ssid
 *	@param 	password 	配置模块连接的路由器的密码【传入nil时，等同于@""，都是无密码的情况】
 *	@param 	error       如果返回值（uSDKDevice对象）是nil，在uSDKError对象里的code字段，描述了发生了什么错误。如果你没有兴趣可能发生的错误，传入nil。
 *
 *	@return	返回配置成功的设备
 *
 *  <p>
 *  示例代码：
 *  </p>
 *  <pre>
 *      NSString* ssid = @"UAT_AP";
 *      NSString* pwd  = @"123456";
 *      uSDKError* error;
 *      uSDKDevice* dev = [[uSDKDeviceManager getSingleInstance] setDeviceSmartConfigV2Info:ssid withPassword:pwd error:&error];
 *  </pre>
 */
- (uSDKDevice*)setDeviceSmartConfigV2Info:(NSString*)ssid withPassword:(NSString*)password error:(uSDKError**)error;

/**
 *	@brief	功能描述：<br>
    *smartconfig设备配置信息接口。<br>
 *
 *      注意：<br>
 *      每种类型的家电设备，进入配置模式的方法，需查看各设备的使用说明。 APP向设备发送配置信息之后，设备配置成功后会连接到配置的路由上。如果APP订阅了设备列表通知消息，会得知该设备上线。设备平均上线时间为20秒左右。
 *	@param 	ssid        配置模块连接的路由器的ssid
 *	@param 	password 	配置模块连接的路由器的密码【传入nil时，等同于@""，都是无密码的情况】
 *  @param  time        超时时间
 *	@param 	error       如果返回值（uSDKDevice对象）是nil，在uSDKError对象里的code字段，描述了发生了什么错误。如果你没有兴趣可能发生的错误，传入nil。
 *
 *	@return	返回配置成功的设备
 *  <p>
 *  示例代码：
 *  </p>
 *  <pre>NSString* ssid = @"UAT_AP";
 *      NSString* pwd  = @"123456";
 *      NSTimeInterval time=100;
 *      uSDKError* error;uSDKDevice* dev = [[uSDKDeviceManager getSingleInstance] setDeviceSmartConfigV2Info:ssid withPassword:pwd  withTimeout:100 error:&error];
 *  </pre>
 */
- (uSDKDevice*)setDeviceSmartConfigV2Info:(NSString*)ssid withPassword:(NSString*)password withTimeout:(NSTimeInterval)time error:(uSDKError**)error;


/**
 *	@brief	功能描述：<br>
 *      smartconfig设备配置信息接口。<br>
 *
 *      注意：<br>
 *      每种类型的家电设备，进入配置模式的方法，需查看各设备的使用说明。 APP向设备发送配置信息之后，设备配置成功后会连接到配置的路由上。如果APP订阅了设备列表通知消息，会得知该设备上线。设备平均上线时间为20秒左右。
 *
 *
 *	@param 	ssid        配置模块连接的路由器的ssid
 *	@param 	password 	配置模块连接的路由器的密码【传入nil时，等同于@""，都是无密码的情况】
 *  @param  deviceMac   配置模块的mac MAC地址格式为：0007A88A4D4D，不区分大小写
 *	@param 	error       如果返回值（uSDKDevice对象）是nil，在uSDKError对象里的code字段，描述了发生了什么错误。如果你没有兴趣可能发生的错误，传入nil。
 *
 *	@return	返回配置成功的设备
 *
 *  <p>
 *  示例代码：
 *  </p>
 *  <pre>
 *      NSString* ssid = @"UAT_AP";
 *      NSString* pwd  = @"123456";
 *      NSString* deviceMac = @"C89346400425";
 *      uSDKError* error;
 *      uSDKDevice* dev = [[uSDKDeviceManager getSingleInstance] setDeviceSmartConfigV2Info:ssid withPassword:pwd withDeviceMac:deviceMac error:&error];
 *  </pre>
 */
- (uSDKDevice*)setDeviceSmartConfigV2Info:(NSString*)ssid withPassword:(NSString*)password withDeviceMac:(NSString*)deviceMac error:(uSDKError**)error;

/**
 *	@brief	功能描述：<br>
 *      smartconfig设备配置信息接口。<br>
 *      注意：<br>
 *      每种类型的家电设备，进入配置模式的方法，需查看各设备的使用说明。 APP向设备发送配置信息之后，设备配置成功后会连接到配置的路由上。如果APP订阅了设备列表通知消息，会得知该设备上线。设备平均上线时间为20秒左右。
 *
 *
 *	@param 	ssid        配置模块连接的路由器的ssid
 *	@param 	password 	配置模块连接的路由器的密码【传入nil时，等同于@""，都是无密码的情况】
 *  @param  deviceMac   配置模块的mac MAC地址格式为：0007A88A4D4D，不区分大小写
 *  @param  time        超时时间
 *	@param 	error       如果返回值（uSDKDevice对象）是nil，在uSDKError对象里的code字段，描述了发生了什么错误。如果你没有兴趣可能发生的错误，传入nil。
 *
 *	@return	返回配置成功的设备
 *
 *  <p>
 *  示例代码：
 *  </p>
 *
 *  <pre>
 *      NSString* ssid = @"UAT_AP";
 *      NSString* pwd  = @"123456";
 *      NSString* deviceMac = @"C89346400425";
 *      NSTimeInterval time=100;
 *      uSDKError* error;
 *      uSDKDevice* dev = [[uSDKDeviceManager getSingleInstance] setDeviceSmartConfigV2Info:ssid withPassword:pwd withDeviceMac:deviceMac withTimeout:100 error:&error];
 *  </pre>
 */

- (uSDKDevice*)setDeviceSmartConfigV2Info:(NSString*)ssid withPassword:(NSString*)password withDeviceMac:(NSString*)deviceMac withTimeout:(NSTimeInterval)time error:(uSDKError**)error;
/**
 *	@brief	功能描述：<br>
 *      停止smartconfig设备配置接口。<br>
 *
 *
 *	@return	返回函数的执行结果
 *
 *  <p>
 *  示例代码：
 *  </p>
 *
 *  <pre>
 *  NSInteger* err;
 *  uSDKErrorConst rst=[[uSDKDeviceManager getSingleInstance] stopDeviceConfig];
 *  </pre>
 */
-(uSDKErrorConst)stopDeviceConfig;
@end
