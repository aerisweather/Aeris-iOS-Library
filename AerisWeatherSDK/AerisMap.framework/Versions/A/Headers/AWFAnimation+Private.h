//
//  AWFAnimation+Private.h
//  AerisMap
//
//  Created by Nicholas Shipes on 3/25/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

@interface AWFAnimation ()

@property (strong, nonatomic) NSDate *currentTime;
@property (assign, nonatomic) NSTimeInterval currentTimeOffset;
@property (assign, nonatomic) NSTimeInterval fromTimeInterval;
@property (assign, nonatomic) NSTimeInterval toTimeInterval;
@property (strong, nonatomic) NSTimer *timer;
@property (assign, nonatomic) CGFloat increment;
@property (assign, nonatomic) NSTimeInterval delay;

@property (nonatomic, assign) BOOL ready;
@property (nonatomic, assign, getter = isLoading) BOOL loading;

- (void)setup;
- (void)restartFromBeginning;
- (void)cancelLoading;

@end