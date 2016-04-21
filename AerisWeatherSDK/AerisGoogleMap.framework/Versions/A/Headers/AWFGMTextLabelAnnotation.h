//
//  AWFGMTextLabelAnnotation.h
//  AerisGoogleMap
//
//  Created by Nicholas Shipes on 2/11/16.
//  Copyright © 2016 Aeris Weather, LLC. All rights reserved.
//

#import <AerisMap/AerisMap.h>
#import <AerisGoogleMap/AWFGMStyledAnnotation.h>

@interface AWFGMTextLabelAnnotation : AWFGMStyledAnnotation

@property (copy, nonatomic) NSString *labelValue;

@end
