//
//  UIControl+Category.h
//  Test
//
//  Created by JefferyWan on 2019/4/4.
//  Copyright © 2019 JefferyWan. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIControl (Category)


/** 多少秒后可以继续响应事件（防止UI控件短时间多次激活事件） */
@property (nonatomic, assign) NSTimeInterval acceptEventInterval;

@end

NS_ASSUME_NONNULL_END
