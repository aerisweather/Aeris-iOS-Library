//
//  AWFAnnotationLegendStyle.h
//  AerisMap
//
//  Created by Nicholas Shipes on 5/2/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import "AWFLegendStyle.h"

@interface AWFDataLegendStyle : AWFLegendStyle

@property (nonatomic, assign) CGFloat pointRadius;
@property (nonatomic, assign) NSInteger numberOfColumns;
@property (nonatomic, assign) UIEdgeInsets rowEdgeInsets;
@property (nonatomic, assign) BOOL applyFill;
@property (nonatomic, assign) BOOL applyStroke;

@property (nonatomic, strong) NSDictionary *labels;

- (void)setLabelText:(NSString *)labelText forIdentifier:(NSString *)identifier;
- (NSString *)labelTextForIdentifier:(NSString *)identifier;

@end