//
//  SNYCameraController.h
//  SNYCamera
//
//  Created by 宋乃银 on 16/10/13.
//  Copyright © 2016年 camhow. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SNYCameraConfig.h"

@protocol SNYCameraControllerDelegate;
@interface SNYCameraController : UINavigationController

-(instancetype)initWithConfig:(SNYCameraConfig *)config;

@property(nonatomic,weak)id<SNYCameraControllerDelegate,UINavigationControllerDelegate>delegate;

@end


@protocol SNYCameraControllerDelegate <NSObject>

@optional
/**
 *  拍照 模式回调
 */
- (void)cameraController:(SNYCameraController *)controller didFinishWithImage:(UIImage *)image;
/**
 *  录制视频 模式回调
 */
- (void)cameraController:(SNYCameraController *)controller didFinishWithVideoPath:(NSString *)filePath;
/**
 *  取消选择回调
 */
- (void)cameraControllerDidCancel:(SNYCameraController *)controller;

@end
