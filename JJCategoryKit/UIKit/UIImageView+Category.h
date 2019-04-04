//
//  UIImageView+Category.h
//  Test
//
//  Created by JefferyWan on 2019/4/4.
//  Copyright © 2019 JefferyWan. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImageView (Category)

/** 通过 Graphics 和 BezierPath 设置圆角（推荐用这个）*/
- (void)setGraphicsCornerRadius:(CGFloat)radius;

@end

NS_ASSUME_NONNULL_END
