//
//  WGCategory+NSString.h
//  WGCategoryAppend
//
//  Created by Apple on 13-12-30.
//  Copyright (c) 2013年 Apple. All rights reserved.
//

//密码  字母、数字、下划线组成，至少n位
#define RE_Si @".*[a-zA-Z]+.*"
#define RE_SecretLeast(n,m) [NSString stringWithFormat:@"[0-9A-Za-z_]\\w{%d,%d}",(n-1),(m)]
//检测字符串为多少位的数字
#define RE_IsNumberAndCount(n) [NSString stringWithFormat:@"^\\d{%d}$",n]
//检测字符串是否为纯数字
#define RE_IsNumber @"^[0-9.]*$"
//检测网址
#define RE_HttpUrl @"http+:[^\\s]*"
////检测固话
//#define RE_FixedTel @"\d{3}-\d{8}|\d{4}-\d{7}"
//手机号码
#define RE_MobileNumber @"^((13)|(17)|(14)|(15)|(18))\\d{9}$"
//匹配电话号码
#define RE_TelNumber @"((\\d{11})|^((\\d{7,8})|(\\d{4}|\\d{3})-(\\d{7,8})|(\\d{4}|\\d{3})-(\\d{7,8})-(\\d{4}|\\d{3}|\\d{2}|\\d{1})|(\\d{7,8})-(\\d{4}|\\d{3}|\\d{2}|\\d{1}))$)"
//匹配电子邮箱
#define RE_Email @"[a-zA-Z0-9!#$%&'*+/=?^_`{|}~-]+(?:\\.[a-z0-9!#$%&'*+/=?^_`{|}~-]+)*@(?:[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\\.)+[a-z0-9](?:[a-z0-9-]*[a-z0-9])?"
//邮编
#define RE_PostCode @"[1-9]\\d{5}(?!\\d)"
//传真
#define RE_Fax @"^[+]{0,1}(\\d){1,3}[ ]?([-]?((\\d)|[ ]){1,12})+$"
//密码
#define RE_Password @"[a-zA-Z]\\w{5,17}"



@interface NSString(Category)

/**
*@brief	处理网络服务器返回数据，区分NSNumber、NSNull、NSString、or 其它
*
*@param 	string 	网络数据对象
*
*@return	NSNumber：NSString，NSNull：WGNull，NSString：self，其他：self
*/
+ (NSString *)handleNetString:(NSString *)string;


/**
*@brief	正则表达式匹配，匹配度为完整字符串匹配，否则都返回NO
*
*@param 	pattern 	正则表达式
*
*@return	YES/NO
*/
- (BOOL)isMatchingRegularEpressionByPattern:(NSString *)pattern;

/**
 *  从字符串中，截取符合正则表达式的字符串
 *
 *  @param pattern 正则表达式
 *
 *  @return 数组，nil if none
 */
- (NSArray *)stringFromRegularEpression:(NSString *)pattern;

/**
*@brief	将  NSObject 无差别地 转化为 NSString
*
*@param 	obj 需要强制转化为NSString字符串的对象 ，可以是任何NSObject
*@param 	lv   当前解析的等级，从0开始，用于首行缩进
*
*@return	NSString
*/
+ (NSString *)changeObjToString:(id )obj CurLV:(int )lv;
/**
 *  @author chao, 15-11-24 11:11:26
 *
 *  判断返回数据是否正确
 *
 *  @param error 服务器返回
 *
 *  @return 是否为空
 */
-(BOOL)isErrorIsNull;
/**
 *  @author chao, 15-12-01 15:12:14
 *
 *  时间戳->日期
 *
 *  @param str 时间戳
 *
 *  @return 2015-12-01 15:40:49
 */
+(NSString *)stringDateFromString:(NSString *)str;
/**
 *  @author chao, 15-12-16 14:12:39
 *
 *  时间戳->日期
 *
 *  @param format @"yyyy-MM-dd HH:mm"等等。。。
 *
 *  @return 2015年12月16日14:09
 */
-(NSString *)stringDateWithFormat:(NSString *)format;
/**
 *  身份证验证
 *
 *  @param cardNo 号码
 *
 *  @return yes /no
 */
+(BOOL)checkIdentityCardNo:(NSString*)cardNo;
@end
