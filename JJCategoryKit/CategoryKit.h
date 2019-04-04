//
//  CategoryKit.h
//  Test
//
//  Created by JefferyWan on 2019/4/4.
//  Copyright © 2019 JefferyWan. All rights reserved.
//

#ifndef CategoryKit_h
#define CategoryKit_h


#if __has_include(<JJCategoryKit/CategoryKit.h>)

#import <CategoryKit/UIView+Category.h>
#import <CategoryKit/UIImage+Category.h>
#import <CategoryKit/UIImageView+Category.h>
#import <CategoryKit/UIButton+Category.h>
#import <CategoryKit/UIColor+Category.h>
#import <CategoryKit/UIControl+Category.h>

#import <CategoryKit/NSString+Category.h>
#import <CategoryKit/NSArray+Category.h>
#import <CategoryKit/NSDictionary+Category.h>
#import <CategoryKit/NSDate+Category.h>


#else

#import "KitMacro.h"

#import "UIView+Category.h"
#import "UIImage+Category.h"
#import "UIImageView+Category.h"
#import "UIButton+Category.h"
#import "UIColor+Category.h"
#import "UIControl+Category.h"

#import "NSString+Category.h"
#import "NSArray+Category.h"
#import "NSDictionary+Category.h"
#import "NSDate+Category.h"



#endif


#endif /* CategoryKit_h */
