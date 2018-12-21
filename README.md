### 简介
基于AFNetworking的马甲库

---
### 作用
    - 日志打印
    - 筛除NULL
    - 检测网络状态
    - 将ERROR进行分类	
    - 转换基本数据类型为字符串
---
### 安装
```
pod 'ZLHTTPSessionManager', '~> 0.0.1'
```
---
### 使用
- 头文件
```
#import <ZLHTTPSessionManager.h>
```
- AppDelegate配置
```
    //配置基本信息
    [ZLHTTPSessionManager configDebugUrlPrefix:@"调试环境前缀" OnlineUrlPrefix:@"发布环境前缀" Online:NO ShowLogs:YES NetworkState:^(ZLHTTPSessionNetworkStatus state) {
       //网络状态改变后的回调
    }];
```
- GET
```
    //参数
    NSMutableDictionary *dictM = [NSMutableDictionary new];
    dictM[@"key"] = @"value";
    
    [ZLHTTPSessionManager GET:@"路径" Params:dictM AddHttpHeader:NO CachePolicy:YES Results:^(ZLHttpErrorState sessionErrorState, id responseObject) {
        ///处理结果
    }];
```
- POST
```
    //参数
    NSMutableDictionary *dictM = [NSMutableDictionary new];
    dictM[@"key"] = @"value";
    
    [ZLHTTPSessionManager POST:@"路径" Params:dictM ModelArray:nil AddHttpHeader:NO CachePolicy:YES Results:^(ZLHttpErrorState sessionErrorState, id responseObject) {
        ///处理结果
    }];
```
