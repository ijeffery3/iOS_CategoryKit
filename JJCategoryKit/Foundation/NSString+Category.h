//
//  NSString+Category.h
//  Test
//
//  Created by JefferyWan on 2019/4/4.
//  Copyright © 2019 JefferyWan. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface NSString (Category)

/**
 电话号码中间4位*显示
 */
- (nullable NSString *)getSecrectStringWithPhoneNumber:(nullable NSString *)phoneNum;

/**
 银行卡号中间8位*显示
 */
- (nullable NSString *)getSecrectStringWithAccountNumber:(nullable NSString *)accountNumber;

/**
 转为手机130-1234-5678格式
 */
- (nullable NSString *)stringMobileFormat:(nullable NSString*)mobile;


/**
 金额数字添加单位（暂时写了万和亿，有更多的需求请参考写法来自行添加）
 */
- (nullable NSString *)stringChineseFormat:(double)value;


//去掉前后空格
- (nullable NSString *)trimmedString;

//有效的电话号码
- (BOOL)isValidMobileNumber;

//有效的真实姓名
- (BOOL)isValidRealName;

//是否只有中文
- (BOOL)isOnlyChinese;

//有效的验证码(根据自家的验证码位数进行修改)
- (BOOL)isValidVerifyCode;

//有效的银行卡号
- (BOOL)isValidBankCardNumber;

//有效的邮箱
- (BOOL)isValidEmail;

//有效的字母数字密码
- (BOOL)isValidAlphaNumberPassword;

//检测有效身份证
//15位
- (BOOL)isValidIdentifyFifteen;

//18位
- (BOOL)isValidIdentifyEighteen;

//限制只能输入数字
- (BOOL)isOnlyNumber;




//MD5加密
- (nullable NSString *)MD5String;

// sha1加密（小写）
- (nullable NSString *)sha1String;

// 截取字符串方法封装
- (nullable NSString *)subStringFrom:(nullable NSString *)startString to:(nullable NSString *)endString;

- (nullable NSString *)stringByDeletingPictureResolution;

// 获取UUID
- (nullable NSString *)UUID;

// 获取base64Encoded
- (nullable NSString *)base64Encoded;


// 数组/字典 转 json字符串
- (nullable NSString *)toJsonString;

@end

