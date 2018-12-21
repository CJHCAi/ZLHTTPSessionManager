//
//  NSDictionary+ZLHttpDataProcess.m
//  HTTPSessionManager
//
//  Created by zhaolei on 2018/12/20.
//  Copyright © 2018 赵磊. All rights reserved.
//

#import "NSDictionary+ZLHttpDataProcess.h"
#import "NSArray+ZLHttpDataProcess.h"

@implementation NSDictionary (ZLHttpDataProcess)

/**将字典中的Null替换成空字符
 *@return 返回新的没有Null的本类对象
 */
- (instancetype)screeningNull {
    NSArray *dictArray = self.allKeys;
    NSInteger count = dictArray.count;
    NSMutableDictionary *dictM = [[NSMutableDictionary alloc] initWithCapacity:count];
    for (NSInteger index = 0; index < count; index++) {
        NSString *key = dictArray[index];
        NSObject *value = self[key];
        if ([value isKindOfClass:[NSNull class]]) {
            [dictM setObject:@"" forKey:key];
            continue;
        }
        if ([value isKindOfClass:[NSDictionary class]]) {
            NSMutableDictionary *dictM2 = (NSMutableDictionary *)[((NSDictionary *)value) screeningNull];
            [dictM setObject:dictM2 forKey:key];
            continue;
        }
        if ([value isKindOfClass:[NSArray class]]) {
            NSMutableArray *objArrayM = (NSMutableArray *)[((NSArray *)value) screeningNull];
            [dictM setObject:objArrayM forKey:key];
            continue;
        }
        if ([[NSString stringWithFormat:@"%@",value] integerValue]) {
            [dictM setObject:[NSString stringWithFormat:@"%@",value] forKey:key];
            continue;
        }
        [dictM setObject:value forKey:key];
    }
    return dictM;
}

@end
