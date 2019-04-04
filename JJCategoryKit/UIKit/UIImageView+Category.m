//
//  UIImageView+Category.m
//  Test
//
//  Created by JefferyWan on 2019/4/4.
//  Copyright © 2019 JefferyWan. All rights reserved.
//

#import "UIImageView+Category.h"

@implementation UIImageView (Category)

#pragma mark - 通过 Graphics 和 BezierPath 设置圆角（推荐用这个）
- (void)setGraphicsCornerRadius:(CGFloat)radius {
    UIGraphicsBeginImageContextWithOptions(self.bounds.size, NO, 1.0);
    [[UIBezierPath bezierPathWithRoundedRect:self.bounds cornerRadius:radius] addClip];
    [self drawRect:self.bounds];
    self.image = UIGraphicsGetImageFromCurrentImageContext();
    // 结束
    UIGraphicsEndImageContext();
}

@end
