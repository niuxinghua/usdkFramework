//
//  uSDKInnerErrorMessage.h
//  uSDK
//
//  Created by liugn on 15/12/14.
//  Copyright © 2015年 haier. All rights reserved.
//

#import <Foundation/Foundation.h>
/**
 *  内部错误信息
 */
@interface uSDKInnerErrorMessage : NSObject
/**
 *  错误号
 */
@property (nonatomic, assign) NSInteger errNo;
/**
 *  错误信息
 */
@property (nonatomic, copy) NSString* message;

@end
