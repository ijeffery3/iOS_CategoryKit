//
//  UIImage+Category.m
//  Test
//
//  Created by JefferyWan on 2019/4/4.
//  Copyright © 2019 JefferyWan. All rights reserved.
//

#import "UIImage+Category.h"

@implementation UIImage (Category)

// 显示原图（避免被系统渲染成蓝色）
+ (UIImage *)originalImage:(NSString *)imageName {
    return [[UIImage imageNamed:imageName] imageWithRenderingMode:UIImageRenderingModeAlwaysOriginal];
}

// 用颜色返回一张图片
+ (UIImage *)imageWithColor:(UIColor *)color {
    return [self imageWithColor:color size:CGSizeMake(1, 1)];
}

// 用颜色返回一张图片
+ (UIImage *)imageWithColor:(UIColor *)color size:(CGSize)size {
    if (!color || size.width <= 0 || size.height <= 0) return nil;
    CGRect rect = CGRectMake(0.0f, 0.0f, size.width, size.height);
    UIGraphicsBeginImageContextWithOptions(rect.size, NO, 0);
    CGContextRef context = UIGraphicsGetCurrentContext();
    CGContextSetFillColorWithColor(context, color.CGColor);
    CGContextFillRect(context, rect);
    UIImage *image = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    return image;
}

/*
 * 截屏或者截取部分视图
 */
+ (UIImage *)imageWithCaptureView:(UIView *)captureView
{
    //开启位图上下文
    UIGraphicsBeginImageContextWithOptions(captureView.bounds.size, NO, 0);
    //获取上下文
    CGContextRef ctx = UIGraphicsGetCurrentContext();
    //把控件上的图层渲染到上下文
    [captureView.layer renderInContext:ctx];
    
    UIImage *screenImage = UIGraphicsGetImageFromCurrentImageContext();
    
    //关闭上下文
    UIGraphicsEndImageContext();
    
    return screenImage;
    
}

/*
 * 根据文字生成水印图片
 */
+ (UIImage *)imageWithWaterMarkImage:(NSString *)imageName text:(NSString *)str textRect:(CGRect)rect;

{
    UIImage *image = [UIImage imageNamed:imageName];
    UIGraphicsBeginImageContextWithOptions(image.size, NO, 0);
    
    //把图片画上去
    [image drawAtPoint:CGPointZero];
    
    //绘制文字到图片
    NSMutableDictionary *arrt = [NSMutableDictionary dictionary];
    arrt[NSFontAttributeName] = [UIFont systemFontOfSize:20.0];
    [str drawInRect:rect withAttributes:arrt];
    
    // 从上下文获取图片
    UIImage *imageWater = UIGraphicsGetImageFromCurrentImageContext();
    
    //关闭上下文
    UIGraphicsEndImageContext();
    
    return imageWater;
}

/**
 *  滤镜名字：OriginImage(原图)、CIPhotoEffectNoir(黑白)、CIPhotoEffectInstant(怀旧)、CIPhotoEffectProcess(冲印)、CIPhotoEffectFade(褪色)、CIPhotoEffectTonal(色调)、CIPhotoEffectMono(单色)、CIPhotoEffectChrome(铬黄)
 *
 *  灰色：CIPhotoEffectNoir //黑白
 */
#pragma mark - 为UIImage添加滤镜效果
- (UIImage *)addFilter:(NSString *)filterName {
    if ([filterName isEqualToString:@"OriginImage"]) {
        return self;
    }
    //将UIImage转换成CIImage
    CIImage *ciImage = [[CIImage alloc] initWithImage:self];
    //创建滤镜
    CIFilter *filter = [CIFilter filterWithName:filterName keysAndValues:kCIInputImageKey, ciImage, nil];
    //已有的值不变，其他的设为默认值
    [filter setDefaults];
    //获取绘制上下文
    CIContext *context = [CIContext contextWithOptions:nil];
    //渲染并输出CIImage
    CIImage *outputImage = [filter outputImage];
    //创建CGImage句柄
    CGImageRef cgImage = [context createCGImage:outputImage fromRect:[outputImage extent]];
    //获取图片
    UIImage *image = [UIImage imageWithCGImage:cgImage];
    //释放CGImage句柄
    CGImageRelease(cgImage);
    return image;
}

#pragma mark - 设置图片的透明度
- (UIImage *)alpha:(CGFloat)alpha {
    UIGraphicsBeginImageContextWithOptions(self.size, NO, 0.0f);
    CGContextRef ctx = UIGraphicsGetCurrentContext();
    CGRect area = CGRectMake(0, 0, self.size.width, self.size.height);
    CGContextScaleCTM(ctx, 1, -1);
    CGContextTranslateCTM(ctx, 0, -area.size.height);
    CGContextSetBlendMode(ctx, kCGBlendModeMultiply);
    CGContextSetAlpha(ctx, alpha);
    CGContextDrawImage(ctx, area, self.CGImage);
    UIImage *newImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    return newImage;
}

// 设置圆角图片
- (UIImage *)imageByRoundCornerRadius:(CGFloat)radius
{
    return [self imageByRoundCornerRadius:radius borderWidth:0 borderColor:nil];
}

// 设置圆角图片
- (UIImage *)imageByRoundCornerRadius:(CGFloat)radius
                             borderWidth:(CGFloat)borderWidth
                             borderColor:(UIColor *)borderColor
{
    return [self imageByRoundCornerRadius:radius
                                     corners:UIRectCornerAllCorners
                                 borderWidth:borderWidth
                                 borderColor:borderColor
                              borderLineJoin:kCGLineJoinMiter];
}

//  设置圆角图片
// corners：需要设置为圆角的角 UIRectCornerTopLeft | UIRectCornerTopRight | UIRectCornerBottomLeft | UIRectCornerBottomRight | UIRectCornerAllCorners
- (UIImage *)imageByRoundCornerRadius:(CGFloat)radius
                                 corners:(UIRectCorner)corners
                             borderWidth:(CGFloat)borderWidth
                             borderColor:(UIColor *)borderColor
                          borderLineJoin:(CGLineJoin)borderLineJoin
{
    
    if (corners != UIRectCornerAllCorners) {
        UIRectCorner tmp = 0;
        if (corners & UIRectCornerTopLeft) tmp |= UIRectCornerBottomLeft;
        if (corners & UIRectCornerTopRight) tmp |= UIRectCornerBottomRight;
        if (corners & UIRectCornerBottomLeft) tmp |= UIRectCornerTopLeft;
        if (corners & UIRectCornerBottomRight) tmp |= UIRectCornerTopRight;
        corners = tmp;
    }
    
    UIGraphicsBeginImageContextWithOptions(self.size, NO, self.scale);
    CGContextRef context = UIGraphicsGetCurrentContext();
    CGRect rect = CGRectMake(0, 0, self.size.width, self.size.height);
    CGContextScaleCTM(context, 1, -1);
    CGContextTranslateCTM(context, 0, -rect.size.height);
    
    CGFloat minSize = MIN(self.size.width, self.size.height);
    if (borderWidth < minSize / 2) {
        UIBezierPath *path = [UIBezierPath bezierPathWithRoundedRect:CGRectInset(rect, borderWidth, borderWidth) byRoundingCorners:corners cornerRadii:CGSizeMake(radius, borderWidth)];
        [path closePath];
        
        CGContextSaveGState(context);
        [path addClip];
        CGContextDrawImage(context, rect, self.CGImage);
        CGContextRestoreGState(context);
    }
    
    if (borderColor && borderWidth < minSize / 2 && borderWidth > 0) {
        CGFloat strokeInset = (floor(borderWidth * self.scale) + 0.5) / self.scale;
        CGRect strokeRect = CGRectInset(rect, strokeInset, strokeInset);
        CGFloat strokeRadius = radius > self.scale / 2 ? radius - self.scale / 2 : 0;
        UIBezierPath *path = [UIBezierPath bezierPathWithRoundedRect:strokeRect byRoundingCorners:corners cornerRadii:CGSizeMake(strokeRadius, borderWidth)];
        [path closePath];
        
        path.lineWidth = borderWidth;
        path.lineJoinStyle = borderLineJoin;
        [borderColor setStroke];
        [path stroke];
    }
    
    UIImage *image = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    return image;
}

@end
