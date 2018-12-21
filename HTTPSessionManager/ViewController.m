//
//  ViewController.m
//  HTTPSessionManager
//
//  Created by zhaolei on 2018/12/20.
//  Copyright © 2018 赵磊. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = UIColor.redColor;
    
    //参数
    NSMutableDictionary *dictM = [NSMutableDictionary new];
    dictM[@"key"] = @"value";
    
//    [ZLHTTPSessionManager GET:@"路径" Params:dictM AddHttpHeader:NO CachePolicy:YES Results:^(ZLHttpErrorState sessionErrorState, id responseObject) {
//        ///处理结果
//    }];
    
//    [ZLHTTPSessionManager POST:@"路径" Params:dictM ModelArray:nil AddHttpHeader:NO CachePolicy:YES Results:^(ZLHttpErrorState sessionErrorState, id responseObject) {
//        ///处理结果
//    }];
}


@end
