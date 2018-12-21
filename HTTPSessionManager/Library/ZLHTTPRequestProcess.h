//
//  ZLHTTPRequestProcess.h
//  HTTPSessionManager
//
//  Created by zhaolei on 2018/12/20.
//  Copyright © 2018 赵磊. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZLHTTPSessionManager.h"
#import <AFNetworking/AFNetworking.h>

@interface ZLHTTPRequestProcess : NSObject

///请求的管理对象
@property (nonatomic,strong) AFHTTPSessionManager *requestManager;
///总管理员
@property (nonatomic,strong) ZLHTTPSessionManager *manager;
///追加请求头
@property (nonatomic,strong,nullable) NSMutableDictionary *httpHeaderM;
///当前网络状态
@property (nonatomic,unsafe_unretained) ZLHTTPSessionNetworkStatus networkStatus;
///调试时的前缀
@property (nonatomic,strong) NSString *debugPrefix;
///发布时的前缀
@property (nonatomic,strong) NSString *onlinePrefix;
///是否是发布环境
@property (nonatomic,unsafe_unretained) BOOL online;
///打印日志
@property (nonatomic,unsafe_unretained) BOOL showLogs;

/**GET请求
 *@param urlString 请求地址
 *@param dict 请求参数
 *@param isAddHeader 是否追加head头，如需增加，请在外界对本类属性httpHeaderM进行配置
 *@param cachePolicy 缓存策略
 *@param complete 处理结果
 */
- (void)GET:(NSString *)urlString Params:(NSDictionary *)dict AddHttpHeader:(BOOL)isAddHeader CachePolicy:(NSURLRequestCachePolicy)cachePolicy Results:(void (^)(ZLHttpErrorState sessionErrorState, id responseObject))complete;

/**POST请求 --  追加图片数据
 *@param urlString 请求地址
 *@param dict 请求参数
 *@param isAddHeader 是否追加head头，如需增加，请在外界对本类属性httpHeaderM进行配置
 *@param cachePolicy 缓存策略
 *@param complete 处理结果
 */
- (void)POST:(NSString *)urlString Params:(NSDictionary *)dict ModelArray:(NSArray <ZLHTTPFileModel *>*)modelArray AddHttpHeader:(BOOL)isAddHeader CachePolicy:(NSURLRequestCachePolicy)cachePolicy Results:(void (^)(ZLHttpErrorState sessionErrorState, id responseObject))complete;

@end
