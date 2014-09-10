//
//  AWFGroupIdentifier.h
//  AerisMap
//
//  Created by Nicholas Shipes on 8/18/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

extern NSString * const AWFRecordAnnotationTypePrecip;
extern NSString * const AWFRecordAnnotationTypeSnow;
extern NSString * const AWFRecordAnnotationTypeMaxTemp;
extern NSString * const AWFRecordAnnotationTypeMinTemp;
extern NSString * const AWFRecordAnnotationTypeHighMinTemp;
extern NSString * const AWFRecordAnnotationTypeLowMaxTemp;

extern NSString * const AWFStormCellAnnotationTypeGeneral;
extern NSString * const AWFStormCellAnnotationTypeHail;
extern NSString * const AWFStormCellAnnotationTypeRotating;
extern NSString * const AWFStormCellAnnotationTypeTornadic;

extern NSString * const AWFLightningStrikeAnnotationTypeAge15;
extern NSString * const AWFLightningStrikeAnnotationTypeAge15To30;
extern NSString * const AWFLightningStrikeAnnotationTypeAge30To45;
extern NSString * const AWFLightningStrikeAnnotationTypeAge45To60;
extern NSString * const AWFLightningStrikeAnnotationTypeAge60;

extern NSString * const AWFEarthquakeAnnotationTypeMagnitude;

@interface AWFGroupIdentifier : NSObject

+ (NSArray *)identifiersForObjectClass:(Class)objectClass;
+ (NSString *)identifierForModelObject:(AWFObject *)modelObject;

@end
