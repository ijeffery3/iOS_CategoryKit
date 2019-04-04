//
//  UIButton+Category.h
//  Test
//
//  Created by JefferyWan on 2019/4/4.
//  Copyright © 2019 JefferyWan. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ButtonEdgeInsetsStyle) {
    /** image在上，label在下 */
    ButtonEdgeInsetsStyleTop,
    /** image在左，label在右 */
    ButtonEdgeInsetsStyleLeft,
    /** image在下，label在上 */
    ButtonEdgeInsetsStyleBottom,
    /** image在右，label在左 */
    ButtonEdgeInsetsStyleRight
};


@interface UIButton (Category)

/**
 *  设置button的文字和图片的布局样式，及间距
 *
 *  @param style 文字和图片的布局样式
 *  @param space 文字和图片的间距
 */
- (void)layoutButtonWithEdgeInsetsStyle:(ButtonEdgeInsetsStyle)style
                           imageTitleSpace:(CGFloat)space;


/*
 *    倒计时按钮
 *
 *    @param seconds          要倒计时的总秒数
 *    @param color            还没倒计时的颜色
 *    @param countDownColor   倒计时的颜色
 */
- (void)startWithTime:(NSInteger)seconds color:(UIColor *)color countDownColor:(UIColor *)countDownColor;

@end

NS_ASSUME_NONNULL_END
