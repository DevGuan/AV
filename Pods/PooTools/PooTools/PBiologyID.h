//
//  PTouchID.h
//  adasdasdadadasdasdadadadad
//
//  Created by MYX on 2017/4/24.
//  Copyright © 2017年 邓杰豪. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef enum
{
    BiologyIDVerifyStatusTypeSuccess,//成功
    BiologyIDVerifyStatusTypeDuplicateItem,//试多一次
    BiologyIDVerifyStatusTypeItemNotFound,//没有发现
    BiologyIDVerifyStatusTypeKeyboardIDNotFound,//没有密码
    BiologyIDVerifyStatusTypeTouchIDNotFound,//没有touchid
    BiologyIDVerifyStatusTypeAlertCancel,//弹出验证框后按取消
    BiologyIDVerifyStatusTypePassWordKilled,//失效
    BiologyIDVerifyStatusTypeUnknowStatus,//未知状态
    BiologyIDVerifyStatusTypeKeyboardCancel,//touchid键盘取消
    BiologyIDVerifyStatusTypeKeyboardTouchID,//输入密码
    BiologyIDVerifyStatusTypeTouchIDNotOpen,//touchid开启不了
    BiologyIDVerifyStatusTypeAuthenticationFailed,//验证失败
    BiologyIDVerifyStatusTypeSystemCancel//系统取消
} BiologyIDVerifyStatusType;

typedef NS_ENUM(NSInteger,BiologyIDType){
    BiologyIDTypeNone = 0,
    BiologyIDTypeFaceID,
    BiologyIDTypeTouchID
};

@protocol PBiologyIDDelegate <NSObject>
-(void)biologyIDVerifyStatus:(BiologyIDVerifyStatusType)status;
@end

@interface PBiologyID : NSObject
@property (nonatomic, weak) id<PBiologyIDDelegate>delegate;
@property (nonatomic, copy) void(^biologyIDVerifyBlock)(BiologyIDVerifyStatusType biologyIDVerifyStatus);
@property (nonatomic, copy) void(^biologyIDBlock)(BiologyIDType biologyIDType);
//初始化
+(instancetype)defaultBiologyID;
//TouchID操作
-(void)verifyBiologyIDAction;
-(void)deleteBiologyID;
-(void)biologyAction;
@end
