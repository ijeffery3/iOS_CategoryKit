//
//  NSDate+Category.h
//  Test
//
//  Created by JefferyWan on 2019/4/4.
//  Copyright © 2019 JefferyWan. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSDate (Category)

// 获取系统当前的时间戳，即当前时间距1970的秒数（以毫秒为单位）
+ (NSString *)timestamp;

// 获取当前的时间
//+ (NSString *)currentDateString;

// 通过时间戳(毫秒单位)计算时间差（几小时前、几天前)
+ (NSString *)compareCurrentTime:(NSTimeInterval)compareDate;

// 通过时间戳得出对应的时间
+ (NSString *)getDateStringWithTimestamp:(NSTimeInterval)timestamp;

//通过时间戳和格式  显示时间
+ (NSString *) getStringWithTimestamp:(NSTimeInterval)timestamp formatter:(NSString*)formatter;

@end

NS_ASSUME_NONNULL_END
