//
//  AWFGroupIdentifier.h
//  AerisMap
//
//  Created by Nicholas Shipes on 8/18/14.
//  Copyright (c) 2014 HAMweather, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Aeris/Aeris.h>

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

extern NSString * const AWFEarthquakeAnnotationTypeMini;
extern NSString * const AWFEarthquakeAnnotationTypeMinor;
extern NSString * const AWFEarthquakeAnnotationTypeLight;
extern NSString * const AWFEarthquakeAnnotationTypeModerate;
extern NSString * const AWFEarthquakeAnnotationTypeStrong;
extern NSString * const AWFEarthquakeAnnotationTypeMajor;
extern NSString * const AWFEarthquakeAnnotationTypeGreat;
extern NSString * const AWFEarthquakeAnnotationTypeCatastrophic;

extern NSString * const AWFStormReportAnnotationTypeAvalanche;
extern NSString * const AWFStormReportAnnotationTypeBlizzard;
extern NSString * const AWFStormReportAnnotationTypeFire;
extern NSString * const AWFStormReportAnnotationTypeFlood;
extern NSString * const AWFStormReportAnnotationTypeFog;
extern NSString * const AWFStormReportAnnotationTypeIce;
extern NSString * const AWFStormReportAnnotationTypeHail;
extern NSString * const AWFStormReportAnnotationTypeLightning;
extern NSString * const AWFStormReportAnnotationTypeRain;
extern NSString * const AWFStormReportAnnotationTypeSnow;
extern NSString * const AWFStormReportAnnotationTypeTides;
extern NSString * const AWFStormReportAnnotationTypeTornado;
extern NSString * const AWFStormReportAnnotationTypeWind;

extern NSString * const AWFFireAnnotationTypeSmall;
extern NSString * const AWFFireAnnotationTypeMedium;
extern NSString * const AWFFireAnnotationTypeLarge;
extern NSString * const AWFFireAnnotationTypeCritical;

extern NSString * const AWFRiverAnnotationTypeMajor;
extern NSString * const AWFRiverAnnotationTypeModerate;
extern NSString * const AWFRiverAnnotationTypeMinor;
extern NSString * const AWFRiverAnnotationTypeNearFlood;
extern NSString * const AWFRiverAnnotationTypeNoFlood;
extern NSString * const AWFRiverAnnotationTypeNotDefined;
extern NSString * const AWFRiverAnnotationTypeLowWater;
extern NSString * const AWFRiverAnnotationTypeOldData;
extern NSString * const AWFRiverAnnotationTypeOutOfService;

@interface AWFGroupIdentifier : NSObject

+ (NSArray *)identifiersForObjectClass:(Class)objectClass;
+ (NSString *)identifierForModelObject:(AWFObject *)modelObject;

@end
