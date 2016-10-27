//
//  uSDKManager.h
//  uSDK_iOS_v2
//
//  Created by Zono on 14-1-7.
//  Copyright (c) 2014年 haierubic. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "uSDKConstantInfo.h"
#import "uSDKInnerErrorMessage.h"

#define USDK_VERSION @"3.3.01"
#define USDK_BUILD_DATE @"2016102515"

/**
 *  uSDK启动状态标识
 */
typedef NS_ENUM(NSInteger, uSDKState){
    /**
     *  uSDK未启动
     */
    uSDKStateUnstart,
    /**
     *  uSDK启动中
     */
    uSDKStateStarting,
    /**
     *  uSDK已启动
     */
    uSDKStateStarted
};

/**
 *	日志级别
 */
typedef NS_ENUM(NSInteger,uSDKLogLevelConst) {
    /**
     *  调试
     */
    USDK_LOG_DEBUG = 1,
    /**
     *  信息
     */
    USDK_LOG_INFO = 2,
    /**
     *  警报
     */
    USDK_LOG_WARNING = 4,
    /**
     *  错误
     */
    USDK_LOG_ERROR = 8,
    /**
     *  无
     */
    USDK_LOG_NONE = 10
} ;


@protocol uSDKManagerDelegage;

/**
 *  uSDK管理者类，用于管理uSDK及监听uSDK消息。
 */
@interface uSDKManager : NSObject

/**
 *  代理，包括Session异常、业务消息。
 */
@property (nonatomic, weak) id<uSDKManagerDelegage> delegate;

/**
 *  uSDK版本号。
 */
@property (nonatomic, strong, readonly) NSString* uSDKVersion;

/**
 *  手机系统信息； 例如:iOS 8.1
 */
@property (nonatomic, strong, readonly) NSString* platform DEPRECATED_ATTRIBUTE;

/**
 *  获取手机型号
 */
@property (nonatomic, strong, readonly) NSString* model DEPRECATED_ATTRIBUTE;

/**
 *  获取uSDK运行状态
 */
@property (nonatomic, assign, readonly) uSDKState state;

@property (nonatomic, assign, readonly) uSDKLogLevelConst logLevel;

/**
 *  获取uSDK单例，此单例用于管理uSDK服务。
 *
 *  @return 返回uSDKManager单例
 */
+ (uSDKManager*)defaultManager;

/**
 *	获取uSDKManager单例，此单例用于管理uSDK服务。
 *
 *	@return	返回uSDKManager单例
 */
+ (uSDKManager*)getSingleInstance DEPRECATED_ATTRIBUTE;


/**
 *  启动uSDK。uSDK启动后，才可以使用本SDK中的API。此方法为同步方法。
 *
 *  @param 	appID   开发者网站上申请获得的appid
 *	@param 	secretKey  开发者网站上申请获得的secretKey
 *	@return	返回uSDK启动成功或失败
 *
 */
-(uSDKErrorConst)startSDK:(NSString*)appID WithSecretKey:(NSString*)secretKey DEPRECATED_ATTRIBUTE;

/**
 *  启动uSDK。uSDK启动后，才可以使用本SDK中的API。执行结果会在回调Block中返回。此方法为异步方法。
 *
 *  @param appID     开发者网站上申请获得的appid
 *  @param secretKey 开发者网站上申请获得的secretKey
 *  @param success   启动成功后的block
 *  @param failure   启动失败后的block
 */
-(void)startSDKWithAppId:(NSString*) appID
               secretKey:(NSString*) secretKey
                 success:(void(^)()) success
                 failure:(void(^)(NSError *error)) failure;

/**
 *  设置uSDK日志信息。uSDK的日志信息包括设置日志级别和是否写日志文件，日志级别设置的越低，输出的日志信息就越详细。
 *
 *  @param level         日志输出级别，详细含义请参见uSDKLogLevelConst
 *  @param isWriteToFile 否需要写日志文件。true表示把日志写到文件中，false表示把日志写到终端上
 *  @param success   调用成功后的block
 *  @param failure   调用失败后的block
 */
- (void)setLogWithLevel:(uSDKLogLevelConst)level
          isWriteToFile:(BOOL)isWriteToFile
                success:(void(^)())success
                failure:(void(^)(NSError *error)) failure;

/**
 *  设置uSDK日志信息。uSDK的日志信息包括设置日志级别和是否写日志文件，日志级别设置的越低，输出的日志信息就越详细。<br>
 *  注:该方法已被setLogWithLevel: isWriteToFile: 方法代替。
 *
 *	@param 	level   日志输出级别，详细含义请参见uSDKLogLevelConst
 *	@param 	isWriteToFile   是否需要写日志文件。YES表示把日志写到文件中，NO表示不写文件。
 *
 *	@return	返回设置日志结果
 */
- (uSDKErrorConst)initLog:(uSDKLogLevelConst)level withWriteToFile:(BOOL)isWriteToFile DEPRECATED_ATTRIBUTE;


/**
 *  停止uSDK。uSDK停止后，所有API将不可使用。
 *
 *	@return	返回停止uSDK结果
 */
- (uSDKErrorConst)stopSDK;

/**
 *  停止uSDK。uSDK停止后，所有API将不可使用。
 *
 *  @param success 停止成功回调
 *  @param failure 停止失败回调
 */
- (void)stopSDKWithSuccess:(void(^)())success
                   failure:(void(^)(NSError *error)) failure;

/**
 *  获取设备唯一标识。
 *
 *	@return	设备唯一标识
 */
-(NSString *)getClientID;

@end



/**
 *  uSDKManager对象的代理协议，包括Session异常、业务消息。
 */
@protocol uSDKManagerDelegage <NSObject>

@optional

/**
 *  会话异常通知。
 *
 *  @param sdkManager     当前uSDKManager对象
 *  @param token          当前会话失效的token
 */
-(void)uSDKManager:(uSDKManager*)sdkManager sessionException:(NSString*)token;

/**
 *  业务消息通知。
 *
 *  @param sdkManager      当前uSDKManager对象
 *  @param businessMessage 当前推送的业务消息
 */
-(void)uSDKManager:(uSDKManager*)sdkManager businessMessage:(NSString*) businessMessage;

@end


