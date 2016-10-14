//
//  SNYVideoConfig.h
//  SNYCamera
//
//  Created by 宋乃银 on 16/6/6.
//  Copyright © 2016年 sny. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <CoreMedia/CoreMedia.h>
#import <AVFoundation/AVFoundation.h>

typedef NS_ENUM(NSInteger,SNYCameraType) {

    SNYCameraType_stillCamera,
    SNYCameraType_videoCamera
    
};

@interface SNYCameraConfig : NSObject

+(instancetype)defaultConfig;

//相机模式   拍照  or  录制短视频
@property (nonatomic, assign)SNYCameraType cameraType;

//----------------------
//照片是否允许编辑 默认YES
@property (nonatomic, assign) BOOL allowsEditing;
//图片裁剪宽高比 默认1.0 ,单选照片，拍摄照片可用，且仅在useEditer == YES时有效
@property (nonatomic, assign) CGFloat aspectRatio;
//----------------------

//最低录制时长 默认3s
@property (nonatomic, assign) CGFloat minRecordedDuration;
/**
 最大录制时长 默认15s
 */
@property (nonatomic, assign) CGFloat maxRecordedDuration;
/**
 帧率 默认30
 */
@property (nonatomic, assign) int32_t videoFrameRate;

/**
 视频码率 默认1024*1024
 */
@property (nonatomic, assign) UInt64 videoBitRate;

/**
 音频码率 默认44*1024
 */
@property (nonatomic, assign) UInt64 audioBitRate;
/**
 是否开启美颜 默认YES
 */
@property (nonatomic, assign) BOOL isBeauty;
/**
 摄像头方向 默认AVCaptureDevicePositionBack
 */
@property (nonatomic, assign) AVCaptureDevicePosition preferredCameraPosition;
/**
 提示语 默认nil
 */
@property (nonatomic, copy)   NSString *tipsString;
@end
