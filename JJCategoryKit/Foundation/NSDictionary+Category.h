//
//  NSDictionary+Category.h
//  Test
//
//  Created by JefferyWan on 2019/4/4.
//  Copyright © 2019 JefferyWan. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSDictionary (Category)

- (NSString *)jsonString:(NSString *)key;
- (NSDictionary *)jsonDict:(NSString *)key;
- (NSArray *)jsonArray:(NSString *)key;
- (NSArray *)jsonStringArray:(NSString *)key;
- (BOOL)jsonBool:(NSString *)key;
- (NSInteger)jsonInteger:(NSString *)key;
- (long long)jsonLongLong:(NSString *)key;
- (unsigned long long)jsonUnsignedLongLong:(NSString *)key;
- (double)jsonDouble:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
