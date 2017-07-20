//
//  Preferences.h
//  AerisCatalog
//
//  Created by Nicholas Shipes on 5/7/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import "PAPreferences.h"

extern NSString * const kMapControlTimeline;
extern NSString * const kMapControlBasic;

@interface Preferences : PAPreferences

@property (nonatomic, assign) NSString *style;
@property (nonatomic, assign) NSString *mapControl;
@property (nonatomic, assign) NSDictionary *place;

// graphs
@property (nonatomic, assign) BOOL graphShowLines;
@property (nonatomic, assign) BOOL graphShowPoints;
@property (nonatomic, assign) BOOL graphSmoothLines;

@property (nonatomic, assign) BOOL saved;

- (AWFCascadingStyle *)preferredStyle;
@end
