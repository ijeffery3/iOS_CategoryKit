//
//  NSArray+Category.m
//  Test
//
//  Created by JefferyWan on 2019/4/4.
//  Copyright © 2019 JefferyWan. All rights reserved.
//

#import "NSArray+Category.h"

@implementation NSArray (Category)

- (NSArray *)reverse {
    return [[self reverseObjectEnumerator] allObjects];
}

@end
