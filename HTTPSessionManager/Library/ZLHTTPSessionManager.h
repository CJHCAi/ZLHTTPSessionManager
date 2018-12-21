//
//  ZLHTTPSessionManager.h
//  BoYi
//
//  Created by zhaolei on 2018/5/8.
//  Copyright © 2018年 hengwu. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ZLHTTPFileModel.h"

///请求失败状态
typedef NS_ENUM (NSInteger , ZLHttpErrorState){
    ///请求正常
    ZLHttpErrorStateNull = 0,
    ///服务器挂掉、访问地址不存在
    ZLHttpErrorStateServerFailure ,
    ///超时
    ZLHttpErrorStateTimeout ,
    ///断网
    ZLHttpErrorStateNoNetwork
};

///网络状态
typedef NS_ENUM(NSInteger, ZLHTTPSessionNetworkStatus) {
    ///未知状态
    ZLHTTPSessionNetworkStatusUnknown          = -1,
    ///未联网
    ZLHTTPSessionNetworkStatusNotReachable     = 0,
    ///流量
    ZLHTTPSessionNetworkStatusReachableViaWWAN = 1,
    ///WIFI
    ZLHTTPSessionNetworkStatusReachableViaWiFi = 2,
};

@interface ZLHTTPSessionManager : NSObject

///追加请求头
@property (nonatomic,strong,nullable) NSMutableDictionary *httpHeaderM;
///请求时间  默认30秒  超过30秒后请求会以ZLHttpErrorStateTimeout的错误类型返回error
@property (nonatomic,unsafe_unretained) NSTimeInterval requestTime;
///当前环境
@property (nonatomic,unsafe_unretained,readonly) BOOL online;

///获取实例
+ (instancetype)shared;

/**AppDelegate配置项
 *@param debugPrefix 调试时的前缀
 *@param onlinePrefix 发布时的前缀
 *@param online 是否是发布环境
 *@param showLogs 打印日志
 *@param networkComplete 网络发生变化时的回调
 */
+ (void)configDebugUrlPrefix:(NSString *)debugPrefix OnlineUrlPrefix:(NSString *)onlinePrefix Online:(BOOL)online ShowLogs:(BOOL)showLogs NetworkState:(void(^)(ZLHTTPSessionNetworkStatus state))networkComplete;

/**GET请求
 *@param urlString 请求地址
 *@param dict 请求参数
 *@param isAddHeader 是否追加head头，如需增加，请在外界对本类属性httpHeaderM进行配置
 *@param cachePolicy 缓存策略
 *@param complete 处理结果
 */
+ (void)GET:(NSString *)urlString Params:(NSDictionary *)dict AddHttpHeader:(BOOL)isAddHeader CachePolicy:(NSURLRequestCachePolicy)cachePolicy Results:(void (^)(ZLHttpErrorState sessionErrorState, id responseObject))complete;

/**POST请求 --  追加图片数据
 *@param urlString 请求地址
 *@param dict 请求参数
 *@param isAddHeader 是否追加head头，如需增加，请在外界对本类属性httpHeaderM进行配置
 *@param cachePolicy 缓存策略
 *@param complete 处理结果
 */
+ (void)POST:(NSString *)urlString Params:(NSDictionary *)dict ModelArray:(NSArray <ZLHTTPFileModel *>*)modelArray AddHttpHeader:(BOOL)isAddHeader CachePolicy:(NSURLRequestCachePolicy)cachePolicy Results:(void (^)(ZLHttpErrorState sessionErrorState, id responseObject))complete;

@end
