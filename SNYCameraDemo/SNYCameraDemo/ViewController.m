//
//  ViewController.m
//  GPUImage短视频录制
//
//  Created by admin on 16/10/11.
//  Copyright © 2016年 camhow. All rights reserved.
//

#import "ViewController.h"
#import <MediaPlayer/MediaPlayer.h>
#import <SNYCamera/SNYCamera.h>

@interface ViewController ()<SNYCameraControllerDelegate,UINavigationControllerDelegate>
@property (weak, nonatomic) IBOutlet UIImageView *imageView;

@end

@implementation ViewController

- (IBAction)btnClick:(id)sender
{
    SNYCameraConfig * config = [SNYCameraConfig defaultConfig];
    config.tipsString = @"请勿裸露";
    config.cameraType = SNYCameraType_videoCamera;
    config.minRecordedDuration = 3;//最低3s
    config.maxRecordedDuration = 30;//最多30s
    SNYCameraController * vc = [[SNYCameraController alloc] initWithConfig:config];
    vc.delegate = self;
    [self presentViewController:vc animated:YES completion:nil];

}
- (IBAction)paizhao:(id)sender
{
    
    SNYCameraConfig * config = [SNYCameraConfig defaultConfig];
    config.cameraType = SNYCameraType_stillCamera;
    config.allowsEditing = YES;
    config.aspectRatio = 16/9.0;//裁剪比例
    
    SNYCameraController * vc = [[SNYCameraController alloc] initWithConfig:config];
    vc.delegate = self;
    [self presentViewController:vc animated:YES completion:nil];
}

#pragma mark - SNYCameraControllerDelegate

/**
 *  单选 拍照 模式回调
 */
- (void)cameraController:(SNYCameraController *)controller didFinishWithImage:(UIImage *)image
{
    self.imageView.image = image;
    [controller dismissViewControllerAnimated:YES completion:nil];
}
/**
 *  录制视频 模式回调
 */
- (void)cameraController:(SNYCameraController *)controller didFinishWithVideoPath:(NSString *)filePath
{
     [controller dismissViewControllerAnimated:YES completion:nil];
    
    MPMoviePlayerViewController * vc = [[MPMoviePlayerViewController alloc] initWithContentURL:[NSURL fileURLWithPath:filePath]];
    [self presentViewController:vc animated:YES completion:nil];
}
/**
 *  取消选择回调
 */
- (void)cameraControllerDidCancel:(SNYCameraController *)controller
{
    [controller dismissViewControllerAnimated:YES completion:nil];
}
@end
