//
//  CallZBar.h
//
// Copyright (c) 2014 Saumitra R Bhave
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <Foundation/Foundation.h>
#import "FlashRuntimeExtensions.h"
#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

@interface CameraPreviewManager : NSObject<ZBarReaderViewDelegate>{
    int _defaultResize;
}

@property (assign,readwrite, nonatomic) FREContext freContext;
@property (assign,readwrite, nonatomic) Boolean scanning;
@property (assign,readonly, nonatomic) Boolean previewing;
@property (assign,readonly, nonatomic) UIView* freRootView;

@property (retain,readwrite, nonatomic) ZBarImageScanner* imageScanner;
@property (retain,readwrite, nonatomic) ZBarReaderView* readerView;

+(instancetype) sharedPreviewManager;

-(void) startPreviewWithCamera:(NSString*)cameraPosition atPostion:(CGRect)previewRect;
-(void) resetScanner;
-(void) stopPreview;
-(void) setOrientation:(UIInterfaceOrientation)orientation;
-(void) pause;
-(void) resume;
-(void) setX:(CGFloat)x andY:(CGFloat)y;
-(void) setWidth:(CGFloat)w andHeight:(CGFloat)h;
- (NSString*) supportedPreviewSizes;
- (void) setPreviewWidth:(int)w andHeight:(int)h;
-(void)dealloc;

@end
static CameraPreviewManager *sharedMyManager = nil;
