//
//  AWFAnnotation.h
//  AerisMap
//
//  Created by Nicholas Shipes on 5/20/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AWFAnnotation : NSObject <MKAnnotation>

@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *subtitle;
@property (readonly, nonatomic) CLLocationCoordinate2D coordinate;

- (instancetype)initWithCoordinate:(CLLocationCoordinate2D)coordinate;

@end
