//
//  UIImage+Category.h
//  Test
//
//  Created by JefferyWan on 2019/4/4.
//  Copyright © 2019 JefferyWan. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (Category)

//显示原图（避免被系统渲染成蓝色）
+ (nullable UIImage *)originalImage:(NSString *)imageName;
/** 用颜色返回一张图片 */
+ (nullable UIImage *)imageWithColor:(UIColor *)color;
/** 用颜色返回一张图片（指定图片大小） */
+ (nullable UIImage *)imageWithColor:(UIColor *)color size:(CGSize)size;


/** 截屏或者截取部分视图 */
+ (UIImage *)imageWithCaptureView:(UIView *)captureView;

/*
 * 根据文字生成水印图片
 * rect 是相对图片大小的位置
 */
+ (UIImage *)imageWithWaterMarkImage:(NSString *)imageName text:(NSString *)str textRect:(CGRect)rect;

/** 为UIImage添加滤镜效果 */
- (nullable UIImage *)addFilter:(NSString *)filter;
/** 设置图片的透明度 */
- (nullable UIImage *)alpha:(CGFloat)alpha;
/** 设置圆角图片 */
- (nullable UIImage *)imageByRoundCornerRadius:(CGFloat)radius;
/** 设置圆角图片 */
- (nullable UIImage *)imageByRoundCornerRadius:(CGFloat)radius
                          borderWidth:(CGFloat)borderWidth
                          borderColor:(UIColor *)borderColor;
//  设置圆角图片
// corners：需要设置为圆角的角 UIRectCornerTopLeft | UIRectCornerTopRight | UIRectCornerBottomLeft | UIRectCornerBottomRight | UIRectCornerAllCorners
- (nullable UIImage *)imageByRoundCornerRadius:(CGFloat)radius
                              corners:(UIRectCorner)corners
                          borderWidth:(CGFloat)borderWidth
                          borderColor:(UIColor *)borderColor
                       borderLineJoin:(CGLineJoin)borderLineJoin;





@end

NS_ASSUME_NONNULL_END
